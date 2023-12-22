

#include "IFile.h"
#include  "IPersistent.h"
#include  "sqlite3.h"
#include<QString>
#include<QVector>
#include<QHash>
#include<QFile>
#include<QCoreApplication>
#include<QDebug>
#include<QHash>
#include"Constant/BL-42N/Common_Constant_Define.h"

//数据库持久化类，应该包括数据库常用四大操作和具体业务需求操作，但是考虑到信号采集场景中常用的操作，没有声明数据库中的DCL列操作函数接口以及复杂的DQL函数接口
class CLiteSqlPersistent : public IFile,public IPersistent
{
public:


    CLiteSqlPersistent(QString fileName="x20pStorage");
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

    //初始化文件：1、创建文件；2、打开文件；
    void initialize(QString& fileName);

    bool writeDataToBaseInfo(QString& strBaseInfoItemName,  QHash<QString,QVariant>&   mapItemInfo);                        //写入基本信息
    bool readDataFromBaseInfo(QString& strBaseInfoItemName,  QVector<QVector<QVariant>>&   mapItemInfo);                    //读取基本信息
    bool updateBaseInfo(QString& strBaseInfoItemName, QHash<QString,QVariant>&   mapItemInfo, QString& strCondition);       //修改基本信息

    bool writeDataToConfigInfo(QString& strConfigInfoItemName,  QHash<QString,QVariant>&   mapItemInfo);                       //写入配置信息
    bool readDataFromConfigInfo(QString& strConfigInfoItemName,  QVector<QVector<QVariant>>&   mapItemInfo);                    //读取配置信息
    bool updateConfigInfo(QString& strConfigInfoItemName, QHash<QString,QVariant>&   mapItemInfo, QString& strCondition);      //修改配置信息


    bool writeDataToEventInfo(QString& strEventInfoItemName,   QHash<QString,QVariant>&   mapItemInfo);                        //写入事件信息
    bool readDataFromEventInfo(QString& strEventInfoItemName,  QVector<QVector<QVariant>>&   mapItemInfo);                    //读取事件信息
    bool updateEventInfo(QString& strEventInfoItemName,   QHash<QString,QVariant>&   mapItemInfo, QString& strCondition);      //修改事件信息
    bool removeEventInfo(QString& strEventInfoItemName, QString& strCondition);                                                 //移除事件信息


    bool writeDataToChannelInfo(QString& strChannelNo,     QHash<QString,QVariant>&   mapItemInfo);                             //写入通道信息
    bool readDataFromChannelInfo(QString& strChannelNo,  QVector<QVector<QVariant>>&   mapItemInfo);                   //读取通道信息
    bool updateChannelInfo(QString& strChannelNo,    QHash<QString,QVariant>&   mapItemInfo, QString& strCondition);            //修改通道信息


    bool writeDataToChannel(QString& strChannelNo, QVector<float>& vecChannelData);                                                   //写入指定通道数据
    void getDataFromChannel(QString& strChannelNo, unsigned long shStart, unsigned long shDuration, QVector<float>& vecChannelData);  //获取指定通道数据

    bool writeDataToChannelDataBySegmentation(short shChannelNo,  unsigned long uStart, unsigned long uLen);       //写入通道数据每一段记录信息开始位置、数据长度到表中
    void getDataFromChannelDataBySegmentation(short shChannelNo, QVector<QVector<QVariant>>& vecRes);                      //获取指定通道的分段信息

    void getChannelDataByLength(short shChaNo, short shStartPos, short shNums, QVector<QVector<float>>& vecFloatRes);

    bool  isDatabaseOpenFlag();                              //检查数据库连接是否打开

    //获取指定表名字段容器
    QVector<QString> getTableFields(QString& strTableName);

    //获取指定流的子项
    void getStreamItems(QString& strStreamName);

    bool isExistsStreamItem(QString& strItemName);




private:

    //数据库DDL操作
    bool    createDataBase(QString& strDataBaseName);       //创建数据库
    bool    openDataBase(QString&   strDataBaseName);       //打开数据库文件
    bool    dropDataBase(QString& strDataBaseName);         //删除数据库

