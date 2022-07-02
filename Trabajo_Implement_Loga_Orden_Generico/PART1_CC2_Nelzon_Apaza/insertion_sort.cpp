/*
DATOS:
ALUMNO: Nelzon Jorge Apaza Apaza
CUI:20190652
CURSO: CC2 - GRUPO A

MÉTODO INSERTION SORT, APLICANDO PUNTEROS A FUNCIONES y TEMPLATES
*/
#include "iostream"
#include "stdlib.h"

using namespace std;
int menu(){
    int opcion;
    do
    {
        cout<<"Elija una opcion: \n1. Ordenar de manera ascendente.\n2. Ordenar de forma descendente\n opcion: ->\t";
        cin>>opcion;
    } while (opcion!=1 && opcion!=2);
    return opcion;
}

template <typename dato>
//Para mostrar elementos del array
void mostrar(dato *array, dato tamanio) {
   for(int i = 0; i<tamanio; i++)
      cout << array[i] << " ";
   cout << endl;
}

//Criterio de comparación 1
template <typename dato>
bool compare1(dato x,dato y){
    return x>y;//esto retornará falso si se contradice esta función.
}
//Criterio de comparación 2
template <typename dato>
bool compare2(dato x,dato y){
    return x<y;//esto retornará falso si se contradice esta función.
}

template <typename dato>
//Método Insertion Sort
void insertion_sort(dato *array, dato tamanio, bool(*p)(dato x,dato y)) {//para ordenar de mayor a menor
    int j;
    dato key;
    for(int i = 1; i<tamanio; i++) {
            key = array[i];   //key toma el valor del elemento del array
            j = i;
            //Ponemos la condición de ordenamiento:
            while(j > 0 && p(array[j-1],key)) {//ascendente y descendente de acuerdo al criterio de comparación
                array[j] = array[j-1];
                j--;
            }
            array[j] = key;

        
    }
}

//Creamos un main 2 para poder usar el template.
template <typename dato>
void main_2(dato *array, dato n, dato opcion){//esta funcion recibirá 2 datos de tipo dato y uno de tipo int
    cout << "Array antes de aplicar insertion sort: ";

    //------------ mostrar ------------
    //FUNCION MOSTRAR -> convertido a puntero a funcion
    void (*Mos)(dato *,dato)=mostrar;//No puedo, no me permite usar templates en main. 
    Mos(array,n);
    // ANTES: mostrar(array, n);//mostramos
    // -----------------------------
    if (opcion==1)
    {
        cout<<"----- Aplicando Insertion sort en orden ascendente -----"<<endl;
        //------------ insertion sort ------------
        void (*In_Sort)(dato *,dato, bool(*p)(dato,dato))=insertion_sort;
        In_Sort(array,n,compare1);//aplicamos insertion
        // insertion_sort(array, n, opcion);
        // -----------------------------

    }
    else{
        cout<<"----- Aplicando Insertion sort en orden descendente -----"<<endl;
        //------------ insertion sort ------------
        void (*In_Sort)(dato *,dato, bool(*p)(dato,dato))=insertion_sort;
        In_Sort(array,n,compare2);//aplicamos insertion
        // insertion_sort(array, n, opcion);
        // -----------------------------
    }
    Mos(array,n);
    // mostrar(array, n);//mostramos
}


//funcion principal
int main() {
    int opcion;
    int n;
    cout<< "Ingrese el numero de elementos a tener:\t";
    cin>>n;
    int array[n];
    cout << "Ahora debe ingresar los elementos del array:" << endl;
    for(int i = 0; i<n; i++) {
        cout<<"Elemento "<<i+1<<": \t";
        cin >> array[i];
    }

    //------------ menu ------------
    //funcion menu-> convertido a puntero a funcion
    int (*M)()=menu;//M=menu;
    opcion=M();//opcion=(*M)();
    //ANTES:  opcion=menu();
    // -----------------------------
    main_2(array,n,opcion);
}