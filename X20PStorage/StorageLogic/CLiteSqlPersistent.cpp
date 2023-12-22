#include"CLiteSqlPersistent.h"
#include<QFile>
#include<algorithm>
#include <QByteArray>
#include <wchar.h>


CLiteSqlPersistent::CLiteSqlPersistent(QString fileName):m_strDataBaseName(fileName)
{
    //初始化操作：创建并打开文件，有异常信息，写入日志
    initialize(fileName);
}


CLiteSqlPersistent::~CLiteSqlPersistent()
{

    if(m_bDataBaseOpenFlag)
    {

        short shResult_Value=sqlite3_close(m_ptrSqlite3Db);
        if(shResult_Value!=SQLITE_OK)
        {
            //不能正常关闭的异常信息会写入日志
            qDebug()<<"m_strDataBaseName close failed";
        }

        qDebug()<<m_strDataBaseName+".db"<<" close successful";
        m_bDataBaseOpenFlag=false;
    }
}


//获取QVariant对应sqlite3数据库中value的类型
QString CLiteSqlPersistent::getDBTypeFromQVariantValue(QVariant& value)
{

    if(value.userType()==QMetaType::Float)
    {
        return  "REAL";
    }


        switch (value.type()) {
        case QVariant::Int:
            return "INTEGER";
        case QVariant::UInt:
            return "INTEGER";
        case QVariant::LongLong:
            return "INTEGER";
        case QVariant::ULongLong:
            return "INTEGER";
        case QVariant::Double:
            return "REAL";
        case QVariant::String:
            return "TEXT";
        case QVariant::ByteArray:
            return "TEXT";

        default:
            return "UNKNOWN";  // Handle other types or provide a default
        }

}



//创建流，strStreamName流名可视为表名，存放对应流信息下的子项(ItemName)名字
bool CLiteSqlPersistent::createStream(QString& strStreamName)
{
    if (!m_bDataBaseOpenFlag)
    {
        return false;
    }

    QHash<QString, QString> mapFieldsAndTypes;
    QString strKey = strStreamName + "_ItemName";
    mapFieldsAndTypes[strKey] = "TEXT";

    // 创建strStreamName表，字段为strStreamName+"_Name"："Text"
    bool mReturn_Value = createTable(strStreamName, mapFieldsAndTypes);

    if (mReturn_Value)
    {
        m_mapStreamAndStreamItem[strStreamName].clear();
        return true;
    }
    else
    {
        // 写错误信息到日志中
        return false;
    }
}



//创建基本信息流-对应于sqlite数据库中创建一个基本信息流表，包含字段信息：信息名
bool CLiteSqlPersistent::createBaseInfoStream()
{
    bool bReturn_Value=false;
    QString strName="BaseInfoStream";
    bReturn_Value=createStream(strName);

    if(bReturn_Value)
    {
        m_bBasicInfoStreamCreateFlag=true;

    }
    else
    {
        m_bBasicInfoStreamCreateFlag=false;
    }
    return bReturn_Value;
}



//创建配置信息流
bool CLiteSqlPersistent::createConfigStream()
{
    bool bReturn_Value=false;
    QString strName="ConfigStream";
    bReturn_Value=createStream(strName);

    if(bReturn_Value)
    {
        m_bConfigStreamCreateFlag=true;

    }
    else
    {
        m_bConfigStreamCreateFlag=false;
    }
    return bReturn_Value;
}


//创建事件流
bool CLiteSqlPersistent::createEventStream()
{
    bool bReturn_Value=false;
    QString strName="EventStream";
    bReturn_Value=createStream(strName);

    if(bReturn_Value)
    {
        m_bEventStreamCreateFlag=true;

    }
    else
    {
        m_bEventStreamCreateFlag=false;
    }
    return bReturn_Value;
}



//创建通道数据流
bool CLiteSqlPersistent::createChannelDataStream()
{
    bool bReturn_Value=false;
    QString strName="ChannelDataStream";
    bReturn_Value=createStream(strName);
    if(bReturn_Value)
    {
        m_bChannelDataStreamCreateFlag=true;

    }
    else
    {
        m_bChannelDataStreamCreateFlag=false;
    }
    return bReturn_Value;
}




//创建通道信息流
bool CLiteSqlPersistent::createChannelInfoStream()
{
    bool bReturn_Value=false;
    QString strName="ChannelInfoStream";
    bReturn_Value=createStream(strName);
    if(bReturn_Value)
    {
        m_bChannelInfoSteamCreateFlag=true;

    }
    else
    {
        m_bChannelInfoSteamCreateFlag=false;
    }
    return bReturn_Value;
}



//写入基本信息
bool CLiteSqlPersistent::writeDataToBaseInfo(QString& strBaseInfoItemName,  QHash<QString,QVariant>&   mapItemInfo)
{
    //判断数据库打开
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }



    //判断基本信息流是否创建
    if(!isExistBaseInfoStream())
    {
        bool b_ResultCreate=false;
        b_ResultCreate=createBaseInfoStream();
        if(!b_ResultCreate)
        {
            return false;
        }
    }

    bool bReturn_Value=false;

    //有表，就直接插入数据
    QVector<QString> vecKeys = QVector<QString>::fromList(mapItemInfo.keys());

    //值类型vector容器
    QVector<QString> vecValueTypes;
    for(auto itemKey:vecKeys)
    {
      // 根据 QVariant 的类型确定 SQLite 数据库中的类型


        vecValueTypes.append(getDBTypeFromQVariantValue(mapItemInfo[itemKey]));
    }


    //类型map容器:  <fieldName : type>
    QHash<QString, QString> mapFieldAndType;

    // 确保vecKeys和vecValueTypes的长度相等
    if (vecKeys.size() != vecValueTypes.size())
    {
        //写入日志
        return false;
    }

    for (int i = 0; i < vecKeys.size(); ++i)
    {
        mapFieldAndType[vecKeys[i]] = vecValueTypes[i];
    }

    QString strStreamName="BaseInfoStream";

    //判断成员变量m_mapStreamAndStreamItem["BaseInfoStream"]的values中是否包含strbaseInfoName
    if(m_mapStreamAndStreamItem[strStreamName].contains(strBaseInfoItemName))
    {
        bReturn_Value=insertIntoTable(strBaseInfoItemName, mapItemInfo);
    }

    else
    {
        //判断vecValues的类型
        //不包含strbaseInfoName，先创建表，再插入数据
        bReturn_Value=createTable(strBaseInfoItemName, mapFieldAndType)&&insertIntoTable(strBaseInfoItemName, mapItemInfo);
        if(bReturn_Value)
        {
            //增加到内存和数据库中
            m_mapStreamAndStreamItem[strStreamName].append(strBaseInfoItemName);

            QHash<QString, QVariant> mapTmpFieldAndValue;
            QString strKey=strStreamName+"_ItemName";
            mapTmpFieldAndValue[strKey] = strBaseInfoItemName;

            //将表名增加到对应流上
            insertIntoTable(strStreamName, mapTmpFieldAndValue);
        }
    }


    return bReturn_Value;
}


 //读取基本信息
