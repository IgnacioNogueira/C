#include "Cuerdas.h"

Cuerdas::Cuerdas(string nombre, char escala):Instrumento(nombre)
{
    this->escala = escala;
}

char Cuerdas::getEscala() const
{
    return escala;
}

string Cuerdas::getDetalles() const
{
    return "";
}

Cuerdas& Cuerdas::operator++() //++c1
{
    int r;

    if(escala == 'B')
    {
        escala = escalasMusicales.front();
    }
    else
    {
        if( (r = seEncontroEscala(escalasMusicales,escala)) != NO)
        {
            escala = escalasMusicales[r+1];
        }
    }

    return *this;
}


Cuerdas Cuerdas::operator++(int) //c1++
{
     Cuerdas c = *this;
    ++*this;

    return c;
}

Cuerdas& Cuerdas::operator--() //--c1
{
    int r;

    if(escala == 'C')
    {
        escala = escalasMusicales.back();
    }
    else
    {
        if( (r = seEncontroEscala(escalasMusicales,escala)) != NO)
        {
            escala = escalasMusicales[r-1];
        }
    }

    return *this;
}


Cuerdas Cuerdas::operator--(int) //c1--
{
    Cuerdas c = *this;
    --*this;
    return c;
}


