
#include<QMetaMethod>
#include<QMetaObject>

#include "plugin_db.h"
#include "CBlock.h"
#include "CStorageBlock.h"

Plugin_DB::Plugin_DB()
{
    CObjReflectClass<QObject>::registerClass<CStorageBlock>();
}


QVector<QString> Plugin_DB::getAllController(){
    QVector<QString> ret;

    for (auto it : CObjReflectClass<QObject>::constructors().keys())
    {
        ret.push_back(it);
    }

    return ret;
}
QObject& Plugin_DB::createNewController(QString strControllerName, QObject *scene){
    QObject *controller = CObjReflectClass<QObject>::createObject(strControllerName, scene);
    m_allControllers.push_back(controller);

    return *controller;

}
QObject& Plugin_DB::getControlllerByIndex(int iIndex){
    QObject *obj = m_allControllers.at(iIndex);
    return *obj;

}
QMap<int, QString> Plugin_DB::getInputPins(int iIndex){
    QMap<int, QString> ret;
    if(m_allControllers.size() != 0 && m_allControllers.size() > iIndex)
    {
        auto meta = m_allControllers.at(iIndex)->metaObject();

        int offset = meta->methodOffset();
        int count = meta->methodCount();

        for (int i = offset; i < count; i++)
        {
            auto method = meta->method(i);
            if(method.methodType() == QMetaMethod::Slot)
            {
                ret.insert(i, method.methodSignature());
            }
        }
    }

    return ret;
}
QMap<int, QString> Plugin_DB::getOutputPins(int iIndex){
    QMap<int, QString> ret;
    if(m_allControllers.size() != 0 && m_allControllers.size() > iIndex)
    {
        auto meta = m_allControllers.at(iIndex)->metaObject();
        int offset = meta->methodOffset();
        int count = meta->methodCount();
        ;
        for (int i = offset; i < count; i++)
        {
            auto method = meta->method(i);
            if(method.methodType() == QMetaMethod::Signal)
            {
                ret.insert(i, method.methodSignature());
            }
        }

        for (int i = meta->propertyOffset(); i < meta->propertyCount(); i++)
        {
            auto propertyInfo = meta->property(i);
            propertyInfo.name();
        }
    }

    return ret;
}
int Plugin_DB::getMethodIndex(int iControllerIndex, QGraphicsItem *pin){
    CBlock *pBlock = (CBlock *)m_allControllers.at(iControllerIndex);
    if(pBlock)
    {
        return pBlock->getMethodIndex(pin);
    }

    return -1;

}


void Plugin_DB::doTest(){


}
