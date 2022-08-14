#ifndef TDA_DEFINICIONES_H_
#define TDA_DEFINICIONES_H_

/** etiquetas típicas de TDA (salvo para primitivas booleanas) **/
#define SIN_MEMORIA     0
#define TODO_BIEN       1
#define CLAVE_DUPLICADA 2

/** etiquetas específicas para Punto 1 a.- **/

/** Tipo de dato para TDA Lista  */

typedef struct sNodo
{
    void           *info;
    unsigned        tamInfo;
    struct sNodo   *sig;
} tNodo;
typedef tNodo *tLista;

//PRIMITIVAS

void crearLista(tLista *pl);
int ponerOrdenLista(tLista *pl,const void *pd,unsigned tam,int (*cmp)(const void*, const void*));




#endif // TDA_DEFINICIONES_H_