bool CLiteSqlPersistent::readDataFromBaseInfo(QString& strBaseInfoItemName,  QVector<QVector<QVariant>>&   mapItemInfo)
{
    if(!m_mapTableAndFields.contains(strBaseInfoItemName))
    {
        return false;
    }

    QString strColumns="*";
    QVector<QVector<QVariant>> vecResult;
    QString strCondition="";
    bool bReturn_Value=selectFromTable(strBaseInfoItemName, strColumns, strCondition, mapItemInfo);
    return bReturn_Value;


}



//修改基本信息
bool CLiteSqlPersistent::updateBaseInfo(QString& strBaseInfoItemName, QHash<QString,QVariant>&   mapItemInfo, QString& strCondition)
{
    bool bReturn_Value=false;
    if(!m_bDataBaseOpenFlag&&!m_bBasicInfoStreamCreateFlag)
    {
        return false;
    }

    QString strStreamName="BaseInfoStream";
    if(m_mapStreamAndStreamItem[strStreamName].contains(strBaseInfoItemName))
    {
        //将修改信息写入到数据库中
        bReturn_Value=updateTable(strBaseInfoItemName, mapItemInfo, strCondition);
        return  bReturn_Value;
    }
    else
    {
        //没有对应地基本信息子项名，将错误信息写入日志
        return false;
    }
}




//写入配置信息
bool CLiteSqlPersistent::writeDataToConfigInfo(QString& strConfigInfoItemName,  QHash<QString,QVariant>&   mapItemInfo)
{
    //判断数据库打开
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }

    //判断流是否创建
    bool b_ResultCreate=false;
    if(!isExistConfigStream())
    {
        b_ResultCreate=createConfigStream();
        if(!b_ResultCreate)
        {
            return false;
        }
    }

    bool bReturn_Value=false;

    //有表，就直接插入数据
    QVector<QString> vecKeys = QVector<QString>::fromList(mapItemInfo.keys());

    //值类型vector容器
    QVector<QString> vecValueTypes;
    for(auto itemKey:vecKeys)
    {
        // 根据 QVariant 的类型确定 SQLite 数据库中的类型
        vecValueTypes.append(getDBTypeFromQVariantValue(mapItemInfo[itemKey]));
    }


    //子类、类型map映射容器:  <fieldName : type>
    QHash<QString, QString> mapFieldAndType;

    // 确保vecKeys和vecValueTypes的长度相等
    if (vecKeys.size() != vecValueTypes.size())
    {
        //写入日志
        return false;
    }

    for (int i = 0; i < vecKeys.size(); ++i)
    {
        mapFieldAndType[vecKeys[i]] = vecValueTypes[i];
    }

    QString strStreamName="ConfigStream";
    //判断成员变量m_mapStreamAndStreamItem["BaseInfoStream"]的values中是否包含strbaseInfoName
    if(m_mapStreamAndStreamItem[strStreamName].contains(strConfigInfoItemName))
    {
        bReturn_Value=insertIntoTable(strConfigInfoItemName, mapItemInfo);
    }

    else
    {
        //判断vecValues的类型
        //不包含strbaseInfoName，先创建表，再插入数据
        bReturn_Value=createTable(strConfigInfoItemName, mapFieldAndType)&&insertIntoTable(strConfigInfoItemName, mapItemInfo);
        if(bReturn_Value)
        {
            //增加到内存和数据库中
            m_mapStreamAndStreamItem[strStreamName].append(strConfigInfoItemName);

            QHash<QString, QVariant> mapFieldAndValue;
            QString strKey=strStreamName+"_ItemName";
            mapFieldAndValue[strKey] = strConfigInfoItemName;

            insertIntoTable(strStreamName, mapFieldAndValue);
        }

    }
    return bReturn_Value;
}

//读取配置信息
bool CLiteSqlPersistent::readDataFromConfigInfo(QString& strConfigInfoItemName,  QVector<QVector<QVariant>>&   mapItemInfo)
{

    if(!m_mapTableAndFields.contains(strConfigInfoItemName))
    {
        return false;
    }

    QString strColumns="*";
    QVector<QVector<QVariant>> vecResult;
    QString strCondition="";
    bool bReturn_Value=selectFromTable(strConfigInfoItemName, strColumns, strCondition, mapItemInfo);
    return bReturn_Value;
}



//修改配置信息
bool CLiteSqlPersistent::updateConfigInfo(QString& strConfigInfoItemName, QHash<QString,QVariant>&   mapItemInfo, QString& strCondition)
{
    bool bReturn_Value=false;
    if(!m_bDataBaseOpenFlag&&!m_bConfigStreamCreateFlag)
    {
        return false;
    }

    QString strStreaName="ConfigStream";
    if(m_mapStreamAndStreamItem[strStreaName].contains(strConfigInfoItemName))
    {
        //将修改信息写入到数据库中
        bReturn_Value=updateTable(strConfigInfoItemName, mapItemInfo, strCondition);
        return  bReturn_Value;
    }
    else
    {
        //没有对应地基本信息子项名，将错误信息写入日志
        return false;
    }

}



