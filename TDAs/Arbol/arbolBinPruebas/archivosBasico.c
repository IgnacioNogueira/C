#include "archivosBasico.h"

int crearCargarArchivoBin(const char* nomArchBin)
{
    tEmpleado emp[14] = {
        {32321231,"pepe perez",'A',{3,4,2021},60000},
        {42321231,"pablo lopez",'B',{12,6,2021},100000},
        {23148231,"roberto mendez",'B',{3,1,2020},60000},
        {34365223,"ruben diaz",'D',{8,12,2021},60000},
        {33454198,"lucas garcia",'C',{1,8,2021},80000},
        {32344421,"alan perez",'B',{20,9,2020},100000},
        {39323812,"juan montero",'A',{2,8,2018},80000},
        {30123481,"gonzalo gomez",'D',{16,4,2021},60000},
        {28303287,"carlos villa",'B',{12,3,2018},60000},
        {32387631,"jorge aguirre",'A',{19,1,2021},80000},

        {42321231,"pablo lopez",'B',{12,6,2021},100000},
        {32344421,"alan perez",'B',{20,9,2020},100000},
        {39323812,"juan montero",'A',{2,8,2018},80000},
        {32344421,"alan perez",'B',{20,9,2020},100000}
    };
    FILE* archBin;
    if(!abrirArchivo(&archBin, nomArchBin, "wb"))
    {
        return ERROR;
    }

    fwrite(emp, sizeof(emp), 1, archBin);
    fclose(archBin);
    return TODO_OK;
}
int abrirArchivo(FILE** arch, const char* nombre, const char* modoApertura)
{
    *arch = fopen(nombre, modoApertura);
    if(*arch == NULL)
    {
        fprintf(stderr, "error al abrir el archivo %s en modo %s",
                nombre,modoApertura);
        return ERROR;
    }
    return TODO_OK;
}
void mostrarArchivoBin(const char* nomArchBin)
{
    tEmpleado emp;
    FILE* archBin;
    if(!abrirArchivo(&archBin, nomArchBin, "rb"))
    {
        return;
    }
    mostrarEmpleado(NULL);
    fread(&emp, sizeof(tEmpleado),1,archBin);
    while(!feof(archBin))
    {
        mostrarEmpleado(&emp);
        fread(&emp, sizeof(tEmpleado),1,archBin);
    }
    fclose(archBin);
}
void mostrarArchivoTextLV(const char* nomArchText, char sep)
{
    char reg[LONG_REG];
    tEmpleado emp;
    FILE* archText;
    if(!abrirArchivo(&archText, nomArchText, "rt"))
    {
        return;
    }
    mostrarEmpleado(NULL);
    while(fgets(reg, LONG_REG, archText))
    {
        parsearRegLV(reg, &emp, sep);
        mostrarEmpleado(&emp);
    }
    fclose(archText);
}
void mostrarEmpleado(const void* vEmp)
{
    tEmpleado *emp = (tEmpleado*)vEmp;
    if(emp == NULL)
    {
        printf("DNI         NOMBRE_APE          ");
        printf("CAT FECHA      SUELDO\n");
    }
    else
    {
        printf("%-12lu%-20s%-2c%02d/%02d/%04d %9.2f\n",emp->dni,
                emp->apyn,
                emp->categoria, emp->fechaIngreso.dia,
                emp->fechaIngreso.mes, emp->fechaIngreso.anio, emp->sueldo);
    }
}

void mostrarArchivoTextLF(const char* nomArchText)
{
    char reg[LONG_REG_LF + 2]; //el \n y \0
    tEmpleado emp;
    FILE* archText;
    if(!abrirArchivo(&archText, nomArchText, "rt"))
    {
        return;
    }
    mostrarEmpleado(NULL);
    while(fgets(reg, sizeof(reg), archText))
    {
        parsearRegLF(reg, &emp);
        mostrarEmpleado(&emp);
    }
    fclose(archText);
}
