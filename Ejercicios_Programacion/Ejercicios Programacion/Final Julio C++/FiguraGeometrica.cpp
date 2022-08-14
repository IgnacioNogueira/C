#include "FiguraGeometrica.h"

FiguraGeometrica::FiguraGeometrica(const string& nombre)
    : _nombre(nombre)
{
}

FiguraGeometrica::~FiguraGeometrica()
{
}

const string& FiguraGeometrica::getNombre() const
{
    return _nombre;
}
