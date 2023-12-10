#include"CLiteSqlPersistent.h"
#include<QFile>

CLiteSqlPersistent::CLiteSqlPersistent(QString& fileName):m_strDataBaseName(fileName)
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
        }
        m_bDataBaseOpenFlag=false;
    }
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
bool CLiteSqlPersistent::writeDataToBaseInfo(QString& strBaseInfoItemName,  QMap<QString,QString>   mapItemInfo)
{
    if(!m_bDataBaseOpenFlag||!m_bBasicInfoStreamCreateFlag)
    {
        return false;
    }

    bool bReturn_Value=false;


    //判断成员变量m_mapStreamAndStreamItem["BaseInfoStream"]的values中是否包含strbaseInfoName
    if(m_mapStreamAndStreamItem["BaseInfoStream"].contains(strBaseInfoItemName))
    {
        //有表，就直接插入数据
        QVector<QString> vecKeys = QVector<QString>::fromList(mapItemInfo.keys());


        QVector<QString> vecValues = QVector<QString>::fromList(mapItemInfo.values());
        insertIntoTable(strBaseInfoItemName, vecKeys, vecValues);
    }

    else
    {
        //不包含strbaseInfoName，先创建表，再插入数据
    }

    return bReturn_Value;
}




//修改基本信息
bool CLiteSqlPersistent::updateBaseInfo(QString& strBaseInfoItemName, QMap<QString,QString>   mapItemInfo)
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
bool CLiteSqlPersistent::writeDataToConfig(QString& configInfoItemName,  QMap<QString,QString>   ItemInfo)
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
bool CLiteSqlPersistent::updateConfigInfo(QString& configInfoItemName, QMap<QString,QString>   ItemInfo)
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
bool CLiteSqlPersistent::writeDataToEvent(QString& eventInfoItemName,    QMap<QString,QString>   ItemInfo)
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
bool CLiteSqlPersistent::updateEventInfo(QString& eventInfoItemName,   QMap<QString,QString>   ItemInfo)
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
bool CLiteSqlPersistent::removeEvent(QString& eventInfoItemName,   QMap<QString,QString>   ItemInfo)
{
    return false;
}




//写入通道信息
bool CLiteSqlPersistent::writeDataToChannelInfo(short channelNo,     QMap<QString,QString>   ItemInfo)
{
    return false;
}


 //修改通道信息
bool CLiteSqlPersistent::updateChannelInfo(short channelNo,    QMap<QString,QString>   ItemInfo)
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


    // 打开文件，如果文件不存在则创建
    if (file.open(QIODevice::WriteOnly)) {
        // 关闭文件
        file.close();
        //写入日志 //        qDebug() << "Database file created successfully: " << filePath;
        return true;
    } else {
        //写入日志          //        qDebug() << "Failed to create database file: " << file.errorString();
        return false;
    }
}

