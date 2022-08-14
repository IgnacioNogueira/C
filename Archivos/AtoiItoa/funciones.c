#include "header.h"
#include "strings.h"
#include "funciones.h"

void menu(void)
{
    char opcion;

    do
    {
        printf("\n\n\n\n=======================MENU MATRICES=======================");
        printf("\n\nA- Ejercicio ITOA - ATOI\n");
        printf("\n\nB- Ejercicio Contar Palabras\n");
        printf("\n\nC- Ejercicio Eliminar Palabra más repetida\n");

        printf("\n\n\n\n0- SALIR ");
        printf("\n\n\n[INGRESE OPCION]: ");
        fflush(stdin);

        scanf("%c",&opcion);
        opcion = aMayusc(opcion);

        switch(opcion)
        {

        case 'A':
            EjercicioAtoiItoa();
            break;

        case 'B':
            EjercicioContarPalabras();
            break;


        case 'C':
            EjercicioEliminarPalMasRepetida();
            break;

        case '0':
            exit(10);

        default:
            printf("\n\nNo esta en el abecedario, saliendo del programa...");

        }

    }
    while(opcion == 'A' || opcion == 'B' || opcion == 'C');

}



/*
In the C Programming Language, the atoi function
converts a string to an integer

The atoi function returns
the integer representation of a string.
The atoi function skips all white-space
characters at the beginning of the string,
converts the subsequent characters as part of the number,
and then stops when it encounters the first character that isn't a number.

*/


/*
    Four corner cases needs to be handled:

- Discards all leading whitespaces
- Sign of the number
- Overflow
- Invalid input

*/

void EjercicioAtoiItoa()
{

    printf("\n//////////////Atoi - Itoa//////////////\n");
    int resOrig, restNacho;

    char carStr[tam2] = "-00123abc";

    printf("\nATOI ORIGINAL:");
    resOrig = atoi(carStr);
    printf("%d",resOrig);

    printf("\nATOI NACHO:");
    restNacho = atoiMio(carStr);
    printf("%d",restNacho);

    //itoa () function in C language converts int data type to string data type

    int ent = -123456;
    char Cadc1[tam2];
    char Cadc2[tam2];

    printf("\nITOA ORIGINAL:");
    itoa(ent,Cadc1,10);
    printf("%s",Cadc1);

    printf("\nITOA NACHO:");
    itoaMio(ent,Cadc2,10);
    printf("%s",Cadc2);

}


int atoiMio(const char *cad)
{
    int signo = 1,res = 0;

    while(ES_BLANCO(*cad))
    {
        ++cad;
    }

    if(*cad == '-')
    {
        signo = signo *(-1);
    }

    while(*cad)
    {
        if(*cad >= '0' && *cad <='9')
        {
            res = res * 10 + (*cad - '0');
        }

        ++cad;
    }

    return res * signo ;
}

/*
Individual digits of the given
number must be processed and their
corresponding characters must be put
in the given string.
Using repeated division by the given base,
we get individual digits from least significant
to most significant digit.
But in the output, these digits are needed in reverse order.
Therefore, we reverse the string obtained after repeated division and return it.
*/

char * revertirString(char * cad)
{
    char aux, *p1 = cad;
    int i, tamA = nogueiraStrlen(cad);

    for(i = 0; i< (tamA/2); ++i)  // divido 2 ya que se hacen dos cambios en paralelo
    {
        aux = *(p1+i);
        *(p1+i) = *(p1+tamA-i-1); //h d -> si lo dejas con tamA solo, se va del tam del string, y el -i sirve para seguir iterando en los valores que va a ir reemplazando
        *(p1+tamA-i-1) = aux;
    }


    *p1 = '\0'; //el \0 está mal metido

    return p1;
}


char * itoaMio(int num, char * cad,int base)
{
    int resto;
    char *p1 = cad;

    if(base < 2 || base > 32)
    {
        return NULL;
    }

    if(num == 0)
    {
        *p1 = '0';
        ++p1;
        *p1 = '\0';
        return p1;
    }

    if(num < 0 && base == 10)
    {
        num  = num *(-1);
        *p1 = '-';
        ++p1;
    }

    while(num != 0)
    {

        resto = num % base;

        if(resto >= 10)
        {
            *p1 = 65 +(resto-10);
        }
        else
        {
            *p1 = 48 + resto;
        }

        ++p1;
        num = num /base;

    }


    revertirString(p1);
    //revertirString(cad);

    return p1; //PREGUNTAR
}

void EjercicioContarPalabras()
{

    char str[tam2] = "    hola    pe!pi%%to,   como   estas?           ";
    int cantPalabras;
    printf("\nString: %s",str);

    espacioPrincipioFin(str);
    //printf("\n2-%s-",str);

    sacarCaracteresYnumeros(str);
    //printf("\n3-%s",str);

    unSoloEspacio(str);
    //printf("\n3-%s",str);

    cantPalabras = cantPalabrasOracion(str);

    printf("\n\nLa cantidad de palabras que tiene el string es de: %d\n\n",cantPalabras);

}


void espacioPrincipioFin(char *cad)
{
    char *p1 = cad;
    char *p2 = cad + (nogueiraStrlen(cad)-1);

    while(ES_BLANCO(*p2))
    {
        --p2;
    }

    *(p2+1) = '\0';


    while(ES_BLANCO(*p1))
    {
        p1++;
    }

    nogueiraStrcpy(cad,p1);
}


