#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define aMayusc(x)( (x)>= 'A' && (x)<='Z' ? (x):(x)-32 )
#define aMinus(x)( (x)>= 'a' && (x)<='z' ? (x):(x)+32 )
#define max 100
#define ES_BLANCO(X)((X) == ' ' ? 1:0)

#define OK 1
#define NO 0

// - VECTORES NUMÉRICOS
#define tam 10

//VECTORES ALFANUMÉRICOS
#define TAM 50
#define TAM2 100



//menu

void menu(void);

//funciones rápidas

double fact(int nro);
double combinatoria(double m, double n);
double eAlaX(int x,double tol);
double potencia (float x,int p);
void fibonacci(int n);
void tipoNro(int nro);
void sacarRestoYDivisor(int divis, int divid);
int modulo(int n);
//Ejercicios - UNIDAD 1

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();

// Fecha

typedef struct{
    int dia,
        mes,
        anio;
}tFecha;

void ingresarFecha(tFecha * fecha);
int fechaCorrecta(const tFecha * fecha);
int cantDiasMes(const int mes, const int anio);
int esBisiesto(const int anio);
void fechaSiguiente(tFecha * fecha);
void mostrarFecha(tFecha * fecha);
void sumaNdiasFecha(tFecha * fecha, int dias);
void restaNdiasFecha(tFecha * fecha, int dias);
void cantDiasDifEntreDosFechas(tFecha * fecha1, tFecha * fecha2);


void ejercicio14();
void ejercicio15();
void ejercicio16();
void ejercicio17();
void ejercicio18();


// Vectores

void mostrarVector(const int *p);
void mostrarVector2(const int *p, unsigned cantElem);
void ingresarElementoEnVec(int vec[],unsigned int pos,int elem,int cantElem); //22

void ingresarElementoEnVec2(int vec[],int elem);
void insertarElementoFormaAsc(int * vec,int elem); //23
void ordenarVectorAsc(int * p); //
void insertarElementoFormaDesc(int * vec,int elem);
void ordenarVectorDesc(int * p);

int eliminarElementoPos(int * vec, unsigned int pos, unsigned cantElem); //24

void moverAIzqVec(int *p1,int *p2);
int eliminarElementoAparicion(int * vec, unsigned cantElem, int elem); //25

int esPalindromo(char * cad);
unsigned int nogueiraStrlen(const char *cad);
int nogueiraStrlen2(const char *cad);

unsigned int contarElementos(const int * p);
int cmp_ent(const void *a,const void *b);

void ejercicio22();
void ejercicio23();
void ejercicio24();
void ejercicio26();
void ejercicio27();


#endif // HEADER_H_INCLUDED
