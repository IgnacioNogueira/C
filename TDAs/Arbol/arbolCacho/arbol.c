#include "arbol.h"
#include "funciones.h"
#define reservarMemoriaNodo(X,Y,Z,W) (   \
                                     ( (X) = (typeof(X))malloc((Y)) ) == NULL || \
                                     ( (Z) = malloc(W) ) == NULL ? \
                                      free(X),0:1)

void crearArbolBinBusq(tArbolBinBusq *p)
{
    *p = NULL;
}

int acumularCantidadProducto(void **info1, unsigned * tamInfo1,const void *info2,unsigned tamInfo2)
{
    tProducto **d1 = (tProducto **)info1;
    const tProducto *d2 = (tProducto *)info2;

    (*d1)->cantidad+=d2->cantidad;

    return TODO_BIEN; //faltan cosas para que se retorne todo bien, pero es un mero ejemplo
}

int insertarAcumulandoArbolBinBusq(tArbolBinBusq *p,const void *d,unsigned cantBytes,
                                   int (*cmp)(const void *,const void *),
                                   int (*acum)(void **,unsigned *,const void *,unsigned))
{
    if(*p == NULL)
    {
        tNodoArbol *nue;

        if( (nue = (tNodoArbol *)malloc(sizeof(tNodoArbol))) == NULL ||
                (nue->info = malloc(cantBytes)) == NULL)
        {
            free(nue);
            return SIN_MEM;
        }

        memcpy(nue->info,d,cantBytes);
        nue->tamInfo = cantBytes;
        nue->izq = NULL;
        nue->der = NULL;
        *p = nue;
    }
    else
    {
        int r = cmp(d,(*p)->info);

        if(r == 0)
        {
            if(acum)
                if( acum(&(*p)->info,&(*p)->tamInfo,d,cantBytes) != TODO_BIEN)
                    return SIN_MEM;

            return CLA_DUP;
        }
        else if(r < 0)
        {
            return insertarAcumulandoArbolBinBusq(&(*p)->izq,d,cantBytes,cmp,acum);
        }
        else
        {
            return insertarAcumulandoArbolBinBusq(&(*p)->der,d,cantBytes,cmp,acum);
        }
    }

    return TODO_BIEN;
}

int insertarArbolBinBusq(tArbolBinBusq *p,const void *d, unsigned tam,
                         int (*cmp)(const void *,const void *))
{
    tNodoArbol *nue;
    int rc;

    while(*p)
    {
        if( (rc = cmp(d,(*p)->info)) < 0)
            p = &(*p)->izq;
        else if(rc > 0)
            p = &(*p)->der;
        else
            return CLA_DUP;
    }

    if( (nue = (tNodoArbol *)malloc(sizeof(tNodoArbol))) == NULL
            || (nue->info = malloc(tam)) == NULL )
    {
        free(nue);
        return SIN_MEM;
    }

    nue->tamInfo = tam;
    memcpy(nue->info,d,tam);
    nue->izq = NULL;
    nue->der = NULL;
    *p = nue;

    return TODO_BIEN;
}

int insertarEnArbBinBusqRec(tArbolBinBusq *p,const void *d, unsigned tam,
                            int (*cmp)(const void *,const void*))
{
    tNodoArbol *nue;
    int rc;

    if(*p)
    {
        if((rc = cmp(d,(*p)->info)) < 0)
            return insertarEnArbBinBusqRec(&(*p)->izq,d,tam,cmp);
        if(rc > 0)
            return insertarEnArbBinBusqRec(&(*p)->der,d,tam,cmp);

        return CLA_DUP;
    }

    if(!reservarMemoriaNodo(nue,sizeof(tNodoArbol),nue->info,tam))
    {
        free(nue);
        return SIN_MEM;
    }

    nue->tamInfo = tam;
    memcpy(nue->info,d,tam);
    nue->der = NULL;
    nue->izq = NULL;
    *p = nue;
    return TODO_BIEN;
}

///////////////////////
//                   //
//  - Preorden:  RID //
//  - In Orden:  IRD //
//  - PostOrden: IDR //
//                   //
///////////////////////

