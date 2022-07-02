#include "FORMA.h"

FORMA::FORMA(string _color, string _nombre_figura){//constructor
    color=_color;
    nombre_figura=_nombre_figura;
}

FORMA::~FORMA(){}//destructor

void FORMA::imprimir(){
    cout<<"\tEl color de su figura es: "<<color<<endl;
    cout<<"\tEl nombre de su figura es: "<<nombre_figura<<endl;
}

string FORMA::get_color(){//Para obtener el color
    return color;
}

void FORMA::set_nuevo_color(){//Para cambiar el color
    cout<<"\tIngrese nuevo color: "<<endl;
    cin>>color;
}

void FORMA::area(){}//para mostrar solo el area

float FORMA::get_area(){}//para cuando necesitemos extraer el area de alguna forma