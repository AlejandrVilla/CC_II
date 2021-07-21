#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Iterator.h"

using namespace std;
int main(){
    // ejemplo 1
    LinkedList<int>l1;
    l1.insert(5,0);
    l1.push_back(10);
    l1.push_front(1);
    for ( LinkedList<int>::Iterator it = l1.begin() ; it != l1.end() ; ++it){
        cout<<*it<<" ";
    }
    LinkedList<int>::Iterator it = l1.begin();
    *++it = 10;
    *it++ = 80;
    *--it = 90;
    *it-- = 100;
    cout<<'\n'<<*it;
    cout<<'\n'<<"tamaño: "<<l1.size();
    cout<<'\n';
    for ( LinkedList<int>::Iterator it2 = l1.begin() ; it2 != l1.end() ; ++it2){
        cout<<*it2<<" ";
    }
    cout<<'\n';
    LinkedList<int>::Iterator it2 = l1.begin();
    if ( it != ++it2 ){
        cout<< " \nson diferentes\n";
    }

    // it2 = it;
    // cout<<*it2;

    //ejemplo 2

    // LinkedList<string>l1(5,"queso");
    // l1.push_back("a");
    // l1.push_back("b");
    // l1.push_front("c");

    // for ( LinkedList<string>::Iterator it = l1.begin() ; it != l1.end() ; it++){
    //     cout<<*it<<" ";
    // }
    // cout<<"\ntamaño: "<<l1.size();

    // cout<<"\n\n";
    // l1.insert("maracuya",2);
    // l1.erase(0);
    // l1.erase(3);
    // l1.insert("fresa",0);
    // l1.erase(0);
    // l1.insert("pera",0);
    // LinkedList<string>::Iterator it2;
    // for ( it2 = l1.begin() ; it2 != l1.end() ; it2++ ){
    //     cout<<*it2<<' ';
    // }
    // cout<<"\ntamaño: "<<l1.size()<<'\n';

    // l1.erase(7);
    // for ( it2 = l1.begin() ; it2 != l1.end() ; it2++ ){
    //     cout<<*it2<<' ';
    // }
    // cout<<"\ntamaño: "<<l1.size()<<'\n';
    // l1.insert( *(--l1.end()) , 6 );
    // for ( it2 = l1.begin() ; it2 != l1.end() ; it2++ ){
    //     cout<<*it2<<' ';
    // }

    // ejemplo 3

    // LinkedList<int>l1;
    // LinkedList<int>l2(5,5);
    // LinkedList<int>::Iterator it = l2.begin();

    // cout<<*it<<'\n';
    // *it=10;
    // cout<<*it<<'\n';

    // LinkedList<int>::Iterator it2 = it; //const copia
    // cout<<*it2<<'\n';
    // LinkedList<int>::Iterator it3 = it2; //const copia

    // LinkedList<int>::Iterator it4;
    // it4 = it3;

    // it4 = l2.begin();

    // it++;
    // if ( it != it2 ){
    //     cout<< " \nson diferentes\n ";
    // }

    // *++it2 = 15;

    // if ( it == it2 ){
    //     cout<< " \nson iguales\n ";
    // }

    // it--;

    // *--it2 = 25;

    // for ( LinkedList<int>::Iterator it = l2.begin() ; it != l2.end() ; it++ )
    //     cout<<*it<<" ";
    // cout<<'\n';

    // l2.push_front(9);
    // l2.pop_back();
    // l2.push_back(15);

    // for ( LinkedList<int>::Iterator it = l2.begin() ; it != l2.end() ; it++ )
    //     cout<<*it<<" ";
    // cout<<'\n';

    // if ( l1 != l2 )
    //     cout<< " \nson diferentes\n ";
    
    // l1.insert(45,0);
    // l1 = l2;

    // if ( l1 == l2 )
    //     cout<< " \nson iguales\n ";
}