    bool    createTable(QString& strTableName,  QHash<QString,QString>& mapFieldsAndTypes);   //创建表操作
    bool    alterTableAddColumn(QString& strTableName, QString& strColumnName, QString& strColumnType);   //表增加列
    bool    dropTable(QString& strTableName);       //删除表


    //数据库DML操作
    bool    insertIntoTable(QString& strTableName, QHash<QString, QVariant>& mapFieldAndValue);                    //将新数据插入到数据库对应表中
    bool    updateTable(QString& strTableName, QHash<QString,QVariant>& mapFieldAndValue, QString& strCondition);   //更新表数据，并更新内存变量
    bool    deleteFromTable(QString& strTableName, const QString& strCondition);                                                                 //删除数据库对应表中的数据


    //数据库DQL操作
    bool    selectFromTable(QString& strTableName,QString& strColumns, QString& strCondition, QVector<QVector<QVariant>>& vecResult);    //从数据库对应表中检索数据



    //批量插入数据，用于插入通道数据
    bool    batchInsertChannelData(QString& strChannelName, QVector<float>& vecChannelData);


    //数据库备份、还原操作，表还原操作
    bool backupDataBase(QString& sourcePath, QString& destinationPath);                                        //数据库备份
    bool restoreRecentVersionDataBase();                                                                                   //回退到最近版本的数据库
    bool restoreTable(QString& strTableName, QString& strBackupTableName);                                           //还原表数据

    //数据库sql语句绑定参数
    void CLiteSqlPersistent::bindParameter(sqlite3_stmt* stmt, int index, const QVariant& value);

    //获取打开数据库中所有结构表的信息，赋值给m_mapAllTableInfo
    void getAllTableAndFields();
    void getAllStreamItems();

    //获取QVariant对应sqlite3数据库中value的类型
    QString getDBTypeFromQVariantValue(QVariant& value);

    //从数据库中判断流是否存在，流指的是数据库中的一张表，表中字段对应该流的所有子信息名，子信息表也是一张表
    bool isExistBaseInfoStream();
    bool isExistConfigStream();
    bool isExistEventStream();
    bool isExistChannelDataStream();
    bool isExistChannelInfoStream();

    void    vecQVariantTransformTovecFloat(QVector<QVector<QVariant>>& vecVariantData, QVector<QVector<float>>& vecFloatData);

private:

    bool               m_bDataBaseOpenFlag;                   //数据库打开标志
    bool               m_bFileCreateFlag;                     //文件创建标志
    bool               m_bBasicInfoStreamCreateFlag;            //基本信息流创建标志
    bool               m_bConfigStreamCreateFlag;               //配置流创建标志
    bool               m_bEventStreamCreateFlag;                //事件流创建标志
    bool               m_bChannelInfoSteamCreateFlag;           //通道信息创建标志
    bool               m_bChannelDataStreamCreateFlag;              //通道流创建标志
    bool               m_bStreamDataCreateFlag;               //数据流文件创建标志，true：流打开


    QString            m_strDataBaseName;                     //数据库文件名
    sqlite3*           m_ptrSqlite3Db;                        //数据库指针
    QVector<QString>   m_vecDataBaseVersionInfo;              //数据库版本信息集合    格式：时间戳+版本id+数据库文件路径
    QString            m_strDataBaseCurrentVersionInfo;       //当前数据库版本信息    格式：时间戳+版本id+数据库文件路径
    QVector<QString>   m_vecBackupRecords;                     //数据库备份记录
    QVector<QString>   m_vecTableBackupRecordsInfo;           //表的备份记录信息        格式：
    QHash<QString, QVector<QString>>    m_mapTableAndFields;            //所有表的结构，具体为：表名 vec(字段名集合)


    short              m_shLogic_Cha_Num;                      // 逻辑采样通道数

    QHash<QString,QVector<QString>>  m_mapStreamAndStreamItem;    //流名和流对应的子项


 };


