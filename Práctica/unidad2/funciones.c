#include "funciones.h"
#include "string2.h"

// Ejercicio Eliminar Letra más repetida

char letraMasRepetida(const char * str)
{
    if(str == NULL)
        return NO;

    int letrasVector[maxmM] = {0}; //como mucho hay 50 letras entre mayus y minus ASCII
    int max = 0;
    char letra = 0;

    while(*str)
    {
        if(++letrasVector[(int)*str] > max && !ES_BLANCO(*str))
        {
            max = letrasVector[(int)*str];
            letra = *str;
        }
        ++str;
    }

    return letra;
}




void moverAIzqElems(void *p1,void *p2)
{
    while((char*)(p1)<(char*)(p2))
    {
        *((char*)p1) = *((char*)p1+1);
        p1++;
    }
}



int eliminarLetraMasRepetida(char *str, const char letra)
{
    char *p1 = str,
         *p2 = str + (nogueiraStrlen(str)-1);

    int elemEncont = 0;

    while(p1 <= p2)
    {
        if(*p1 == letra)
        {
            moverAIzqElems(p1,p2);
            --p2;
            ++elemEncont;
        }
        else
        {
            ++p1;
        }
    }

    if(!elemEncont)
        return NO;

    return elemEncont;
}


//Ejercicio 8


void unSoloEspacio(char * textComp)
{

    char *p1 = textComp,// + (strlen(textComp)-1); en este caso no importa el espacio de la der de todo
          *p2;

    while( (p2 = nogueiraStrStr(p1,"  ")) != NULL)
    {
        nogueiraMemmove(p2,p2+1,nogueiraStrlen(p2));
    }
}




//Ejercicio 12


int leerYmostrarArchivoBinNotas(const char * nombreArchivo)
{
    tAlumno alum;
    FILE * fp = fopen(nombreArchivo,"rb");

    if(!fp)
    {
        printf("\nNo se pudo abrir el archivo %s",nombreArchivo);
        return NO;
    }

    fread(&alum,sizeof(tAlumno),1,fp);

    while(!feof(fp))
    {
        mostrarAlumnoNotas(&alum);
        fread(&alum,sizeof(tAlumno),1,fp);
    }

    fclose(fp);
    return OK;
}

int leerYmostrarArchivoBinNotas2(const char * nombreArchivo)
{
    tAlumno alum;
    FILE * fp = fopen(nombreArchivo,"rb");

    if(!fp)
    {
        printf("\nNo se pudo abrir el archivo %s",nombreArchivo);
        return NO;
    }

    fread(&alum,sizeof(tAlumno),1,fp);

    while(!feof(fp))
    {
        mostrarAlumnoNotas2(&alum);
        fread(&alum,sizeof(tAlumno),1,fp);
    }

    fclose(fp);
    return OK;
}



int leerYmostrarArchivoTxt(const char * nombreArchivo)
{
    tAlumno alum;
    char linea[100];
    FILE * fp = fopen(nombreArchivo,"rt");

    if(!fp)
    {
        printf("\nNo se pudo abrir el archivo %s",nombreArchivo);
        return NO;
    }


    while(fgets(linea,sizeof(linea),fp))
    {
        trozarCamposLF(&alum,linea);
        mostrarAlumnoFinal(&alum);
    }

    fclose(fp);
    return OK;
}


int crearArchivoLF(const char * nombreOrig, const char * nombreDest)
{
    tAlumno alum;
    int i = 0;
    FILE * fpb = fopen(nombreOrig,"rb");

    if(!fpb)
    {
        printf("\nNo se encontró el archivo %s para crear el %s de longitud fija\n",nombreOrig,nombreDest);
        return -1;
    }

    FILE *fpt = fopen(nombreDest,"wt");

    if(!fpt)
    {
        printf("\nNo se pudo crear el archivo %s de longitud fija\n",nombreDest);
        fclose(fpb);
        return -2;
    }

    fread(&alum,sizeof(tAlumno),1,fpb);
    fprintf(fpt,"   Apellido/s, Nombre/s                 P. 1  P. 2  P. 3  P. 4  P. 5  P. 6 - Promedio\n");
    fprintf(fpt,"   =================================== ===== ===== ===== ===== ===== =====   ========\n");

    while(!feof(fpb))
    {
        fprintf(fpt,"%2d %-*.*s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f   %5.2f\n",i+1,
                (int)sizeof(alum.nya)-1,
                (int)sizeof(alum.nya)-1,
                alum.nya,
                alum.nota1,
                alum.nota2,
                alum.nota3,
                alum.nota4,
                alum.nota5,
                alum.nota6,
                alum.prom
               );
        fread(&alum,sizeof(tAlumno),1,fpb);
        ++i;
    }

    fclose(fpb);
    fclose(fpt);
    return OK;
}


void mostrarAlumnoNotas(const tAlumno * alum)
{

    if(!alum)
    {
        printf("\nNo hay alumnos que mostrar\n");
        return;
    }

    printf("   %-*.*s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n",
           (int)sizeof(alum->nya)-1,
           (int)sizeof(alum->nya)-1,
           alum->nya,
           alum->nota1,
           alum->nota2,
           alum->nota3,
           alum->nota4,
           alum->nota5,
           alum->nota6
          );
}

