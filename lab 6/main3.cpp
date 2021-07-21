#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Iterator.h"

using namespace std;
int main(){
    //ejemplo 1
    // LinkedList<string> lista(5,"queso");
    // cout<<"tamanio: "<<lista.size()<<'\n';
    // for ( LinkedList<string>::Iterator it=lista.begin() ; it != lista.end() ; it++ )
    //     cout<<*it<<" ";
    // cout<<'\n';
    // lista.clear();
    // for ( LinkedList<string>::Iterator it=lista.begin() ; it != lista.end() ; it++ )
    //     cout<<*it<<" ";
    // cout<<'\n';
    // cout<<"tamanio: "<<lista.size()<<'\n';

    // LinkedList<string> lista2(5,"queso");
    // lista = lista2;

    // for ( LinkedList<string>::Iterator it=lista.begin() ; it == lista.end() ; it++ )
    //     cout<<*it<<" ";
    // cout<<'\n';
    // cout<<"tamanio: "<<lista.size()<<'\n';

    //ejemplo 2
    LinkedList<string> lista;
    lista.push_back("primero");
    lista.push_back("penultimo");
    lista.push_back("ultimo");
    lista.pop_front();
    string c,s;
    s = lista.front();
    c = lista.back();
    cout<<s<<'\n';
    cout<<c<<'\n';
}