//写入事件信息
bool CLiteSqlPersistent::writeDataToEventInfo(QString& strEventInfoItemName,   QHash<QString,QVariant>&   mapItemInfo)
{
    //判断数据库打开
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }

    bool b_ResultCreate=false;
    //判断流是否创建
    if(!isExistEventStream())
    {
        b_ResultCreate=createEventStream();
        if(!b_ResultCreate)
        {
            return false;
        }
    }

    bool bReturn_Value=false;

    //有表，就直接插入数据
    QVector<QString> vecKeys = QVector<QString>::fromList(mapItemInfo.keys());

    //值类型vector容器
    QVector<QString> vecValueTypes;
    for(auto itemKey:vecKeys)
    {
        // 根据 QVariant 的类型确定 SQLite 数据库中的类型
        vecValueTypes.append(getDBTypeFromQVariantValue(mapItemInfo[itemKey]));
    }


    //类型map容器:  <fieldName : type>
    QHash<QString, QString> mapFieldAndType;

    // 确保vecKeys和vecValueTypes的长度相等
    if (vecKeys.size() != vecValueTypes.size())
    {
        //写入日志
        return false;
    }

    for (int i = 0; i < vecKeys.size(); ++i)
    {
        mapFieldAndType[vecKeys[i]] = vecValueTypes[i];
    }

    QString strStreamName="EventStream";

    //判断成员变量m_mapStreamAndStreamItem["BaseInfoStream"]的values中是否包含strbaseInfoName
    if(m_mapStreamAndStreamItem[strStreamName].contains(strEventInfoItemName))
    {
        bReturn_Value=insertIntoTable(strEventInfoItemName, mapItemInfo);
    }

    else
    {
        //判断vecValues的类型
        //不包含strbaseInfoName，先创建表，再插入数据
        bReturn_Value=createTable(strEventInfoItemName, mapFieldAndType)&&insertIntoTable(strEventInfoItemName, mapItemInfo);
        //增加到内存和数据库中
        if(bReturn_Value)
        {
            m_mapStreamAndStreamItem[strStreamName].append(strEventInfoItemName);
            QHash<QString, QVariant> mapTmpFieldAndValue;
            QString strKey=strStreamName+"_ItemName";
            mapTmpFieldAndValue[strKey] = strEventInfoItemName;

            insertIntoTable(strStreamName, mapTmpFieldAndValue);
        }
    }
    return bReturn_Value;
}




bool CLiteSqlPersistent::readDataFromEventInfo(QString& strEventInfoItemName,  QVector<QVector<QVariant>>&   mapItemInfo)
{
    if(!m_mapTableAndFields.contains(strEventInfoItemName))
    {
        return false;
    }

    QString strColumns="*";
    QVector<QVector<QVariant>> vecResult;
    QString strCondition="";
    bool bReturn_Value=selectFromTable(strEventInfoItemName, strColumns, strCondition, mapItemInfo);
    return bReturn_Value;
}



//修改事件信息
bool CLiteSqlPersistent::updateEventInfo(QString& strEventInfoItemName, QHash<QString,QVariant>&  mapItemInfo, QString& strCondition)
{
    bool bReturn_Value=false;
    if(!m_bDataBaseOpenFlag&&!m_bEventStreamCreateFlag)
    {
        return false;
    }

    QString strStreaName="EventStream";
    if(m_mapStreamAndStreamItem[strStreaName].contains(strEventInfoItemName))
    {
        //将修改信息写入到数据库中
        bReturn_Value=updateTable(strEventInfoItemName, mapItemInfo, strCondition);
        return  bReturn_Value;
    }
    else
    {
        //没有对应地基本信息子项名，将错误信息写入日志
        return false;
    }
}



//移除事件信息
bool CLiteSqlPersistent::removeEventInfo(QString& strEventInfoItemName, QString& strCondition)
{

    return false;
}




//写入通道信息
bool CLiteSqlPersistent::writeDataToChannelInfo(QString& strChannelNo,     QHash<QString,QVariant>&   mapItemInfo)
{
    //判断数据库打开
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }

    //判断通道信息流是否创建
    bool b_ResultCreate=false;
    if(!m_bChannelInfoSteamCreateFlag)
    {
        b_ResultCreate=createChannelInfoStream();
        if(!b_ResultCreate)
        {
            return false;
        }
    }


    bool bReturn_Value=false;

    //有表，就直接插入数据
    QVector<QString> vecKeys = QVector<QString>::fromList(mapItemInfo.keys());

    //值类型vector容器
    QVector<QString> vecValueTypes;
    for(auto itemKey:vecKeys)
    {
        // 根据 QVariant 的类型确定 SQLite 数据库中的类型
        vecValueTypes.append(getDBTypeFromQVariantValue(mapItemInfo[itemKey]));
    }


    //类型map容器:  <fieldName : type>
    QHash<QString, QString> mapFieldAndType;

    // 确保vecKeys和vecValueTypes的长度相等
    if (vecKeys.size() != vecValueTypes.size())
    {
        //写入日志
        return false;
    }

    for (int i = 0; i < vecKeys.size(); ++i)
    {
        mapFieldAndType[vecKeys[i]] = vecValueTypes[i];
    }

    QString strStreamName="ChannelInfoStream";
    QString strTableName=strChannelNo+"_info";
    //判断成员变量m_mapStreamAndStreamItem["BaseInfoStream"]的values中是否包含strbaseInfoName
    if(m_mapStreamAndStreamItem[strStreamName].contains(strChannelNo))
    {
        bReturn_Value=insertIntoTable(strTableName, mapItemInfo);
    }
    else
    {
        //判断vecValues的类型
        //不包含strbaseInfoName，先创建表，再插入数据
        bReturn_Value=createTable(strTableName, mapFieldAndType)&&insertIntoTable(strTableName, mapItemInfo);
        //增加到内存和数据库中
        if(bReturn_Value)
        {
            m_mapStreamAndStreamItem[strStreamName].append(strChannelNo);

            QHash<QString, QVariant> mapTmpFieldAndValue;
            QString strKey=strStreamName+"_ItemName";
            mapTmpFieldAndValue[strTableName] = strChannelNo;

            insertIntoTable(strStreamName, mapTmpFieldAndValue);

        }
    }

    return bReturn_Value;
}



bool CLiteSqlPersistent::readDataFromChannelInfo(QString& strChannelNo,  QVector<QVector<QVariant>>&   mapItemInfo)
{
    if(!m_mapTableAndFields.contains(strChannelNo))
    {
        return false;
    }

    QString strColumns="*";
    QVector<QVector<QVariant>> vecResult;
    QString strCondition="";
    bool bReturn_Value=selectFromTable(strChannelNo, strColumns, strCondition, mapItemInfo);
    return bReturn_Value;

}


 //修改通道信息
bool CLiteSqlPersistent::updateChannelInfo(QString& strChannelNo,  QHash<QString,QVariant>&  mapItemInfo, QString& strCondition)
{
    bool bReturn_Value=false;
    if(!m_bDataBaseOpenFlag&&!m_bChannelInfoSteamCreateFlag)
    {
        return false;
    }

    QString strStreaName="ChannelInfoStream";
    if(m_mapStreamAndStreamItem[strStreaName].contains(strChannelNo))
    {
        //将修改信息写入到数据库中
        bReturn_Value=updateTable(strChannelNo, mapItemInfo, strCondition);
        return  bReturn_Value;
    }
    else
    {
        //没有对应地基本信息子项名，将错误信息写入日志
        return false;
    }
}



