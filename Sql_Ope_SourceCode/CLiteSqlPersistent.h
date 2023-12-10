#ifndef CLITESQLPERSISTENT_H
#define CLITESQLPERSISTENT_H

#include "IFile.h"
#include "IPersistent.h"
#include"sqlite3.h"
#include<QString>
#include<QVector>
#include<QFile>
#include<QCoreApplication>
#include<QDebug>

//数据库持久化类，应该包括数据库常用四大操作和具体业务需求操作，但是考虑到信号采集场景中常用的操作，没有声明数据库中的DCL列操作函数接口以及复杂的DQL函数接口
class CLiteSqlPersistent : public IFile,public IPersistent
{
public:


    CLiteSqlPersistent(QString& fileName);
    ~CLiteSqlPersistent();



protected:

    bool createStream(QString& strStreamName);              //创建流
    bool createBaseInfoStream();                            //创建基本信息流
    bool createConfigStream();                              //创建配置信息流
    bool createEventStream();                               //创建事件流
    bool createChannelDataStream();                         //创建通道数据流
    bool createChannelInfoStream();                         //创建通道信息流

    bool createFile(QString& strFileName);                                                             //创建文件
    bool openFile(QString& strFileName);                                                               //打开文件
    bool saveFile(QString& strFileName);                                                               //保存文件
    bool deleteFile(QString& strFileName);                                                             //删除文件



public:

    bool writeDataToBaseInfo(QString& strBaseInfoItemName,  QMap<QString,QString>   mapItemInfo);                     //写入基本信息
    bool updateBaseInfo(QString& strBaseInfoItemName, QMap<QString,QString>   mapItemInfo);                    //修改基本信息
    bool writeDataToConfig(QString& strConfigInfoItemName,  QMap<QString,QString>   mapItemInfo);                       //写入配置信息
    bool updateConfigInfo(QString& strConfigInfoItemName, QMap<QString,QString>   mapItemInfo);                      //修改配置信息
    bool writeDataToEvent(QString& strEventInfoItemName,    QMap<QString,QString>   mapItemInfo);                        //写入事件信息
    bool updateEventInfo(QString& strEventInfoItemName,   QMap<QString,QString>   mapItemInfo);                       //修改事件信息
    bool removeEvent(QString& strEventInfoItemName,   QMap<QString,QString>   mapItemInfo);                       //移除事件信息
    bool writeDataToChannelInfo(short shChannelNo,     QMap<QString,QString>   mapItemInfo);                  //写入通道信息
    bool updateChannelInfo(short shChannelNo,    QMap<QString,QString>   mapItemInfo);                 //修改通道信息





private:

    //数据库DDL操作
    bool    createDataBase(QString& strDataBaseName);       //创建数据库
    bool    openDataBase(QString&   strDataBaseName);       //打开数据库文件
    bool    dropDataBase(QString& strDataBaseName);         //删除数据库
    bool    isDatabaseOpenFlag();                              //检查数据库连接是否打开
    bool    createTable(QString& strTableName,  QMap<QString,QString> mapFieldsAndTypes);   //创建表操作
    bool    alterTableAddColumn(QString& strTableName, QString& strColumnName, QString& strColumnType);   //表增加列
    bool    dropTable(QString& strTableName);       //删除表


    //数据库DML操作
    bool    insertIntoTable(QString& strTableName, QVector<QString>& vecColumns, QVector<QString>& vecValues);                    //将新数据插入到数据库对应表中
    bool    updateTable(QString& strTableName, QVector<QString>& vecColumns, QVector<QString>& vecValues, QString& strCondition);   //更新表数据，并更新内存变量
    bool    deleteFromTable(QString& strTableName, const QString& strCondition);                                                                 //删除数据库对应表中的数据


    //数据库DQL操作
    void    selectFromTable(QString& strTableName,QString& strColumns, QString& strCondition, QVector<QVector<QString>>& vecResult);    //从数据库对应表中检索数据



    //数据库备份、还原操作，表还原操作
    bool backupDataBase(QString& sourcePath, QString& destinationPath);                                        //数据库备份
    bool restoreRecentVersionDataBase();                                                                                   //回退到最近版本的数据库
    bool restoreTable(QString& strTableName, QString& strBackupTableName);                                           //还原表数据

    //初始化文件：1、创建文件；2、打开文件；
    bool initialize(QString& fileName);

    //获取打开数据库中所有结构表的信息，赋值给m_mapAllTableInfo
    bool getAllTableAndFields();


private:

    bool               m_bDataBaseOpenFlag;                   //数据库打开标志
    bool               m_bBasicInfoStreamCreateFlag;            //基本信息流创建标志
    bool               m_bConfigStreamCreateFlag;               //配置流创建标志
    bool               m_bEventStreamCreateFlag;                //事件流创建标志
    bool               m_bChannelInfoSteamCreateFlag;           //通道信息创建标志
    bool               m_bChannelStreamCreateFlag;              //通道流创建标志
    bool               m_bStreamDataCreateFlag;               //数据流文件创建标志，true：流打开


    QString            m_strDataBaseName;                     //数据库文件名
    sqlite3*           m_ptrSqlite3Db;                        //数据库指针
    QVector<QString>   m_vecDataBaseVersionInfo;              //数据库版本信息集合    格式：时间戳+版本id+数据库文件路径
    QString            m_strDataBaseCurrentVersionInfo;       //当前数据库版本信息    格式：时间戳+版本id+数据库文件路径
    QVector<QString>   m_vecBackupRecords;                     //数据库备份记录
    QVector<QString>   m_vecTableBackupRecordsInfo;           //表的备份记录信息        格式：
    QMap<QString, QVector<QString>>    m_mapTableAndFields;            //所有表的结构，具体为：表名 vec(字段名)


    short              m_shLogic_Cha_Num;                      // 逻辑采样通道数

    QMap<QString,QVector<QString>>  m_mapStreamAndStreamItem;    //流名和流对应地子项
 };

#endif // CLITESQLPERSISTENT_H
