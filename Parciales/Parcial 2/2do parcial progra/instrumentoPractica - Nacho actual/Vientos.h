#ifndef VIENTOS_H_INCLUDED
#define VIENTOS_H_INCLUDED

#include "Instrumento.h"

class Vientos: public Instrumento
{


private:
    char escala;
    string detalle;

protected:

public:

    Vientos(string nombre,char escala,string detalle);
    //virtual ~Vientos();

    char getEscala() const;
    string getDetalles() const;

    Vientos& operator++();
    Vientos operator++(int);
    Vientos& operator --();
    Vientos operator --(int);
};


#endif // VIENTOS_H_INCLUDED
