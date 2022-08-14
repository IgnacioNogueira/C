#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#include <iostream>
using namespace std;

#include "CambioEscalaException.h"

#define ES_ESCALA(X)( (X) >= 'A' && (X) <= 'G')


class Instrumento
{
private:
    string nombre;

protected:

public:

    Instrumento(string);
    virtual ~Instrumento();
    string getNombre();
    virtual char getEscala() const = 0;
    virtual string getDetalles() const = 0;
};



#endif // INSTRUMENTO_H_INCLUDED
