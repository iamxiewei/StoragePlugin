QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CLiteSqlPersistent.cpp \
        CX20PStorage.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CLiteSqlPersistent.h \
    CX20PStorage.h \
    Constant/BL-42N/Common_Constant_Define.h \
    Constant/BL-42N/Experiment_Constant_Define.h \
    Constant/BL-42N/Hardware_Constant_Define.h \
    Constant/SystemConstant.h \
    IFile.h \
    IPersistent.h \
    Storage.h \
    sqlite3.h

unix|win32: LIBS += -L$$PWD/./ -lsqlite3

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

# 设置源文件编码
CODECFORTR = UTF-8
CODECFORSRC = UTF-8
 
  
 H E A D E R S   + =   \  
         s q l i t e 3 . h 
