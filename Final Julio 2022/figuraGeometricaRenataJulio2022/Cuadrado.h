#ifndef CUADRADO_H_INCLUDED
#define CUADRADO_H_INCLUDED

#include "FiguraGeometrica.h"

class Cuadrado:public FiguraGeometrica
{

private:
    float longitud;

public:

    Cuadrado(const string &,float);
    virtual ~Cuadrado();

    float area() const;
    float perimetro() const;

};


#endif // CUADRADO_H_INCLUDED
