/**//*             en los siguientes macroreemplazos indique:             *//**/
/**//*    su(s)         APELLIDO(S)     completo(s)                       *//**/
/**//*    su(s)         Nombre(S)       completo(s)                       *//**/
/**//*    su legajo     NÚMERO DE DNI   con los puntos de millón y de mil *//**/
/**//*    COMISIÓN                                                        *//**/
/**//*              reemplazando los que están como ejemplo               *//**/
#define APELLIDO    "Nogueira"
#define NOMBRE      "Ignacio Ezequiel"
#define DOCUMENTO   "41.714.018".
#define COMISION    "05(1976)"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** aquí insertaremos nuestras observaciones y / o correcciones              **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#undef APELLIDO
#undef NOMBRE
#undef DOCUMENTO
#undef COMISION
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO DESDE ACÁ *//**/


/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"

#define A_MAYUS(X) ((X) >= 'a' && (X) <= 'z' ? (X)-32 : (X))
#define ES_LETRA_MINUS(X)(((X)>='a' && (X)<='z'))



/** para el PUNTO 1 **/
char *pasarAmayuscula_MIO(char *s)
{
    while(*s)
    {
        if(ES_LETRA_MINUS(*s))
        {
            *s = A_MAYUS(*s);
        }
        ++s;
    }

    return s;

}
/** FIN de PUNTO 1 **/

/** para el PUNTO 2 **/
int apilarDesdeArchivoYdesapilar_MIO(char *nombreArchivo, FILE *fpPantalla)
{
    tPila p;
    tEmpleado emp;
    tEmpleado empAux;
    crearPila(&p);
    int cant = 0;

    FILE *fp = fopen(nombreArchivo,"rb");

    if(!fp)
    {
        return -1;
    }

    fread(&emp,sizeof(tEmpleado),1,fp);
    fprintf(fpPantalla,"Secuencia de apilado:\n");
    while(!feof(fp))
    {
        fprintf(fpPantalla,"%08li %-*.*s %c   %02d/%02d/%04d  %9.2f\n",
                emp.dni,
                (int)sizeof(emp.apyn)-1,
                (int)sizeof(emp.apyn)-1,
                emp.apyn,
                emp.categoria,
                emp.fecIngreso.dia,
                emp.fecIngreso.mes,
                emp.fecIngreso.anio,
                emp.sueldo
               );
        ponerEnPila(&p,&emp,sizeof(tEmpleado));
        fread(&emp,sizeof(tEmpleado),1,fp);
    }

    fprintf(fpPantalla,"\nSecuencia de desapilado:\n");
    while(!pilaVacia(&p))
    {
        sacarDePila(&p,&empAux,sizeof(tEmpleado));
        fprintf(fpPantalla,"%08li %-*.*s %c   %02d/%02d/%04d  %9.2f\n",
                empAux.dni,
                (int)sizeof(empAux.apyn)-1,
                (int)sizeof(empAux.apyn)-1,
                empAux.apyn,
                empAux.categoria,
                empAux.fecIngreso.dia,
                empAux.fecIngreso.mes,
                empAux.fecIngreso.anio,
                empAux.sueldo
               );
               ++cant;
    }

    return cant;
}



/** FIN de PUNTO 2 **/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

