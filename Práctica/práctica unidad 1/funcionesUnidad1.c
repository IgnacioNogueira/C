#include "header.h"

void menu(void)
{
    char opcion;

    do
    {
        printf("\n\n\n\n=======================MENU VECTORES=======================");
        printf("\n\nA- Ejercicio 1");
        printf("\n\nB- Ejercicio 2");
        printf("\n\nC- Ejercicio 3");
        printf("\n\nD- Ejercicio 4");
        printf("\n\nE- Ejercicio 5");
        printf("\n\nF- Ejercicio 6");
        printf("\n\nG- Ejercicio 7");
        printf("\n\nH- Ejercicio 8");
        printf("\n\nI- Ejercicio 9");
        printf("\n\nJ- Ejercicio 14");
        printf("\n\nK- Ejercicio 15");
        printf("\n\nL- Ejercicio 16");
        printf("\n\nM- Ejercicio 17");
        printf("\n\nN- Ejercicio 18");
        printf("\n\nQ- Ejercicio 22");
        printf("\n\nR- Ejercicio 23");
        printf("\n\nS- Ejercicio 24");
        printf("\n\nT- Ejercicio 26");
        printf("\n\nU- Ejercicio 27");



        printf("\n\n\n\n0- SALIR ");
        printf("\n\n\n[INGRESE OPCION]: ");
        fflush(stdin);

        scanf("%c", &opcion);
        opcion = aMayusc(opcion);

        switch(opcion)
        {
        case 'A':
            ejercicio1();
            break;

        case 'B':
            ejercicio2();
            break;

        case 'C':
            ejercicio3();
            break;

        case 'D':
            ejercicio4();
            break;

        case 'E':
            ejercicio5();
            break;

        case 'F':
            ejercicio6();
            break;

        case 'G':
            ejercicio7();
            break;

        case 'H':
            ejercicio8();
            break;

        case 'I':
            ejercicio9();
            break;

        case 'J':
            ejercicio14();
            break;

        case 'K':
            ejercicio15();
            break;

        case 'L':
            ejercicio16();
            break;

        case 'M':
            ejercicio17();
            break;

        case 'N':
            ejercicio18();
            break;

        //case 'O':
        //ejercicio19();

        //case 'P':
        //    ejercicio22();


        case 'Q':
            ejercicio22();


        case 'R':
            ejercicio23();

        case 'S':
            ejercicio24();

        case 'T':
            ejercicio26();

        case 'U':
            ejercicio27();

        /*
        case 'V':
            ejercicio27();

        case 'V':
        ejercicio27();

        case 'W':
        ejercicio28();

        */
        case '0':
            exit(10);

        default:
            printf("\n\nNo existe esa opcion.");
        }
    }
    while(opcion == 'A' || opcion == 'B' || opcion == 'C' || opcion == 'D'
            || opcion == 'E' || opcion == 'F' || opcion == 'G' || opcion == 'H'
            || opcion == 'I' || opcion == 'J' || opcion == 'K' || opcion == 'L'
            || opcion == 'M' || opcion == 'N' || opcion == 'O' || opcion == 'P'
            || opcion == 'Q' || opcion == 'R' || opcion == 'S' || opcion == 'T'
            || opcion == 'U' || opcion == 'V' || opcion == 'W'
         );
}

void ejercicio1()
{

    double nro,factorial = 1;
    int i;

    printf("\n///FACTORIAL///\n");
    printf("\nIngrese un nro: ");
    scanf("%lf",&nro);

    if(nro < 0)
        exit(printf("nro es < 0 mal"));

    for(i=nro; i>0; i--)
    {
        factorial = factorial * i;
    }

    printf("El factorial de %.0lf es: %.0lf",nro,factorial);
}

// o función rápida
double fact(int nro)
{
    double factorial = 1;
    int i;

    if(nro < 0)
        return -1;

    for(i=nro; i>0; i--)
    {
        factorial = factorial * i;
    }
    return factorial;
}

