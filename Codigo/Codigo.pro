TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Jugador.cpp \
        main.cpp \
        partida.cpp \
        reglasothello.cpp \
        tablero.cpp

HEADERS += \
    Jugador.h \
    partida.h \
    reglasothello.h \
    tablero.h
