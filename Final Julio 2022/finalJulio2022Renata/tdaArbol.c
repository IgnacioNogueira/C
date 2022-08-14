#include "tdaArbol.h"

void crearArbolBinBusq(tArbolBinBusq * p)
{
    *p = NULL;
}

int insertarEnArbolBinBusqRec(tArbolBinBusq *p,const void *d,
                              unsigned cantBytes,
                              int (*cmp)(const void*,const void*))
{
    tNodoArbol *nue;
    int rc;

    if(*p)
    {
        if((rc = cmp((*p)->info,d)) < 0)
            return insertarEnArbolBinBusqRec(&(*p)->izq,d,cantBytes,cmp);
        else if(rc > 0)
            return insertarEnArbolBinBusqRec(&(*p)->der,d,cantBytes,cmp);

        return CLA_DUP;
    }

    if( (nue = (tNodoArbol *)malloc(sizeof(tNodoArbol))) == NULL ||
            (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return SIN_MEM;
    }

    nue->tamInfo = cantBytes;
    memcpy(nue->info,d,cantBytes);
    nue->der = NULL;
    nue->izq = NULL;
    *p = nue;

    return TODO_BIEN;
}

int recorrerYMostrarArbolHastaNivel(const tArbolBinBusq *p,
                                    unsigned nivel,
                                    void(*mostrar)(void *,unsigned, void *),
                                    void *paramAccion)
{
    if(!*p)
        return 0;

    if(nivel == 0)
    {
        mostrar((*p)->info,(*p)->tamInfo,paramAccion);
        return TODO_BIEN;
    }

    int li,ld;

    li = recorrerYMostrarArbolHastaNivel(&(*p)->izq,nivel-1,mostrar,paramAccion);
    ld = recorrerYMostrarArbolHastaNivel(&(*p)->der,nivel-1,mostrar,paramAccion);

    return li || ld;
}
