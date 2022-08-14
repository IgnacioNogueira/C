#include "header.h"
#define OK 1
#define NO 0
#define cantPosMax 5846
/*
    En un arreglo se informan los n�meros de identificaci�n de una campa�a de vacunaci�n. Este arreglo de informaci�n termina con un valor 0 y a lo sumo tiene de 5846 posiciones.

    Los n�meros de identificaci�n se encuentran en el siguiente intervalo:
    0<id<220

    Desarrollar una funci�n que reciba el arreglo de datos, y retorne el valor del identificador m�ximo.

    El prototipo de la funci�n es el siguiente:
    <definir> maximo(<definir> vec);

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

int analizar2(unsigned char * vec,const unsigned char valor)
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

unsigned char maximoValor(const unsigned char* vec)
{
    unsigned char max = *vec;

    while(*vec)
    {
        if(*vec > max)
        {
            max = *vec;
        }

        ++vec;
    }

    return max;
}
*/
