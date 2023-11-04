#include "Partida.h"
#include <iostream>

Partida::Partida(Jugador& jugador1, Jugador& jugador2) : jugador1(jugador1), jugador2(jugador2), tablero(8) {
}

void Partida::jugar() {
    bool turnoJugador1 = true;

    while (true) {
        Jugador& jugadorActual = turnoJugador1 ? jugador1 : jugador2;
        char colorActual = jugadorActual.getColor();

        std::cout << "Turno de " << jugadorActual.getNombre() << " (" << colorActual << "):" << std::endl;
        tablero.imprimirTablero();

    turnoJugador1 = !turnoJugador1;
}
}
