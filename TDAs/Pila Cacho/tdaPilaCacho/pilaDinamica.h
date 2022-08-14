#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#include "pila.h"

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;

} tNodo;

typedef tNodo * tPilaD;

void crearPilaDinamica(tPilaD *p);
int pilaDinLlena(const tPilaD *p, unsigned cantBytes);
int pilaDinVacia(const tPilaD *p);
int ponerEnPilaDinamica(tPilaD *p,const void *d,unsigned cantBytes);
int verTopePilaDinamica(const tPilaD *p,void *d,unsigned cantBytes);
int sacarPilaDinamica(tPilaD *p,void *d,unsigned cantBytes);
void vaciarPilaDinamica(tPilaD *p);


#endif // PILADINAMICA_H_INCLUDED
