#include "Instrumento.h"

Instrumento::Instrumento(string nombre)
{
    this->nombre = nombre;
}

Instrumento::~Instrumento()
{
    //dtor
}

string Instrumento::getNombre()
{
    return nombre;
}