//写入指定通道数据
bool CLiteSqlPersistent::writeDataToChannel(QString& strChannelNo, QVector<float>& vecChannelData)
{
    //判断数据库打开
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }


    QString strStreamName="ChannelDataStream";
    QString strTableName="Channel_"+strChannelNo+"_Data";


    //判断通道数据流是否创建
    bool b_ResultCreate=false;
    m_bChannelDataStreamCreateFlag=m_mapStreamAndStreamItem.contains(strStreamName);
    if(!m_bChannelDataStreamCreateFlag)
    {
        b_ResultCreate=createChannelDataStream();
        if(!b_ResultCreate)
        {
            return false;
        }
    }

    bool bReturn_Value=false;

    //类型map容器:  <fieldName : type>
    QHash<QString, QString> mapFieldAndType;
    mapFieldAndType["ChannelData"]="REAL";



    if(m_mapStreamAndStreamItem[strStreamName].contains(strTableName))
    {
        bReturn_Value=batchInsertChannelData(strTableName, vecChannelData);
    }
    else
    {
        //创建表
        bReturn_Value=createTable(strTableName, mapFieldAndType)&&batchInsertChannelData(strTableName, vecChannelData);
        if(bReturn_Value)
        {
            //增加到内存和数据库中
            m_mapStreamAndStreamItem[strStreamName].append(strTableName);
        }

        QHash<QString, QVariant> mapFieldAndValue;
        QString strKey=strStreamName+"_ItemName";
        mapFieldAndValue[strKey] = strTableName;

        bReturn_Value=insertIntoTable(strStreamName, mapFieldAndValue);

    }

    return bReturn_Value;

}





//获取指定通道数据
//void CLiteSqlPersistent::getDataFromChannel(short shChannelNo, unsigned long shStart, unsigned long shDuration, QVector<float>& vecChannelData);


 //写入通道数据每一段记录信息开始事件、数据位置到表中
bool CLiteSqlPersistent::writeDataToChannelDataBySegmentation(short shChannelNo,  unsigned long uPos, unsigned long uTime)
{
    QString strTableName="Channel_Data_Record_By_Segmentation";
    bool b_Return_Res=false;
    if(!m_mapTableAndFields.contains(strTableName))
    {
        QHash<QString,QString> mapFieldsAndTypes;
        mapFieldsAndTypes["Cha_No"]="INTEGER";
        mapFieldsAndTypes["Event_Pos"]="INTEGER";
        mapFieldsAndTypes["Time"]="INTEGER";
        createTable(strTableName, mapFieldsAndTypes);
    }


    QHash<QString,QVariant> mapFieldAndValue;
    mapFieldAndValue["Cha_No"]=shChannelNo;
    mapFieldAndValue["Event_Pos"]=QVariant::fromValue(static_cast<qlonglong>(uPos));
    mapFieldAndValue["Time"]=QVariant::fromValue(static_cast<qlonglong>(uTime));
    b_Return_Res=insertIntoTable(strTableName, mapFieldAndValue);

    return b_Return_Res;

}

 //获取指定通道的分段信息
void CLiteSqlPersistent::getDataFromChannelDataBySegmentation(short shCha_No, QVector<QVector<QVariant>>& vecRes)
{
    QString strTable="Channel_Data_Record_By_Segmentation";
    QString strColumns="dataPos, startTime";
    QString strCondition="Cha_No="+shCha_No;
    selectFromTable(strTable, strColumns, strCondition, vecRes);
}



void CLiteSqlPersistent::getChannelDataByLength(short shChaNo, short shStartPos, short shNums, QVector<QVector<float>>& vecFloatRes)
{
    QString strTable="Channel_"+QString::number(shChaNo)+"_Data";
    QString strColumns="*";
    QString strEndPos=QString::number(shStartPos+shNums);
    QString strCondition="rowid<="+strEndPos+"AND rowid>="+shStartPos;

    QVector<QVector<QVariant>> vecVariantRes;
    selectFromTable(strTable, strColumns, strCondition, vecVariantRes);
    vecQVariantTransformTovecFloat(vecVariantRes, vecFloatRes);
}




//创建文件
bool CLiteSqlPersistent::createFile(QString& fileName)
{
    //存在两种情况：1、文件若不存在，就创建，则createDataBase(fileName)返回true，m_bFileCreateFlag为true
    //           2、文件若存在，就不创建，createDataBase(fileName)返回false, m_bFileCreateFlag为true

    bool bResult_Value=createDataBase(fileName)&&m_bFileCreateFlag;
    if(bResult_Value)
    {
        qDebug()<<"Database  created successfully.";
    }
    else{
        qDebug()<<"Database  created failed.";
    }
    return m_bFileCreateFlag;
}



//打开文件
bool CLiteSqlPersistent::openFile(QString& fileName)
{
    bool bResult_Value=openDataBase(fileName);
    return bResult_Value;
}



