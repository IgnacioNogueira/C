#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "Persona.h"
#include "EdadEmpleadoInvalidaException.h"

class Empleado:public Persona
{
private:
    string legajo;

public:
    Empleado(const string &,int,const string &);
    ~Empleado();
    const string& getLegajo() const;



};


#endif // EMPLEADO_H_INCLUDED
