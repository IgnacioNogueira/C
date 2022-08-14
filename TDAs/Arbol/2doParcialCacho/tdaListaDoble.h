#ifndef TDALISTADOBLE_H_INCLUDED
#define TDALISTADOBLE_H_INCLUDED

#define A_MAYUS(X)((X)>='a' && (X)<='z' ? (X)-32:(X))

typedef struct sNodoListaDoble
{
    void *info;
    unsigned tamBytes;
    struct sNodoListaDoble * ant;
    struct sNodoListaDoble * sig;

} tNodoListaDoble;

typedef tNodoListaDoble * tListaD;

void crearListaDoble(tListaD *pl);
int listaVaciaDoble(const tListaD *pl);
int sacarPrimeroListaDoble(tListaD *pl,void *d,unsigned cantBytes);
void vaciarListaDoble(tListaD *pl);
int acumularCantidadNov(void **info,unsigned *tam,
                         const void *info2,unsigned tam2);
int insertarEnOrdenAcum(tListaD *pl,const void *d,unsigned cantBytes,
                        int (*cmp)(const void *,const void *),
                        int (*acum)(void **,unsigned *,const void *,unsigned));
int mostrarDeIzqADer(const tListaD *pl,void (*mostrar)(const void*));

#endif // TDALISTADOBLE_H_INCLUDED