void ejercicio2()
{

    printf("\n///COMBINATORIA///\n");

    double nro1,nro2, resultado ;

    printf("\nIngrese primer nro: ");
    scanf("%lf",&nro1);

    printf("\nIngrese segundo nro: ");
    scanf("%lf",&nro2);

    if(nro1 >= nro2 && nro2 >=0)
        resultado = fact(nro1)/(fact(nro2)*fact(nro1-nro2));
    else
    {
        exit(printf("Tas ingresando mal los valores pibe, fijate bien -> m >=n y n >= 0"));
    }

    printf("\nEl resultado de la combinatoria es: %.2lf",resultado);

}

// o función rápida
double combinatoria(double m, double n)
{
    if(m < n || m <0)
        return 0;

    return fact(m)/(fact(n)*fact(m-n));
}

void ejercicio3()
{

    int x;
    double tol = 0.000001,r;

    printf("\nIngrese el valor de x: ");
    scanf("%d",&x);

    r = eAlaX(x,tol);

    printf("\ne^%d = %lf",x,r);

}

double eAlaX(int x,double tol)
{
    int i=1;
    double d=1, result = 1;

    while(d>tol)
    {
        d = potencia(x,i)/fact(i);
        result+=d;
        i++; //se termina cuando se obtiene un término calculado que sea menor que TOL
        // por eso la i se va aumentando, para agregar suma de niveles
    }

    return result;
}

double potencia (float x,int p)
{
    int i;
    double N=1;
    for(i=0; i<p; i++)
    {
        N*=x;
    }
    return N;
}

void ejercicio4()
{

    printf("\nEn el proximo parche sale");

}

void ejercicio5()
{
    int n;
    printf("Digite el numero de elementos: ");
    scanf("%d",&n);

    printf("1 ");
    fibonacci(n);

}

void fibonacci(int n)
{
    int z = 1,y=1,x=0,i;

    for(i = 1; i < n; i++)
    {
        z = x + y;
        x = y;
        y = z;

        printf("%d ",z);
    }

}

void ejercicio6()
{

    printf("\nEn el proximo parche sale");

}

void ejercicio7()
{
    /*
        /// Desarrollar una función que determine si un número natural es perfecto, deficiente o abundante ///

       - Los números perfectos son aquellos iguales a la suma de sus divisores: 6 se puede dividir por 1, 2 y 3, y cuando sumas esos números, el resultado es 6
       - Un número deficiente es un número natural que es mayor que la suma de sus divisores propios exceptuándose a sí mismo.
       - un número abundante o número excesivo es un número para el cual la suma de todos los divisores es mayor que el doble del número. Para 20 todos los divisores son el 1, 2, 4, 5, 10 y 20. Si sumamos estos números 1+2+4+5+10+20= 42 que es mayor que 2×20 = 40.
    */
    int nro;

    printf("\nIngrese el nro para determinar que tipo es: ");
    scanf("%d",&nro);

    tipoNro(nro);
}

void tipoNro(int nro)
{
    int i,suma = 0;

    for(i = 1; i < nro; i++)
    {
        if(nro%i == 0)
        {
            suma+=i;
        }
    }

    printf("suma de nro %d: %d",nro,suma);

    if(suma == nro)
    {
        printf("\nEl nro %d es PERFECTO",nro);

    }
    else if(suma < nro)
    {
        printf("\nEl nro %d es DEFICIENTE",nro);
    }
    else if(suma > nro)
    {
        printf("\nEl nro %d es ABUNDANTE",nro);
    }
}

void ejercicio8()
{

    printf("\nEn el proximo parche sale");

}

void ejercicio9()
{
    int divis,divid;
    printf("\nIngrese el divisor: ");
    scanf("%d",&divis);

    printf("\nIngrese el dividendo: ");
    scanf("%d",&divid);

    sacarRestoYDivisor(divis,divid);

}

void sacarRestoYDivisor(int divis, int divid)
{
    // Esto se va a hacer mediante resta sucesivas -> si a >= b, se va a seguir restando (eso aplica para el cociente)
    int co;

    while(divis >= divid)
    {
        divis-=divid;
        co++;
    }

    printf("\n-El cociente es: %d",co);
    printf("\n-El resto es: %d",divis);

}