void sacarCaracteresYnumeros(char *cad)
{
    char * p1 = cad;

    while(*p1)
    {
        if(!ES_LETRA(*p1) && !ES_BLANCO(*p1))//si no es letra
        {
            nogueiraMemmove(p1,p1+1,nogueiraStrlen(p1));
        }
        else
        {
            ++p1;
        }
    }
}



void unSoloEspacio(char * cad)
{
    char *p1 = cad;
    char *p2;

    while( (p2 = nogueiraStrStr(p1,"  ")) != NULL)
    {
        nogueiraMemmove(p2,p2+1,nogueiraStrlen(p2));
    }

}


size_t cantPalabrasOracion(const char * cad)
{
    const char *p1 = cad;
    size_t cantPalabras = 0;

    if(!*cad)
        return 0;

    while(*p1)
    {
        if(ES_BLANCO(*p1))
        {
            cantPalabras++;
        }

        ++p1;
    }

    ++cantPalabras; // por la últ palabra que no tiene espacio

    return cantPalabras;
}


void EjercicioEliminarPalMasRepetida()
{
    char str[tam2] = "   !La calle tiene la   esquina  mal señalada en   la Capital. Por eso, la policia está preocupada!   "; //más repitada: la
    //char str[tam2] = "la la mas la"; //más repitada: la
    int cantPalabras;
    char palMasRepetida;

    printf("\n\nString: %s\n\n",str);

    espacioPrincipioFin(str); /*esto es ilegal supuestamente si no te piden normalizarlo*/
    sacarCaracteresYnumeros(str);
    unSoloEspacio(str);
    textoAMinus(str);
    printf("\n4-%s-",str);

    cantPalabras = cantPalabrasOracion(str);
    printf("\n-La cantidad de palabras es de: %d\n",cantPalabras);

    palMasRepetida = palabraMasRepetida(str,cantPalabras);

    printf("\n-La palabra más repetida es: %s\n",palMasRepetida);

}

void textoAMinus(char *cad) //hay que convertir esto en strlwr
{
    char *p1 = cad;

    while(*p1)
    {
        aMinusc(*p1);
        ++p1;
    }
}


char * palabraMasRepetida(char * cad,size_t cantPal)
{
    int maxCoinc = 1, coincActual = 1, primeraPasada = 1;
    char * p1 = cad;
    char * p2 = cad + (nogueiraStrlen(cad)-1);
    char * p3 = cad;// = cad + i; //para empezar después en por ej: más

    //Primer pal
    //char str[tam2] = "la la mas la";

    char palabra1[24]; //como mucho la long de la palabra más larga en el español es de 23 caract
    char *ocu = palabra1; //en ocu se guarda la primer pal
    nogueiraStrcpyMOD(palabra1,p1); //guardo la primer palabra en

    // Segunda pal

    char palabra2[24]; //como mucho la long de la palabra más larga en el español es de 23 caract
    char *ocu2 = palabra2; //en ocu se guarda la primer pal

    char palabra3[24]; //como mucho la long de la palabra más larga en el español es de 23 caract
    char *ocu3 = palabra3; //en ocu se guarda la primer pal

    while(cantPal)
    {
        while(*p1 && p1 != p2) //Caso 2: se me va del tam de cad
        {
            while(!ES_BLANCO(*p1))
            {
                if(p1 == p2)
                {
                    p1 = p3;// vuelvo a la palabra la (La segunda 'la')
                }

                ++p1;
            }

            if(ES_BLANCO(*p1)) //para la primera vez
            {
                ++p1;
            }

            if(primeraPasada)
            {
                p3 = p1; //se va a la pos de la segunda palabra -> 'segunda la'
                //nogueiraStrcpyMOD(palabra3,p3); //esto es para guardar el estado de la palabra anterior. O sea: "la la mas la" -> 2do la
                primeraPasada--; //es una bandera, mal
            }

            nogueiraStrcpyMOD(palabra2,p1); //tengo la segunda palabras


            if(nogueiraStrcmp(palabra1,palabra2) == 0) // no tiene que entrar acá siempre
            {
                coincActual++;
            }

            ++p1;
        }

        if(coincActual > maxCoinc)
        {
            maxCoinc = coincActual;
            coincActual = 0;
            nogueiraStrcpy(palabra1,palabra3); //esto hay que arreglarlo, porque tendría que empezar la pal 1 en
        }

        primeraPasada = 1; //esto se relaciona con lo comentado arriba de p3
        --cantPal;
    }

    return palabra1; //palabra
}

/*
void palabraMasRepetida(const char * cad)
{
    const char *p1 = cad;
    char *p2;

    //char *palComp; // para comparar más tarde

    char palabras[24]; //como mucho la long de la palabra más larga en el español es de 23 caract
    char *ocu = palabras; //en ocu se guarda la primer pal

    nogueiraStrcpyMOD(palabras,p1); //guardo la primer palabra en

}
*/

char * nogueiraStrcpyMOD(char * dest, const char * orig)
{
    char *p = dest;

    while(*orig && !ES_BLANCO(*orig))
    {
        *dest = *orig;
        ++orig;
        ++dest;
    }

    *dest = '\0';

    return p;
}

