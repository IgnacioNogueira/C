#include "Llamada.h"

Llamada::Llamada(string nroOrigen,string nroDest, unsigned seg)
{
    this->telOrig = nroOrigen;
    this->telDest = nroDest;
    this->duracion = seg;
}

Llamada::~Llamada()
{
}

Llamada Llamada::operator+(const Llamada& ll2)
{
    if(this->telOrig != ll2.telOrig)
        throw exceptionLlamada();

    Llamada suma(this->telOrig,"",(this->duracion+ll2.duracion));
    return suma;
}

Llamada operator+(unsigned seg, const Llamada& ll2)
{
    Llamada ll1(ll2.telOrig,ll2.telDest,(seg + ll2.duracion));
    return ll1;
}

ostream & operator << (ostream& sal,const Llamada &obj)
{
    return sal << "( " <<
    obj.telOrig << ", " <<
    obj.telDest << ", " <<
    obj.duracion << ")" << endl;
}
