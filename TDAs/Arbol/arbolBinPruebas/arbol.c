#include "arbol.h"
#define FOUND 1
#define NOT_FOUND 0
#define minimo(x, y) (x > y) ? x : y

#define SIN_MEM 0
#define TODO_BIEN 1
#define CLAVE_DUP 2
#define CLA_DUP 2
#define ERROR_ACUM 3

void crearArbol(tArbol *p)
{
    *p = NULL;
}
int arbolVacio(const tArbol *p)
{
    return *p == NULL;
}

int insertarAcumulandoEnArbol(tArbol *p,const void *d,unsigned cantBytes,
                              int (*cmp)(const void *,const void *),
                              int (*acum)(void **,unsigned *,const void *,unsigned))
{
    int r;

    if(*p == NULL)
    {
        tNodo *nue;

        if( (nue = (tNodo *)malloc(sizeof(tNodo))) == NULL
                || (nue->info = malloc(cantBytes)) == NULL )
        {
            free(nue);
            return SIN_MEM;
        }

        nue->tamInfo = cantBytes;
        memcpy(nue->info,d,cantBytes);
        nue->izq = NULL;
        nue->der = NULL;
        *p = nue;

        return TODO_BIEN;
    }
    else
    {
        if( (r = cmp((*p)->info,d)) == 0)
        {
            if(acum)
            {
                if(acum(&(*p)->info,&(*p)->tamInfo,d,cantBytes) != TODO_BIEN)
                    return ERROR_ACUM;
            }

            return CLA_DUP;
        }
        else if(r < 0)
            return insertarAcumulandoEnArbol(&(*p)->izq,d,cantBytes,cmp,acum);
        else
            return insertarAcumulandoEnArbol(&(*p)->der,d,cantBytes,cmp,acum);
    }

    return TODO_BIEN;
}
int ponerEnOrden(tArbol *p, const void *d, unsigned tam,
                 int (*comp)(const void *, const void *))
{

    if(*p != NULL)
    {
        if(comp((*p)->info, d) < 0)
        {
            return ponerEnOrden(&(*p)->izq, d, tam, comp);
        }
        else if(comp((*p)->info, d) > 0)
        {
            return ponerEnOrden(&(*p)->der, d, tam, comp);
        }
        else
        {
            return CLAVE_DUP;
        }
    }

    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return SIN_MEM;
    }
    nue->info = malloc(tam);
    if(nue->info == NULL)
    {
        free(nue);
        return SIN_MEM;
    }
    memcpy(nue->info, d, tam);
    nue->tamInfo = tam;
    nue->der = NULL;
    nue->izq = NULL;

    *p = nue;

    return TODO_BIEN;
}
int ponerEnOrdenAcum(tArbol *p, const void *d, unsigned tam,
                     int (*comp)(const void *, const void *),
                     int (*acum)(void **, unsigned *, const void *, unsigned))
{

    if(*p)
    {
        if(comp((*p)->info, d) < 0)
        {
            return ponerEnOrdenAcum(&(*p)->izq, d, tam, comp, acum);
        }
        else if(comp((*p)->info, d) > 0)
        {
            return ponerEnOrdenAcum(&(*p)->der, d, tam, comp, acum);
        }
        else
        {
            if(acum)
            {
                if(!acum(&(*p)->info, &(*p)->tamInfo, d, tam))
                {
                    return ERROR_ACUM;
                }
            }
            return CLAVE_DUP;
        }
    }

    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return SIN_MEM;
    }
    nue->info = malloc(tam);
    if(nue->info == NULL)
    {
        free(nue);
        return SIN_MEM;
    }
    memcpy(nue->info, d, tam);
    nue->tamInfo = tam;
    nue->der = NULL;
    nue->izq = NULL;

    *p = nue;
    return TODO_BIEN;
}
// recorrer ideal
void recorrerEnOrden(const tArbol *p, void (*mostrar)(const void *))
{
    if(*p != NULL)
    {
        recorrerEnOrden(&(*p)->izq, mostrar);
        mostrar((*p)->info);
        recorrerEnOrden(&(*p)->der, mostrar);
    }
}
// construir / reconstruir arbol
void recorrerPreOrden(const tArbol *p, void (*mostrar)(const void *))
{
    if(*p != NULL)
    {
        mostrar((*p)->info);
        recorrerEnOrden(&(*p)->izq, mostrar);
        recorrerEnOrden(&(*p)->der, mostrar);
    }
}
// eliminar arbol
void recorrerPosOrden(const tArbol *p, void (*mostrar)(const void *))
{
    if(*p != NULL)
    {
        recorrerEnOrden(&(*p)->izq, mostrar);
        recorrerEnOrden(&(*p)->der, mostrar);
        mostrar((*p)->info);
    }
}
int contarNodosArbol(const tArbol *p, int *cont)
{
    if(*p == NULL)
    {
        return 0;
    }
    return contarNodosArbol(&(*p)->izq, &(*cont));
    return contarNodosArbol(&(*p)->der, &(*cont));
}
void vaciarArbol(tArbol *p)
{
    if(*p)
    {
        vaciarArbol(&(*p)->izq);
        vaciarArbol(&(*p)->der);
        free((*p)->info);
        free(*p);
        *p = NULL;
    }
}

