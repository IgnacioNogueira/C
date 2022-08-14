#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include <iostream>
#include <string>

using namespace std;

class FiguraGeometrica
{
    private:
        string _nombre;
    public:
        FiguraGeometrica(const string& nombre);
        virtual ~FiguraGeometrica();
        const string& getNombre() const;
        virtual float area() const = 0;
        virtual float perimetro() const = 0;
};

#endif // FIGURAGEOMETRICA_H
