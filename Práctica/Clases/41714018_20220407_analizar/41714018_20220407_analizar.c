#include "header.h"
#define OK 1
#define NO 0
#define cantPosMax 5846


/*
    Los n�meros de identificaci�n se encuentran en el siguiente intervalo:
    0<id<220

    - Desarrollar una funci�n que reciba el arreglo de datos, y a partir de un identificador recibido por par�metro retorne si existe el identificador en el arreglo de datos y tambi�n
    - �ndique la cantidad de veces que dicho identificador aparece en el arreglo.
    - Tambi�n debe calcular la �ltima posici�n donde se ha encontrado dicho identificador.

    El prototipo de la funci�n es el siguiente:
    int analizar(<definir> vec, <definir> valor,  �);

*/

size_t contarElementos(const unsigned char * p)
{
    size_t n = 0;
    while(*p)
    {
        ++n;
        ++p;
    }
    return n;
}


int analizar(unsigned char * vec,const unsigned char valor)
{
    size_t cantCoinc = 0;
    size_t cantPos = contarElementos(vec);
    int p = 0,i = 0;

     if((valor < 0 && valor > 220) || cantPos > cantPosMax)
        return NO;

    while(*vec)
    {
        if(valor == *vec)
        {
            ++cantCoinc;
            p = i;

        }

        ++i;
        ++vec;
    }

    if(cantCoinc == 0)
        return NO;

    printf("\n- La ultima posicion en la que se encuentra el elem %d es en la posicion %d\n",valor,p+1);

    return cantCoinc;
}
