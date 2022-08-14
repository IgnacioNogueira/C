#ifndef TDADEFINICIONES_H_INCLUDED
#define TDADEFINICIONES_H_INCLUDED

#define CLA_DUP 0
#define SIN_MEM 2

#define MINIMO(X,Y)((X) <= (Y) ? (X):(Y))

typedef struct sNodoArbol
{
    void *info;
    unsigned tamInfo;
    struct sNodoArbol *izq;
    struct sNodoArbol *der;

} tNodoArbol;

typedef tNodoArbol *tArbolBinBusq;

typedef struct sNodoLista
{
    void *info;
    unsigned tamInfo;
    struct sNodoLista *sig;

}tNodoLista;

typedef tNodoLista *tLista;

#endif // TDADEFINICIONES_H_INCLUDED
