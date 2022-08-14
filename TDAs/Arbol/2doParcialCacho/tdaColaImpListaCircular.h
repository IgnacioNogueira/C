#ifndef TDACOLAIMPLISTACIRCULAR_H_INCLUDED
#define TDACOLAIMPLISTACIRCULAR_H_INCLUDED

#include "main.h"

typedef struct sNodoColaImpListaCircular
{
    void *info;
    unsigned tamInfo;
    struct sNodoColaImpListaCircular *sig;


}tNodoColaImpListaCircular;

typedef tNodoColaImpListaCircular * tCola;

void crearCola(tCola *pc);
int colaVacia(tCola *pc);
int ponerEnColaCir(tCola *pc,const void *d,unsigned cantBytes);
int verPrimeroCola(tCola *pc,void *d,unsigned cantBytes);
int sacarEnColaCir(tCola *pc,void *d,unsigned cantBytes);
#endif // TDACOLAIMPLISTACIRCULAR_H_INCLUDED
