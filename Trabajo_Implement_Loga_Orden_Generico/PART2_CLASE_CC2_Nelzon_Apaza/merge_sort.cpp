/*
DATOS:
ALUMNO: Nelzon Jorge Apaza Apaza
CUI:20190652
CURSO: CC2 - GRUPO A

MÉTODO MERGE SORT(PARA 2DA PARTE), APLICANDO PUNTEROS A FUNCIONES y TEMPLATES
*/

#include "iostream"
#include "stdlib.h"

using namespace std;

template <typename dato>
void mostrar_array_me(dato *array, int tamanio) {
   for(int i = 0; i<tamanio; i++)
      cout << array[i] << " ";
   cout << endl;
}

//Criterio de comparación 1
template <typename dato>
bool compare1_me(dato x,dato y){
    return x<=y;//esto retornará falso si se contradice esta función.
}
//Criterio de comparación 2
template <typename dato>
bool compare2_me(dato x,dato y){
    return x>y;//esto retornará falso si se contradice esta función.
}


template <typename dato>
void merge(dato *array, int left, int midium, int right,bool(*p)(dato,dato)) {
   int i, j, k; //Para los indices
   int nl, nr;//datos auxiliares
   //nl, nf: tamaño de sub arrays de left y right

   nl = midium-left+1;
   nr = right-midium;
   dato left_arr[nl], right_arr[nr];//creamos sub arrays

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
      void (*ME)(dato*,int,int,int,bool(*p)(dato,dato))=merge;
      if (opcion==1)
      {
         ME(array, left, m, right,compare1_me);
      }
      else
      {
         ME(array, left, m, right,compare2_me);
      }
   }
}

template <typename dato>
void main_mergesort(dato *array, int tamanio, int opcion) {
   cout<<endl<<"----------- ORDENANDO FIGURA POR MERGE SORT: -----------"<<endl;
   cout << "Array antes de aplicar merge sort: ";

   //PARA MOSTRAR
   void (*Mos)(dato*,int)=mostrar_array_me;
   Mos(array, tamanio);
   // mostrar_array_me(array, n);

   //PARA MERGE SORT
   void (*MS)(dato*,dato,dato,int)=merge_sort;
   MS(array, 0, tamanio-1, opcion);//(tamanio-1) para el último indice

   cout << "Array despues de aplicar merge sort: ";

   Mos(array,tamanio);//volvemos a mostrar
   // mostrar_array_me(array, n);
}