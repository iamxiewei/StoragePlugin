#ifndef CINFOSTORAGE_H
#define CINFOSTORAGE_H

#include<QString>
#include<QMap>
#include<QVariant>
#include"CLiteSqlPersistent.h"

//存放单独的一个实体信息（实体对应数据库中的一张表）的数据
class CInfoStorage
{

private:
    QString infoName;                                       //信息名
    QVector<QMap<QString,QVariant>> m_vecInfoContent;       //存储整个结构化信息的内容
    QVector<QMap<QString,QString>>  m_vecfieldsAndTypes;    //存储当前实体信息中的字段名和字段类型
    CLiteSqlPersistent*    m_pDataBasePersistent;          //存放至数据库下，需要的持久化类

public:
    CInfoStorage();
    ~CInfoStorage();



public:
    void   InsertInfo(QVector<QVariant>& info);                        //插入数据
    void   UpdateInfo(QString& key,QVariant value);                  //修改数据
    void   DeleteInfo(QString& rowId);                              //删除数据
    void   SearchInfo(QVector<QVariant>& info, QString key=NULL, QString whereClause=NULL); //条件查询数据

private:
    void   Initialize();                                          //初始化

};

#endif // CINFOSTORAGE_H
