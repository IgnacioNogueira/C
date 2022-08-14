#include "Percusion.h"

Percusion::Percusion(string nombre):Instrumento(nombre)
{
}

//Percusion::~Percusion()
//{
//}

char Percusion::getEscala() const
{
    return 'X';
}

string Percusion::getDetalles() const
{
    return "";
}

Percusion& Percusion::operator++()
{
    throw CambioEscalaException();
}

Percusion Percusion::operator++(int)
{
    throw CambioEscalaException();
}

Percusion& Percusion::operator--()
{
    throw CambioEscalaException();
}

Percusion Percusion::operator--(int)
{
    throw CambioEscalaException();
}
