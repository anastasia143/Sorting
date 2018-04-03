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
    test.cpp \
    multiway_merge_sort.cpp \
    funnel_sort.cpp \
    priority_queue.cpp \
    multiway_merge_sort2.cpp

HEADERS += \
    merge_sort.h \
    test.h \
    multiway_merge_sort.h \
    funnel_sort.h \
    priority_queue.h \
    multiway_merge_sort2.h
