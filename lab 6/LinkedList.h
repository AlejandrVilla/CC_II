#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>

template <typename T> class Node;

template <typename T>
class LinkedList{
    private:
        Node<T>* head;      //puntero a la cabeza
        Node<T>* _end;      //puntero al elemento despues del ultimo
        int _size;          //tamaño
        
    public:
        class Iterator;         //iterator pertenece a linkedlist
        //constructors
        explicit LinkedList( )
        :_size( 0 ),head( nullptr ){ _end = new Node<T>( nullptr ); }  //constructor por defecto 
        LinkedList( int, T );                               //constructor recive tamaño y elementos
        LinkedList( LinkedList<T> & );                      //constructor copia
        LinkedList( LinkedList<T> && );                     //constructor movimiento
        //destructor
        ~LinkedList();                                      //destructor
        //capacity          
        bool empty();                       //true si esta vacio, false si no
        int size(){ return _size; }         //devuelve tamaño
        //element access
        T front();                  //devuelve el primer elemento
        T back();                   //devuelve el ultimo elemento
        //modifiers
        void push_front( T );       //inserta al comienzo
        void pop_front( );          //elimina al comienzo
        void push_back( T );        //inserta al final
        void pop_back( );           //elimina al final
        void insert( T , int );     //inserta segun posicion
        void erase( int );          //elimina segun posicion
        void clear();               //limpia la lista
        //iterators
        Node<T>* find( Node<T>* , bool );       //defuelve un puntero segun la posicion
        LinkedList<T>::Iterator begin();        //devuelve iterador al primer elemento
        LinkedList<T>::Iterator end();          //devuelve iterador al final
        //overloads
        const LinkedList<T>& operator=( const LinkedList<T>& );     //sobrecarga operador asignacion (lvalue)
        LinkedList<T>& operator=( LinkedList<T>&& );                //sobrecarga operador asignacion (rvalue)
        bool operator==( const LinkedList<T>& ) const ;             //sobrecarga de operador igual
        bool operator!=( const LinkedList<T>& ) const ;             //sobrecarga de operador diferencia
};

template <typename T>
LinkedList<T>::LinkedList( int size , T value ){   //constructor recibe tamaño y valor
    head = nullptr;
    _end = new Node<T>( nullptr );                  //crea nodo que esta despues del ultimo
    _size = 0;
    while ( size-- )
        push_back( value );                         //inserta valores
}

template <typename T>
LinkedList<T>::LinkedList( LinkedList<T> & L){      //constructor copia
    head = nullptr ;
    _end = new Node<T>( nullptr );                  //crea nodo que esta despues del ultimo
    _size = 0;
    Node<T>* temp = L.head;
    while( temp != nullptr && temp != L._end ){     //mientras no se llegue al final de la segunda lista
        push_back( temp->getValue() );              //inserta elemento usando valores de la segunda lista
        temp = temp->getNext();
    }
}

template <typename T>
LinkedList<T>::LinkedList( LinkedList<T> && L){     //constructor de movimiento
    head = L.head;                                  //intercambia datos
    _end = L._end;
    size = L.size;
    L.head = nullptr;
    L._end = nullptr;
    L.size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){                   //destructor
    Node<T>* temp = nullptr;
    if ( head != nullptr ){                     //si no esta vacio
        while ( head != nullptr ){              //mientras no llegue al final
            temp = head->getNext();             //guarda el sig
            delete head;                        //libera memoria
            head = temp;                        //avanza al sig
        }
    }else{                                      //si esta vacio
        delete _end;
    }
}

template <typename T>
bool LinkedList<T>::empty(){        
    if ( _size == 0 )               //si esta vacio
        return true;
    return false;
}

template <typename T>
T LinkedList<T>::front(){                       //devuelve el primer elemento de la lista
    try {
        if ( _size == 0 ){                      //si esta vacio                        
            throw "error lista vacia";          //arroja excepcion
        }else{                                  //si no esta vacio
            return head->getValue();            //devuelve el valor de head
        }
    }catch (const char* msg) {
         std::cout << msg << '\n';              //muestra excepcion
    }
    return head->getValue();
}

