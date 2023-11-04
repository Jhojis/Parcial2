#ifndef PARTIDA_H
#define PARTIDA_H

#include "Tablero.h"
#include "Jugador.h"

class Partida {
public:
    Partida(Jugador& jugador1, Jugador& jugador2);
    void jugar();
private:
    Jugador& jugador1;
    Jugador& jugador2;
    Tablero tablero;
};

#endif
