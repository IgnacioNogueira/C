#ifndef TDALISTASIMPLE_H_INCLUDED
#define TDALISTASIMPLE_H_INCLUDED

#include "main.h"

typedef struct sNodoListaSimple
{
    void * info;
    unsigned tamInfo;
    struct sNodoListaSimple *sig;

}tNodoLista;

typedef tNodoLista *tListaSimple;

void crearListaSimple(tListaSimple *pl);


#endif // TDALISTASIMPLE_H_INCLUDED
