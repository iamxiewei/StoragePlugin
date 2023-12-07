QT -= gui
QT      += core widgets
TEMPLATE = lib
DEFINES += PLUGIN_DB_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = ../../VisualProgramDemo/release/plugins

SOURCES += \
    CBlock.cpp \
    CInfoStorage.cpp \
    CLiteSqlPersistent.cpp \
    CObjModule.cpp \
    CPin.cpp \
    CChannelDataStorage.cpp \
    CX20PStorage.cpp \
    CStorageBlock.cpp \
    plugin_db.cpp

HEADERS += \
    CBlock.h \
    CInfoStorage.h \
    CLiteSqlPersistent.h \
    CObjModule.h \
    CPin.h \
    IFile.h \
    IPersistent.h \
    IStorage.h \
    Plugin_DB_global.h \
    CChannelDataStorage.h \
    CX20PStorage.h \
    CStorageBlock.h \
    plugin_db.h \
    sqlite3.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L$$PWD/./ -lsqlite3

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