//保存文件到指定路径
bool CLiteSqlPersistent::saveFile(QString& strDestinationPath)
{
    //关闭数据库
    if(m_bDataBaseOpenFlag)
    {
        sqlite3_close(m_ptrSqlite3Db);
        m_ptrSqlite3Db=nullptr;
    }

    //拷贝数据库文件
    QString strsourcePath=QCoreApplication::applicationDirPath();
    QFile sourceFile(strsourcePath);

    if(sourceFile.exists())
    {
        if(QFile::copy(strsourcePath, strDestinationPath))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else{
        return false;
    }
}


//删除文件
bool CLiteSqlPersistent::deleteFile(QString& fileName)
{
    bool bReturn_Value=dropDataBase(fileName);
    return bReturn_Value;
}


//数据库DDL操作
//检查数据库连接是否打开
bool  CLiteSqlPersistent::isDatabaseOpenFlag()
{
    return m_bDataBaseOpenFlag;
}



 //创建数据库文件
bool    CLiteSqlPersistent::createDataBase(QString& strDataBaseName)
{
    //构造数据库文件路径
    QString filePath=strDataBaseName+".db";

    //创建一个QFile对象
    QFile file(filePath);
    if(file.exists())
    {
        qDebug()<<"File already exists. ";
        m_bFileCreateFlag=true;
        return false;
    }
    else
    {
        qDebug()<<"File does not exists. Creating file: "<<filePath;

        //打开文件，如果文件不存在则创建
        if(file.open(QIODevice::ReadWrite))
        {

            qDebug()<<"File created successfully: "<<filePath;
            m_bFileCreateFlag=true;
            return true;
        }
        else
        {
            qDebug()<<"Failed to create file: "<<file.errorString();
            m_bFileCreateFlag=false;
            return false;
        }
    }


}




//打开数据库文件
bool   CLiteSqlPersistent::openDataBase(QString&   strDataBaseName)
{
//    // 构造数据库文件路径
    QString filePath = strDataBaseName + ".db";

//    // 将 QString 转换为 char*，sqlite3_open 接受 char* 类型的文件路径
//    const char* dbName = filePath.toStdString().c_str();

//    // 打开数据库
//    if (sqlite3_open(dbName, &m_ptrSqlite3Db) == SQLITE_OK) {
//        qDebug() << "Database opened successfully.";
//        m_bDataBaseOpenFlag=true;
//        return true;
//    } else {
//        qDebug() << "Failed to open database: " << sqlite3_errmsg(m_ptrSqlite3Db);
//        m_bDataBaseOpenFlag=false;
//        return false;
//    }

    int ret=sqlite3_open(filePath.toStdString().c_str(), &m_ptrSqlite3Db);
    if(ret==SQLITE_OK)
    {
        m_bDataBaseOpenFlag=true;
        return true;
    }
    else
    {
        m_bDataBaseOpenFlag=false;
        return false;
    }

}



//删除数据库
bool    CLiteSqlPersistent::dropDataBase(QString& strDataBaseName)
{
    //关闭数据库连接
    if(m_bDataBaseOpenFlag)
    {
        short shReturn_Value=sqlite3_close(m_ptrSqlite3Db);

        //检查数据库是否关闭
        if(shReturn_Value!=SQLITE_OK)
        {
            //异常信息写入日志
            return false;
        }
        m_ptrSqlite3Db=nullptr;
    }

    //删除数据库文件
    QFile databaseFile(strDataBaseName);
    if(databaseFile.remove())
    {

        return true;
    }
    else{
        //写入日志
        return false;
    }
}



bool CLiteSqlPersistent::createTable(QString& strTableName, QHash<QString, QString>& mapFieldsAndTypes)
{
    // 检查数据库连接是否打开
    if (!m_bDataBaseOpenFlag)
    {
        return false;
    }

    short rc = sqlite3_exec(m_ptrSqlite3Db, "PRAGMA encoding = 'UTF-8';", nullptr, nullptr, nullptr);

    if (rc != SQLITE_OK) {
        // 处理设置字符集失败的情况
        return rc;
    }


    // 定义创建表的语句
    QString strCreateTableSql = "CREATE TABLE IF NOT EXISTS " + strTableName + " (";

    // 拼接创建表的语句
    for (auto it = mapFieldsAndTypes.begin(); it != mapFieldsAndTypes.end(); ++it)
    {
        strCreateTableSql += it.key() + " " + it.value() + ", ";
    }

    // 移除最后一个逗号
    strCreateTableSql.chop(2);
    strCreateTableSql += ");";
    qDebug()<<strCreateTableSql;
    // 执行创建表的语句
    int result = sqlite3_exec(m_ptrSqlite3Db, strCreateTableSql.toUtf8().constData(), nullptr, nullptr, nullptr);

    // 检查创建表的语句是否成功执行
    if (result != SQLITE_OK)
    {
        qDebug() << "创建表失败: " << sqlite3_errmsg(m_ptrSqlite3Db);
        return false;
    }

    qDebug() <<strTableName<<" create successful";

    //更新内存变量m_mapTableAndFields
    for(auto item:mapFieldsAndTypes.keys())
    {
        m_mapTableAndFields[strTableName].append(item);
    }
    return true;
}




 //表增加列
bool    CLiteSqlPersistent::alterTableAddColumn(QString& strTableName, QString& strColumnName, QString& strColumnType)
{
    // 检查数据库连接是否打开
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }

    // 构建插入语句
    QString alterTableSql = "ALTER TABLE " + strTableName +
                            " ADD COLUMN " + strColumnName + " " + strColumnType + ";";

    // 执行插入语句
    int rc = sqlite3_exec(m_ptrSqlite3Db, alterTableSql.toUtf8().constData(), nullptr, nullptr, nullptr);

    // 返回值处理
    if (rc != SQLITE_OK) {
        //写入日志： "Failed to alter table and add column: " << sqlite3_errmsg(m_ptrSqlite3Db)
        return false;
    }
    return true;
}




 //删除表
bool    CLiteSqlPersistent::dropTable(QString& strTableName)
{
    //检查数据库连接是否打开
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }
    //定义删除表语句
    QString strDropTableSql="DROP TABLE IF EXISTS "+strTableName +";";

    //执行删除表语句
    short shReturn_Value=sqlite3_exec(m_ptrSqlite3Db, strDropTableSql.toUtf8().constData(), nullptr, nullptr, nullptr);

    //检查删除表语句是否执行成功
    if(shReturn_Value!=SQLITE_OK)
    {
        //写入日志：“Failed to drop table： sqlite3_errmsg(m_ptrSqlite3Db)”
        return false;
    }
    return true;
}






