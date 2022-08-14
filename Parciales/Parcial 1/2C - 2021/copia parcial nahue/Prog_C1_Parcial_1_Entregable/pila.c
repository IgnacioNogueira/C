#include "pila.h"
#include "funciones.h"

void crearPilaDin(Pila *pil)
{
    *pil = NULL;
}

void vaciarPilaDin(Pila *pil)
{
    while(*pil)
    {
        tNodo2 *aux= *pil;

        *pil = aux ->sig;

        free(aux->info);
        free(aux);
    }

}

int PilaLlenaDin(const Pila *pil,unsigned cantBytes)
{
    Pila *aux= (Pila *) malloc(sizeof(Pila));
    void *info= malloc(cantBytes);

    free(aux);
    free(info);

    return aux == NULL || info == NULL; //retorna 1 si alguno de los dos no se pudo asignar sea por lo que fuese
}

int PilaVaciaDin(const Pila *pil)
{
    return pil == NULL ? CORRECTO : INCORRECTO;
}

int ponerEnPilaDin(Pila *pil,const void *d,unsigned cantBytes)
{
    tNodo2* nue = (tNodo2*) malloc(sizeof(tNodo));
    nue->info = malloc(cantBytes);

    if(!nue || !nue->info)
    {
        free(nue);
        return INCORRECTO;

    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo =cantBytes;
    nue->sig=*pil;

    *pil=nue;

    return CORRECTO;
}

int verTopeDin(const Pila *pil,void *d,unsigned cantBytes)
{
    if(PilaVaciaDin(pil)) ///CORREGIR NO LLAMAR PRIMITIVAS DENTRO DE PRIMITIVAS
    {
        return INCORRECTO;
    }

    memcpy(d,(*pil)->info,MINIMO(cantBytes, (*pil)->tamInfo));
    return CORRECTO;
}

int desapilarEnPilaDin(Pila *pil,void *d,unsigned cantBytes)
{
    tNodo2 *aux= *pil;

    if(aux == NULL) // Si no hay nada en la pila
    {
        return INCORRECTO;
    }

    *pil=aux->sig;

    memcpy(d,aux->info,MINIMO(cantBytes,aux->tamInfo));

    free(aux->info);
    free(aux);

    return CORRECTO;
}
