#include "Tablero.h"
#include <iostream>

Tablero::Tablero(int tamaño) : tamaño(tamaño) {
    casillas.resize(tamaño, std::vector<char>(tamaño, ' '));
}

Tablero::~Tablero() {
}

void Tablero::inicializar() {
    int mitad = tamaño / 2;
    casillas[mitad - 1][mitad - 1] = '*'; // Fichas iniciales blancas
    casillas[mitad - 1][mitad] = '-';     // Fichas iniciales negras
    casillas[mitad][mitad - 1] = '-';     // Fichas iniciales negras
    casillas[mitad][mitad] = '*';         // Fichas iniciales blancas
}

void Tablero::imprimirTablero() {
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            if (casillas[i][j] == ' ') {
                std::cout << '.' << " ";
            } else {
                std::cout << casillas[i][j] << " ";
            }
}
std::cout << std::endl;
}
}

bool Tablero::esMovimientoValido(int fila, int columna, char color) {
if (casillas[fila][columna] != ' ') {
return false;
}

char oponente = (color == '-') ? '*' : '-';

// Direcciones posibles para verificar los encierros: arriba, abajo, izquierda, derecha, diagonales
int deltas[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

for (int dir = 0; dir < 8; dir++) {
int deltaFila = deltas[dir][0];
int deltaColumna = deltas[dir][1];
int filaActual = fila + deltaFila;
int columnaActual = columna + deltaColumna;

bool hayFichasOponenteEncerradas = false;

while (filaActual >= 0 && filaActual < tamaño && columnaActual >= 0 && columnaActual < tamaño) {
            if (casillas[filaActual][columnaActual] == oponente) {
                hayFichasOponenteEncerradas = true;
            } else if (casillas[filaActual][columnaActual] == color) {
                if (hayFichasOponenteEncerradas) {
                    return true;
                } else {
                    break;
                }
            } else {
                break;
            }

filaActual += deltaFila;
columnaActual += deltaColumna;
}
}

return false;
}


bool Tablero::realizarMovimiento(int fila, int columna, char color) {
if (!esMovimientoValido(fila, columna, color)) {
return false;
}

casillas[fila][columna] = color;

char oponente = (color == '-') ? '*' : '-';

// Direcciones posibles para verificar los encierros: arriba, abajo, izquierda, derecha, diagonales
int deltas[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

for (int dir = 0; dir < 8; dir++) {
int deltaFila = deltas[dir][0];
int deltaColumna = deltas[dir][1];
int filaActual = fila + deltaFila;
int columnaActual = columna + deltaColumna;

bool cambiarFichas = false;

while (filaActual >= 0 && filaActual < tamaño && columnaActual >= 0 && columnaActual < tamaño) {
if (casillas[filaActual][columnaActual] == oponente) {
                cambiarFichas = true;
} else if (casillas[filaActual][columnaActual] == color) {
                if (cambiarFichas) {
                    int filaCambio = fila + deltaFila;
                    int columnaCambio = columna + deltaColumna;
                    while (filaCambio != filaActual || columnaCambio != columnaActual) {
                        casillas[filaCambio][columnaCambio] = color;
                        filaCambio += deltaFila;
                        columnaCambio += deltaColumna;
                    }
                }
                break;
} else {
                break;
}

filaActual += deltaFila;
columnaActual += deltaColumna;
}
}

return true;
}


bool Tablero::fichasCapturadas(int fila, int columna, char color, int deltaFila, int deltaColumna) {
    return false;
}
