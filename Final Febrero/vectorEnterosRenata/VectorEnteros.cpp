#include "VectorEnteros.h"

VectorEnteros::VectorEnteros()
{
    this->vec = NULL;
    this->cantElem = 0;
}

VectorEnteros::~VectorEnteros()
{
    delete [] vec;
}

/*
VectorEnteros::VectorEnteros(int *vec,unsigned cantElem)
{
    this->vec = vec;
    this->cantElem = cantElem;
}
*/


VectorEnteros::VectorEnteros(int *vec,unsigned cantElem)
{
    unsigned i;

    this->vec = new int[cantElem];

    for(i = 0; i < cantElem; ++i)
    {
        this->vec[i] = vec[i];
    }

    this->cantElem = cantElem;
}

void VectorEnteros::printVec(ostream &sal,const VectorEnteros &obj) const
{
    unsigned i;

    sal << "[";
    if(obj.cantElem == 0)
        sal << "el vector no tiene elementos que mostrar";
    else
    {
        sal << obj.vec[0];
        for (i = 1 ; i < obj.cantElem ; i++ )
        {
            sal << ", " << obj.vec[i];
        }
    }
    sal << "]\n";
}

ostream& operator <<(ostream &sal, const VectorEnteros &obj)
{
    obj.printVec(sal,obj);
    return sal;
}


VectorEnteros& VectorEnteros::agregar(int *vec,unsigned cantElemNuevos)
{
    unsigned i, j = 0;
    unsigned cantTotalElem = this->cantElem + cantElemNuevos;
    int * vecNue = new int[cantTotalElem];

    for(i = 0; i < this->cantElem; ++i)
    {
        vecNue[i] = this->vec[i];
    }

    for(j = 0; j < cantElemNuevos; ++j,++i)
    {
        vecNue[i] = vec[j];
    }

    delete[] this->vec;
    this->vec = vecNue;
    //delete [] vecNue;
    this->cantElem = cantTotalElem;
    return *this;
}

VectorEnteros VectorEnteros::operator+(const VectorEnteros &v2)
{
    VectorEnteros vr(this->vec,this->cantElem);

    vr.agregar(v2.vec,v2.cantElem);

    return vr;

}


VectorEnteros& VectorEnteros::operator+(int v2)
{
    this->agregar(&v2,1);
    return *this;
}

/* MALLLL PORQUE ES REFERENCIA, SE REPITA
VectorEnteros VectorEnteros::operator+(int v2)
{
    VectorEnteros vr(this->vec,this->cantElem);

    vr.agregar(&v2,1);

    return vr;
}
*/
