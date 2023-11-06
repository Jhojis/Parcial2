#ifndef TABLERO_H
#define TABLERO_H

#include <vector>

class Tablero {
public:
    Tablero(int tamaño);
        ~Tablero();
    void inicializar();
    void imprimirTablero();
    bool esMovimientoValido(int fila, int columna, char color);
    bool realizarMovimiento(int fila, int columna, char color);
    bool tableroLleno() const;
    bool jugadorPuedeMover(char color);
private:
    int tamaño;
        std::vector<std::vector<char>> casillas;

    bool fichasCapturadas(int fila, int columna, char color, int deltaFila, int deltaColumna);
};

#endif
