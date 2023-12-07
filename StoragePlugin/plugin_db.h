#ifndef PLUGIN_DB_H
#define PLUGIN_DB_H

#include "Plugin_DB_global.h"
#include "CObjModule.h"

QT_BEGIN_NAMESPACE

#define pluginInterface_iid "cn.com.tme.plugin_DB"

Q_DECLARE_INTERFACE(CObjModule, pluginInterface_iid)

QT_END_NAMESPACE


class PLUGIN_DB_EXPORT Plugin_DB:public CObjModule
{

    Q_OBJECT
    Q_PLUGIN_METADATA(IID pluginInterface_iid FILE "plugin_DB.json")
    Q_INTERFACES(CObjModule)


public:
    Plugin_DB();

public:
public:
    QVector<QString> getAllController();
    QObject &createNewController(QString strControllerName, QObject *scene);
    QObject &getControlllerByIndex(int iIndex);
    QMap<int, QString> getInputPins(int iIndex);
    QMap<int, QString> getOutputPins(int iIndex);
    int getMethodIndex(int iControllerIndex, QGraphicsItem *pin);
    void doTest();
};

#endif // PLUGIN_DB_H
