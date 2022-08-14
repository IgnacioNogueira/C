#include "header.h"
#include "ejercicios.h"

int main()
{

    char opcion;

    do
    {
        printf("\n\n\n\n=======================MENU - UNIDAD 2=======================");
        printf("\n\nA- Ejercicio eliminar letra mas repetida\n");
        printf("\n\nB- Ejercicio 8 - Terminar de resolver cuando veamos lista\n");
        printf("\n\nC- Ejercicio 12\n");

        printf("\n\n\n\n0- SALIR ");
        printf("\n\n\n[INGRESE OPCION]: ");
        fflush(stdin);

        scanf("%c",&opcion);
        opcion = aMayusc(opcion);

        switch(opcion)
        {

        case 'A':
            EjercicioEliminarLetMasRepetida();
            break;

        case 'B':
            ejercicio8();
            break;


        case 'C':
            ejercicio12();
            break;





        case '0':
            return NO;

        default:
            printf("\n\nIngrese una tecla correcta...");

        }

    }
    while(opcion != 0 || opcion == 'A' || opcion == 'B' || opcion == 'C');

    return 0;
}

/*
char letraMasRepetida(const char * str)
{
    int cantLetras[maxmM] = {0}; //como mucho hay 50 letras entre mayus y minus ASCII
    int max = 0;
    char letra = 0;

    if(str == NULL)
        return NO;

    while(*str)
    {
        if(++cantLetras[*str] > max && !ES_BLANCO(*str))
        {
            max = cantLetras[*str];
            letra = *str;
        }
        ++str;
    }

    return letra;
}
*/

