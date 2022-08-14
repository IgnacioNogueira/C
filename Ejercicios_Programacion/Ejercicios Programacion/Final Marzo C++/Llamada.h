#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

#include <iostream>
#include <string>
#include "OperacionInvalidaException.h"

using namespace std;

class Llamada
{
private:
    string _origen;
    string _destino;
    int _duracion;
public:
    Llamada(string origen, string destino, int duracion);
    Llamada operator + (const Llamada &obj) const;
    friend Llamada operator + (const int &segundos, const Llamada &obj);
    friend ostream& operator << (ostream &salida, const Llamada &obj);
};

#endif // LLAMADA_H_INCLUDED