void recorrerEnOrdenArbolBinBusqRecMIOOO(const tArbolBinBusq *p,
        void (*accion)(void *,unsigned,void *,unsigned),
        void *params,
        unsigned tamArch);

void recorrerEnOrdenArbolBinBusqRecConParams(const tArbolBinBusq *p,
        void (*accion)(void *,unsigned,void *,unsigned),
        void *params,
        unsigned tamArch)
{
    if(*p == NULL)
        return;

    recorrerEnOrdenArbolBinBusqRecConParams(&(*p)->izq,accion,params,tamArch);
    accion((*p)->info,(*p)->tamInfo,params,tamArch);
    recorrerEnOrdenArbolBinBusqRecConParams(&(*p)->der,accion,params,tamArch);
}

void recorrerEnOrdenArbolBinBusqRec(const tArbolBinBusq *p, unsigned n, void * params,
                                    void (*accion)(void *,unsigned,unsigned,void *))
{
    if(!*p)
        return;

    recorrerEnOrdenArbolBinBusqRec(&(*p)->izq,n+1,params,accion);
    accion((*p)->info,(*p)->tamInfo,n,params);
    recorrerEnOrdenArbolBinBusqRec(&(*p)->der,n+1,params,accion);
}

void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq *p,void *params,
                                 void(*accion)(void *,unsigned,unsigned,void *))
{
    recorrerEnOrdenArbolBinBusqRec(p,0,params,accion);
}

void recorrerPreOrdenArbolBinBusqRec(const tArbolBinBusq *p, unsigned n, void * params,
                                     void (*accion)(void *,unsigned,unsigned,void *))
{
    if(!*p)
        return;

    accion((*p)->info,(*p)->tamInfo,n,params);
    recorrerPreOrdenArbolBinBusqRec(&(*p)->izq,n+1,params,accion);
    recorrerPreOrdenArbolBinBusqRec(&(*p)->der,n+1,params,accion);
}

void recorrerPreOrdenArbolBinBusq(const tArbolBinBusq *p,void *params,
                                  void(*accion)(void *,unsigned,unsigned,void *))
{
    recorrerPreOrdenArbolBinBusqRec(p,0,params,accion);
}

void recorrerPostOrdenArbolBinBusqRec(const tArbolBinBusq *p, unsigned n, void * params,
                                      void (*accion)(void *,unsigned,unsigned,void *))
{
    if(!*p)
        return;

    recorrerPostOrdenArbolBinBusqRec(&(*p)->izq,n+1,params,accion);
    recorrerPostOrdenArbolBinBusqRec(&(*p)->der,n+1,params,accion);
    accion((*p)->info,(*p)->tamInfo,n,params);
}

void recorrerPostOrdenArbolBinBusq(const tArbolBinBusq *p,void *params,
                                   void(*accion)(void *,unsigned,unsigned,void *))
{
    recorrerPostOrdenArbolBinBusqRec(p,0,params,accion);
}

void recorrerOrdenInversoArbolBinBusqRec(const tArbolBinBusq *p, unsigned n, void * params,
        void (*accion)(void *,unsigned,unsigned,void *))
{
    if(!*p)
        return;

    recorrerOrdenInversoArbolBinBusqRec(&(*p)->der,n+1,params,accion);
    accion((*p)->info,(*p)->tamInfo,n,params);
    recorrerOrdenInversoArbolBinBusqRec(&(*p)->izq,n+1,params,accion);
}

void recorrerOrdenInversoArbolBinBusq(const tArbolBinBusq *p,void *params,
                                      void(*accion)(void *,unsigned,unsigned,void *))
{
    recorrerOrdenInversoArbolBinBusqRec(p,0,params,accion);
}

unsigned alturaArbolBin(const tArbolBinBusq *p)
{
    unsigned hi,hd;

    if(!*p)
        return 0;

    hi = alturaArbolBin(&(*p)->izq) +1;
    hd = alturaArbolBin(&(*p)->der) +1;

    return hi > hd ? hi : hd;
}

