#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
public:
    Jugador(const std::string& nombre, char color);
    char getColor() const;
    std::string getNombre() const;
private:
    char color;
    std::string nombre;
};

#endif