//数据库DML操作
//将动态（不定的）数据结构的数据插入到数据库对应表中
bool CLiteSqlPersistent::insertIntoTable(QString& strTableName, QHash<QString, QVariant>& mapFieldAndValue)
{
    // 判断数据库是否打开
    if (!m_bDataBaseOpenFlag)
    {
        return false;
    }

    // 获取表strTableName的所有字段
    QVector<QString> vecFieldsofTableName = m_mapTableAndFields[strTableName];
    std::sort(vecFieldsofTableName.begin(), vecFieldsofTableName.end());

    // 获取待插入数据mapFieldAndValue的所有字段
    QVector<QString> vecFieldsofFieldAndValue = QVector<QString>::fromList(mapFieldAndValue.keys());
    std::sort(vecFieldsofFieldAndValue.begin(), vecFieldsofFieldAndValue.end());

    // 求容器vecFieldsofTableName与vecFieldsofFieldAndValue之间的差集vectorDifferenceField，目的是获取待插入数据中未在已知表字段列的字段
    QVector<QString> vectorDifferenceField;
    std::set_difference(vecFieldsofFieldAndValue.begin(), vecFieldsofFieldAndValue.end(),
                        vecFieldsofTableName.begin(), vecFieldsofTableName.end(),
                        std::back_inserter(vectorDifferenceField));

    // 差集vectorDifferenceField中的字段进行新增到表strTableName中
    if (!vectorDifferenceField.isEmpty())
    {
        for (auto& strField : vectorDifferenceField)
        {
            QString strType = getDBTypeFromQVariantValue(mapFieldAndValue[strField]);
            alterTableAddColumn(strTableName, strField, strType);
        }
    }

    // 开始事务
    sqlite3_exec(m_ptrSqlite3Db, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);

    // 执行插入操作
    QString strInsertSql = "INSERT INTO " + strTableName + " (";
    QString strValues;

    for (const auto& column : mapFieldAndValue.keys())
    {
        strInsertSql += column + ",";
        strValues += "?,";
    }


    // 移除末尾的逗号
    strInsertSql.chop(1);
    strValues.chop(1);

    strInsertSql += ") VALUES (" + strValues + ");";

    // 预处理 SQL 语句
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(m_ptrSqlite3Db, strInsertSql.toUtf8().constData(), -1, &stmt, nullptr);

    int paramIndex = 1;
    for (const auto& value : mapFieldAndValue.values())
    {
        // 绑定参数
        bindParameter(stmt, paramIndex++, value);
    }

    // 执行 SQL 语句
    int rc = sqlite3_step(stmt);

    // 结束事务
    sqlite3_exec(m_ptrSqlite3Db, "COMMIT;", nullptr, nullptr, nullptr);

    if (rc != SQLITE_DONE)
    {
        // 写入日志
        qDebug() << "Failed to insert data into table: " << sqlite3_errmsg(m_ptrSqlite3Db);
        sqlite3_finalize(stmt);
        return false;
    }

    // 写入日志
    qDebug() << strTableName << " Data inserted successfully!";

    sqlite3_finalize(stmt);
    return true;
}


void CLiteSqlPersistent::bindParameter(sqlite3_stmt* stmt, int index, const QVariant& value)
{
    if (value.type() == QVariant::Int)
    {
        sqlite3_bind_int(stmt, index, value.toInt());
    }
    else if (value.type() == QVariant::String)
    {
        const QString strValue = value.toString();
        sqlite3_bind_text16(stmt, index, reinterpret_cast<const void*>(strValue.utf16()), -1, SQLITE_STATIC);
    }
    else if(value.type()==QVariant::Double||value.userType()==QMetaType::Float)
    {
        sqlite3_bind_double(stmt, index, value.toFloat());
    }
    else if(value.type() ==QVariant::ByteArray)
    {

    }
    else if(value.type()==QVariant::ULongLong||value.type()==QVariant::LongLong)
    {
        sqlite3_bind_int64(stmt, index, value.toLongLong());
    }


    // 扩展其他数据类型的绑定...
}


// 将 QByteArray 转换为 UTF-16 编码的 wchar_t 数组
//wchar_t* CLiteSqlPersistent::convertQByteArrayToWChar(const QByteArray& byteArray)
//{
//    const char* utf8Data = byteArray.constData();
//    // 使用 UTF-8 编码的字符串创建 QString
//    QString utf8String = QString::fromUtf8(utf8Data);
//    // 使用 QString 转换为 UTF-16 编码的字符串
//    QString utf16String = utf8String.toUtf16();
//    // 获取 UTF-16 编码的字符串的 constData()
//    return const_cast<wchar_t*>(utf16String.constData());
//}




//修改表数据
bool CLiteSqlPersistent::updateTable(QString &strTableName, QHash<QString, QVariant> &mapFieldAndValue, QString& strCondition)
{
    // 打开或创建 SQLite 数据库
    if(!m_bDataBaseOpenFlag)
    {
        qDebug()<<"DataBase is not open.";
        return false;
    }

    // 构建 UPDATE 语句
    QString updateQuery = "UPDATE " + strTableName + " SET ";
    QStringList setClauses;
    for (auto it = mapFieldAndValue.constBegin(); it != mapFieldAndValue.constEnd(); ++it) {
        setClauses.append(QString("%1 = ?").arg(it.key()));
    }
    updateQuery += setClauses.join(", ");

    // 添加 WHERE 子句
    if (!strCondition.isEmpty()) {
        updateQuery += " WHERE " + strCondition;
    }

    // 准备 SQL 语句
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(m_ptrSqlite3Db, updateQuery.toUtf8().constData(), -1, &stmt, NULL) != SQLITE_OK) {
        qDebug() << "Failed to prepare statement: " << sqlite3_errmsg(m_ptrSqlite3Db);
        return false;
    }

    // 绑定值到参数
    int paramIndex = 1;
    for (auto it = mapFieldAndValue.constBegin(); it != mapFieldAndValue.constEnd(); ++it) {
        if (it.value().type() == QVariant::String)
        {
            // 如果是字符串类型，使用 sqlite3_bind_text
            sqlite3_bind_text(stmt, paramIndex++, it.value().toString().toUtf8().constData(), -1, SQLITE_STATIC);
        }
        else if (it.value().type() == QVariant::Int)
        {
            // 如果是整数类型，使用 sqlite3_bind_int
            sqlite3_bind_int(stmt, paramIndex++, it.value().toInt());
        }
        else if(it.value().type() == QVariant::Double)
        {
            sqlite3_bind_double(stmt, paramIndex++, it.value().toFloat());
        }
        else if(it.value().type() == QVariant::ByteArray)
        {
            const QByteArray byteArray = it.value().toByteArray();
            sqlite3_bind_blob(stmt, paramIndex++, byteArray.constData(), byteArray.size(), SQLITE_STATIC);
        }

    }
    // 执行 SQL 语句
    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        qDebug() << "Execution failed: " << sqlite3_errmsg(m_ptrSqlite3Db);
        sqlite3_finalize(stmt);
        return false;
    }

    // 释放资源
    sqlite3_finalize(stmt);
    return true;
}





