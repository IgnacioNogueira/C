#ifndef CUADRADO_H
#define CUADRADO_H

#include "FiguraGeometrica.h"

class Cuadrado : public FiguraGeometrica
{
    private:
        float _lado;
    public:
        Cuadrado(string nombre, float lado);
        virtual ~Cuadrado();
        float area() const;
        float perimetro() const;
};

#endif // CUADRADO_H
