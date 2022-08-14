#include "Cuadrado.h"

Cuadrado::Cuadrado(string nombre, float lado)
    : FiguraGeometrica(nombre), _lado(lado)
{
}

Cuadrado::~Cuadrado()
{
}

float Cuadrado::area() const
{
    return _lado * _lado;
}

float Cuadrado::perimetro() const
{
    return _lado * 4;
}
