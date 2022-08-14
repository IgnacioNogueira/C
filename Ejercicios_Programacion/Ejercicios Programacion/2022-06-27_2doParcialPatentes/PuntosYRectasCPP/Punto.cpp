#include "Punto.h"

Punto::Punto(double coordX, double coordY)
{
    this->coordX = coordX;
    this->coordY = coordY;
}

ostream& operator <<(ostream& salida, const Punto& punto)
{
    salida << "(" << punto.coordX << "," << punto.coordY << ")";
    return salida;
}
