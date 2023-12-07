#include"CLiteSqlPersistent.h"
#include<QFile>

CLiteSqlPersistent::CLiteSqlPersistent()
{

}


CLiteSqlPersistent::~CLiteSqlPersistent()
{


}


//创建流，strStreamName流名可视为表名，存放对应流信息下的子选项（Item）的ID,子信息对应传入结构体
bool CLiteSqlPersistent::createStream(QString& strStreamName)
{
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }
    QMap<QString,QString> mapFieldsAndTypes;
    QString strKey1=strStreamName+"_ItemId";
    QString strKey2=strStreamName+"_ItemName";
    mapFieldsAndTypes[strKey1]="Integer";
    mapFieldsAndTypes[strKey2]="Text";

    //创建strStreamName表，字段为strStreamName+"_ItemId":"Text"，strStreamName+"_ItemName"："Text"
    bool mReturn_Value=createTable(strStreamName,mapFieldsAndTypes);
    if(mReturn_Value)
    {
        m_mapStreamAndStreamItem[strStreamName].clear();
        return true;
    }
    else
    {
        //写错误信息到日志中
        return false;
    }
}



//创建基本信息流-对应于sqlite数据库中创建一个基本信息流表，包含字段信息：子项id，信息名
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
        m_bChannelStreamCreateFlag=true;

    }
    else
    {
        m_bChannelStreamCreateFlag=false;
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
bool CLiteSqlPersistent::writeDataToBaseInfo(QString& strbaseInfoItemName,  QMap<QString,QVariant>   mapItemInfo)
{
    if(!m_bDataBaseOpenFlag&&!m_bBasicInfoStreamCreateFlag)
    {
        return false;
    }

    bool bReturn_Value=false;
    //判断成员变量m_mapStreamAndStreamItem["BaseInfoStream"]的values中是否包含strbaseInfoName
    if(m_mapStreamAndStreamItem["BaseInfoStream"].contains(strbaseInfoItemName))
    {
        //有表，就直接插入数据

    }
    else
    {
        //不包含strbaseInfoName，先创建表，再插入数据
    }

    return bReturn_Value;
}




//修改基本信息
bool CLiteSqlPersistent::updateBaseInfo(QString& strBaseInfoItemName, QMap<QString,QVariant>   mapItemInfo)
{
    if(!m_bDataBaseOpenFlag&&!m_bBasicInfoStreamCreateFlag)
    {
        return false;
    }

    if(m_mapStreamAndStreamItem["BaseInfoStream"].contains(strBaseInfoItemName))
    {
        //将修改信息写入到数据库中
        return true;
    }
    else
    {
        //没有对应地基本信息子项名，将错误信息写入日志
        return false;
    }
}


//写入配置信息
bool CLiteSqlPersistent::writeDataToConfig(QString& configInfoItemName,  QMap<QString,QVariant>   ItemInfo)
{
    if(!m_bDataBaseOpenFlag&&!m_bConfigStreamCreateFlag)
    {
        return false;
    }

    bool bReturn_Value=false;
    //判断成员变量m_mapStreamAndStreamItem["BaseInfoStream"]的values中是否包含strbaseInfoName
    if(m_mapStreamAndStreamItem["ConfigStream"].contains(configInfoItemName))
    {
        //有表，就直接插入数据
    }
    else
    {
        //不包含configInfoItemName，先创建表，再插入数据
    }

    return bReturn_Value;
}


//修改配置信息
bool CLiteSqlPersistent::updateConfigInfo(QString& configInfoItemName, QMap<QString,QVariant>   ItemInfo)
{
    if(!m_bDataBaseOpenFlag&&!m_bConfigStreamCreateFlag)
    {
        return false;
    }

    if(m_mapStreamAndStreamItem["ConfigStream"].contains(configInfoItemName))
    {
        //将修改信息写入到数据库中
        return true;
    }
    else
    {
        //没有对应地基本信息子项名，将错误信息写入日志
        return false;
    }

}



//写入事件信息
bool CLiteSqlPersistent::writeDataToEvent(QString& eventInfoItemName,    QMap<QString,QVariant>   ItemInfo)
{
    if(!m_bDataBaseOpenFlag&&!m_bEventStreamCreateFlag)
    {
        return false;
    }

    bool bReturn_Value=false;
    //判断成员变量m_mapStreamAndStreamItem["BaseInfoStream"]的values中是否包含strbaseInfoName
    if(m_mapStreamAndStreamItem["EventStream"].contains(eventInfoItemName))
    {
        //有表，就直接插入数据
    }
    else
    {
        //不包含configInfoItemName，先创建表，再插入数据
    }

    return bReturn_Value;

}



//修改事件信息
bool CLiteSqlPersistent::updateEventInfo(QString& eventInfoItemName,   QMap<QString,QVariant>   ItemInfo)
{
    if(!m_bDataBaseOpenFlag&&!m_bEventStreamCreateFlag)
    {
        return false;
    }

    if(m_mapStreamAndStreamItem["EventStream"].contains(eventInfoItemName))
    {
        //将修改信息写入到数据库中
        return true;
    }
    else
    {
        //没有对应地基本信息子项名，将错误信息写入日志
        return false;
    }
}



//移除事件信息
bool CLiteSqlPersistent::removeEvent(QString& eventInfoItemName,   QMap<QString,QVariant>   ItemInfo)
{
    return false;
}




//写入通道信息
bool CLiteSqlPersistent::writeDataToChannelInfo(short channelNo,     QMap<QString,QVariant>   ItemInfo)
{
    return false;
}


 //修改通道信息
bool CLiteSqlPersistent::updateChannelInfo(short channelNo,    QMap<QString,QVariant>   ItemInfo)
{
    return false;
}




//创建文件
bool CLiteSqlPersistent::createFile(QString& fileName)
{
    bool bResult_Value=createDataBase(fileName);
    return bResult_Value;
}

//打开文件
bool CLiteSqlPersistent::openFile(QString& fileName)
{
    return m_bDataBaseOpenFlag;
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



 //创建数据库
bool    CLiteSqlPersistent::createDataBase(QString& strDataBaseName)
{
    if(!m_bDataBaseOpenFlag)
    {
        short shReturn_Value  =   sqlite3_open(strDataBaseName.toUtf8().constData(),  &m_ptrSqlite3Db);
        if(shReturn_Value==SQLITE_OK)
        {
            m_bDataBaseOpenFlag=true;
        }
        else
        {
             //写入日志：“Failed to Open DBFile sqliteerrMsg()”
        }
    }
    return m_bDataBaseOpenFlag;
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



//创建表操作
bool    CLiteSqlPersistent::createTable(QString& strTableName,  QMap<QString,QString> mapFieldsAndTypes)
{
    //检查数据库连接是否打开
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }

    //定义创建表语句
    QString strCreateTableSql="CREATE TABLE IF NOT EXISTS "+ strTableName + " (";

    //拼接创建表语句
    for(auto it=mapFieldsAndTypes.begin(); it!=mapFieldsAndTypes.end(); it++)
    {
        strCreateTableSql+=it.key()+" "+ it.value() + ",";
    }

    //移除sql语句最后一个逗号
    strCreateTableSql.chop(1);
    strCreateTableSql+=");";


    //执行创建表语句
    short shReturn_Value=sqlite3_exec(m_ptrSqlite3Db, strCreateTableSql.toUtf8().constData(), nullptr, nullptr, nullptr);
    //检查创建表语句是否执行成功
    if(shReturn_Value!=SQLITE_OK)
    {
        //写入日志:"Failed to create table: sqlite3_errmsg(m_ptrSqlite3Db)"
        return false;
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
//将新数据插入到数据库对应表中
bool    CLiteSqlPersistent::insertIntoTableSingle(QString& strTableName, QVector<QString>& vecColumns, QVector<QString>& vecValues)
{
    if (!m_bDataBaseOpenFlag)
    {
        return false;
    }

    // 构建 INSERT INTO SQL 查询
    QString strinsertSql = "INSERT INTO " + strTableName + " (";

    // 添加列到查询中
    for (const QString& column : vecColumns)
    {
        strinsertSql += column + ",";
    }

    // 移除末尾的逗号
    strinsertSql.chop(1);

    strinsertSql += ") VALUES (";

    // 添加值到查询中
    for (const QString& value : vecValues)
    {
        strinsertSql += "'" + value + "',"; // 假设值是字符串类型; 根据需要进行修改
    }

    // 移除末尾的逗号
    strinsertSql.chop(1);

    strinsertSql += ");";

    // 执行 SQL 查询
    char* errorMsg = nullptr;
    int rc = sqlite3_exec(m_ptrSqlite3Db, strinsertSql.toUtf8().constData(), nullptr, nullptr, &errorMsg);

    if (rc != SQLITE_OK)
    {
        qDebug() << "Failed to insert data into table: " << errorMsg;
        sqlite3_free(errorMsg);
        return false;
    }

    qDebug() << "Data inserted successfully!";
    return true;
}




//更新表数据
bool    CLiteSqlPersistent::updateTable(QString& strTableName, QVector<QString>& vecColumns, QVector<QString>& vecValues, QString& strCondition)
{

    return true;
}

//删除数据库对应表中的数据
bool    CLiteSqlPersistent::deleteFromTable(QString& strTableName, const QString& strCondition)
{
    return true;
}


//数据库DQL操作
//从数据库对应表中检索数据
void    CLiteSqlPersistent::selectFromTable(QString& strTableName,QString& vecColumns, QString& strCondition, QVector<QVector<QString>>& vecResult)
{

}




//数据库备份、还原操作，表的备份、还原操作
//数据库备份
bool CLiteSqlPersistent::backupDataBase(const QString& sourcePath, QString& destinationPath)
{



    return true;
}

//回退到最近日期版本的数据库
bool CLiteSqlPersistent::restoreRecentVersionDataBase()
{
    return true;
}

//备份表数据
bool CLiteSqlPersistent::backupTable(const QString& strTableName, QString& strBackupTableName)
{
    return true;
}
//还原表数据
bool CLiteSqlPersistent::restoreTable(const QString& strTableName, QString& strBackupTableName)
{
    return true;
}









