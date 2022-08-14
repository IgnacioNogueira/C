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

Cuadrado& Cuadrado::operator++()
{
    this->longitud++;
    return *this;
}


Cuadrado Cuadrado::operator++(int)
{
    Cuadrado cuad(*this);
    ++*this;
    return cuad;

}

Cuadrado& Cuadrado::operator--()
{
    this->longitud--;
    return *this;
}


Cuadrado Cuadrado::operator--(int)
{
    Cuadrado cuad(*this);
    --*this;
    return cuad;
}

ostream& operator <<(ostream& sal,const Cuadrado &obj)
{
    return sal << "Valor radio cuadrado:" << obj.longitud << endl;
}
