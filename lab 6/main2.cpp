#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Iterator.h"

using namespace std;

struct Ficha{
    string nombre;
    string nro;
    int edad;
};

int main(){
    LinkedList<Ficha>fichas;
    int n;
    cout<<"numero de fichas: ";cin>>n;fflush(stdin);
    while(n--){
        string nombre,nro;
        int edad;
        cout<<"\n-----------INGRESE DATOS DE FICHA-----------\n";
        cout<<"nombre: ";getline(cin,nombre);fflush(stdin);
        cout<<"nro: ";getline(cin,nro);fflush(stdin);
        cout<<"edad: ";cin>>edad;fflush(stdin);
        Ficha f;
        f.nombre=nombre;
        f.nro=nro;
        f.edad=edad;
        fichas.push_back(f);
    }
    cout<<'\n';
    for ( LinkedList<Ficha>::Iterator it=fichas.begin() ; it != fichas.end() ; it++ ){
        cout<<"nombre: "<<it->nombre<<'\n';
        cout<<"nro: "<<it->nro<<'\n';
        cout<<"edad: "<<it->edad<<'\n';
    }
}