#include <iostream>
#include "Tablero.h"

int main() {
    Tablero tablero(8);

    tablero.inicializar();

    std::cout << "Tablero inicial:" << std::endl;
    tablero.imprimirTablero();

    // Ejemplo de uso
    int fila = 3;
    int columna = 5;
    char color = '*'; // El jugador actual es negro

    if (tablero.esMovimientoValido(fila-1, columna-1, color)) {
        tablero.realizarMovimiento(fila-1, columna-1, color);
        std::cout << "Movimiento valido. Tablero despues del movimiento:" << std::endl;
                                                                                 tablero.imprimirTablero();
    } else {
        std::cout << "Movimiento no valido." << std::endl;
    }

    return 0;
}
