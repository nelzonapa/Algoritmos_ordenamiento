/*
DATOS PERSONALES:
Alumno: Apaza Apaza Nelzon Jorge 
CUI:20190652
CURSO: CC2 - GRUPO A
- Segunda parte de IMPLEMENTACIÓN DE ALGORITMOS DE ORDENAMIENTO GENÉRICO
*/
#include "iostream"
#include "stdlib.h"
#include "string"
using namespace std;

//Incluimos las clases con .h y .cpp
//Estamos tomando las demás formas de los anteriores ejercicios como ejemplo
#include "FORMA.h"
#include "FORMA.cpp"
#include "RECTANGULO.h"
#include "RECTANGULO.cpp"
#include "ELIPSE.h"
#include "ELIPSE.cpp"
#include "CUADRADO.h"
#include "CUADRADO.cpp"
#include "CIRCULO.h"
#include "CIRCULO.cpp"
#include "insertion_sort.cpp"
#include "quick_sort.cpp"
#include "merge_sort.cpp"
int menu2(){
    int opcion;
    do
    {
        cout<<"Elija un metodo para ordenar: \n1. Insertion Sort.\n2.Quick Sort\n3. Merge Sort\n opcion: ->\t";
        cin>>opcion;
    } while (opcion!=1 && opcion!=2 && opcion!=3);
    return opcion;
}

template <typename dato>
void mostrar_ordenado(dato *vector_areas,FORMA *vector_formas[]){

    cout<<endl<<"----------- FIGURAS ORDENADAS SEGUN EL ORDEN ELEGIDO: -----------"<<endl;
    /*-----------------IMPRIMIMOS DATOS ORDENADOS por forma----------------*/
    //Imprimir cada forma y su area respectiva
    //HACIENDO uso de (Virtual)
    for (int i = 0; i < 4; i++)
    {
        cout<<"---------------Figura "<<i+1<<"--------------"<<endl;
        for (int j = 0; j < 4; j++)
        {
            if(vector_areas[i]==vector_formas[j]->get_area()){//imprimimos las formas en orden
                vector_formas[j]->imprimir();
                cout<<endl;
                vector_formas[j]->area();
            }
        }
        
    }
}


int main(){
    /*-----------------LLENADO DE DATOS de las figuras-----------------*/
    string color;
    cout<<"Ingrese el color que tendran todas las formas: "<<endl;
    getline(cin,color);
    //crear un vector puntero .. mas detalles en pasos.txt
    FORMA *vector_formas[4];
    //Bucle for:
    for (int i = 0; i < 4; i++)
    {   
        //Damos una posición específica para cada forma y llenamos los datos
        switch (i)
        {
        case 0:
            vector_formas[i]=new RECTANGULO(color,"Rectangulin",5.6,12.5);
            break;
        case 1:
            vector_formas[i]=new CUADRADO(color,"Cuadradin",5.6,5.6);
            break;
        case 2:
            vector_formas[i]=new ELIPSE(color,"Elipsin",14.6,6.8);
            break;
        case 3:
            vector_formas[i]=new CIRCULO(color,"Circulin",6.8,6.8);
            break;
        default:
            break;
        }
    }
    /*-----------------IMPRIMIMOS DATOS por forma----------------*/
    //Imprimir cada forma y su area respectiva
    //HACIENDO uso de (Virtual)
    for (int i = 0; i < 4; i++)
    {
        cout<<"---------------Firgura "<<i+1<<"--------------"<<endl;
        vector_formas[i]->imprimir();
        cout<<endl;
        vector_formas[i]->area();
        
    }

    /*-----------------PARA ORDENAR----------------*/
   float vector_areas[4];//vector que almacenará las areas
    for (int i = 0; i < 4; i++)
    {
        //rellenamos el vector de todas las areas de las figuras:
        vector_areas[i]=vector_formas[i]->get_area();

    }
    cout<<endl<<"----------- ORDENANDO FIGURA POR AREA: -----------"<<endl;
    //Defiimos que orden queremos usar
    int met_orden;
    met_orden=menu2();

    int opcion;
    int (*ME)()=menu;
    opcion=ME();

    switch (met_orden)
    {
    case 1://USAMOS EL INSERTIO SORT.CPP
        main_insertion(vector_areas,4,opcion);
        mostrar_ordenado(vector_areas,vector_formas);
        break;
    case 2://USAMOS EL INSERTIO SORT.CPP
        main_quicksort(vector_areas,4,opcion);
        mostrar_ordenado(vector_areas,vector_formas);
        break;
    case 3://USAMOS EL INSERTIO SORT.CPP
        main_mergesort(vector_areas,4,opcion);
        mostrar_ordenado(vector_areas,vector_formas);
        break;
    default:
        break;
    }
    return 0;
}