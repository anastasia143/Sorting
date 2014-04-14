#-------------------------------------------------
#
# Project created by QtCreator 2014-04-04T17:10:18
#
#-------------------------------------------------

QT   += core

QT   -= gui

TARGET = sorting
CONFIG   += console
CONFIG   -= app_bundle
#QT  += testlib

TEMPLATE = app


SOURCES += main.cpp \
    merge_sort.cpp \
    tree.cpp \
    test.cpp \
    multiway_merge_sort.cpp

HEADERS += \
    merge_sort.h \
    tree.h \
    test.h \
    multiway_merge_sort.h