//删除数据库对应表中的数据
bool    CLiteSqlPersistent::deleteFromTable(QString& strTableName, const QString& strCondition)
{
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }

    // 开始事务
    short shReturn_Value = sqlite3_exec(m_ptrSqlite3Db, "BEGIN TRANSACTION", 0, 0, 0);
    if (shReturn_Value != SQLITE_OK) {
        //事务开启失败信息写入日志
        qDebug() << "Failed to begin transaction: " << sqlite3_errmsg(m_ptrSqlite3Db);
        return false;
    }

    QString strDeleteSql = "DELETE FROM " + strTableName;

    if (!strCondition.isEmpty()) {
        strDeleteSql += " WHERE " + strCondition;
    }

    //执行删除语句
    shReturn_Value = sqlite3_exec(m_ptrSqlite3Db, strDeleteSql.toUtf8().constData(), 0, 0, 0);

    if (shReturn_Value != SQLITE_OK) {
        //失败信息写入日志
        qDebug()<< "Delete failed: " << sqlite3_errmsg(m_ptrSqlite3Db);
        sqlite3_exec(m_ptrSqlite3Db, "ROLLBACK", 0, 0, 0); // 回滚事务
        return false;
    }


    // 提交事务
    shReturn_Value = sqlite3_exec(m_ptrSqlite3Db, "COMMIT", 0, 0, 0);
    if (shReturn_Value != SQLITE_OK) {
        //提交失败信息写入日志
        qDebug() << "Failed to commit transaction: " << sqlite3_errmsg(m_ptrSqlite3Db);
        return false;
    }

    return true;
}





//数据库DQL操作
//从数据库对应表中检索数据
bool    CLiteSqlPersistent::selectFromTable(QString& strTableName,QString& strColumns, QString& strCondition, QVector<QVector<QVariant>>& vecResult)
{
    //判断数据库是否打开
    if(!m_bDataBaseOpenFlag)
    {
        //写入打开数据库失败信息到日志
        return false;
    }

    //构建查询sql语句
    QString strSelectSql="SELECT " + strColumns + " FROM " + strTableName;

    if(!strCondition.isEmpty())
    {
        strSelectSql+=" WHERE "+strCondition;
    }

    //绑定sql语句
    sqlite3_stmt*   stmt;
    short shReturn_Value=sqlite3_prepare(m_ptrSqlite3Db,strSelectSql.toUtf8().constData(),-1,&stmt,nullptr);

    if(shReturn_Value!=SQLITE_OK)
    {
        qDebug()<<shReturn_Value;
        //写入绑定失败的错误信息到日志中
        qDebug() << "Failed to prepare query: " << sqlite3_errmsg(m_ptrSqlite3Db);
        return false;

    }

    //执行查询
    vecResult.clear();

    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        int columns=sqlite3_column_count(stmt);
        QVector<QVariant> vecRow;

        //对所有列进行获取值
        for(int i=0;i<columns;++i)
        {
            const char* value=reinterpret_cast<const char*>(sqlite3_column_text(stmt,i));
            vecRow.push_back(value?QString(value):"");
        }

        //每一行添加记录
        vecResult.push_back(vecRow);
    }

    //释放预编译指针
    sqlite3_finalize(stmt);
    return true;
}


bool    CLiteSqlPersistent::batchInsertChannelData(QString& strChannelName, QVector<float>& vecChannelData)
{
    sqlite3_exec(m_ptrSqlite3Db, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);


    // 准备插入语句
    QString insertSql = "INSERT INTO "+strChannelName+ " VALUES (?);";
    char* errorMsg = nullptr;


    // 编译 SQL 语句
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(m_ptrSqlite3Db, insertSql.toUtf8().constData(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        qDebug() << "Failed to prepare insert statement: " << sqlite3_errmsg(m_ptrSqlite3Db);
        return false;
    }

    //绑定参数
    // 执行批量插入
    for (auto ChannelData : vecChannelData)
    {
        // 绑定具体的值
        sqlite3_bind_double(stmt, 1, static_cast<double>(ChannelData));

        // 执行插入
        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            qDebug() << "Failed to insert data: " << sqlite3_errmsg(m_ptrSqlite3Db);
            // 回滚事务
            sqlite3_exec(m_ptrSqlite3Db, "ROLLBACK;", nullptr, nullptr, nullptr);
            sqlite3_finalize(stmt);
            return false;
        }

        // 重置语句以供下一次使用
        sqlite3_reset(stmt);
        sqlite3_clear_bindings(stmt);
    }

    // 结束事务
    if (sqlite3_exec(m_ptrSqlite3Db, "COMMIT;", nullptr, nullptr, &errorMsg) != SQLITE_OK)
    {
        qDebug() << "Failed to commit transaction: " << errorMsg;
        return false;
        sqlite3_free(errorMsg);
    }

    // 释放语句资源
    sqlite3_finalize(stmt);
    return true;

}




//数据库备份、还原操作，表的备份、还原操作
//数据库备份
bool CLiteSqlPersistent::backupDataBase(QString& sourcePath, QString& destinationPath)
{
    sqlite3 *sourceDB;              //源数据库指针
    sqlite3 *destinationDB;         //目的数据库指针

    // 打开源数据库
    if (sqlite3_open(sourcePath.toStdString().c_str(), &sourceDB) != SQLITE_OK) {
        qDebug() << "Cannot open source database: " << sqlite3_errmsg(sourceDB);
        return false;
    }

    // 打开目标数据库
    if (sqlite3_open(destinationPath.toStdString().c_str(), &destinationDB) != SQLITE_OK) {
        qDebug() << "Cannot open destination database: " << sqlite3_errmsg(destinationDB);
        sqlite3_close(sourceDB);
        return false;
    }

    // 初始化备份操作
    sqlite3_backup *backup = sqlite3_backup_init(destinationDB, "main", sourceDB, "main");

    if (backup == nullptr) {
        qDebug() << "Backup initialization failed: " << sqlite3_errmsg(destinationDB);
        sqlite3_close(sourceDB);
        sqlite3_close(destinationDB);
        return false;
    }

    // 执行备份
    int rc = sqlite3_backup_step(backup, -1);

    if (rc == SQLITE_DONE) {
        qDebug() << "Database backup completed.";
    } else if (rc == SQLITE_OK) {
        qDebug() << "Database backup in progress.";
    } else {
        qDebug() << "Database backup failed: " << sqlite3_errmsg(destinationDB);
    }

    // 完成备份操作
    sqlite3_backup_finish(backup);

    // 关闭数据库连接
    sqlite3_close(sourceDB);
    sqlite3_close(destinationDB);

    return rc == SQLITE_DONE;
}




//回退到最近日期版本的数据库文件，误删操作、误修改操作
bool CLiteSqlPersistent::restoreRecentVersionDataBase()
{
    return true;
}




//还原表数据
bool CLiteSqlPersistent::restoreTable(QString& strTableName, QString& strBackupTableName)
{


    return true;
}



