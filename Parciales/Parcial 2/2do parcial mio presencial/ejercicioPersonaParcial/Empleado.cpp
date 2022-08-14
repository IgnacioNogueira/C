#include "Empleado.h"

Empleado::Empleado(const string &nombre,int edad,const string &legajo):Persona(nombre,edad)
{
    if(edad < 18)
        throw EdadEmpleadoInvalidaException();

    this->legajo = legajo;
}


Empleado::~Empleado()
{
}

const string& Empleado::getLegajo() const
{
    return legajo;
}

