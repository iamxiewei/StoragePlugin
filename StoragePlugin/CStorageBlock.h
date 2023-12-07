#ifndef CSTORAGEBLOCK_H
#define CSTORAGEBLOCK_H

#include <CBlock.h>
#include"CX20PStorage.h"
#include <QPainter>
#include <QLineEdit>


class CStorageBlock : public CBlock
{
    Q_OBJECT
public:
    CStorageBlock(QObject *pScene);


public slots:
//    void  getChannelData(short channelNumber, QVector<float>& channelData);
//    void insertChannelData(short channelNumber,QVector<float>& channelData);
//    void  getInfo(QString& infoName, QMap<QString,QVariant>& infoData);
//    void  insertInfo(QString& infoName,QMap<QString,QVariant>& infoData);
    void  Operate(int a);

protected:
    void buildNewBlock();

    void reLayout();


private:

    CX20PStorage m_storageManager;

    QLineEdit* m_nameLabel;
    QString m_strBlockName;
    QVector<QWidget *> m_allWidgets;

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CSTORAGEBLOCK_H
