#ifndef IPERSISTENT_H
#define IPERSISTENT_H

#include<QString>
#include<QVector>
#include<QMap>
#include<QVariant>


//持久化操作抽象类
class IPersistent
{
    virtual bool createStream(QString& strStreamName)=0;                      //创建流
    virtual bool createBaseInfoStream()=0;                                    //创建基本信息流
    virtual bool createConfigStream()=0;                                        //创建配置信息流
    virtual bool createEventStream()=0;                                         //创建事件流
    virtual bool createChannelDataStream(short channelNo)=0;                    //创建通道数据流
    virtual bool createChannelInfoStream(short channelNo)=0;                    //创建通道信息流




    virtual bool writeBaseInfo(QString& baseInfoName,  QMap<QString,QVariant>   ItemInfo)=0;                     //写入基本信息
    virtual bool updateBaseInfo(QString& baseInfoName, QMap<QString,QVariant>   ItemInfo)=0;                    //修改基本信息
    virtual bool writeConfig(QString& configInfoName,  QMap<QString,QVariant>   ItemInfo)=0;                    //写入配置信息
    virtual bool updateConfig(QString& configInfoName, QMap<QString,QVariant>   ItemInfo)=0;                   //修改配置信息
    virtual bool writeEvent(QString& eventInfoName,    QMap<QString,QVariant>   ItemInfo)=0;                        //写入事件信息
    virtual bool updateEvent(QString& eventInfoName,   QMap<QString,QVariant>   ItemInfo)=0;                       //修改事件信息
    virtual bool removeEvent(QString& eventInfoName,   QMap<QString,QVariant>   ItemInfo)=0;                       //移除事件信息
    virtual bool writeChannelInfo(short channelNo,     QMap<QString,QVariant>   ItemInfo)=0;                  //写入通道信息
    virtual bool updateChannelInfo(short channelNo,    QMap<QString,QVariant>   ItemInfo)=0;                 //修改通道信息


};

#endif // IPERSISTENT_H
