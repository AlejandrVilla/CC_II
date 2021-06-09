#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

class LinkedList{
    private:
        int size;       //tamaño de la lista
        Node *head;     //puntero al primer elemento
    public:
        LinkedList(int _size=0,Node *_head=NULL):size(_size),head(_head){}  //constructor
        LinkedList(LinkedList &);                                           //constructor copia
        ~LinkedList();                                                      //destructor

        int getSize();
        void insert(int);      //insertar elemento
        void remove(int);      //quitar elemento por posicion
        bool search(int);      //buscar elemento
        friend std::ostream &operator<<(std::ostream &,LinkedList &);   //sobrecarga operador insercion de flujo
};

LinkedList::LinkedList(LinkedList &L){  //constructor copia
    size=L.size;    //copia tamaño
    if (size==0)    //si no tiene elementos
        head=NULL;  //apunta a nada;
    else{
        Node *temp = L.head;                            //temp mueve por los elementos de la lista a copiar
        head = new Node(temp->getElem(),NULL);          //reserva memoria para un nuevo elemento
        temp = temp->getNext();                         //temp apunta al sig elemento
        Node *thisTemp = head;                          //thistemp se mueve por los elementos de la nueva lista
        for (int i=1;i<size;i++){                       //bucle para copiar valores
            thisTemp -> setNext( new Node( temp->getElem(),NULL ));     //nodo actual apunta aun nuevo nodo
            thisTemp = thisTemp->getNext();                             //avanza al sig nodo de la nueva lista
            temp = temp->getNext();                                     //avanza al sig nodo de la lista a copiar
        }
    }
}

LinkedList::~LinkedList(){      //destructor
    Node *aux{nullptr};         //aux para moverse por la lista
    while (head!=NULL){         //mientras no se llegue al final
        aux = head -> getNext() ;       //aux apunta al sig nodo
        delete head;            //borra el nodo actual
        head = aux;             //apunta al sig nodo
    }
}

int LinkedList::getSize(){
    return size;
}

void LinkedList::insert(int num){       //inserta elemento
    if ( size == 0){                    //si no tiene elementos
        head = new Node(num,NULL);      //crea un nuevo nodo
        size++;                         //aumenta tamaño
    }
    else{
        Node *temp = head;                      //temp avanza por la lista, representa al nodo actual
        Node *aux{nullptr};                     //aux guarda la direccion del nodo anterior
        for (int i=0; i<=size ;i++){
            if ( temp==NULL){                           //si se llego al final el numero es el mayor
                aux -> setNext( new Node(num,temp) );   //crea un nuevo nodo
                size++;                                 //aumenta el tamaño
                break;
            }
            else if ( num <= temp->getElem() && i==0){      //si numero es menor y esta en la primera posicion
                aux = new Node(num,temp);                   //crea un nuevo nodo que apunta al primer nodo
                head = aux;                                 //head apunta al nuevo nodo
                size++;                                     //aumenta el tamaño
                break;
            }
            else if ( num <= temp->getElem() ){             //si solo es menor y no esta en la primera posicion
                aux -> setNext( new Node(num,temp) );       //nodo anterior apunta a un nuevo nodo, el nuevo nodo apunta al actual
                size++;                                     //aumenta el tamaño
                break;                                      
            }       
            aux = temp;                     //aux apunta al nodo actual
            temp = temp->getNext();         //avanza al sig nodo
        }
    }
}


void LinkedList::remove(int pos){       //elimina un nodo por la posicion
    Node *temp = head;                  //temp avanza por la lista, representa al nodo actual
    Node *aux{nullptr};                 //aux guarda la direccion del nodo anterior

    if (pos==0){                        //elimina el primer elemento
        head = head -> getNext();       //head apunta al siguiente nodo
        size--;                         //disminuye el tamaño
        delete temp;                    //libera la memoria del nodo
    }
    else{
        for (int i=0;;i++){                             //bucle para viajar por los nodos
            if (i==pos){                                //si se llego a la posicion
                aux -> setNext( temp -> getNext() );    //nodo anterior apunta al nodo siguiente
                delete temp;                            //borra nodo actual
                size--;                                 //disminuye el tamaño
                break;
            }
            aux = temp;                 //aux apunta al nodo actual
            temp = temp->getNext();     //temp apunta al sig nodo
        }
    }
}

bool LinkedList::search(int num){       //busca un nodo
    Node *temp = head;                  //temp avanza por la lista, representa al nodo actual 
    Node *aux{nullptr};                 //aux guarda la direcicon del nodo anterior
    if (size == 0){                     //si no tiene elementos
        return false;                   //devuelve false
    }
    else{
        while ( temp != NULL){                  //mientras no se llegue al final
            if ( num == temp->getElem() )       //si lo encuentra
                return true;                    //devuelve true
            temp = temp->getNext();             //avanza al sig nodo
        }
        return false;                   //si no encontro devuelve false
    }
}

/*std::ostream &operator<< (std::ostream &out , LinkedList &L){
    Node *temp = L.head;
    for (int i=0;i<L.size;i++){
        out << "(" << temp->getElem() << ")" << '\t';
        temp = temp -> getNext();
    }
    out<<'\n';
    return out;
}*/
std::ostream &operator<< (std::ostream &out , LinkedList &L){   //sobrecarga del operador de insercion de flujo
    Node *temp = L.head;                //temp avanza por la lista, representa al nodo actual 
    for (int i=0;i<L.size;i++){
        out<<*temp<<'\t';               //usa la sobrecarga del objeto Nodo
        temp = temp -> getNext();       //avanza al sig nodo
    }
    out<<std::endl;
    return out;
}

#endif 