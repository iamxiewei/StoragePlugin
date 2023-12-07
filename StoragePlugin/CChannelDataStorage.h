
#include<QMap>
#include<QVector>
#include<QString>
#include<QVariant>
#include"CLiteSqlPersistent.h"



//通道数据存储类
class CChannelDataStorage
{

private:

    QMap<short,QVector<float>>   m_mapchannelNoAndchannelData;         //所用通道数据
    QMap<short,QMap<QString,QVariant>>         m_mapchannelInfo;          //所用通道的信息
    CLiteSqlPersistent*    m_pDataBasePersistent;                      //数据持久化

public:
    CChannelDataStorage();
    ~CChannelDataStorage();

    void         readChannelData(short channelNo, QVector<float>& data);          //读取指定通道数据
    void         writeChannelData(short channelNo, QVector<float>& data);          //写入指定通道数据

    void         writeInfoToChannelInfo(short channelNo, QMap<short,QMap<QString,QVariant>>& channelInfo);       //写入指定通道信息
    void         getInfoFromChannelInfo(short channelNo, QMap<short,QMap<QString,QVariant>>& channelInfo);         //获取指定通道信息

    void         readChannelDataInterval(short channelNo, int interval, QVector<float>& data);   //间隔读取指定通道数据

private:
    void         initialize();                                          //初始化当前通道
    void         setChannelInfo(short channelNo,QString& channelInfo);                        //设置指定通道信息
    bool         isExistsChannelNumber(short channelNo);   //判断通道号是否存在

};

