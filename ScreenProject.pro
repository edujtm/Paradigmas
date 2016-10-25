QT += core
QT -= gui

CONFIG += c++11

TARGET = ScreenProject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += screen.cpp \
    reta.cpp \
    retangulo.cpp \
    circulo.cpp \
    interpretador.cpp \
    main.cpp

HEADERS += screen.h \
    figurageometrica.h \
    reta.h \
    retangulo.h \
    circulo.h \
    interpretador.h
