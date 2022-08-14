#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

#include <iostream>
#include <string>
#include "exceptionLlamada.h"

using namespace std;

class Llamada
{
private:
    string telOrig;
    string telDest;
    unsigned duracion;

public:

    Llamada(string,string,unsigned); //el & usalo cuando sean strings constantes,
    virtual ~Llamada();
    Llamada operator+(const Llamada&);
    friend Llamada operator + (unsigned, const Llamada&);
    friend ostream & operator << (ostream& sal,const Llamada &obj);
};

#endif // LLAMADA_H_INCLUDED
