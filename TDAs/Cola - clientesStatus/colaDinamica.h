#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

#include "pedidos.h"
#define MINIMO(X,Y)((X)<=(Y)?(X):(Y))

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef struct
{
   tNodo *pri,
         *ult;

}tColaD;


void crearColaDin(tColaD *col);
int colaVaciaDin(const tColaD *col);
void vaciarColaDin(tColaD *col);
int colaLlenaDin(const tColaD *col,unsigned cantBytes);
int ponerEnColaDin(tColaD *col,const void *d,unsigned cantBytes);
int sacarColaDin(tColaD *col,void *d,unsigned tam);
int verPrimeroColaDin(const tColaD *col,void *d,unsigned cantBytes);


#endif // COLADINAMICA_H_INCLUDED
