QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    hranitel.cpp \
    main.cpp \
    mainwindow.cpp \
    newrecord.cpp \
    rekords.cpp \
    spisok_recordov.cpp \
    w1.cpp \
    w2.cpp \
    w3.cpp

HEADERS += \
    hranitel.h \
    mainwindow.h \
    newrecord.h \
    rekords.h \
    spisok_recordov.h \
    w1.h \
    w2.h \
    w3.h

FORMS += \
    mainwindow.ui \
    newrecord.ui \
    rekords.ui \
    w1.ui \
    w2.ui \
    w3.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MyRes.qrc