template <typename T>
T LinkedList<T>::back(){                                //devuelve el ultimo elemento de la lista
    try {
        if ( _size == 0 ){                              //si esta vacio
            throw "error lista vacia";                  //arroja excepcion
        }else{                                          //si no esta vacio
            return find( _end , false )->getValue();    //devuelve el valor del ultimo elemento
        }
    }catch (const char* msg) {
         std::cout << msg << '\n';                      //muestra excepcion
    }
    return find( _end , false )->getValue();
}

template <typename T>
void LinkedList<T>::push_front( T value ){              //inserta al comienzo
    Node<T>* nodo = new Node<T>{ value , nullptr };     //reserva memoria
    if ( head == nullptr ){                             //si esta vacio
        head = nodo;                                    //inserta
        head -> setNext(_end);                          //nuevo nodo apunta a _end
    }else{
        Node<T>* aux = head;                            //aux guarda head
        head = nodo;                                    //inserta nuevo nodo
        head->setNext(aux);                             //nuevo nodo apunta a aux
    }
    _size++;                                             
}

template <typename T>
void LinkedList<T>::pop_front(){                    //elimina al comienzo
    try {
        if ( head == nullptr ){                         //si esta vacio
            throw "error lista vacia";                  //arroja excepcion
        }else{
            Node<T>* aux = head->getNext();             //guarda el siguiente
            delete head;                                //elimina el primero
            head = aux;                                 //apunta al siguiente
            _size--;
        }
    }catch (const char* msg) {
         std::cout << msg << '\n';                      //muestra excepcion
    }  
}

template <typename T>
void LinkedList<T>::push_back( T value ){               //inserta al final
    Node<T>* nodo = new Node<T>{ value , nullptr };     //reserva memoria
    if ( head == nullptr ){                             //si esta vacio
        head = nodo;                                    //inserta
        head -> setNext(_end);                          //nuevo nodo apunta a _end
    }
    else{
        Node<T>* temp = head;                           //temp avanza por la lista
        while ( temp -> getNext() != _end ){            //mientras el siguiente no llegue a _end
            temp = temp->getNext();                     //avanza
        }
        temp -> setNext( nodo );                        //inserta al final  
        nodo -> setNext( _end );                        //nuevo nodo apunta a _end
    }
    _size++;
}

template <typename T>   
void LinkedList<T>::pop_back(){                         //elimina al final
    try {
        if ( head == nullptr ){                             //si esta vacio
            throw "error lista vacia";                      //arroja excepcion
        }else{
            Node<T>* temp = head;                           //temp avanza por la lista
            Node<T>* ant = nullptr;                         //ant guarda el anterior
            while ( temp->getNext() != _end ){              //mientras el sig no llegue al final
                ant = temp;                                 //ant apunta al actual
                temp = temp->getNext();                     //temp avanza
            }
            delete temp;                                    //elimina el ultimo
            ant->setNext( _end );                           //ant next apunta a _end
            _size--;
        }
    }catch (const char* msg){   
         std::cout << msg << '\n';                          //muestra excepcion
    }  
}

template <typename T>
void LinkedList<T>::insert( T value , int pos ){        //inserta valor segun posicion
    Node<T>* nodo = new Node<T>( value , nullptr );     //crea nodo
    Node<T>* temp = head;                               //guarda actual
    Node<T>* ant = nullptr;                             //guarda anterior
    if ( _size != 0 ){                                  //si hay almenos un elemento
        if ( pos != 0){                                 //si la posicion no es cero
            for ( int i=0 ; i!=pos ; i++ ){             //avanza hasta llegar a la posicon
                ant = temp;
                temp = temp->getNext();
            }
            ant->setNext( nodo );                       //anterior apunta al nodo
            nodo->setNext( temp );                      //nodo apunta al actual
        }else{                                          //si la posicion es cero
            head = nodo;                                //head apunta a nodo    
            nodo->setNext( temp );                      //nodo apunta al que era primera
        }   
    }else{                                              //si no hay elementos   
        head = nodo;                                    //inserta nodo al comienzo
        nodo->setNext( _end );                          //nodo apunta a _end, que esta despues del ultimo
    }
    _size++;
}

