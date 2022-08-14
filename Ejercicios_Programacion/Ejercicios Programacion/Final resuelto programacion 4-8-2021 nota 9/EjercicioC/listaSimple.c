#include "listaSimple.h"

#define MINIMO(X, Y) ((X)<=(Y)? (X):(Y))

void crearLista(tLista *p) {
    *p = NULL;
}

int listaVacia(const tLista *p) {
    return *p == NULL;
}

int listaLlena(const tLista *p, unsigned cantBytes) {
    tNodo *aux = (tNodo *) malloc(sizeof(tNodo));
    void *info = malloc(cantBytes);
    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

/*
void vaciarLista(tLista* p)
{
    while(*p)
    {
        tNodo *aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}

*/

int vaciarLista(tLista *p) {
    int cant = 0;
    while (*p) {
        tNodo *aux = *p;
        cant++;
        *p = aux->sig;
        free(aux->info);
        free(aux);

    }
    return cant;
}

int ponerAlComienzo(tLista *p, const void *d, unsigned cantBytes) {
    tNodo *nue;
    if ((nue = (tNodo *) malloc(sizeof(tNodo))) == NULL ||
        (nue->info = malloc(cantBytes)) == NULL) {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes) {
    tNodo *aux = *p;
    if (aux == NULL)
        return 0;
    *p = aux->sig;
    memcpy(d, aux->info, MINIMO(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}

int verPrimeroLista(const tLista *p, void *d, unsigned cantBytes) {
    if (*p == NULL)
        return 0;
    memcpy(d, (*p)->info, MINIMO(cantBytes, (*p)->tamInfo));
    return 1;
}

int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes) {
    tNodo *nue;
    while (*p)
        p = &(*p)->sig;
    if ((nue = (tNodo *) malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(cantBytes)) == NULL) {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    *p = nue;
    return 1;
}

int sacarUltimoDeLista(tLista *p, void *d, unsigned cantBytes) {
    if (*p == NULL)
        return 0;
    while ((*p)->sig)
        p = &(*p)->sig;
    memcpy(d, (*p)->info, MINIMO(cantBytes, (*p)->tamInfo));
    free((*p)->info);
    free(*p);
    *p = NULL;
    return 1;
}

int verUltimoLista(const tLista *p, void *d, unsigned cantBytes) {
    if (*p == NULL)
        return 0;
    while ((*p)->sig)
        p = &(*p)->sig;
    memcpy(d, (*p)->info, MINIMO(cantBytes, (*p)->tamInfo));
    return 1;
}

int vaciarListaYMostrar(tLista *p, void (*mostrar)(const void *, FILE *), FILE *fp) {
    int cant = 0;
    while (*p) /// mientras hay nodo
    {
        tNodo *aux = *p; /// "memoriza" adonde está
        cant++;        ///lo contabiliza
        *p = aux->sig;  /// lo desengancha
        if (mostrar && fp)/// no fallará si no recibe la función o el archivo
            mostrar(aux->info, fp);/// muestra el elemento
        free(aux->info); ///libera la memoria del elemento
        free(aux);///libera la memoria del nodo
    }
    return cant;
}

int ponerEnOrden(tLista *p, const void *d, unsigned cantBytes,
                 int (*comparar)(const void *, const void *),
                 int (*acumular)(void **, unsigned *, const void *, unsigned)) {
    tNodo *nue;
    while (*p && comparar((*p)->info, d) < 0)///avanza por la lista buscando el lugar de inserción
        p = &(*p)->sig;
    if (*p && comparar((*p)->info, d) == 0) {
        if (acumular)
            if (!acumular(&(*p)->info, &(*p)->tamInfo, d, cantBytes))
                return SIN_MEM;
        return CLA_DUP;
    }
    if ((nue = (tNodo *) malloc(sizeof(tNodo))) == NULL ||
        (nue->info = malloc(cantBytes)) == NULL) {
        free(nue);
        return SIN_MEM;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return TODO_BIEN;
}

void ordenar(tLista *p, int(*comparar)(const void *, const void *)) {
    tLista *pri = p; ///pri siempre mantendrá la direccion del 1° de la lista
    if (*p == NULL) ///si no hay lista no hay nada que hacer
        return;
    while ((*p)->sig) ///mientras haya siguiente
    {
        if (comparar((*p)->info, (*p)->sig->info) > 0) ///si el actual es mayor que su sig
        {
            tLista *q = pri; ///prepara comenzar desde el inicio de la lista
            tNodo *aux = (*p)->sig;///toma la direccion del nodo
            (*p)->sig = aux->sig; ///lo desvincula de la lista
            while (comparar((*q)->info, aux->info) > 0) ///avanza buscando el lugar de insercion
                q = &(*q)->sig;
            aux->sig = *q;///vincula el nodo en la lista
            *q = aux;
        } else
            p = &(*p)->sig;///avanza si no tuvo que hacer lo anterior
    }

}

int recorrerLista(tLista *p, void *params,
                  void (*accion)(void *dato, unsigned tam, void
                  *params)) {
    if (!*p) {
        return 0;
    }
    while (*p) {
        accion((*p)->info, (*p)->tamInfo, params);
        p = &(*p)->sig;
    }
    return 1;
}

int sacarPorClave(tLista *p, const void *d, unsigned int cantBytes, int (*comparar)(const void *, const void *)) {
    tNodo *elim;
    if (comparar((*p)->info, d) == 0) {
        elim = *p;
        *p = elim->sig;
        free(elim->info);
        free(elim);
        return 1;
    }
    while ((*p)->sig) {
        if (comparar((*p)->sig->info, d) == 0) {
            elim = (*p)->sig;
            (*p)->sig = elim->sig;
            free(elim->info);
            free(elim);
            return 1;
        }
        p = &(*p)->sig;
    }
    return 0;
}
