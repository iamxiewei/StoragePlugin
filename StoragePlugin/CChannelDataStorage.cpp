#include"CChannelDataStorage.h"


CChannelDataStorage::CChannelDataStorage()
{
    initialize();


}


CChannelDataStorage::~CChannelDataStorage()
{


}


//读取指定通道数据
void       CChannelDataStorage::readChannelData(short channelNo, QVector<float>& data)
{

}

//写入指定通道数据
void       CChannelDataStorage::writeChannelData(short channelNo, QVector<float>& data)
{



}

//写信息到指定通道信息中
void      CChannelDataStorage::writeInfoToChannelInfo(short channelNo, QMap<short,QMap<QString,QVariant>>& channelInfo)
{


}

 //获取指定通道信息
void      CChannelDataStorage::getInfoFromChannelInfo(short channelNo,QMap<short,QMap<QString,QVariant>>& channelInfo)
{

}

//间隔读取指定通道数据
void       CChannelDataStorage::readChannelDataInterval(short channelNo, int interval, QVector<float>& data)
{

}

//初始化，清空缓冲区成员变量
void       CChannelDataStorage::initialize()
{
    m_mapchannelNoAndchannelData.clear();
    m_mapchannelInfo.clear();

}



//设置指定通道信息
void       CChannelDataStorage::setChannelInfo(short channelNo,QString& channelInfo)
{

}

//判断通道号是否存在
bool       CChannelDataStorage::isExistsChannelNumber(short channelNo)
{


}
