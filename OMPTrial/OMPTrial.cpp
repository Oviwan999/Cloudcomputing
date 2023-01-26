// OMPTrial.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <ctime>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif
// en este primer paso definimos las librerias a usar al igual que verificamos si necesitaremos llamr OPENMP o no
//

#define N 1000
#define chunk	100
#define mostrar 10

// definimos el tamaño de muestra y el tamño de divixion que usaremos
//


void imprimirArreglos(int* a,int* b,int* c)// esta parte  definimos una funcion para mandar imprimier el elemento N de cada arreglo//
{
	for (int i = 0; i < mostrar; i++)
	{
		std::cout << "A[" << i << "] = " << a[i];
		std::cout << "\n";
		std::cout << "B[" << i << "] = " << b[i];
		std::cout << "\n";
		std::cout << "La suma Final es C[" << i << "] = " << c[i];
		std::cout << "\n";

	}
}

void Suma(int* a, int* b, int* c)
{
	for (int i = 0; i < N; ++i) 
	{
		c[i] = a[i] + b[i];
	}
}

const int tamano = N+1, MAXIMO = 100, MAXIMO2=100;

int main()
{
	int a[tamano] = { 0 };
	int i;
	for (i = 0; i < tamano; ++i)
		a[i] = rand() % MAXIMO;
	std::cout << "TErmine arreglo A:\n";
	int b[tamano] = { 0 };
	for (i = 0; i < tamano; ++i)
		b[i] = rand() % MAXIMO2;
	std::cout << "Termine Arreglo B:\n";

	omp_set_num_threads(10);
	int c[tamano] = { 0 };
	Suma(a, b, c);
	imprimirArreglos(a, b, c);
}