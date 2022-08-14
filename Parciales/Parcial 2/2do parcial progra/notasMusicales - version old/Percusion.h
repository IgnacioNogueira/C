#ifndef PERCUSION_H_INCLUDED
#define PERCUSION_H_INCLUDED

#include "Instrumento.h"

class Percusion : public Instrumento
{
    private:

    public:
        Percusion(string);
        ~Percusion(){};

        char getEscala() const;
        string getDetalles() const;

        Percusion& operator++();
        Percusion operator++(int);
        Percusion& operator--();
        Percusion operator--(int);
};

#endif // PERCUSION_H_INCLUDED
