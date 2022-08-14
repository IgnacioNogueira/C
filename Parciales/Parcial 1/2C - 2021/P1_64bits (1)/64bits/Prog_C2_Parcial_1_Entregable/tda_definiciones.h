#ifndef TDA_DEFINICIONES_H_
#define TDA_DEFINICIONES_H_

/** etiquetas típicas de TDA (salvo para primitivas booleanas) **/
#define SIN_MEMORIA     0
#define TODO_BIEN       1
#define CLAVE_DUPLICADA 2


/** Tipo de dato para TDA Lista  */
typedef struct sNodoL
{
    void           *info;
    unsigned        tamInfo;
    struct sNodoL   *sig;
} tNodoL;
typedef tNodoL *tLista;



#endif // TDA_DEFINICIONES_H_
