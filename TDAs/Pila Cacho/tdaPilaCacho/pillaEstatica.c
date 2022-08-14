#include "pilaEstatica.h"

void crearPilaEstatica(tPilaE *p)
{
    p->tope = TAM_PILA;

}

int pilaEstaticaLlena(const tPilaE *p,unsigned cantBytes)
{
    return p->tope < cantBytes + sizeof(unsigned); //es el tope < a el dato + el pedacito tipo del tipo de dato que ocupa una porción
}

int pilaEstaticaVacia(const tPilaE *p)
{
    return p->tope == TAM_PILA;
}

int ponerEnPilaEstatica(tPilaE *p,void *d,unsigned cantBytes)
{
    if(p->tope < cantBytes + sizeof(unsigned))
        return 0; //sin espacio para poner en pila

    p->tope-=cantBytes;
    memcpy(p->pila + p->tope,d,cantBytes);
    p->tope-=sizeof(unsigned);
    memcpy(p->pila+p->tope,&cantBytes,sizeof(unsigned));
    return 1;
}
int pilaEstaticaVerTope(const tPilaE *p,void *d,unsigned cantBytes)
{
    unsigned tamInfo;

    if(p->tope == TAM_PILA)
        return 0; //revisa si tiene algo, que no está vacia

    memcpy(&tamInfo,p->pila+p->tope,sizeof(unsigned)); //el pedacito de bloque del tipo de dato
    memcpy(d,p->pila+p->tope + sizeof(unsigned),MINIMO(cantBytes,tamInfo)); //el dato directamente -> el minimo va a buscar por si hay diferentes tipos de tam de datos
    return 1;
}
int sacarDePilaEstatica(tPilaE *p,void *d,unsigned cantBytes)
{
    unsigned tamInfo;

    if(p->tope == TAM_PILA)
        return 0; //no hay nada que sacar - pila vacia

    memcpy(&tamInfo,p->pila+p->tope,sizeof(unsigned));
    p->tope+=sizeof(unsigned); //se ve a partir del dato, es como empezar a ver el verTope
    memcpy(d,p->pila+p->tope,MINIMO(tamInfo,cantBytes));
    p->tope+=tamInfo;

    return 1;
}

void vaciarPilaEstatica(tPilaE *p)
{
    p->tope = TAM_PILA; //esta función basicamente es más capciosa, es como crear, pero con la diferencia que la volvés al lugar de donde empezó (Por eso la vacías)
}

