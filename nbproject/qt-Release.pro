TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = MapEditor
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
QT = core gui
SOURCES += TreeModel.cpp main.cpp MainWindow.cpp ExplorerWidget.cpp ItemsWidget.cpp PreviewItemWidget.cpp KEWidget.cpp FileDelegate.cpp
HEADERS += MainWindow.h PreviewItemWidget.h FileDelegate.h KEWidget.h TreeModel.h ItemsWidget.h ExplorerWidget.h
FORMS +=
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
