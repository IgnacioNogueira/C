#include "Cuadrado.h"

Cuadrado::Cuadrado(const string &nombre,float longitud):FiguraGeometrica(nombre)
{
    this->longitud = longitud;
}

Cuadrado::~Cuadrado()
{

}

float Cuadrado::area() const
{
    return longitud * longitud;
}

float Cuadrado::perimetro() const
{
    return longitud *4;
}
