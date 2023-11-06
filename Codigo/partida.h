#ifndef PARTIDA_H
#define PARTIDA_H

#include "Tablero.h"
#include "Jugador.h"

enum class Status;

class Partida {
public:
    Partida(Jugador& jugador1, Jugador& jugador2);
    void jugar();
    Status juegoTerminado();
private:
    Jugador& jugador1;
    Jugador& jugador2;
    Tablero tablero;

protected:
    Status status;
};

enum class Status{
    INICIAR, JUEGO, FINALIZADO
};

#endif