void mostrarAlumnoNotas2(const tAlumno * alum)
{

    if(!alum)
    {
        printf("\nNo hay alumnos que mostrar\n");
        return;
    }

    printf("   %-*.*s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f   %5.2f\n",
           (int)sizeof(alum->nya)-1,
           (int)sizeof(alum->nya)-1,
           alum->nya,
           alum->nota1,
           alum->nota2,
           alum->nota3,
           alum->nota4,
           alum->nota5,
           alum->nota6,
           alum->prom
          );
}

void mostrarAlumnoFinal(const tAlumno * alum)
{

    if(!alum)
    {
        printf("\nNo hay alumnos en el archivo de texto que mostrar\n");
        return;
    }

    printf("   %-*.*s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f   %5.2f\n",
           (int)sizeof(alum->nya)-1,
           (int)sizeof(alum->nya)-1,
           alum->nya,
           alum->nota1,
           alum->nota2,
           alum->nota3,
           alum->nota4,
           alum->nota5,
           alum->nota6,
           alum->prom
          );
}


int crearArchivoBin(char * nombreArchivo)
{
    tAlumno arrayAl[] =
    {
        {"Evangelina Mendez",10,10,10,10,10,10},
        {"Nogueira Daniel",9.15,7.30,6.50,8,9,9},
        {"Nogueira Ignacio",7,8.50,8.50,7.50,7,7},
        {"Pepito Elburro",2,2,2,2,2,2}
    };

    FILE *fp = fopen(nombreArchivo,"wb");

    if(fp)
    {
        fwrite(&arrayAl,sizeof(arrayAl),1,fp);
        fclose(fp);
        return OK;
    }

    return NO;
}

int crearArchivoTxt(char * nombreArchivo)
{
    tAlumno arrayAl[] =
    {
        {"Evangelina Mendez",10,10,10,10,10,10},
        {"Nogueira Daniel",9,9,9,9,9,9},
        {"Nogueira Ignacio",7,7,7,7,7,7},
        {"Pepito Elburro",2,2,2,2,2,2}
    };

    FILE *fp = fopen(nombreArchivo,"wt");

    if(fp)
    {
        fwrite(&arrayAl,sizeof(arrayAl),1,fp);
        fclose(fp);
        return OK;
    }

    return NO;
}

/*esto no se hace, caca pedo pis ->*/

int promAlumnos(char * archivoBinNotas, tAlumno * alumno, size_t cantNotas)
{
    tAlumno alum;
    FILE * archBin;
    float sumaNotas = 0;
    //rewind(archBin);

    archBin = fopen(archivoBinNotas,"r+b");

    if(!archBin)
    {
        printf("\nNo se pudo abrir el archivo %s",archivoBinNotas);
        return NO;
    }

    long posInicial = ftell(archBin);

    fread(&alum,sizeof(tAlumno),1,archBin);
    while(!feof(archBin))
    {
        sumaNotas = alum.nota1+ alum.nota2 + alum.nota3 + alum.nota4 + alum.nota5 +alum.nota6;
        alum.prom = sumaNotas / cantNotas;
        fseek(archBin,-1L*(float)sizeof(tAlumno),SEEK_CUR);
        fwrite(&alum,sizeof(tAlumno),1,archBin);
        fseek(archBin,0L,SEEK_CUR); // ya que previamente escribimos y lo abrimos como r+b, lo seteamos en 0 para volverlo nuevamente a lectura
        fread(&alum,sizeof(tAlumno),1,archBin);
    }

    fseek(archBin,posInicial,SEEK_SET);
    return OK;
}
/*esto no se hace, caca pedo pis ->*/



void trozarCamposLF(tAlumno * alum,char * linea)
{
    char * aux = linea + TAM_LINEA;
    *aux = '\0';

    aux -= TAM_PROMEDIO;
    sscanf(aux,"%f",&alum->prom);
    *aux = '\0';

    aux -= TAM_NOTA6;
    sscanf(aux,"%f",&alum->nota6);
    *aux = '\0';

    aux -= TAM_NOTA5;
    sscanf(aux,"%f",&alum->nota5);
    *aux = '\0';

    aux -= TAM_NOTA4;
    sscanf(aux,"%f",&alum->nota4);
    *aux = '\0';

    aux -= TAM_NOTA3;
    sscanf(aux,"%f",&alum->nota3);
    *aux = '\0';

    aux -= TAM_NOTA2;
    sscanf(aux,"%f",&alum->nota2);
    *aux = '\0';

    aux -= TAM_NOTA1;
    sscanf(aux,"%f",&alum->nota1);
    *aux = '\0';

    aux -= TAM_NYA;
    strcpy(alum->nya,aux);
    *aux = '\0';

    /*
    aux -= TAM_NRO;
    sscanf(aux,"%2d",(int*)aux); //preguntar
    *aux = '\0'; //así agarra la otra linea
    */

}

