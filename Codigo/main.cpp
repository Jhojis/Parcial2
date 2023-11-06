#include <iostream>
#include "Tablero.h"
#include "partida.h"
#include "Jugador.h"
#include <string>

using namespace std;

int main() {

    int menu;
    do{
        cout << "----- Menu inicial -----" << endl;
        cout << "1. Iniciar nuevo juego" << endl;
        cout << "2. Cargar datos del archivo" << endl;
        cout << "3. Salir" << endl;
        cin >> menu;
    } while (menu != 1 && menu != 2 && !isdigit(menu));

    switch (menu) {
    case 1: {

        string nombreJugador1;
        string nombreJugador2;
        char color1;
        char color2;
        cout << "Introduce el nombre del jugador 1: ";
        cin >> nombreJugador1;
        cout << "Introduce el nombre del jugador 2: ";
        cin >> nombreJugador2;
        cout << "Introduce el color del jugador 1: ";
        cin >> color1;
        cout << "Introduce el color del jugador 2: ";
        cin >> color2;
        Jugador jugador1(nombreJugador1, color1);
        Jugador jugador2(nombreJugador2, color2);

        Partida partida(jugador1, jugador2);


        partida.jugar();
        break;
    }
    default:
        break;
    }


    return 0;
}