void podarHastaAltura(tArbol *p, int h)
{
    if(*p == NULL)
    {
        return;
    }
    if(h == 0)
    {
        vaciarArbol(p);
    }
    else
    {
        podarHastaAltura(&(*p)->izq, h-1);
        podarHastaAltura(&(*p)->der, h-1);
    }
}
unsigned contarNodosPorCritCorrecto(const tArbol *p, unsigned (*crit)(const void *, unsigned))
{
    if(!*p)
    {
        return 0;
    }
    return contarNodosPorCritCorrecto(&(*p)->izq, crit) +
           contarNodosPorCritCorrecto(&(*p)->der, crit) +
           crit((*p)->info, (*p)->tamInfo);
}
unsigned contarNodosPorCrit(const tArbol *p, int (*crit)(const void *))
{
    if(!*p)
    {
        return 0;
    }
    return contarNodosPorCrit(&(*p)->izq, crit) +
           contarNodosPorCrit(&(*p)->der, crit) +
           crit((*p)->info);
}
//esto es mas eficiente que utilizar contarNodos
// solo sirve para saber si existe o no
unsigned buscarEnArbol(const tArbol *p, const void *bus, int (*comp)(const void *, const void *))
{
    if(*p == NULL)
    {
        return NOT_FOUND;
    }
    int res = comp((*p)->info, bus);
    if(res < 0)
    {
        return buscarEnArbol(&(*p)->izq, bus, comp);
    }
    else if(res > 0)
    {
        return buscarEnArbol(&(*p)->der, bus, comp);
    }
    return FOUND;
}
// busca y recupera la informacion
unsigned recuperarDeArbol(const tArbol *p, void *bus, unsigned tamBus,
                          int (*comp)(const void *, const void *))
{
    if(*p == NULL)
    {
        return NOT_FOUND;
    }
    int res = comp((*p)->info, bus);
    if(res < 0)
    {
        return buscarEnArbol(&(*p)->izq, bus, comp);
    }
    else if(res > 0)
    {
        return buscarEnArbol(&(*p)->der, bus, comp);
    }
    memcpy(bus, (*p)->info, minimo(tamBus, (*p)->tamInfo));
    return FOUND;
}

int cmpNodosPares(const void *v1, unsigned tamNodoInfo)
{
    tEmpleado *d1 = (tEmpleado *)v1;

    if(d1->dni % 2 == 0)
    {
        return TODO_BIEN;
    }

    return 0;
}

int contarNodosCondicion(const tArbol *p,
                         int (*cmp)(const void *,unsigned))
{
    if(!*p)
        return 0;

    return contarNodosCondicion(&(*p)->izq,cmp)
         + contarNodosCondicion(&(*p)->der,cmp)
         + cmp((*p)->info,(*p)->tamInfo);
}

int contarNodosCondicionPorLadoIzq(const tArbol *p,
                                   int (*cmp)(const void *,unsigned))
{

    if(!*p)
        return 0;

    if((*p)->izq)
    {
        return contarNodosCondicion(&(*p)->izq,cmp)
             + cmp((*p)->info,(*p)->tamInfo); //por la raiz padre si es par
    }

    return cmp((*p)->info,(*p)->tamInfo) != 0 ? 0:1;
}
