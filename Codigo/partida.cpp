#include "Partida.h"
#include <iostream>

using namespace std;

Partida::Partida(Jugador& jugador1, Jugador& jugador2) : jugador1(jugador1), jugador2(jugador2), tablero(8) {
}

void Partida::jugar() {
    bool turnoJugador1 = true;
    Tablero tablero(8);

    tablero.inicializar();
    cout << "Tablero inicial:" << endl;
    do {
        Jugador& jugadorActual = turnoJugador1 ? jugador1 : jugador2;
        char colorActual = jugadorActual.getColor();
        int fila;
        cout << "Turno de " << jugadorActual.getNombre() << " (" << colorActual << "):" << endl;
        tablero.imprimirTablero();
        cout << "Introduce la fila: ";
        cin >> fila;
        int columna;
        cout << "Introduce la columna: ";
        cin >> columna;

        if (tablero.esMovimientoValido(fila-1, columna-1, colorActual)) {
            tablero.realizarMovimiento(fila-1, columna-1, colorActual);
            cout << "Movimiento valido." << endl;
        } else {
            cout << "Movimiento no valido." << endl;
        }

        turnoJugador1 = !turnoJugador1;
    }while (juegoTerminado() == Status::JUEGO);
}

Status Partida::juegoTerminado() {
    if (tablero.tableroLleno()) {
        return Status::FINALIZADO;
    }
    if (!tablero.jugadorPuedeMover(jugador1.getColor()) && !tablero.jugadorPuedeMover(jugador2.getColor())) {
        return Status::FINALIZADO;
    }

    return Status::JUEGO;
}

