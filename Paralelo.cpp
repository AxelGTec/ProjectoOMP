/*
	Paralelo.cpp : Este archivo implementa la suma de dos arreglos en paralelo usando OpenMP.
	La ejecución del programa comienza en la función main.
*/

#include <iostream>  // Biblioteca estándar para entrada y salida
#include <omp.h>     // Biblioteca OpenMP para paralelismo

// Definición de constantes
#define N 1000      // Tamaño del arreglo
#define chunk 200   // Tamaño de los bloques para procesamiento paralelo
#define mostrar 10  // Cantidad de elementos a mostrar

// Prototipo de la función que imprime un arreglo
void imprimeArreglo(float *d);

int main()
{
	std::cout << "Sumando Arreglos en Paralelo!\n";

	// Declaración de los arreglos
	float a[N], b[N], c[N];
	int i;

	// Inicialización de los arreglos a y b con valores
	for (i = 0; i < N; i++)
	{
		a[i] = i * 10;        // Cada elemento de 'a' es múltiplo de 10
		b[i] = (i + 3) * 3.7; // Cada elemento de 'b' sigue una progresión
	}

	int pedazos = chunk; // Definición del tamaño de los bloques

	// Directiva de OpenMP para paralelizar el bucle de suma de arreglos
#pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i]; // Suma de los arreglos 'a' y 'b' almacenada en 'c'

	// Imprimir los primeros 'mostrar' valores de los arreglos
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
	imprimeArreglo(c);
}

// Función que imprime los primeros 'mostrar' valores de un arreglo
void imprimeArreglo(float *d)
{
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " - ";
	std::cout << std::endl;
}
