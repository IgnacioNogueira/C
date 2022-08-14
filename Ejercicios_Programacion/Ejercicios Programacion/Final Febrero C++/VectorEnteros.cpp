#include "VectorEnteros.h"

VectorEnteros::VectorEnteros()
{
    _vector = new int[1];
    _cantElementos = 0;
}

VectorEnteros::VectorEnteros(const int *vec, const int cant)
{
    _vector = new int[cant];
    int *aux = _vector;
    int cont = 0;
    while(cont < cant)
    {
        *aux = *vec;
        cont++;
        aux++;
        vec++;
    }
    _cantElementos = cant;
}

VectorEnteros::~VectorEnteros()
{
    delete [] this->_vector;
}

VectorEnteros VectorEnteros::agregar(const int *vec, const int cant)
{
    int* agregarNum = new int[_cantElementos + cant];
    int* auxAgregado = agregarNum;
    const int* auxVecAct = _vector;
    int cont = 0;
    while(cont < _cantElementos)
    {
        *auxAgregado = *auxVecAct;
        cont++;
        auxAgregado++;
        auxVecAct++;
    }
    cont = 0;
    auxVecAct = vec;
    while(cont < cant)
    {
        *auxAgregado = *auxVecAct;
        cont++;
        auxAgregado++;
        auxVecAct++;
    }
    _cantElementos += cant;

    delete [] this->_vector;
    this->_vector = agregarNum;

    return *this;
}

VectorEnteros VectorEnteros::operator + (const VectorEnteros &obj) const
{
    VectorEnteros resultado;
    resultado._vector = new int[_cantElementos + obj._cantElementos];
    int *aux = resultado._vector;
    int *aux2 = _vector;
    int *aux3 = obj._vector;
    int cont = 0;
    while(cont < _cantElementos)
    {
        *aux = *aux2;
        cont++;
        aux++;
        aux2++;
    }
    resultado._cantElementos = _cantElementos;
    cont = 0;
    while(cont < obj._cantElementos)
    {
        *aux = *aux3;
        cont++;
        aux++;
        aux3++;
    }
    resultado._cantElementos += obj._cantElementos;
    return resultado;
}

VectorEnteros VectorEnteros::operator + (const int &num) const
{
    VectorEnteros resultado;
    resultado._vector = new int[_cantElementos + 1];
    int *aux = resultado._vector;
    int *aux2 = _vector;
    int cont = 0;
    while(cont < _cantElementos)
    {
        *aux = *aux2;
        cont++;
        aux++;
        aux2++;
    }
    resultado._cantElementos = _cantElementos;
    *aux = num;
    resultado._cantElementos++;
    return resultado;
}

ostream & operator <<(ostream &salida, VectorEnteros obj)
{
    int *aux = obj._vector;
    int cont = 0;
    salida << "[";
    while(cont < (obj._cantElementos)-1)
    {
        salida << *aux << ", ";
        cont++;
        aux++;
    }
    salida << *aux << "]" << endl;
    return salida;
}
