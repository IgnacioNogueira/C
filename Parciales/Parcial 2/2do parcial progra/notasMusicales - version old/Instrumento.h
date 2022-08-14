#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "CambioEscalaException.h"

#define NO -1

using namespace std;
class Instrumento
{
private:
    string nombre;

public:
    Instrumento(string);
    string getNombre() const;
    virtual char getEscala() const = 0;
    virtual string getDetalles() const = 0;
    virtual ~Instrumento() {}

    int seEncontroEscala(vector<char> escalas,char escala);
    const vector<char> escalasMusicales = {'C','D','E','F','G','A','B'};
};

/*
    int inc(int val)
    {
    val++;

    if(val > 6)
        val-=7;
        return val;

        return (++val)%7;
    }



*/


#endif // INSTRUMENTO_H_INCLUDED
