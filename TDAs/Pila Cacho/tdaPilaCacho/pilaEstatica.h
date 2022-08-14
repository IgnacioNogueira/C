#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED

#include "pila.h"

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope; //la flechita

}tPilaE;

typedef struct
{
    char nombre[20];
    unsigned edad;
}tAlumno;

void crearPilaEstatica(tPilaE *p);
int pilaEstaticaLlena(const tPilaE *p,unsigned cantBytes);
int pilaEstaticaVacia(const tPilaE *p);
int ponerEnPilaEstatica(tPilaE *p,void *d,unsigned cantBytes);
int pilaEstaticaVerTope(const tPilaE *p,void *d,unsigned cantBytes);
int sacarDePilaEstatica(tPilaE *p,void *d,unsigned cantBytes);
void vaciarPilaEstatica(tPilaE *p);






#endif // PILAESTATICA_H_INCLUDED
