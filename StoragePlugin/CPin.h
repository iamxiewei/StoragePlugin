#ifndef CPIN_H
#define CPIN_H

#include <QLabel>
#include <QGraphicsPathItem>

class CPin : public QGraphicsPathItem
{

public:

    //
    enum {
        Type = QGraphicsItem::UserType + 3
    };

    enum PinType
    {
        Unkown = -1,
        Input = 0,
        Output = 1
    };

public:
    CPin(QGraphicsPathItem *parent);

public:
    void setPinType(PinType type);
    int getPinType();

    void setPinInfo(QString strInfo);

    void setPinIndex(int index);
    int getPinIndex();

private:
    int m_index{-1};

    PinType m_type{Unkown};
    QString m_strInfo;

    // The margin away from the port that is kept empty
    static qreal s_margin;
    // The size of the Port being displayed
    static qreal s_radius;

    // QGraphicsItem interface
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // QGraphicsItem interface
public:
    int type() const;
};

class CPinName : public QGraphicsTextItem
{
public:
    CPinName(CPin *pin, QString strPinName);

private:
    CPin *m_pOwner;
    QString m_strPinName;
};

#endif // CPIN_H
