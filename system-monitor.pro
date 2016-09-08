#-------------------------------------------------
#
# Project created by QtCreator 2016-08-08T12:24:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = system-monitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    processinformationworker.cpp \
    workerthread.cpp \
    resourcesworker.cpp \
    memoryconversion.cpp \
    filesystemworker.cpp \
    processpropertiesdialogue.cpp \
    processtools.cpp

HEADERS  += mainwindow.h \
    processinformationworker.h \
    tablenumberitem.h \
    workerthread.h \
    resourcesworker.h \
    memoryconversion.h \
    tablememoryitem.h \
    filesystemworker.h \
    processpropertiesdialogue.h \
    processtools.h

FORMS    += mainwindow.ui \
    processpropertiesdialogue.ui

QMAKE_CXXFLAGS += -std=c++14 -Wall
LIBS += -L"libprocps" -lprocps -lstdc++fs
