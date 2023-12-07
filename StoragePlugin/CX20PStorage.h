 #ifndef CX20PSTORAGE_H
#define CX20PSTORAGE_H


#include"sqlite3.h"
#include"CX20pstorage.h"
#include"CInfoStorage.h"
#include"CChannelDataStorage.h"


//X20P数据存储类
class CX20PStorage
{
private:
    CChannelDataStorage* m_pChannelDataStorage;     //通道数据存储
    QVector<CInfoStorage*>  m_vecInfoStorage;       //除通道数据外其他结构化数据存储


public:

    CX20PStorage();
    ~CX20PStorage();


    short  getLogicChannelNo(short machineNo);      //获取逻辑通道号
    bool  setLogicChannelNo(short machineNo,short logicChannelNo);  //设置逻辑通道号

    void  getInfo( QString& infoName, QVector<QVariant>& infoData) ;      //获取信息
    void  insertInfo( QString& infoName,QVector<QVariant>& infoData) ;             //插入信息

    void  getChannelData(short channelNo, QVector<float>& channelData) ;                //获取指定通道数据
    void  insertChannelData(short channelNo,QVector<float>& channelData) ;              //插入指定通道数据
    void  readDataInterval(short channelNo,short interval, QVector<float> channelData);   //间隔指定数量读取数据




private:
    void    Initialize();                                                                //初始化
    void	openStorage();                                                               //打开存储
    void	closeStorage();                                                              //关闭存储
    bool    createInfo(QString& infoName, QMap<QString,QString> fieldsSet);              //创建结构化信息
    bool    deleteInfo(QString& infoName);                                               //根据信息名删除指定信息
    void    isExistsInfo(QString& infoName);                                             //根据信息名判断是否在内存中
    void    deleteData(QString& infoName,  QString& key);                                //根据指定信息名和指定关键字删除数据
    void    addProperty(QString& infoName, QString& key);                                //根据指定信息名和指定关键字插入属性



};

#endif // CX20PSTORAGE_H
