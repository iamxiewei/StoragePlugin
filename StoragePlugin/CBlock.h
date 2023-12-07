#ifndef CBLOCK_H
#define CBLOCK_H

#include <QObject>
#include <QGraphicsPathItem>
#include <QGraphicsScene>
#include "CPin.h"

class CBlock : public QObject, public QGraphicsPathItem{
    Q_OBJECT

    enum {
        Type = QGraphicsItem::UserType + 2
    };
public:
     CBlock(QObject *pScene);
     int getMethodIndex(QGraphicsItem *pin);

 protected:
     virtual void buildNewBlock() = 0;
     void autoGainAllPins();

 protected:
     QGraphicsScene *m_pScene{nullptr};

     QVector<CPin *> m_Pins;

     static int s_horizontalMargin;
     //
     static int s_verticalMargin;
     //
     static int s_textSpacing;

 public:
     int type() const;

};

#endif // CBLOCK_H
