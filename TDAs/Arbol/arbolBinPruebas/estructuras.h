#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#define TODO_OK 1
#define ERROR 0

typedef struct
{
    int dia, mes, anio;
}tFecha;

typedef struct
{
    unsigned long dni;
    char apyn[36];
    char categoria;
    tFecha fechaIngreso;
    float sueldo;
}tEmpleado;

#endif // ESTRUCTURAS_H_INCLUDED
