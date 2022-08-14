#include "pasajeBinText.h"

int pasarArchivoBinTextLV(const char* nomArchBin,
                          const char* nomArchText,
                          char sep)
{
    tEmpleado emp;
    FILE* archBin, *archText;
    if(!abrirArchivo(&archBin, nomArchBin, "rb"))
    {
        return ERROR;
    }
    if(!abrirArchivo(&archText, nomArchText, "wt"))
    {
        fclose(archBin);
        return ERROR;
    }
    fread(&emp, sizeof(tEmpleado),1,archBin);
    while(!feof(archBin))
    {
        fprintf(archText, "%lu%c%s%c%c%c%d/%d/%d%c%f\n",
                emp.dni, sep, emp.apyn, sep, emp.categoria, sep,
                emp.fechaIngreso.dia, emp.fechaIngreso.mes,
                emp.fechaIngreso.anio, sep, emp.sueldo);
        fread(&emp, sizeof(tEmpleado),1,archBin);
    }
    fclose(archBin);
    fclose(archText);
    return TODO_OK;
}
int pasarArchivoTextLVBin(const char* nomArchText,
                          const char* nomArchBin,
                          char sep)
{
    FILE* archText, *archBin;
    char reg[LONG_REG];
    tEmpleado emp;
    if(!abrirArchivo(&archText, nomArchText, "rt"))
    {
        return 0;
    }
    if(!abrirArchivo(&archBin, nomArchBin, "wb"))
    {
        fclose(archText);
        return 0;
    }

    while(fgets(reg, LONG_REG, archText))
    {
        parsearRegLV(reg, &emp, sep);
        fwrite(&emp, sizeof(tEmpleado), 1, archBin);
    }

    fclose(archBin);
    fclose(archText);
    return TODO_OK;
}
int pasarArchivoBinTextLF(const char* nomArchBin,
                          const char* nomArchText)
{
    FILE* archBin, *archText;
    tEmpleado emp;
    if(!abrirArchivo(&archBin, nomArchBin, "rb"))
    {
        return 0;
    }
    if(!abrirArchivo(&archText, nomArchText, "wt"))
    {
        fclose(archBin);
        return 0;
    }

    fread(&emp, sizeof(tEmpleado), 1, archBin);
    while(!feof(archBin))
    {
        fprintf(archText, "%08lu%-30s%c%02d%02d%04d%9.2f\n",emp.dni,
                 emp.apyn,
                emp.categoria, emp.fechaIngreso.dia,
                emp.fechaIngreso.mes, emp.fechaIngreso.anio, emp.sueldo);
        fread(&emp, sizeof(tEmpleado), 1, archBin);
    }
    fclose(archBin);
    fclose(archText);
    return TODO_OK;
}
int pasarArchivoTextLFBin(const char* nomArchText,
                          const char* nomArchBin)
{
    FILE* archBin, *archText;
    char reg[LONG_REG_LF+2]; //el \n y \0
    tEmpleado emp;

    if(!abrirArchivo(&archText, nomArchText, "rt"))
    {
        return 0;
    }
    if(!abrirArchivo(&archBin, nomArchBin, "wb"))
    {
        fclose(archText);
        return 0;
    }

    while(fgets(reg, sizeof(reg),archText))
    {
        parsearRegLF(reg, &emp);
        fwrite(&emp, sizeof(tEmpleado), 1, archBin);
    }

    fclose(archBin);
    fclose(archText);
    return TODO_OK;
}
