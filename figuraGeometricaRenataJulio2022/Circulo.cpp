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

Circulo& Circulo::operator++() //preincremento
{
    this->radio++;
    return *this;
}

Circulo Circulo::operator++(int)
{
    Circulo cir(*this);
    ++*this;
    return cir;
}

Circulo& Circulo::operator--()
{
    this->radio--;
    return *this;
}

Circulo Circulo::operator--(int)
{
    Circulo cir(*this);
    --*this;
    return cir;
}

Circulo& Circulo::operator+=(float valorFloat)
{
    this->radio+=valorFloat;
    return *this;
}

Circulo& Circulo::operator-=(float valorFloat)
{
    if(valorFloat > this->radio)
        throw excepcionValorNegativoException();

    this->radio-=valorFloat;

    return *this;
}

ostream& operator <<(ostream& sal,const Circulo &obj)
{
    return sal << "Valor radio circulo:" << obj.radio << endl;
}
