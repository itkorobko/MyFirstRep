QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app
HEADERS +=../FirstTerehApp/myclass.h
SOURCES +=  tst_mytest.cpp ../FirstTerehApp/myclass.cpp
