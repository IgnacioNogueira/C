#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//Defines
#define fil 5
#define col 5

#define fil2 3
#define col2 3

#define fil3 4
#define col3 3

#define OK 1
#define NO 0

#define aMayusc(x)( (x)>= 'A' && (x)<='Z' ? (x):(x)-32 )

//Menú

void menu(void);

//Funciones varias matrices

void tab(int n);
void mostrarMatriz(const int mat[][col],int f,int c);
void mostrarMatriz2(int mat[][col3],int f,int c);
void mostrarMatrizTransp(int mat[][col2],int f,int c);
void mostrarMatrizTransp2(int mat[][fil3],int f,int c);
int esMatrizCuadrada(int f,int c);
void matrizTranspuestaNxN(int mat[][col2],int f,int c);
void matrizTranspuestaNxM(int mat[][col3],int mat2[][fil3],int f,int c);

//Diagonal principal

void sumConDiagPrincipalInferior(int mat[][col],int f,int c);
void sumSinDiagPrincipalInferior(int mat[][col],int f,int c);
void sumConDiagPrincipaSuperior(int mat[][col],int f,int c);
void sumSinDiagPrincipaSuperior(int mat[][col],int f,int c);
void sumaDiagPrincipal(int mat[][col],int f,int c);

//Diagonal secundaria
void sumConDiagSecundSuperior(int mat[][col],int f,int c);
void sumSinDiagSecundSuperior(int mat[][col],int f,int c);
void sumConDiagSecundInferior(int mat[][col],int f,int c);
void sumSinDiagSecundInferior(int mat[][col],int f,int c);
void sumaDiagSecundaria(int mat[][col],int f,int c);

int esMatrizDiagonal(int mat[][col],int f,int c);

int esMatrizIdentidad(int mat[][col],int f,int c);

int esMatrizSimetrica(int mat[][col],int f,int c);

void productoMatrices(int mat1[][col3],int mat2[][fil3],int mat3[][fil3],int f,int c);
void mostrarMatrizProd(const int mat[][fil3],int f,int c);

void mostrarMatrizPart(const int partidos[][col2],int f,int c);
unsigned int puntosEquipos(const int partidos[][col2],int f, int c);
int diagonalPrincipalCeros(const int partidos[][col2],int f, int c);
int sumaCorrectaPuntos(const int partidos[][col2],int f, int c);




//Ejercicios matrices

void ejercicio29();
void ejercicio30();
void ejercicio31();
void ejercicio32();
void ejercicio33();
void ejercicio34();
void ejercicio35();
void ejercicio36();
void ejercicio37();

#endif // MATRIZ_H_INCLUDED
