#ifndef VIENTOS_H_INCLUDED
#define VIENTOS_H_INCLUDED

#include "Instrumento.h"

class Vientos : public Instrumento
{
    private:
        char escala;
        string detalles;

    public:
        Vientos(string, char, string);
        ~Vientos(){};

        char getEscala() const;
        string getDetalles() const;

        Vientos& operator++();   //++v1
        Vientos operator++(int); //v1++
        Vientos& operator--(); //--v1
        Vientos operator--(int); //v1--
};

#endif // VIENTOS_H_INCLUDED