//打开数据库文件
bool   CLiteSqlPersistent::openDataBase(QString&   strDataBaseName)
{
    // 构造数据库文件路径
    QString filePath = strDataBaseName + ".db";

    // 将 QString 转换为 char*，sqlite3_open 接受 char* 类型的文件路径
    const char* dbName = filePath.toStdString().c_str();

    sqlite3* db;

    // 打开数据库
    if (sqlite3_open(dbName, &db) == SQLITE_OK) {
        qDebug() << "Database opened successfully.";
        m_bDataBaseOpenFlag=true;
        // 在这里你可以执行其他的数据库操作
        return true;
    } else {
        qDebug() << "Failed to open database: " << sqlite3_errmsg(db);
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
bool    CLiteSqlPersistent::insertIntoTable(QString& strTableName, QVector<QString>& vecColumns, QVector<QString>& vecValues)
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


//修改表数据
bool    CLiteSqlPersistent::updateTable(QString& strTableName, QVector<QString>& vecColumns, QVector<QString>& vecValues, QString& strCondition)
{
    //数据库是否打开
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }


    //开始事务
    short shResult_Value=sqlite3_exec(m_ptrSqlite3Db,"BEGIN TRANSACTION",0,0,0);
    if(shResult_Value!=SQLITE_OK)
    {
        //事务开启失败信息写入日志
        qDebug()<< "Failed to begin transaction: " << sqlite3_errmsg(m_ptrSqlite3Db);
        return false;
    }



    //拼接修改语句
    QString strUpdateQuery="UPDATE "+strTableName+" SET ";
    for(short i=0;i<vecColumns.size();++i)
    {
        strUpdateQuery+=vecColumns[i]+" = ?";
        if(i<vecColumns.size()-1)
        {
            strUpdateQuery+=", ";
        }
    }
    if(!strCondition.isEmpty())
    {
        strUpdateQuery+=" WHERE "+strCondition;
    }

    //预绑定
    sqlite3_stmt* ptrStmt;
    shResult_Value=sqlite3_prepare_v2(m_ptrSqlite3Db,strUpdateQuery.toUtf8().constData(),-1,&ptrStmt,nullptr);
    if(shResult_Value!=SQLITE_OK)
    {
        //错误信息写入日志
        qDebug()<<"Failed to prepare update statement: " << sqlite3_errmsg(m_ptrSqlite3Db);
        sqlite3_exec(m_ptrSqlite3Db,"ROLLBACK",0,0,0);  //回滚事务
        return false;
    }

    //绑定对应占位值
    for(short i=0;i<vecValues.size();++i)
    {
        shResult_Value=sqlite3_bind_text(ptrStmt,i+1,vecValues[i].toUtf8().constData(),-1,SQLITE_STATIC);
        if(shResult_Value!=SQLITE_OK)
        {
            //错误信息写入日志
            qDebug()<<"Failed to bind parameter: " << sqlite3_errmsg(m_ptrSqlite3Db);
            sqlite3_exec(m_ptrSqlite3Db,"ROLLBACK",0,0,0);  //回滚事务
            sqlite3_finalize(ptrStmt);
            return false;
        }
    }

    //执行修改语句
    shResult_Value=sqlite3_step(ptrStmt);


    shResult_Value = sqlite3_exec(m_ptrSqlite3Db, "COMMIT", 0, 0, 0);   // 提交事务
    if(shResult_Value!=SQLITE_DONE)
    {
        //将错误信息写入日志
        qDebug()<< "Update failed: " << sqlite3_errmsg(m_ptrSqlite3Db);
        sqlite3_exec(m_ptrSqlite3Db,"ROLLBACK",0,0,0);  //回滚事务
        sqlite3_finalize(ptrStmt);
        return false;
    }

    sqlite3_finalize(ptrStmt);
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
void    CLiteSqlPersistent::selectFromTable(QString& strTableName,QString& vecColumns, QString& strCondition, QVector<QVector<QString>>& vecResult)
{
    //判断数据库是否打开
    if(!m_bDataBaseOpenFlag)
    {
        //写入打开数据库失败信息到日志
    }

    //构建查询sql语句
    QString strSelectSql="SELECT " + vecColumns + " FROM " + strTableName;

    if(!strCondition.isEmpty())
    {
        strSelectSql+=" WHERE "+strCondition;
    }

    //绑定sql语句
    sqlite3_stmt*   stmt;
    short shReturn_Value=sqlite3_prepare_v2(m_ptrSqlite3Db,strSelectSql.toUtf8().constData(),-1,&stmt,nullptr);

    if(shReturn_Value!=SQLITE_OK)
    {
        //写入绑定失败的错误信息到日志中
        qDebug() << "Failed to prepare query: " << sqlite3_errmsg(m_ptrSqlite3Db);

    }

    //执行查询
    vecResult.clear();

    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        int columns=sqlite3_column_count(stmt);
        QVector<QString> vecRow;

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
bool CLiteSqlPersistent::initialize(QString& fileName)
{
    //创建文件和打开文件成功后，才能读取数据库中所有表名、字段名信息
    if(createFile(fileName)&&openFile(fileName))
    {

        //读取数据库中的信息，将信息赋值到成员变量m_mapTableAndFields中
        bool bReturn_Value=getAllTableAndFields();
        return bReturn_Value;
    }
    else{
        return false;
    }
}



//获取打开数据库中所有结构表的信息
bool CLiteSqlPersistent::getAllTableAndFields()
{
    //判断数据库是否打开
    if(!m_bDataBaseOpenFlag)
    {
        return false;
    }


    QVector<QVector<QString>> vecTableNamesResult;
    QString strTableName="sqlite_master";
    QString strColumns="name";
    QString strCondition="type='table'";

    //首先在数据库中查询有多少张表
    selectFromTable(strTableName, strColumns,strCondition, vecTableNamesResult);
    short shTableCount=vecTableNamesResult.size();

    //如果是新创建的数据库文件，那么shTableCount就为0，就不执行下面的逻辑
    if(shTableCount>0)
    {
        //根据查询所有表名结果信息，根据对应表名查询该表的所有字段名
        strTableName="pragma_table_info";
        strColumns="name";
        strCondition="";


        for(auto ItemTable:vecTableNamesResult)
        {
            QVector<QVector<QString>> vecFields;
            QString tableName=ItemTable[0];
            strTableName=strTableName+"('"+tableName+"')";
            selectFromTable(strTableName, strColumns, strCondition, vecFields);

            //将每个表的表名和所有字段添加到变量m_mapTableAndFields中，内存中存有一份表名和所有字段名的map，便于在快速用于添加数据、修改数据时作逻辑判断
            for(auto vecFieldsItem:vecFields)
            {
                m_mapTableAndFields[tableName].append(vecFieldsItem[0]);
            }

        }
        return true;
    }
    else
    {
        return false;
    }

}






