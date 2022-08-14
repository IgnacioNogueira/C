#ifndef COMUN_H
#define COMUN_H


#define TODO_OK 0
#define ERR_ARCHIVO 1
#define SIN_MEM 2
#define DUPLICADO 3


typedef enum
{
    falso,
    verdadero
}
booleano;


typedef int (*Cmp)(const void* e1, const void* e2);

typedef int (*Condicion)(const void* elem);

typedef void (*Actualizar)(void* actualizado, const void* actualizador);

typedef void (*Accion)(void* elem, void* datosAccion);


#endif // COMUN_H
