#include "FiguraGeometrica.h"

FiguraGeometrica::FiguraGeometrica(const string& nombre)
{
    this->nombre = nombre;
}

FiguraGeometrica::~FiguraGeometrica()
{
}

const string& FiguraGeometrica::getNombre()const
{
    return nombre;
}
