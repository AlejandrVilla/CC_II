#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Iterator.h"

using namespace std;

int main(){
    LinkedList<int>lista1;
    lista1.insert(5,0);
    for ( LinkedList<int>::Iterator it= lista1.begin();it!=lista1.end();){
        cout<<*it++<<" ";
    }
    cout<<"\n";
    lista1.push_front(1);
    lista1.push_back(13);
    for ( LinkedList<int>::Iterator it= lista1.begin();it!=lista1.end();){
        cout<<*it++<<" ";
    }
    cout<<"\n";

    LinkedList<int>::Iterator it = ++lista1.begin();
    ++it;
    cout<<*it<<'\n';
    
    LinkedList<int>lista2=lista1;
    lista2.push_back(48);
    for ( LinkedList<int>::Iterator it= lista2.begin();it!=lista2.end();){
        cout<<*it++<<" ";
    }

    LinkedList<int>lista3;
    LinkedList<int>lista4=lista3;
    for ( LinkedList<int>::Iterator it= lista3.begin();it!=lista3.end();){
        cout<<*++it<<" ";
    }
    cout<<"\n";
    for ( LinkedList<int>::Iterator it= lista4.begin();it!=lista4.end();){
        cout<<*it++<<" ";
    }
}