tNodoArbol ** menorNodoArbolArbolBinBusqRec(const tArbolBinBusq *p)
{
    if(!*p)
        return NULL;
    if(!(*p)->izq)
        return (tNodoArbol **)p;

    return menorNodoArbolArbolBinBusqRec(&(*p)->izq);
}

tNodoArbol ** mayorNodoArbolArbolBinBusqRec(const tArbolBinBusq *p)
{
    if(!*p)
        return NULL;
    if(!(*p)->der)
        return (tNodoArbol **)p;

    return mayorNodoArbolArbolBinBusqRec(&(*p)->der);
}

tNodoArbol ** buscarNodoArbolBinBusqRec(const tArbolBinBusq *p,const void *d,
                                        int (*cmp)(const void *, const void *))
{
    int rc;

    if(!*p)
        return NULL;

    if(*p && (rc = cmp(d,(*p)->info)) != 0)
    {
        if(rc < 0)
            return buscarNodoArbolBinBusqRec(&(*p)->izq,d,cmp);

        return buscarNodoArbolBinBusqRec(&(*p)->der,d,cmp);
    }

    return (tNodoArbol **)p;
}

int buscarElemArbolBinBusq(const tArbolBinBusq *p,void *d,unsigned tam,
                           int (*cmp)(const void *,const void *))
{
    if(!(p = buscarNodoArbolBinBusqRec(p,d,cmp)))
    {
        return 0;
    }

    memcpy(d,(*p)->info,MINIMO((*p)->tamInfo,tam));
    return TODO_BIEN;
}

/*
int buscarElemMenorArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam,
                                int(*cmp)(const void *, const void *))
{
    const tArbolBinBusq * menor = p;

    if(!*p)
        return 0;

    menor = buscarElemArbolBinBusq(&(*p)->izq,menor,tam,cmp);
    menor = buscarElemArbolBinBusq(&(*p)->der,menor,tam,cmp);

    memcpy(d,(*menor)->info,MINIMO(tam,))

    return TODO_BIEN;
}
*/

int eliminarRaizArbolBinBusq(tArbolBinBusq *p)
{
    tNodoArbol **remp,
               *elim;

    if(!*p)
        return 0;

    free((*p)->info);

    if(!(*p)->izq && !(*p)->der)
    {
        free(*p);
        *p = NULL;
        return TODO_BIEN;
    }

    remp = alturaArbolBin(&(*p)->izq) > alturaArbolBin(&(*p)->der)?
           menorNodoArbolArbolBinBusqRec(&(*p)->izq):
           mayorNodoArbolArbolBinBusqRec(&(*p)->der);//hay que buscar el más grande de los chicos o el más chico de los grandes

    elim = *remp;
    (*p)->info = elim->info;
    (*p)->tamInfo = elim->tamInfo;

    *remp = elim->izq ? elim->izq : elim->der;
    free(elim);

    return TODO_BIEN;
}

int eliminarElemArbolBinBusq(tArbolBinBusq *p,void *d,unsigned tam,
                             int (*cmp)(const void *,const void *))
{
    if(!(p = buscarNodoArbolBinBusqRec(p,d,cmp)))
        return 0; //NO EXISTE

    memcpy(d,(*p)->info,MINIMO(tam,(*p)->tamInfo));
    return eliminarRaizArbolBinBusq(p);
}


void vaciarArbolBinBusq(tArbolBinBusq *p)
{
    if(!*p)
        return;

    vaciarArbolBinBusq(&(*p)->izq);
    vaciarArbolBinBusq(&(*p)->der);

    free((*p)->info);
    free((*p));
    *p = NULL;
}

void podarArbol(tArbolBinBusq *p, unsigned nivel)
{
    if(!*p)
        return;

    if(nivel == 0)
    {
        vaciarArbolBinBusq(p);
    }
    else
    {
        podarArbol(&(*p)->izq,nivel-1);
        podarArbol(&(*p)->der,nivel-1);
    }
}





void vaciarArbolBinBusq(tArbolBinBusq *p)
{
    if(*p == NULL)
        return;


    vaciarArbolBinBusq(&(*p)->izq);
    vaciarArbolBinBusq(&(*p)->der);

    free((*p)->info);
    free((*p));
    *p = NULL;
}


