#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "funciones.h"


#define CORRECTO 1
#define INCORRECTO 0

#define TAM_PILA 340
#define TAM_LINEA 500

#define MINIMO(X,Y) ( (X)<(Y) ? X : Y)
//Dinámica

typedef struct sNodo2
{
    void *info; ///GUARDO LA INFO ACÁ DE CUALQUIER TIPO
    unsigned tamInfo; /// TAM DEL DATO PARA NO CASTEAR
    struct sNodo2 *sig; ///PUNTERO AL SIG NODO

}tNodo2;

typedef tNodo2 *Pila; ///ALIAS - Puntero a tNodo -DINAMIC

void crearPilaDin(Pila *pil);
void vaciarPilaDin(Pila *pil);
int PilaLlenaDin(const Pila *pil,unsigned cantBytes);
int PilaVaciaDin(const Pila *pil);
int ponerEnPilaDin(Pila *pil,const void *d,unsigned cantBytes);
int verTopeDin(const Pila *pil,void *d,unsigned cantBytes);
int desapilarEnPilaDin(Pila *pil,void *d,unsigned cantBytes);


#endif // PILA_H_INCLUDED