void ejercicio14()
{
    //fecha correcta
    tFecha fecha;
    ingresarFecha(&fecha);

    if(fechaCorrecta(&fecha))
    {
        printf("\nLa fecha es CORRECTA");
    }
    else
    {
        printf("\nLa fecha es INCORRECTA");
    }


}

void ingresarFecha(tFecha * fecha)
{
    do
    {
        fflush(stdin);
        printf("\nIngrese el dia: ");
        scanf("%d",&fecha->dia);

        fflush(stdin);
        printf("\nIngrese el mes: ");
        scanf("%d",&fecha->mes);

        fflush(stdin);
        printf("\nIngrese el anio: ");
        scanf("%d",&fecha->anio);

    }
    while(!fechaCorrecta(fecha));
}

int fechaCorrecta(const tFecha * fecha)
{
    if(fecha->anio > 1600)
        if(fecha->mes >= 1 && fecha->mes <=12)
            if(fecha->dia >= 1 && fecha->dia <= cantDiasMes(fecha->mes,fecha->anio))
                return OK;
    return NO;
}

int cantDiasMes(const int mes, const int anio)
{
    int cantDias[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };
    return cantDias[esBisiesto(anio)][mes-1]; //-1 para empezar en el dia 31 y no en el 28
}

int esBisiesto(const int anio)
{
    if( (anio%4 == 0 && anio%100 != 0) || (anio%400 == 0))
        return OK;

    return NO;
}


void ejercicio15()
{
    tFecha fecha;
    ingresarFecha(&fecha);
    printf("\n\n-Fecha original:\n\n");
    mostrarFecha(&fecha);
    fechaSiguiente(&fecha);
    printf("\n\n-Fecha +1 dia:\n\n");
    mostrarFecha(&fecha);
}

void fechaSiguiente(tFecha * fecha)
{
    //dias limites: 30 - 31 - 28 - 29

    if(fechaCorrecta(fecha))
    {
        //12 04 1999
        if(fecha->dia == 31)
        {
            if(fecha->mes == 12)
            {
                fecha->anio++;
                fecha->mes = 1;
                fecha->dia = 0;

            }
            else if(fecha->mes == 3 || fecha->mes == 5 || fecha->mes == 7 || fecha->mes == 8 || fecha->mes == 10)
            {
                fecha->mes++;
                fecha->dia=0;
            }
            else  //por el problema que tiene diciembre con enero
            {
                fecha->mes++;
                fecha->dia=0;
            }
        }
        else if(fecha->dia == 30)
        {
            if(fecha->mes == 4 || fecha->mes == 6 || fecha->mes == 9 || fecha->mes == 11)
            {
                fecha->dia = 0;
                fecha->mes++;
            }
        }

        if(fecha->mes == 2)
        {

            if(fecha->dia == 29 && esBisiesto(fecha->anio))
            {
                fecha->dia = 0; // ya que abajo se suma solito
                fecha->mes = 3;
            }
            else if(fecha->dia == 28 && !esBisiesto(fecha->anio))
            {
                fecha->dia = 0;
                fecha->mes = 3;
            }
        }

        fecha->dia++; // todo va acá si no son los meses border -> bisiesto
    }
}


void mostrarFecha(tFecha * fecha)
{

    printf("Fecha: %d/%d/%d",fecha->dia,fecha->mes,fecha->anio);
}

void ejercicio16()
{
    int dias;
    tFecha fecha;
    ingresarFecha(&fecha);
    printf("\n\n-Fecha original:\n\n");
    mostrarFecha(&fecha);
    printf("\n\nIngrese los días que quiere SUMAR:\n\n");
    scanf("%d",&dias);
    sumaNdiasFecha(&fecha,dias);
    printf("\n\n-Fecha sumada:\n\n");
    mostrarFecha(&fecha);
}

void sumaNdiasFecha(tFecha * fecha, int dias)
{
    while(dias)
    {

        fecha->dia++;

        if(fecha->dia > cantDiasMes(fecha->mes,fecha->anio))
        {
            fecha->dia=1;
            fecha->mes++;
        }

        if(fecha->mes > 12)
        {
            fecha->mes = 1;
            fecha->anio++;
        }

        dias--;
    }
}


