#ifndef IPERSISTENT_H
#define IPERSISTENT_H

#include<QString>
#include<QVector>
#include<QHash>
#include<QVariant>


//持久化操作抽象类
class IPersistent
{
    virtual bool createStream(QString& strStreamName)=0;                      //创建流
    virtual bool createBaseInfoStream()=0;                                    //创建基本信息流
    virtual bool createConfigStream()=0;                                        //创建配置信息流
    virtual bool createEventStream()=0;                                         //创建事件流
    virtual bool createChannelDataStream()=0;                    //创建通道数据流
    virtual bool createChannelInfoStream()=0;                    //创建通道信息流




    virtual bool writeDataToBaseInfo(QString& strBaseInfoItemName,  QHash<QString,QVariant>&   mapItemInfo)=0;                     //写入基本信息
    virtual bool updateBaseInfo(QString& strBaseInfoItemName, QHash<QString,QVariant>&   mapItemInfo, QString& strCondition)=0;                    //修改基本信息
    virtual bool writeDataToConfigInfo(QString& strConfigInfoItemName,  QHash<QString,QVariant>&   mapItemInfo)=0;                    //写入配置信息
    virtual bool updateConfigInfo(QString& strConfigInfoItemName, QHash<QString,QVariant>&   mapItemInfo, QString& strCondition)=0;                   //修改配置信息
    virtual bool writeDataToEventInfo(QString& strEventInfoItemName,   QHash<QString,QVariant>&   mapItemInfo)=0;                        //写入事件信息
    virtual bool updateEventInfo(QString& strEventInfoItemName,   QHash<QString,QVariant>&   mapItemInfo, QString& strCondition)=0;                       //修改事件信息
    virtual bool removeEventInfo(QString& strEventInfoItemName, QString& strCondition)=0;                       //移除事件信息
    virtual bool writeDataToChannelInfo(QString& strChannelNo,     QHash<QString,QVariant>&   mapItemInfo)=0;                  //写入通道信息
    virtual bool updateChannelInfo(QString& strChannelNo,    QHash<QString,QVariant>&   mapItemInfo, QString& strCondition)=0;                 //修改通道信息


};

#endif // IPERSISTENT_H
