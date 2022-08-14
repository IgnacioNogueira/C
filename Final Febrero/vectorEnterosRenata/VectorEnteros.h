#ifndef VECTORENTEROS_H_INCLUDED
#define VECTORENTEROS_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class VectorEnteros
{

private:
    int *vec;
    unsigned cantElem;

public:
    VectorEnteros();
    VectorEnteros(int*,unsigned);
    virtual ~VectorEnteros();

    void printVec(ostream &sal,const VectorEnteros &obj) const;
    VectorEnteros& agregar(int *vec,unsigned cantElemNuevos);
    VectorEnteros operator+(const VectorEnteros &vec2);
    VectorEnteros& operator+(int v2);

    friend ostream& operator <<(ostream &sal, const VectorEnteros &obj);

};


#endif // VECTORENTEROS_H_INCLUDED