void ejercicio17()
{

    int dias;
    tFecha fecha;
    ingresarFecha(&fecha);
    printf("\n\n-Fecha original:\n\n");
    mostrarFecha(&fecha);
    printf("\n\nIngrese los días que quiere RESTAR:\n\n");
    scanf("%d",&dias);
    restaNdiasFecha(&fecha,dias);
    printf("\n\n-Fecha restada:\n\n");
    mostrarFecha(&fecha);

}

void restaNdiasFecha(tFecha * fecha, int dias)
{
    while(dias)
    {
        fecha->dia--;
        if(fecha->dia < 1)
        {
            fecha->dia = cantDiasMes(fecha->mes,fecha->anio);
            fecha->mes--;

            if(fecha->mes < 1)
            {
                fecha->mes = 12;
                fecha->anio--;
                fecha->dia = cantDiasMes(fecha->mes,fecha->anio); //para darle los dias
            }
        }
        dias--;
    }
}


void ejercicio18()
{

    tFecha fecha1,fecha2;
    printf("\n-Ingrese la primer fecha:\n");
    ingresarFecha(&fecha1);
    printf("\n-Ingrese la segunda fecha:\n");
    ingresarFecha(&fecha2);
    printf("\n\n-Para demostrar que quedo todo bien (Fecha 1):\n");
    mostrarFecha(&fecha1);
    printf("\n\n-Para demostrar que quedo todo bien (Fecha 2):\n");
    mostrarFecha(&fecha2);

    cantDiasDifEntreDosFechas(&fecha1,&fecha2);

}

void cantDiasDifEntreDosFechas(tFecha * fecha1, tFecha * fecha2)
{

    int cantDias = 0;

    if(fecha1->anio == fecha2->anio)
    {
        if(fecha1->mes == fecha2->mes)
        {
            cantDias = modulo(fecha1->dia - fecha2->dia);
        }
        else if(fecha1->mes > fecha2->mes)  // ej: 2022/05/15 > 2022/04/15
        {
            while(fecha2->mes < fecha1->mes || fecha2->dia < fecha1->dia)
            {
                if(fecha1->dia < 1)
                {
                    fecha1->mes--;
                    fecha1->dia = cantDiasMes(fecha1->mes,fecha1->anio);
                }
                cantDias++;
                fecha1->dia--;
            }
        }
        else  //2022/04/15 < 2022/05/15
        {
            while(fecha1->mes < fecha2->mes || fecha1->dia < fecha2->dia)
            {
                if(fecha1->dia > cantDiasMes(fecha1->mes,fecha1->anio))
                {
                    fecha1->mes++;
                    fecha1->dia = 1;
                }
                cantDias++;
                fecha1->dia++;
            }
        }
    }
    else if(fecha1->anio < fecha2->anio)  //2022/05/15 < 2023/05/16
    {

        while(fecha1->anio != fecha2->anio || fecha1->mes != fecha2->mes || fecha1->dia != fecha2->dia)
        {
            if(fecha1->dia > cantDiasMes(fecha1->mes,fecha1->anio))
            {
                fecha1->dia = 1;
                fecha1->mes++;
            }

            if(fecha1->mes > 12) // (1)
            {
                fecha1->anio++;
                fecha1->mes = 1;
                fecha1->dia = 1;
            }

            cantDias++;
            fecha1->dia++;

        }

    }
    else  //2023/05/15 > 2022/05/16
    {
        while(fecha2->anio != fecha1->anio || fecha2->mes != fecha1->mes || fecha2->dia != fecha1->dia)
        {
            if(fecha1->dia < 1)
            {
                fecha1->mes--;
                fecha1->dia = cantDiasMes(fecha1->mes,fecha1->anio);
            }

            if(fecha1->mes < 1) // (1)
            {
                fecha1->anio--;
                fecha1->mes = 12;
                fecha1->dia = 31;
            }

            cantDias++;
            fecha1->dia--;
        }
    }

    printf("\nLa cantidad de dias de diferencia que hay es de: %d",cantDias);
}

int modulo(int n)
{
    return n*(-1);
}