template <typename T>
void LinkedList<T>::erase( int pos ){              //elimina segun posicion
    Node<T>* temp = head;                           //temp avanza por la lista
    Node<T>* ant = nullptr;                         //ant guarda el anterior
    if ( pos != 0 ){                                //si la posicion es 0
        for( int i=0; i!=pos ; i++){                //avanza hasta coincidir la posicion
            ant = temp;
            temp = temp->getNext();
        }
        ant->setNext( temp->getNext() );            //anterior apunta al siguiente
        delete temp;                                //borra actual
    }else{
        head = head->getNext();                     //head apunta al sig
        delete temp;                                //borra el actual
    }
    _size--;
}

template <typename T>
void LinkedList<T>::clear(){
    Node<T>* temp = nullptr;
    if ( head != nullptr ){                     //si no esta vacio
        while ( head != _end ){                 //mientras no llegue al final
            temp = head->getNext();             //guarda el sig
            delete head;                        //libera memoria
            head = temp;                        //avanza al sig
        }
    }
    head = nullptr;
    _size = 0;
}

template <typename T>
Node<T>* LinkedList<T>::find( Node<T>* N, bool opcion ){        //duvuelve puntero comparando direccion de memoria
                                                                //opcion define si el valor a retornar sera el sig o el anterior
    Node<T>* temp = head;                       //temp avanza por la lista
    Node<T>* ant = nullptr;                     //guarda el anterior
    for ( int i=0 ; ; i++){                         
        if ( temp == N && opcion )              //si opcion = true, tomar el elemento sig guiente
            return temp->getNext();             //devuelve el puntero al sig elemento
        if ( temp == N && !opcion )             //si opcion = false, tomar elemento anterior
            return ant;                         //devuelve el puntero al anterior
        ant = temp;                             //ant apunta al anterior
        temp = temp->getNext();                 //temp avanza
    }
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin(){        //devuelve iterador al primer elemento
    if ( _size != 0 ){                                          //si hay almenos un elemento
        LinkedList<T>::Iterator it( head , this );              //crea iterador apuntando al primer elemento
        return it;
    }else{                                                      //si no hay elementos
        LinkedList<T>::Iterator it( _end , this );              //devuelve _end, elemento que esta despues del ultimo
        return it;
    }
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end(){      //devuelve iterador al elemento que esta despues del ultimo
    LinkedList<T>::Iterator it( _end , this );              //crea iterador apuntado a _end
    return it;
}   

template <typename T>
const LinkedList<T>& LinkedList<T>::operator=( const LinkedList<T>& L ){
    if ( &L != this ){
        Node<T>* temp = head;
        if ( head != nullptr ){                 //si hay almenos un elemento
            while ( temp != nullptr ){          //borra todo
                temp = head->getNext();         //guarda el sig
                delete head;                    //libera memoria
                head = temp;                    //avanza al sig
            }
        }else{                          //si no hay elementos
            delete _end;                //borra _end
        }
        _end = new Node<T>( nullptr );                      //crea nuev nodo _end
        temp = L.head;                                      //avanza por la lista a copiar
        while ( temp != nullptr && temp != L._end  ){
            push_back( temp->getValue() );                  //inserta valor
            temp = temp->getNext();                         //avanza el sig
        }
        _size = L._size;
    }
    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=( LinkedList<T>&& L ){   
    if ( &L != this ){
        head = L.head;          //intercambia valores
        _end = L._end;
        _size = L._size;
        L.head = nullptr;
        L._end = nullptr;
        L._size = 0;
    }
    return *this;
}

template <typename T>
bool LinkedList<T>::operator==( const LinkedList<T>& L )const{
    if ( _size != L._size )                                       //si los tamaños son diferentes
        return false;
    else{                                                       //si los tamaños son iguales
        Node<T>* temp = head;                                   //temp avanza por la lista actual
        Node<T>* temp2 = L.head;                                //temp2 avanza por la lista a copiar
        while ( temp != _end ){
            if ( temp->getValue() != temp2->getValue() )        //si los valores son diferentes
                return false;
            temp = temp->getNext();
            temp2 = temp2->getNext();
        }
    }
    return true;
}

template<typename T>
bool LinkedList<T>::operator!=( const LinkedList<T>& L )const{
    return !( *this == L );                                         //usa la sobrecarga de igualdad
}

#endif