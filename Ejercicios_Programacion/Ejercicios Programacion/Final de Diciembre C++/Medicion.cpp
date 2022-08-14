#include "Medicion.h"

Medicion::Medicion(float valor, string unidad)
        : _valor(valor), _unidad(unidad)
{
}

Medicion Medicion::operator - (const Medicion &obj) const
{
    if(_unidad != obj._unidad)
        throw RestaInvalidaException();
    Medicion aux = *this;
    aux._valor -= obj._valor;
    return aux;
}

Medicion operator + (const float &izq, const Medicion &der)
{
    float valor = izq + der._valor;
    string unidad = der._unidad;
    Medicion aux(valor, unidad);
    return aux;
}

ostream& operator << (ostream &salida, const Medicion &obj)
{
    salida << obj._valor << " " << obj._unidad << endl;
    return salida;
}