void ejercicio22()
{
    int vec[] = {1,2,3,4,5}; //como mucho 5 elementos
    int elem;
    unsigned int pos,cantElem = contarElementos(vec);

    printf("\nVector original:\n");
    mostrarVector(vec);
    printf("\nIngrese el elemento que quiere ingresar en el vector: ");
    scanf("%d",&elem);
    printf("\nIngrese en la posicion que quiere que esté, (max posiciones del 1 al %d): ",cantElem);
    scanf("%d",&pos);
    if(pos > 0 && pos <= cantElem)
    {
        ingresarElementoEnVec(vec,pos,elem,cantElem);
        printf("\nVector con elemento insertado:\n");
        mostrarVector(vec);
    }
    else
    {
        printf("\nNo se pudo insertar el elemento, ERROR");
    }

}


unsigned int contarElementos(const int * p)
{

    unsigned n = 0;
    while(*p)
    {
        ++n;
        ++p;
    }
    return n;
}

void ingresarElementoEnVec(int vec[],unsigned int pos,int elem,int cantElem)
{
    int i;

    for(i = 0; i < cantElem; i++)
    {
        vec[pos-1] = elem;
    }

}

void mostrarVector(const int *p)
{
    int i;
    for(i = 0; i<tam; ++i,++p)
    {
        printf("%d ",*p);
    }
}

void mostrarVector2(const int *p, unsigned cantElem)
{
    int i;
    for(i = 0; i<cantElem; ++i,++p)
    {
        printf("%d ",*p);
    }
}

void ejercicio23()
{
    int vec[tam] = {1,8,7,3,2,5}; //como mucho 5 elementos
    int elem;
    printf("\nVector original:\n");
    mostrarVector(vec);

    printf("\nIngrese el elemento que quiere ingresar en el vector: ");
    scanf("%d",&elem);
    insertarElementoFormaAsc(vec,elem);

    printf("\nVector forma ascendente:\n");
    mostrarVector(vec);

}

void insertarElementoFormaAsc(int * vec,int elem)
{
    int *ultPos = vec + (tam-1);
    * ultPos = elem;
    printf("\nVector después de insertar elemento:\n");
    mostrarVector(vec);
    ordenarVectorAsc(vec);

}

void ordenarVectorAsc(int * p)
{
    int *p1,*p2;
    p1 = p;
    p2 = p + (tam - 1);
    int aux;

    while(p1 < p2)
    {
        while(p1 != p2)
        {
            if(*(p1) > *(p1+1))
            {
                aux = *(p1);
                *(p1) = *(p1+1);
                *(p1+1) = aux;
            }
            p1++;
        }
        p2--;
        p1 = p;
    }

}

void insertarElementoFormaDesc(int * vec,int elem)
{
    int *ultPos = vec + (tam-1);
    * ultPos = elem;
    printf("\nVector después de insertar elemento:\n");
    mostrarVector(vec);
    ordenarVectorDesc(vec);

}


void ordenarVectorDesc(int * p)
{
    int *p1,*p2;
    p1 = p;
    p2 = p + (tam - 1);
    int aux;

    while(p1 < p2)
    {
        while(p1 != p2)
        {
            if(*(p1) < *(p1+1))
            {
                aux = *(p1);
                *(p1) = *(p1+1);
                *(p1+1) = aux;
            }
            p1++;
        }
        p2--;
        p1 = p;
    }

}


void ejercicio24()
{
    int vec[tam] = {1,8,7,3,2,5,4}; //como mucho 5 elementos
    unsigned int pos, cantElem = contarElementos(vec);
    int resultado;
    printf("\nVector original:\n");
    mostrarVector(vec);

    printf("\nIngrese la pos para eliminar el elemento en el vector: \n");
    scanf("%u",&pos);
    resultado = eliminarElementoPos(vec,pos,cantElem);

    if(resultado)
    {
        printf("\n\nSe pudo eliminar el vector\n\n");
        mostrarVector(vec);
    }
    else
        printf("\nError se pasó de los elementos que se pueden eliminar");

}


