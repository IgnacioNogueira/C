#ifndef CUERDAS_H_INCLUDED
#define CUERDAS_H_INCLUDED

#include "Instrumento.h"

class Cuerdas: public Instrumento
{

private:
    char escala;

protected:

public:

    Cuerdas(string,char);
    //virtual ~Cuerdas();
    char getEscala() const;
    string getDetalles() const;

    Cuerdas& operator++();
    Cuerdas operator++(int);
    Cuerdas& operator--();
    Cuerdas operator--(int);

};


#endif // CUERDAS_H_INCLUDED
