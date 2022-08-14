#include "Instrumento.h"

Instrumento::Instrumento(string nombre)
{
    this->nombre = nombre;
}

string Instrumento::getNombre() const
{
    return nombre;
}

int Instrumento::seEncontroEscala(vector<char> escalas,char escala)
{
    for(unsigned i = 0; i < escalas.size(); i++)
    {
        if(escalas[i] == escala)
        {
            return i;
        }
    }

    return NO; //si no se encuentra
}
