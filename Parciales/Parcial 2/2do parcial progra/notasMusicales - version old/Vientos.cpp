#include "Vientos.h"
Vientos::Vientos(string nombre, char escala, string detalles):Instrumento(nombre)
{
    this->escala = escala;
    this->detalles = detalles;
}

Vientos::~Vientos()
{

}

char Vientos::getEscala() const
{
    return escala;
}
string Vientos::getDetalles() const
{
    string material = "material:";
    return material + detalles;
}

Vientos& Vientos::operator++() //++c1
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


Vientos Vientos::operator++(int) //v1++
{
    Vientos v = *this;
    ++*this;

    return v;
}

Vientos& Vientos::operator--() //--v1
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

Vientos Vientos::operator--(int) //v1--
{
     Vientos v = *this;
    --*this;

    return v;
}





