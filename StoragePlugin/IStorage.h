#ifndef ISTORAGE_H
#define ISTORAGE_H

class IStorage{

    virtual bool createNewStorage()=0;          //创建新的存储
    virtual bool openStorage()=0;               //打开存储
    virtual bool closeStorage()=0;              //关闭存储
    virtual void appendChannelData()=0;         //添加通道数据
    virtual bool createOneChannel()=0;          //创建一个通道
    virtual bool openOneChannel()=0;            //打开一个通道
    virtual void pickChannelData()=0;           //获取一个通道显示一屏的数据
    virtual bool updateStorage()=0;             //修改存储
    virtual void flushStorage()=0;              //刷新存储
    virtual void appendEvent()=0;               //添加事件
    virtual void updateEvent()=0;               //修改事件
    virtual bool removeEvent()=0;               //移除事件
    virtual void pickEvent()=0;                 //获取事件
};





#endif // ISTORAGE_H
