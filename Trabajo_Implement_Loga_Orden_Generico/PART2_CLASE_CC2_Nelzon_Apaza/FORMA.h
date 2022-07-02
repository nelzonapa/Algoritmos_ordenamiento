#ifndef FORMA_H
#define FORMA_H

#include "iostream"
using namespace std;
//Creamos clase FORMA
class FORMA{
    private://atributos
        string color;
        string nombre_figura;
    public://métodos
        FORMA(string,string);//CONSTRUCTOR
        ~FORMA();
        virtual void imprimir();//USO del polimorfismo mediante (virtual)
        string get_color();//obtenemos el color
        void set_nuevo_color();//cambiamos de color
        virtual void area();//usamos virtual
        virtual float get_area();//obtenemos el dato area, usamos virtual
        //pasamos al archivo .cpp para definir los métodos
};

#endif