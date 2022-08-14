#include "Vientos.h"

Vientos::Vientos(string nombre,char escala,string detalle):Instrumento(nombre)
{
    if(ES_ESCALA(escala))
    {
        this->escala = escala;
        this->detalle = detalle;
    }
    else
    {
        throw invalid_argument("Error al ingresar la escala a Vientos");
    }
}

//Vientos::~Vientos()
//{
//
//}

char Vientos::getEscala() const
{
    return escala;
}

string Vientos::getDetalles() const
{
    return "material:" + detalle;
}

Vientos& Vientos::operator++()
{
    switch(this->escala)
    {
    case 'C':
        this->escala = 'D';
        break;
    case 'D':
        this->escala ='E';
        break;
    case 'E':
        this->escala ='F';
        break;
    case 'F':
        this->escala ='G';
        break;
    case 'G':
        this->escala ='A';
        break;
    case 'A':
        this->escala ='B';
        break;
    case 'B':
        this->escala ='C';
        break;

    }

    return *this;
}

Vientos Vientos::operator++(int)
{
    Vientos v = *this;
    ++*this;
    return v;
}

Vientos & Vientos::operator--()
{
    switch(this->escala)
    {
    case 'C':
        this->escala = 'B';
        break;
    case 'D':
        this->escala ='C';
        break;
    case 'E':
        this->escala ='D';
        break;
    case 'F':
        this->escala ='E';
        break;
    case 'G':
        this->escala ='F';
        break;
    case 'A':
        this->escala ='G';
        break;
    case 'B':
        this->escala ='A';
        break;
    }

    return *this;
}

Vientos Vientos::operator--(int)
{
    Vientos v = *this;
    --*this;
    return v;
}
