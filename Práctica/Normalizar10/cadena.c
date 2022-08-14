#include "cadena.h"
#include "string.h"
//"     ju###?=?221An     ,,     Pe1!l22otas   "

void sacarCaracteresYnum(char *nombre)
{
    char * cad = nombre;

    while(*cad)
    {

        if(!ES_LETRA(*cad) && !ES_BLANCO(*cad))//si no es letra
        {
            nogueiraMemmove(cad,cad+1,nogueiraStrlen(cad));
        }
        else
        {
            cad++;
        }
    }
}

//"     ju###?=?221An     ,,     Pe1!l22otas   "
//"     juAn          Pelotas   "

void eliminarEspacioPrincipioFin(char * nombre)
{
    char *p = nombre,
          *p2 = nombre + (nogueiraStrlen(nombre)-1);

    while(ES_BLANCO(*p2))
    {
        p2--;
    }

    *(p2+1) = '\0'; //PREGUNTAR SI SE PUEDE PORQUE NO ME LO PONÍA AL FINAL DE LA CAD EL *P2


    while(ES_BLANCO(*p))
    {
        p++;
    }

    nogueiraStrcpy(nombre,p); // Como no sabemos la longitud de la cadena por la cant de espacios que puede haber, usamos strcpy y no memmove (FIJARSE QUE 13/4 DEJÉ UNOS SCREENS EN WPP QUE EXPLICAN TODO MEJOR)
}

//juAn,          Pelotas\0 //10
//juAn  Pelotas\0
/*
void unicoEspacio(char *nombre)
{
    char *p = nombre,
    *p2;

    while((p2 = nogueiraStrStr(p,"  "))!= NULL){
        nogueiraMemmove(p2,p2+1,nogueiraStrlen(p2));
    }
}
*/

void moverEspacios(char *nombre)
{
    char *p = nombre,
          *p2;

    while((p2 = nogueiraStrStr(p,"   "))!= NULL)
    {
        nogueiraMemmove(p2,p2+1,nogueiraStrlen(p2));
    }
}


void comaNombre(char * nombre)
{

    while(!ES_BLANCO(*nombre))
    {
        nombre++;
    }
    *(nombre) = ',';
}

void CamelCase(char * nombre)
{
    char * p = nombre;

    aMayus(*p); // Primer letra

    while(*p != ',')
    {
        p++;
        aMinus(*p);
    }

    p+=2;

    aMayus(*p);

    while(*p)
    {
        p++;
        aMinus(*p);
    }
}


/*
void eliminarEspacioPrincipioFin(char * nombre)
{
    char *pIni = nombre,
         *pFin = nombre + (nogueiraStrlen(nombre) - 1);

    while(*pIni == ' ')
    {
        if(!ES_LETRA(*(char *)(pIni+1)))
        {
            nogueiraMemmove(pIni+1,pIni,nogueiraStrlen(pIni));
        }
    }
    while(*pFin == ' ')
    {
        if(!ES_LETRA(*(char *)(pFin-1)))
        {
            nogueiraMemmove(pFin,pFin-1,nogueiraStrlen(pFin));
        }
    }
}



void sacarCaracteres(char *nombre)
{
    char * cad = nombre;

    while(*cad)
    {
        if(!ES_LETRA(*cad) || !ES_BLANCO(*cad) || *(cad) != ',')//letra, espacio o coma
        {
            memmove(cad,cad+1,nogueiraStrlen(cad));
        }
        else
        {
            cad++;
        }
    }
}
*/


