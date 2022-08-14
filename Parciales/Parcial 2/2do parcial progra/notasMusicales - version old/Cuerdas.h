#ifndef CUERDAS_H_INCLUDED
#define CUERDAS_H_INCLUDED

#include "Instrumento.h"

class Cuerdas : public Instrumento
{
    private:
        char escala;
    public:
        Cuerdas(string, char);
        ~Cuerdas(){};

        char getEscala() const;
        string getDetalles() const;

        Cuerdas& operator++();   //++c1
        Cuerdas operator++(int); //c1++
        Cuerdas& operator--(); //--c1
        Cuerdas operator--(int); //c1--
};

#endif // CUERDAS_H_INCLUDED
