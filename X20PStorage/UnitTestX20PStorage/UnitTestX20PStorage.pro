QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_cx20pstorage.cpp \
    ../StorageLogic/CLiteSqlPersistent.cpp \
    ../StorageLogic/CX20PStorage.cpp

unix|win32: LIBS += -L$$PWD/../StorageLogic/ -lsqlite3

INCLUDEPATH += $$PWD/../StorageLogic
DEPENDPATH += $$PWD/../StorageLogic

# 设置源文件编码
CODECFORTR = UTF-8
CODECFORSRC = UTF-8
