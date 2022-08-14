#include "Llamada.h"

Llamada::Llamada(string origen, string destino, int duracion)
{
    _origen = origen;
    _destino = destino;
    _duracion = duracion;
}

Llamada Llamada::operator + (const Llamada &obj) const
{
    if(_origen != obj._origen)
        throw OperacionInvalidaException();
    Llamada aux(_origen, "", (_duracion + obj._duracion));
    return aux;
}

Llamada operator + (const int &segundos, const Llamada &obj)
{
    Llamada aux(obj._origen, obj._destino, (obj._duracion + segundos));
    return aux;
}

ostream& operator << (ostream &salida, const Llamada &obj)
{
    salida << "( " << obj._origen << ", " << obj._destino << ", " << obj._duracion << ")" << endl;
    return salida;
}
