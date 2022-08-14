#ifndef TDA_DEFINICIONES_H_
#define TDA_DEFINICIONES_H_

/** etiquetas típicas de TDA (salvo para primitivas booleanas) **/
#define CLA_DUP 1
#define SIN_MEM 2
#define TODO_BIEN 0

typedef struct sNodoArbol
{
    void *info;
    unsigned tamInfo;
    struct sNodoArbol *izq,
                      *der;

}tNodoArbol;

typedef tNodoArbol *tArbol;

/** Tipo de dato para TDA Lista doblemente enlazada */
typedef struct sNodo
{
    void           *info;
    unsigned        tamInfo;
    struct sNodo   *ant,
                   *sig;
} tNodoL;

typedef tNodoL *tLista;

#endif // TDA_DEFINICIONES_H_
