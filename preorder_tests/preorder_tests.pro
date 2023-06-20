QT += testlib
QT += xml
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_preorder.cpp \
    ../functions.cpp \
    ../exception.cpp

HEADERS +=  \
    ../header.h \
    ../exception.h
