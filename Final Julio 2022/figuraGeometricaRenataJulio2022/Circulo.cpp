#include "Circulo.h"

Circulo::Circulo(const string &nombre,float radio):
    FiguraGeometrica(nombre)
{
    this->radio = radio;
}

Circulo::~Circulo()
{
}

float Circulo::area() const
{
    return PI *(radio*radio);
}

float Circulo::perimetro() const
{
    return 2 * PI * radio;
}
