#include "Persona.h"

Persona::Persona(const string &nombre,int edad)
{
    this->nombre = nombre;
    this->edad = edad;
}

Persona::~Persona()
{
}

const string& Persona::getNombre() const
{
    return nombre;
}

int Persona::getEdad() const
{
    return edad;
}

