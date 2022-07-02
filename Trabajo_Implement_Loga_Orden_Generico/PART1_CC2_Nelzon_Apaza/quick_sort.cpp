/*
DATOS:
ALUMNO: Nelzon Jorge Apaza Apaza
CUI:20190652
CURSO: CC2 - GRUPO A

MÉTODO QUICK SORT, APLICANDO PUNTEROS A FUNCIONES y TEMPLATES
*/
#include "stdio.h"
#include "iostream"
using namespace std;


template <typename dato>
void agregar_elem(dato array[],dato length)
{
	cout<<"Ingrese "<<length<<" elementos: "<<endl;
	for (int i = 0; i < length; i++)
	{
		cin>>array[i];
	}
	
}

template <typename dato>
void mostrar_array(dato array[],dato length)
{
	cout<<"Los elementos dados en el array son: "<<endl;
	for (int i = 0; i < length; i++)
	{
		cout<<array[i]<<", ";
	}
	
}
template <typename dato>
void intercambio(dato* p, dato* q)// Para intercambiar el valor que apuntan los punteros p y q
{
    int temporal = *q;//probablemente usemos dato
    *q = *p;
    *p = temporal;
}

//Criterio de comparación 1
template <typename dato>
bool compare1(dato x,dato y){
    return x<=y;//esto retornará falso si se contradice esta función.
}
//Criterio de comparación 2
template <typename dato>
bool compare2(dato x,dato y){
    return x>y;//esto retornará falso si se contradice esta función.
}

template <typename dato>
//'lower' nos indica el primer indice del array y 'upper' indica el último indice de este
int dividir (dato array[], dato lower, dato upper, bool (*p)(dato,dato))// divide el array, tomamos el ultimo elemento como pivote
{
    int i = (lower - 1);  //indice del elemento mas pequeño

	//PARA INTERCAMBIO
	void (*I)(dato *, dato *)=intercambio;
    for (int j = lower; j < upper; j++)
    {
		if (p(array[j],array[upper]))//IMPORTANTE, define lo ascendente y descendente
		{
			i++; // Incrementamos el indice del elemento más pequeño

			I(&array[i],&array[j]);// Pasamos la direccion de cada array por refrencia. Para el intercambio
			// intercambio(&array[i],&array[j]);
		}	
    }
	I(&array[i + 1], &array[upper]);//finalmente, intercambiamos el pivote con el elemento que se encuentra en la posición donde el pivote esta
    // intercambio(&array[i + 1], &array[upper]);
    return (i + 1);//Retorna la posición del pivote que tomará en el array ordenado
}

template <typename dato>
void quick_sort(dato array[], dato lower, dato upper, int opcion)
{
	
    if (lower < upper)// Verificamos
    {
		//PARA DIVIDIR
		int (*D)(dato *,dato,dato, bool (*p)(dato,dato))=dividir;
		//PARA QUICK SORT
		void (*Q)(dato*,dato,dato,int)=quick_sort;

		if (opcion==1)
		{
			int pivotIndex=D(array, lower, upper,compare1);// Obtenemos el índice del pivote despues de la division del array
			Q(array, lower, pivotIndex - 1,opcion);//ordena elementos antes del pivote
			Q(array, pivotIndex + 1, upper,opcion);//ordena elementos después del pivote
			// quick_sort(array, lower, pivotIndex - 1);
        	// quick_sort(array, pivotIndex + 1, upper);
		}
		else
		{
			int pivotIndex=D(array, lower, upper,compare2);// Obtenemos el índice del pivote despues de la division del array
			Q(array, lower, pivotIndex - 1,opcion);//ordena elementos antes del pivote
			Q(array, pivotIndex + 1, upper,opcion);//ordena elementos después del pivote
			// quick_sort(array, lower, pivotIndex - 1);
        	// quick_sort(array, pivotIndex + 1, upper);
		}
    }
}



int main()
{
	int tamanio;
	cout<<"Ingrese el tamanio del array: \t";
	cin>>tamanio;
    int array[tamanio];

	//PARA AGREGAR ELEMENTOS
	void (*A)(int*,int)=agregar_elem;

	int opcion;
    do
    {
        cout<<"Elija una opcion: \n1. Ordenar de manera ascendente.\n2. Ordenar de forma descendente\n opcion: ->\t";
        cin>>opcion;
    } while (opcion!=1 && opcion!=2);
	//PARA QUICK SORT
	void (*Q)(int*,int,int, int)=quick_sort;
	//PARA MOSTRAR
	void (*M)(int*,int)=mostrar_array;

	A(array,tamanio);
    // agregar_elem(array,tamanio);

	Q(array,0,tamanio-1,opcion);// Pasamos tamanio-1, porque en la funcion se contará desde 0
    // quick_sort(array,0,tamanio-1);

	M(array,tamanio);
    // mostrar_array(array,tamanio);

    return 0;
}