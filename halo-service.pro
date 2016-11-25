#-------------------------------------------------
#
# Project created by QtCreator 2016-09-01T13:02:17
#
#-------------------------------------------------

QT       += core gui\
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = halo-service
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    authform.cpp \
    connect.cpp \
    addclient.cpp

HEADERS  += mainwindow.h \
    authform.h \
    connect.h \
    addclient.h

FORMS    += mainwindow.ui \
    authform.ui \
    addclient.ui
