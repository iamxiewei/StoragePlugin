#ifndef COBJMODULE_H
#define COBJMODULE_H

#include<QObject>
#include<QMap>
#include <QVector>
#include <QWidget>
#include <QMetaMethod>
#include <QGraphicsPathItem>

template<typename L>  //用于反射传父类参数
class CObjReflectClass
{

typedef QObject *(*Constructor)(L* parent);
public:
    //首先要注册创建的类
    template<typename T>
    static void registerClass()
    {
        //&constructorHelper<T>其实是获取创建的函数指针,核心功能。

        constructors().insert(T::staticMetaObject.className(), &constructorHelper<T>);
    }

    static QObject *createObject(const QString& className,L* scene = nullptr)
    {
        Constructor constructor = constructors().value(className);
        if (constructor == nullptr ){
            return nullptr;
        }
        return (*constructor)(scene);//执行new T函数，创建对应实例
    }

    static QHash<QString, Constructor> &constructors()
    {
        static QHash<QString, Constructor> instance;
        return instance;
    }
private:
    template<typename T>
    static QObject *constructorHelper(L* scene)
    {

        return new T(scene);

    }
};

class CObjModule : public QObject
{
public:
    virtual QVector<QString> getAllController() = 0;

    virtual QObject &createNewController(QString strControllerName, QObject *scene = nullptr) = 0;

    virtual QObject &getControlllerByIndex(int iIndex) = 0;

    virtual QMap<int, QString> getInputPins(int iIndex) = 0;

    virtual QMap<int, QString> getOutputPins(int iIndex) = 0;

    virtual int getMethodIndex(int iControllerIndex, QGraphicsItem *pin) = 0;

    virtual void doTest() = 0;

protected:

    QVector<QObject *> m_allControllers;
};

#endif // COBJMODULE_H
