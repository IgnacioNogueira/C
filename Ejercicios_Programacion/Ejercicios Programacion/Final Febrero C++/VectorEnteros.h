#ifndef VECTORENTEROS_H_INCLUDED
#define VECTORENTEROS_H_INCLUDED
#include <iostream>

using namespace std;

class VectorEnteros
{
private:
    int *_vector;
    int _cantElementos;
public:
    VectorEnteros();
    VectorEnteros(const int *vec, const int cant);
    ~VectorEnteros();
    VectorEnteros agregar(const int *vec, const int cant);
    VectorEnteros operator + (const VectorEnteros &obj) const;
    VectorEnteros operator + (const int &num) const;
    friend ostream& operator << (ostream &salida, VectorEnteros obj);
};

#endif // VECTORENTEROS_H_INCLUDED
