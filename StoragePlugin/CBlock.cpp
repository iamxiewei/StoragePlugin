#include <QMetaMethod>
#include "CBlock.h"

int CBlock::s_horizontalMargin  = 5;
int CBlock::s_verticalMargin    = 5;
int CBlock::s_textSpacing       = 5;

CBlock::CBlock(QObject *pScene)
{
    QGraphicsScene *p = static_cast<QGraphicsScene *>(pScene);
    if(p != nullptr)
    {
        m_pScene = p;
    }
}

void CBlock::autoGainAllPins()
{
    auto meta = this->metaObject();

    int offset = meta->methodOffset();
    int count = meta->methodCount();

    for (int i = offset; i < count; i++)
    {
        auto method = meta->method(i);

        CPin *pin = new CPin(this);

        pin->setPinInfo(method.methodSignature());
        pin->setPinIndex(i);

        if(method.methodType() == QMetaMethod::Slot)
        {
            pin->setPinType(CPin::Input);
        }
        else if(method.methodType() == QMetaMethod::Signal)
        {
            pin->setPinType(CPin::Output);
        }
        else {
            int a = 0;
        }
        m_Pins.push_back(pin);
    }
}

int CBlock::getMethodIndex(QGraphicsItem *pin)
{
    int ret = 0;
    foreach(QGraphicsItem *p, m_Pins)
    {
        if(p == pin)
        {
            CPin *temp = (CPin *)p;
            ret = temp->getPinIndex();
        }
    }
    return ret;
}

int CBlock::type() const
{
    return Type;
}
