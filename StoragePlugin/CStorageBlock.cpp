#include "CStorageBlock.h"
#include <QGraphicsProxyWidget>
#include <QPushButton>


CStorageBlock::CStorageBlock(QObject *pScene):CBlock (pScene)
{
    m_pScene->addItem(this);
    autoGainAllPins();
    buildNewBlock();
    reLayout();
}




void CStorageBlock::buildNewBlock()
{
    m_strBlockName = "Data_Storage";
    m_nameLabel = new QLineEdit();
    m_nameLabel->setText(m_strBlockName);
    m_nameLabel->setAttribute(Qt::WA_TranslucentBackground);
    m_nameLabel->setReadOnly(true);

    QPushButton *btn1 = new QPushButton();
    btn1->setText("getChannelData");

    QPushButton *btn2 = new QPushButton();
    btn2->setText("insertChannelData");


    QPushButton *btn3 = new QPushButton();
    btn3->setText("getInfo");

    QPushButton *btn4 = new QPushButton();
    btn4->setText("insertInfo");


    //使用代理去添加一个widget，它会跟着block的拖动而自动改变位置
    QGraphicsProxyWidget* proxy1 = new QGraphicsProxyWidget(this);
    proxy1->setWidget(m_nameLabel);

    QGraphicsProxyWidget* proxy2 = new QGraphicsProxyWidget(this);
    proxy2->setWidget(btn1);

    QGraphicsProxyWidget* proxy3 = new QGraphicsProxyWidget(this);
    proxy3->setWidget(btn2);

    QGraphicsProxyWidget* proxy4 = new QGraphicsProxyWidget(this);
    proxy4->setWidget(btn3);

    QGraphicsProxyWidget* proxy5 = new QGraphicsProxyWidget(this);
    proxy5->setWidget(btn4);

    m_allWidgets.push_back(m_nameLabel);
    m_allWidgets.push_back(btn1);
    m_allWidgets.push_back(btn2);
    m_allWidgets.push_back(btn3);
    m_allWidgets.push_back(btn4);

    foreach (CPin *pin, m_Pins)
    {
        m_pScene->addItem(pin);     //增加引脚图元
    }


    //设置路径
    QPainterPath path;
    path.addRect(0, 0, 0, 0);
    setPath(path);
    setPen(QPen(Qt::darkRed));
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}


void CStorageBlock::reLayout()
{
    //Expand the Node when the text is too large
    int width  = s_horizontalMargin * 2 + 100;
    int height = s_verticalMargin;

    foreach (QWidget *widget, m_allWidgets)
    {
        height += widget->height();
        widget->setMinimumWidth(width);
        widget->setMaximumWidth(width);
    }

    //    height += m_nameLabel->fontMetrics().height() + s_horizontalMargin;
    //    m_nameLabel->setMinimumWidth(width);
    //    m_nameLabel->setMaximumWidth(width);

    foreach (const CPin *pin, m_Pins)
    {
        int textWidth  = pin->boundingRect().width();
        int textHeight = pin->boundingRect().height();

        if(textWidth > width - s_horizontalMargin * 2)
        {
            width = textWidth + s_horizontalMargin * 2;
        }

        height += textHeight + s_textSpacing;
    }
    height += s_verticalMargin;

    QPainterPath path;
    path.addRect(-width / 2, -height / 2, width, height + 50);
    setPath(path);

    int y = - height / 2;

    foreach (QWidget *widget, m_allWidgets)
    {
        widget->move(-width / 2, y);
        y += widget->height();
    }

    y += s_verticalMargin * 2;

    //    m_nameLabel->move(-m_nameLabel->fontMetrics().width(m_strBlockName) / 2 - s_horizontalMargin , y);
    //    y += m_nameLabel->fontMetrics().height() * 2 + s_textSpacing * 4;

    foreach (CPin *pin, m_Pins)
    {
        qreal textHeight = pin->boundingRect().height();

        if(pin->getPinType() == CPin::Input)
        {
            pin->setPos(-width / 2 + 2, y - textHeight / 2);
        }
        else if(pin->getPinType() == CPin::Output)
        {
            pin->setPos(width / 2 + 2, y - textHeight / 2);
        }

        y += textHeight + s_textSpacing;
    }
}

void CStorageBlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if(isSelected())
    {
        painter->setPen(QPen(Qt::red));
        painter->setBrush(QBrush(Qt::yellow));
    }
    else
    {
        painter->setPen(QPen(Qt::black));
        painter->setBrush(QBrush(Qt::gray));
    }
    painter->drawPath(path());
}


void  CStorageBlock::Operate(int a)
{

}


