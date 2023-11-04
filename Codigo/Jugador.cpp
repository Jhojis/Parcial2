#include "Jugador.h"

Jugador::Jugador(const std::string& nombre, char color) : nombre(nombre), color(color) {}

char Jugador::getColor() const {
    return color;
}

std::string Jugador::getNombre() const {
    return nombre;
}