//初始化文件：1、创建文件；2、打开文件；
void CLiteSqlPersistent::initialize(QString& fileName)
{
    //创建文件和打开文件成功后，才能读取数据库中所有表名、字段名信息
    //如果文件不存在，就创建，并返回true，文件存在，就不创建，返回false.
    m_bDataBaseOpenFlag=false;
    m_bFileCreateFlag=false;
    m_bBasicInfoStreamCreateFlag=false;
    m_bConfigStreamCreateFlag=false;
    m_bEventStreamCreateFlag=false;
    m_bChannelInfoSteamCreateFlag=false;
    m_bChannelDataStreamCreateFlag=false;
    m_bStreamDataCreateFlag=false;

    if(openFile(fileName))
    {
        //读取数据库中的信息，将信息赋值到成员变量m_mapTableAndFields中
        getAllTableAndFields();
        getAllStreamItems();
        qDebug()<<"initialize Successful";
    }
    else{
        qDebug()<<"initialize Failed";
    }
}




//获取打开数据库中所有表及字段的信息
void CLiteSqlPersistent::getAllTableAndFields()
{
    //判断数据库是否打开
    if(!m_bDataBaseOpenFlag)
    {
        qDebug()<<"DataBase is opened. ";
    }

    QVector<QVector<QVariant>> vecTableNamesResult;
    QString strTableName="sqlite_master";
    QString strColumns="name";
    QString strCondition="type='table'";

    //首先在数据库中查询有多少张表
    selectFromTable(strTableName, strColumns,strCondition, vecTableNamesResult);


    //表的数量
    short shTableCount=vecTableNamesResult.size();

    //如果是新创建的数据库文件，那么shTableCount就为0，就不执行下面的逻辑

    //再根据查询所有表名结果信息，根据对应表名查询该表的所有字段名


    for(auto ItemTable:vecTableNamesResult)
        {

        QString tableName=ItemTable[0].toString();
        QVector<QString> vecFields=getTableFields(tableName);

        //将每个表的表名和所有字段添加到变量m_mapTableAndFields中，内存中存有一份表名和所有字段名的map，便于在快速用于添加数据、修改数据时作逻辑判断
        for(auto FieldItem:vecFields)
        {
            m_mapTableAndFields[tableName].append(FieldItem);
        }

        strTableName="";

        }
}


void CLiteSqlPersistent::getAllStreamItems()
{
        QVector<QString> vecStreamNames={"BaseInfoStream", "ConfigStream", "EventStream", "ChannelDataStream", "ChannelInfoStream"};
        for(auto StreamName:vecStreamNames)
        {
            if(m_mapTableAndFields.contains(StreamName))
            {
                getStreamItems(StreamName);
            }
        }
}



bool CLiteSqlPersistent::isExistBaseInfoStream()
{
        QString strStreamName="BaseInfoStream";
        bool bReturn_Value=m_mapStreamAndStreamItem.contains(strStreamName);
        if(bReturn_Value)
        {
            m_bBasicInfoStreamCreateFlag=true;
        }
        return bReturn_Value;
}

bool CLiteSqlPersistent::isExistConfigStream()
{
        QString strStreamName="ConfigStream";
        bool bReturn_Value=m_mapStreamAndStreamItem.contains(strStreamName);
        if(bReturn_Value)
        {
            m_bConfigStreamCreateFlag=true;
        }
        return bReturn_Value;
}


bool CLiteSqlPersistent::isExistEventStream()
{
        QString strStreamName="EventStream";
        bool bReturn_Value=m_mapStreamAndStreamItem.contains(strStreamName);
        if(bReturn_Value)
        {
            m_bEventStreamCreateFlag=true;
        }
        return bReturn_Value;

}

bool CLiteSqlPersistent::isExistChannelDataStream()
{
        QString strStreamName="ChannelDataStream";
        bool bReturn_Value=m_mapStreamAndStreamItem.contains(strStreamName);
        if(bReturn_Value)
        {
            m_bChannelInfoSteamCreateFlag=true;
        }
        return bReturn_Value;

}


bool CLiteSqlPersistent::isExistChannelInfoStream()
{
        QString strStreamName="ChannelInfoStream";
        bool bReturn_Value=m_mapStreamAndStreamItem.contains(strStreamName);
        if(bReturn_Value)
        {
            m_bStreamDataCreateFlag=true;
        }
        return bReturn_Value;
}


//获取表名字段容器
QVector<QString> CLiteSqlPersistent::getTableFields(QString& strTableName)
{
    // 构造查询语句
    QString strQuerySql = "PRAGMA table_info(";
    strQuerySql += strTableName;
    strQuerySql += ");";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(m_ptrSqlite3Db, strQuerySql.toUtf8().constData(), -1, &stmt, nullptr);

    QVector<QString> vecFields;
    if (rc == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {

                const char* columnName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                vecFields.append(QString(columnName));
            }

            sqlite3_finalize(stmt); // Finalize the statement
        } else {
            qDebug() << "Failed to prepare query: " << sqlite3_errmsg(m_ptrSqlite3Db);
        }

    return vecFields;
}



//获取指定流的子项
void CLiteSqlPersistent::getStreamItems(QString& strStreamName)
{
    QVector<QVector<QVariant>> vecResult_Query;
    if(!m_mapTableAndFields[strStreamName].isEmpty())
    {
            QString strColumnName=m_mapTableAndFields[strStreamName][0];
            QString strCondition="";
            selectFromTable(strStreamName, strColumnName, strCondition, vecResult_Query);

            for(auto item:vecResult_Query)
            {
                m_mapStreamAndStreamItem[strStreamName].append(item[0].toString());
            }
    }

}



//是否存在流的子项
 bool CLiteSqlPersistent::isExistsStreamItem(QString& strItemName)
{
    if(m_mapTableAndFields.contains(strItemName))
    {
            return true;
    }
    else{
            return false;
    }

 }

 void    CLiteSqlPersistent::vecQVariantTransformTovecFloat(QVector<QVector<QVariant>>& vecVariantData, QVector<QVector<float>>& vecFloatData)
 {
    // 遍历原始向量
    for (const QVector<QVariant>& innerVariantVector : vecVariantData) {
            QVector<float> innerFloatVector;

            // 将 QVariant 转换为 float
            for (const QVariant& variantValue : innerVariantVector) {
                innerFloatVector.push_back(variantValue.toFloat());
            }

            // 将转换后的向量添加到结果向量中
            vecFloatData.push_back(innerFloatVector);
    }
 }







