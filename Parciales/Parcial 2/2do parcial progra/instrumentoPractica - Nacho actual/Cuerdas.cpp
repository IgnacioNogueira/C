#include "Cuerdas.h"

Cuerdas::Cuerdas(string nombre,char escala):Instrumento(nombre)
{
    if(ES_ESCALA(escala))
    {
        this->escala = escala;
    }
    else
    {
        throw invalid_argument("Error al ingresar la escala a Cuerdas");
    }
}

//Cuerdas::~Cuerdas()
//{
//
//}

char Cuerdas::getEscala() const
{
    return escala;
}

string Cuerdas::getDetalles() const
{
    return "";
}

Cuerdas& Cuerdas::operator++()
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

Cuerdas Cuerdas::operator++(int)
{
    Cuerdas cue(*this);
    ++*this; //revisar, todos tienen que ser así. CORREGIR
    return cue;
}

Cuerdas& Cuerdas::operator--()
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

Cuerdas Cuerdas::operator--(int)
{
    Cuerdas cue(*this);
    --*this; //revisar, todos tienen que ser así. CORREGIR
    return cue;

}