int condicionParaSacarHoja(tArbolBinBusq *p)
{
    return (*p)->izq == NULL && (*p)->der == NULL ? 1 : 0;
}


void podarHojasMIO(tArbolBinBusq *p)
{

    if(*p == NULL)
        return;

    if((*p)->izq == NULL && (*p)->der == NULL)
    {
        free((*p)->info);
        free((*p));
        *p = NULL;
    }
    else
    {
        podarHojasMIO(&(*p)->izq);
        podarHojasMIO(&(*p)->der);
    }
}























void podarHojas(tArbolBinBusq *p) //Elimina los nodos que no tienen ni izq ni derecha
{
    if(!*p)
        return;

    if(!(*p)->izq && !(*p)->der)
    {
        free((*p)->info);
        free(*p);
        *p = NULL;
    }
    else
    {
        podarHojas(&(*p)->izq);
        podarHojas(&(*p)->der);
    }
}

int accionContarPares(const void *info,unsigned tam)
{
    if(tam != sizeof(int))
        return 0;

    if(*(const int *)info % 2 == 0)
    {
        return 1;
    }

    return 0;
}

unsigned cantNodosArbolBinHastaNivel(const tArbolBinBusq *p,unsigned n,
                                     int(*accion)(const void *,unsigned))
{
    if(!*p)
        return 0;

    if(n == 0)
    {
        return 1;
    }

    return cantNodosArbolBinHastaNivel(&(*p)->izq,n-1,accion) +
           cantNodosArbolBinHastaNivel(&(*p)->der,n-1,accion) +
           accion((*p)->info,(*p)->tamInfo);
}


int cmpNodosPares(const void *v1, unsigned tamNodoInfo)
{
    const tProducto *d1 = (tProducto *)v1;

    if(d1->idProducto %2 == 0)
    {
        return 1;
    }

    return 0;
}

int contarNodosCondicion(const tArbolBinBusq *p,
                         int (*cmp)(const void *,unsigned))
{
    if(!*p)
        return 0;

    return contarNodosCondicion(&(*p)->izq,cmp)
           + contarNodosCondicion(&(*p)->der,cmp)
           + cmp((*p)->info,(*p)->tamInfo);
}

int contarNodosCondicionPorLadoIzq(const tArbolBinBusq *p,
                                   int (*cmp)(const void *,unsigned))
{
    if(!*p)
        return 0;

    if((*p)->izq)
    {
        return contarNodosCondicion(&(*p)->izq,cmp)
               + cmp((*p)->info,(*p)->tamInfo); //por la raiz padre si es par
    }

    return cmp((*p)->info,(*p)->tamInfo) != 0 ? 1:0;
}

int esCompletoHastaNivelArbolBin(const tArbolBinBusq * p,unsigned n)
{
    if(!*p)
        return 0;

    if(n == 0)
    {
        return 1;
    }

    return esCompletoHastaNivelArbolBin(&(*p)->izq,n-1) &&
           esCompletoHastaNivelArbolBin(&(*p)->der,n-1);
}

int esArbolCompletoBin(const tArbolBinBusq *p)
{
    return esCompletoHastaNivelArbolBin(p,alturaArbolBin(p)-1); //ya que si no le ponemos el -1, entra nuevamente en un ciclo que no tiene que ir
}

/*
int esCompletoArbolBin2(const tArbolBinBusq *p)
{
    int h = alturaArbolBin(p);

    return cantNodosArbolBin(p) == pow(2,h)-1;
}
*/


int esArbolBalanceadoBin(const tArbolBinBusq * p,unsigned n)
{
    return esCompletoHastaNivelArbolBin(p,alturaArbolBin(p)-2);
}

int esArbolAVLBin(const tArbolBinBusq *p)
{
    int hi,hd;

    if(!*p) //condición de corte, si ya no queda más que recorrer
        return 1;

    hi = alturaArbolBin(&(*p)->izq);
    hd = alturaArbolBin(&(*p)->der);

    if(abs(hi-hd)>1)
        return 0;

    return esArbolAVLBin(&(*p)->izq) &&
           esArbolAVLBin(&(*p)->der);
}
