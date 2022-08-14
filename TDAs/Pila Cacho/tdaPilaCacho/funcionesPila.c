#include "funcionesPila.h"

///asumimos que las cadenas contienen SOLO numeros

char sumarValores(char valorPila1, char valorPila2,unsigned char *carry)
{
    char resultado = valorPila1 + valorPila2 - '0' + *carry;

    if(resultado > '9')
    {
        *carry = 1;
        resultado-=10; //para ponerlo lo más cercano a 0 el valorcito de ese pedazo de la cuenta
    }
    else
    {
        *carry = 0;
    }

    return resultado;
}


void valoresRestantes(tPilaD *pil, unsigned char * carry, tPilaD *pil3)
{
    char valor;
    char resultado;

    while(!pilaDinVacia(pil))
    {
        sacarPilaDinamica(pil,&valor,sizeof(char));
        resultado = sumarValores(valor,'0',carry);
        ponerEnPilaDinamica(pil3,&resultado,sizeof(char));
    }
}

char * sumarNGrandes (char * n1,char * n2, char * resultado)
{
    tPilaD pila1;
    tPilaD pila2;
    tPilaD pila3;
    char suma;
    unsigned char carry = 0;
    char valorPila1;
    char valorPila2;
    char * valorResIni = resultado;

    crearPilaDinamica(&pila1);
    crearPilaDinamica(&pila2);
    crearPilaDinamica(&pila3);

    while(*n1)
    {
        ponerEnPilaDinamica(&pila1,n1,sizeof(char));
        ++n1;
    }

    while(*n2)
    {
        ponerEnPilaDinamica(&pila2,n2,sizeof(char));
        ++n2;
    }

    ///

    while(!pilaDinVacia(&pila1) && !pilaDinVacia(&pila2))
    {
        sacarPilaDinamica(&pila1,&valorPila1,sizeof(char));
        sacarPilaDinamica(&pila2,&valorPila2,sizeof(char));

        suma = sumarValores(valorPila1,valorPila2,&carry);

        ponerEnPilaDinamica(&pila3,&suma,sizeof(char));

    }

    valoresRestantes(&pila1,&carry,&pila3);
    valoresRestantes(&pila2,&carry,&pila3);

    if(carry == 1)
    {
        carry = '1'; /// 9999 + 1 = 1 0000
        ponerEnPilaDinamica(&pila3,&carry,sizeof(char));
    }

    while(!pilaDinVacia(&pila3))
    {
        sacarPilaDinamica(&pila3,resultado,sizeof(char)); //lo pone en el buffer resultado
        ++resultado;
    }

    *resultado = '\0';

    return valorResIni;
}
