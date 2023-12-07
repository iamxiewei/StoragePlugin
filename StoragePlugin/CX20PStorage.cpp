#include "cx20pstorage.h"

CX20PStorage::CX20PStorage(QString& storageFile)
{
    this->m_strDbFileName=storageFile;
    Initialize();
}

short  CX20PStorage::getLogicChannelNo(short machineNo)
{
    if(m_mapMachineNoAndChannelNo.contains(machineNo))
    {
        return m_mapMachineNoAndChannelNo[machineNo];
    }
    else{
        return -1;
    }

}


bool CX20PStorage:: setLogicChannelNo(short machineNo,short logicChannelNo)
{
    //若逻辑通道号没有使用，就进行赋值
    //否则返回false
    if(m_veclogicChannelNo.contains(logicChannelNo))
    {
        m_mapMachineNoAndChannelNo[machineNo]=logicChannelNo;
        return true;
    }
    else{
        return false;
    }


}

void  CX20PStorage::getInfo( QString& infoName, QVector<QMap<QString,QVariant>>& infoData)
{

}

void  CX20PStorage::insertInfo( QString& infoName,QMap<QString,QVariant>& infoData)
{

}

void  CX20PStorage::getChannelData(short channelNo, QVector<float>& channelData)
{

}
void  CX20PStorage::insertChannelData(short channelNo,QVector<float>& channelData)
{

}
void    CX20PStorage::jumpReadData(short channelNo,short interval, QVector<float> channelData)
{

}

void	CX20PStorage::openStorage()
{

}

void	CX20PStorage::closeStorage()
{

}
bool    CX20PStorage::createInfo(QString& infoName, QMap<QString,QString> fieldsSet)
{

}

bool    CX20PStorage::deleteInfo(QString& infoName)
{

}
void    CX20PStorage::isExistsInfo(QString& infoName)
{

}
void    CX20PStorage::Initialize()
{
    int rc=sqlite3_open(m_strDbFileName.toUtf8().constData(), &m_ptrDataBase);
    if(rc)
    {

    }
    else{


    }
}
void    CX20PStorage::deleteData(QString& infoName,  QString& key)
{

}
void    CX20PStorage::addProperty(QString& infoName, QString& key)
{

}

