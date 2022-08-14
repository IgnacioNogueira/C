#ifndef MEDICION_H_INCLUDED
#define MEDICION_H_INCLUDED

#include <iostream>
#include <string>
#include "RestaInvalidaException.h"

using namespace std;

class Medicion
{
private:
    float _valor;
    const string _unidad;
public:
    Medicion(float valor, string unidad);
    Medicion operator - (const Medicion &obj) const;
    friend Medicion operator + (const float &izq, const Medicion &der);
    friend ostream& operator << (ostream &salida, const Medicion &obj);
};

#endif // MEDICION_H_INCLUDED
