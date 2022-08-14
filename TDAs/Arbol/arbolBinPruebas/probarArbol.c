#include "probarArbol.h"
#include "arbol.h"

int acumularSueldo(void **info1, unsigned * tam1,const void * info2, unsigned tam2);

int acumularSueldo(void **info1, unsigned * tam1,const void * info2, unsigned tam2)
{
    tEmpleado **d1 = (tEmpleado **)info1;
    tEmpleado *d2 = (tEmpleado *)info2;

    (*d1)->sueldo += d2->sueldo;

    return 1;
}

int probarArbol_1(tArbol *p, const char *nomArch, const char *modoAp)
{
    tEmpleado emp;
    FILE *arch;
    int r;

    if(!abrirArchivo(&arch, nomArch, modoAp))
    {
        return 0;
    }

    fread(&emp, sizeof(tEmpleado), 1, arch);
    while(!feof(arch))
    {
        //ponerEnOrden(p, &emp, sizeof(tEmpleado), compEmp);
        insertarAcumulandoEnArbol(p,&emp,sizeof(tEmpleado),compEmp,NULL);

        fread(&emp, sizeof(tEmpleado), 1, arch);
    }

    mostrarEmpleado(NULL);
    recorrerPreOrden(p, mostrarEmpleado);

    mostrarEmpleado(NULL);
    recorrerEnOrden(p, mostrarEmpleado);

    r = contarNodosCondicion(p,cmpNodosPares);

    printf("\nLa cantidad de nodos pares de los empleados según DNI es de: %d",r);

    r = contarNodosCondicionPorLadoIzq(p,cmpNodosPares);

    printf("\nLa cantidad de nodos pares del lado izq de los empleados según DNI es de: %d",r);

    /*
    printf("%u -->Categoria A\n",contarNodosPorCrit(p,crit));
    printf("%u -->Sueldo Superior a 60k\n",contarNodosPorCrit(p,critSueldo));
    printf("%u -->DNI Superior a 35M\n",contarNodosPorCrit(p,critDni));
    printf("%u -->Cantidad de Perez\n",contarNodosPorCrit(p,critAyN));
    printf("%u -->De 2018\n",contarNodosPorCrit(p,critAn));
    printf("%u -->dia 1 y 15 del es 8\n",contarNodosPorCrit(p,critMesyDia));

    emp.dni = 32321231;
    if(recuperarDeArbol(p, &emp, sizeof(tEmpleado), compEmp))
    {
        printf("\nENCONTRADO, datos del cliente:\n");
        mostrarEmpleado(&emp);
        printf("\n");
    }
    else
    {
        printf("\nNO ENCONTRADO\n");
    }

    podarHastaAltura(p, 4);
    recorrerEnOrden(p, mostrarEmpleado);
    vaciarArbol(p);
    if(arbolVacio(p))
    {
        printf("\nEl arbol quedo vacio\n");
    }*/
    fclose(arch);
    return 1;
}
/*
// aca no puedo recuperarla
int compClave(const void *vCla, const void *vEmp)
{
    unsigned long* dni = (unsigned long*)vCla;
    tEmpleado *emp = (tEmpleado*)vEmp;
    if(emp->dni < dni)
    {
        return -1;
    }
    else if(emp->dni > dni)
    {
        return 1;
    }
    return 0;
}*/
//aca puedo recuperar la informacion
// solamente
int compClave2(const void *vEmp1, const void *vEmp2)
{
    tEmpleado *emp1 = (tEmpleado*)vEmp1;
    tEmpleado *emp2 = (tEmpleado*)vEmp2;
    if(emp1->dni < emp2->dni)
    {
        return -1;
    }
    else if (emp1->dni > emp2->dni)
    {
        return 1;
    }
    return 0;
}
int crit(const void *e)
{
    tEmpleado* emp = (tEmpleado*)e;
    if(emp->categoria == 'A')
    {
        return 1;
    }
    return 0;
}
int critSueldo(const void *e)
{
    tEmpleado* emp=(tEmpleado*)e;
    if(emp->sueldo > 60000)
    {
        return 1;
    }
    return 0;
}
int critDni(const void *e)
{
    tEmpleado* emp=(tEmpleado*)e;
    if(emp->dni >35000000)
    {
        return 1;
    }
    return 0;
}
int critAn(const void *e)
{
    tEmpleado* emp=(tEmpleado*)e;
    if(emp->fechaIngreso.anio == 2018)
    {
        return 1;
    }
    return 0;
}
int critMesyDia(const void *e)
{
    tEmpleado* emp=(tEmpleado*)e;
    if(emp->fechaIngreso.mes == 8 && (emp->fechaIngreso.dia >=1 && emp->fechaIngreso.dia <=15))
    {
        return 1;
    }
    return 0;
}
int critAyN(const void *e)
{
   tEmpleado* emp=(tEmpleado*)e;
   const char *aux = emp->apyn;
   aux = strchr(emp->apyn,' ');
   aux++;//es importante.
    if(strcmp(aux,"montero")== 0)
    {
        return 1;
    }
    return 0;
}
int compEmp(const void *vEmp1, const void *vEmp2)
{
    tEmpleado *emp1 = (tEmpleado*)vEmp1;
    tEmpleado *emp2 = (tEmpleado*)vEmp2;

    // se permiten duplicados
    if(emp1->dni < emp2->dni)
    {
        return -1;
    }
    else if(emp1->dni > emp2->dni)
    {
        return 1;
    }
    return 0;
}
//que termine con " montero"
//dia 1 al 15 y mes 8
