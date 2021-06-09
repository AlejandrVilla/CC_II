#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main(){
    LinkedList listaEnteros;
    int n,num;

    cout<<"cantidad de elementos: ";cin>>n;
    while (n--){
        cout<<"valor: ";cin>>num;
        listaEnteros.insert(num);
    }
    
    cout<<"MOSTRANDO LISTA ENLAZADA\n";
    cout<<listaEnteros;

    cout<<"posicion del elemento a borrar: ";cin>>n;
    listaEnteros.remove(n);

    cout<<"MOSTRANDO LISTA ENLAZADA\n";
    cout<<listaEnteros;

    cout<<"elemento a buscar: ";cin>>n;
    if (listaEnteros.search(n))
        cout<<"ENCONTRADO\n";
    else
        cout<<"NO ENCONTRADO\n";
    /*
    LinkedList listaEnteros;
    cout<<listaEnteros;

    listaEnteros.insert(6);
    cout<<listaEnteros;

    listaEnteros.insert(8);
    cout<<listaEnteros;

    listaEnteros.insert(1);
    cout<<listaEnteros;

    listaEnteros.remove(2); //elimina en la posicion 2
    cout<<listaEnteros;

    listaEnteros.insert(2);
    cout<<listaEnteros;

    listaEnteros.insert(2);
    cout<<listaEnteros;

    listaEnteros.insert(8);
    cout<<listaEnteros;

    LinkedList listaEnteros2 = listaEnteros;    //constructor copia
    cout<<listaEnteros2;    //muestra la lista copiada*/
    /*
    if (listaEnteros.search(1))
        cout<<"ENCONTRADO\n";
    else
        cout<<"NO ENCONTRADO\n";

    if (listaEnteros.search(6))
        cout<<"ENCONTRADO\n";
    else
        cout<<"NO ENCONTRADO\n";

    if (listaEnteros.search(2))
        cout<<"ENCONTRADO\n";
    else
        cout<<"NO ENCONTRADO\n";

    if (listaEnteros.search(8))
        cout<<"ENCONTRADO\n";
    else
        cout<<"NO ENCONTRADO\n"; */ 
}