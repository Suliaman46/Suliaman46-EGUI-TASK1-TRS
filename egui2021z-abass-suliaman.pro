QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activestatus.cpp \
    addactivity.cpp \
    addentry.cpp \
    dataStructure.cpp \
    database.cpp \
    datamodel.cpp \
    editentry.cpp \
    main.cpp \
    mainwindow.cpp \
    managerediting.cpp \
    managermainwindow.cpp \
    managertablemodel.cpp \
    sessionloginwindow.cpp \
    sessionuser.cpp

HEADERS += \
    activestatus.h \
    addactivity.h \
    addentry.h \
    dataStructure.h \
    database.h \
    datamodel.h \
    editentry.h \
    mainwindow.h \
    managerediting.h \
    managermainwindow.h \
    managertablemodel.h \
    sessionloginwindow.h \
    sessionuser.h

FORMS += \
    activestatus.ui \
    addactivity.ui \
    addentry.ui \
    editentry.ui \
    mainwindow.ui \
    managerediting.ui \
    managermainwindow.ui \
    sessionloginwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
