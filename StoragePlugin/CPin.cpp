#include "CPin.h"

#include <QGraphicsScene>
#include <QPainter>

qreal CPin::s_margin = 0;
qreal CPin::s_radius = 4;

CPin::CPin(QGraphicsPathItem *parent) : QGraphicsPathItem (parent)
{
    qreal centreX   = -s_radius;
    qreal centreY   = -s_radius;
    qreal sizeX     = 2 * s_radius;
    qreal sizeY     = 2 * s_radius;

    QPainterPath portDrawing;
    portDrawing.addEllipse(centreX, centreY, sizeX, sizeY);
    setPath(portDrawing);

    setPen(QPen(Qt::black));
    setBrush(QBrush(Qt::gray));

    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);

//    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

void CPin::setPinType(CPin::PinType type)
{
    m_type = type;
}

int CPin::getPinType()
{
    return m_type;
}

void CPin::setPinInfo(QString strInfo)
{
    m_strInfo = strInfo;

    this->setToolTip(strInfo);
}

void CPin::setPinIndex(int index)
{
    this->m_index = index;
}

int CPin::getPinIndex()
{
    return m_index;
}

void CPin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if(isSelected())
    {
        painter->setPen(QPen(Qt::black));
        painter->setBrush(QBrush(Qt::green));
    }
    else
    {
        painter->setPen(QPen(Qt::black));
        painter->setBrush(QBrush(Qt::gray));
    }

    painter->drawPath(path());
}

int CPin::type() const
{
    return Type;
}

CPinName::CPinName(CPin *pin, QString strPinName)
{
    m_pOwner = pin;
    m_strPinName = strPinName;
}