int eliminarElementoPos(int * vec, unsigned int pos, unsigned cantElem)
{
    int *p1,*p2 = vec + cantElem; //esto se toma para que se agarre un '0' de afuera, cosa que no existe en el vector y se pise

    if(pos > cantElem)
        return NO;

    p1 = vec + (pos-1); //-> te situas en el elemento que querés eliminar y empieza a hacer copias de derecha para izq

    while(p1 < p2)
    {
        *p1 = *(p1+1);
        p1++;
    }
    return OK;
}


void ejercicio26()
{
    int vec[tam] = {1,8,7,8,2,8,8}; //como mucho 5 elementos
    unsigned int cantElem = contarElementos(vec);
    int elem;
    printf("\nVector original:\n");
    mostrarVector2(vec,cantElem);

    printf("\nIngrese el elemento que quiere eliminar del vector: \n");
    scanf("%d",&elem);
    cantElem = eliminarElementoAparicion(vec,cantElem,elem);

    if(!cantElem)
        printf("\nError no se encuentra el elemento que se quiere eliminar");
    else
    {
        printf("\n\nSe pudo/pudieron eliminar el: %d del vector\n\n",elem);
        mostrarVector2(vec,cantElem);
    }

}

void moverAIzqVec(int *p1,int *p2)
{
    while(p1<p2)
    {
        *p1 = *(p1+1);
        p1++;
    }
}


int eliminarElementoAparicion(int * vec, unsigned cantElem, int elem)
{
    /*
        1 - Si está el valor en la últ posición -> nomás hay que restar un cantElem
        2 - Si se eliminó un valor, y queda otro en la derecha, también hay que eliminarlo -> caso else i++

        int vec[tam] = {1,8,8,7,8,2,8,8}; //como mucho 5 elementos
        ////int vec[tam] = {1,8,7,2}; //como mucho 5 elementos

    */
    int elemEncontrado = 0;
    int *p1 = vec,
         *p2 = vec +(cantElem-1); //se pone en la últ pos

    while(p1 <= p2)
    {
        if(*p1 == elem)
        {
            moverAIzqVec(p1,p2);
            cantElem--;
            p2--;
            elemEncontrado++;
        }
        else
        {
            p1++;
        }
    }

    if(elemEncontrado == 0)
        return NO;

    return cantElem;
}


void ejercicio27()
{
    int pal;
    //char cad1[TAM]= "neuquen";
    //char cad2[TAM] = "alla";
    //char cad3[TAM] = "cabeza";
    char paliTexto[TAM2]="amo   la                 paloma";
    //char paliTexto2[TAM2]="yo hago yoga hoy";
    //char unicaLetra[TAM] = "a";
    //char noLetras[TAM] = "";

    pal = esPalindromo(paliTexto);

    if(pal)
        printf("\nEs palindromo");
    else
        printf("\nNo es palindromo");
}

/*
- Si la cadena está hecha de cero letras o de una letra, entonces es un palíndromo.
- De lo contrario, compara la primera y la última letra de la cadena.
- Si la primera y la última letra difieren, entonces la cadena no es un palíndromo.
- De lo contrario, la primera y la última letra son la misma.


*/

int esPalindromo(char * cad)
{

    char *p1 = cad,
         *p2 = cad + (nogueiraStrlen(cad)-1);

    if(nogueiraStrlen(cad) <= 1)
        return OK; //coincidencia de una sola letra

    while(p1 < p2)
    {
        if(!ES_BLANCO(*p1) && !ES_BLANCO(*p2))
        {

            if(*p1 == *p2)
            {
                p1++;
                p2--;
            }
            else
                return NO;
        }
        else if(ES_BLANCO(*p1))
        {
            p1++;
        }
        else{
            p2--;
        }
    }

    return OK;
}

unsigned int nogueiraStrlen(const char *cad)
{
    unsigned int n = 0;
    while(*cad)
    {
        ++cad;
        ++n;
    }
    return n;
}

int nogueiraStrlen2(const char *cad)
{
    int cont=0;

    while(*cad) // *cad != '\0'
    {
        cad++;
        cont++;
    }

    return cont;
}












int cmp_ent(const void *a,const void *b)
{
    return(*(int*)a - *(int*)b);
}

