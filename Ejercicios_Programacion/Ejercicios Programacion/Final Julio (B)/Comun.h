#ifndef COMUN_H
#define COMUN_H

#include <stdlib.h>

#define TODO_OK 0
#define SIN_MEM 1
#define ERR_ARCHIVO 2
#define ERR_LISTA 3

typedef enum
{
    FALSO, VERDADERO
} booleano;

typedef int (*Cmp)(const void*, const void*);
typedef void (*Accion)(const void*, size_t, void*);
typedef int (*Acumular)(void**, size_t*, void*, size_t);

#endif // COMUN_H
