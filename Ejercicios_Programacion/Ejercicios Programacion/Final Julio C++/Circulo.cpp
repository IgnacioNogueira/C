#include "Circulo.h"

Circulo::Circulo(string nombre, float radio)
    : FiguraGeometrica(nombre), _radio(radio)
{
}

Circulo::~Circulo()
{
}

float Circulo::area() const
{
    return PI * pow(_radio, 2);
}

float Circulo::perimetro() const
{
    return PI * 2 * _radio;
}
