/*
DATOS:
ALUMNO: Nelzon Jorge Apaza Apaza
CUI:20190652
CURSO: CC2 - GRUPO A

MÉTODO MERGE SORT, APLICANDO PUNTEROS A FUNCIONES y TEMPLATES
*/

#include "iostream"
#include "stdlib.h"

using namespace std;

template <typename dato>
void Intercambio(dato &a, dato &b) {//Intercambio  de contenido entre a y b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
template <typename dato>
void mostrar_array(dato *array, dato tamanio) {
   for(int i = 0; i<tamanio; i++)
      cout << array[i] << " ";
   cout << endl;
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
void merge(dato *array, dato left, dato midium, dato right,bool(*p)(dato,dato)) {
   int i, j, k; //Para los indices
   int nl, nr;//datos auxiliares
   //nl, nf: tamaño de sub arrays de left y right

   nl = midium-left+1;
   nr = right-midium;
   int left_arr[nl], right_arr[nr];//creamos sub arrays

   //llenamos ambos arrays, left y right
   for(i = 0; i<nl; i++)
      left_arr[i] = array[left+i];
   for(j = 0; j<nr; j++)
      right_arr[j] = array[midium+1+j];
   i = 0; j = 0; k = left;


   //Unir el array temporal con el original
   while(i < nl && j<nr) {
      if(p(left_arr[i],right_arr[j])) {//CONDICIÓN PARA EL ORDEN ascendente
         array[k] = left_arr[i];
         i++;
      }
      else{
         array[k] = right_arr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       // Elemento extra en el array left
      array[k] = left_arr[i];
      i++; k++;
   }
   while(j<nr) {     // Elemento extra en el array right
      array[k] = right_arr[j];
      j++; k++;
   }

}

template <typename dato>
void merge_sort(dato *array, dato left, dato right, int opcion) {//OPCION nos ayudará a definir el orden descendente o ascendente
   int m;//midium,  elemento medio
   if(left < right) {
      int m = left+(right-left)/2;
      // Clasifica el primer y segundo array

      void (*MS)(dato*,dato,dato,int)=merge_sort;
      MS(array, left, m,opcion);
      MS(array, m+1, right,opcion);
      // merge_sort(array, left, m,opcion);
      // merge_sort(array, m+1, right,opcion);
      //Unimos
      //PARA MERGE
      void (*ME)(dato*,dato,dato,dato,bool(*p)(dato,dato))=merge;
      if (opcion==1)
      {
         ME(array, left, m, right,compare1);
      }
      else
      {
         ME(array, left, m, right,compare2);
      }
   }
}

//FUNCION MAIN
int main() {
   int n;//cantidad de elementos
   cout << "Ingrese el numero de elementos: ";
   cin >> n;
   int array[n];  //creamos array
   cout << "ingrese los elementos:" << endl;
   for(int i = 0; i<n; i++) {
      cout<<"Elemento "<<i+1<<"\t";
      cin >> array[i];
   }
   cout << "Array antes de aplicar merge sort: ";

   //APARA MOSTRAR
   void (*Mos)(int*,int)=mostrar_array;
   Mos(array, n);
   // mostrar_array(array, n);


   int opcion;
   do
   {
      cout<<"Elija una opcion: \n1. Ordenar de manera ascendente.\n2. Ordenar de forma descendente\n opcion: ->\t";
      cin>>opcion;
   } while (opcion!=1 && opcion!=2);

   //PARA MERGE SORT
   void (*MS)(int*,int,int,int)=merge_sort;
   MS(array, 0, n-1, opcion);
   // merge_sort(array, 0, n-1,opcion);//(n-1) para el último indice

   cout << "Array despues de aplicar merge sort: ";

   Mos(array,n);//volvemos a mostrar
   // mostrar_array(array, n);
}