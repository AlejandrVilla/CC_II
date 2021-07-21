#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "LinkedList.h" //clase que envuelve a Iterator
#include <iostream>

template <typename T> class Node;

template <typename T>
class LinkedList<T>::Iterator{
    private:
        Node<T>* it;            //puntero a nodo
        LinkedList<T>* list;    //puntero a la lista a la que pertenece
    public:
        Iterator( Node<T>* _it = nullptr , LinkedList<T>* _list = nullptr )
        :it( _it ),list( _list ){}          //constructor predeterminado
        Iterator( LinkedList<T>::Iterator& );           //constructor copia
        Iterator( LinkedList<T>::Iterator&& );         //constructor movimiento
        
        const LinkedList<T>::Iterator& operator=( const LinkedList<T>::Iterator& );     //sobrecarga operador de asignacion
        LinkedList<T>::Iterator& operator=( LinkedList<T>::Iterator&& );                //sobrecarga operador de asignacion
        T& operator*();                                         //sobrecarga operador *
        T* operator->();                                        //sobrecarga operador ->
        LinkedList<T>::Iterator operator++();                    //sobrecarga operador preincremento
        LinkedList<T>::Iterator operator++(int);                  //sobrecarga operador postincremento
        LinkedList<T>::Iterator operator--();                    //sobrecarga operador predecremento
        LinkedList<T>::Iterator operator--(int);                  //sobrecarga de opeador postdecremento
        bool operator==( const LinkedList<T>::Iterator& ) const;    //sobrecarga operador igualdad
        bool operator!=( const LinkedList<T>::Iterator& ) const;    //sobrecarga operador desigualdad

        friend class LinkedList<T>;
};

template <typename T>
LinkedList<T>::Iterator::Iterator( LinkedList<T>::Iterator& I ){    //constructor de copia
    it = I.it;                              //copia punteros
    list = I.list;
}

template <typename T>
LinkedList<T>::Iterator::Iterator( LinkedList<T>::Iterator&& I ){   //constructor de movimiento
    it = I.it;              //intercambia punteros
    list = I.list;
    I.it = nullptr;
    I.list = nullptr;
}

template <typename T>
const typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator=( const LinkedList<T>::Iterator &I ){  //copia un iterador en otro (copia)
    if ( &I != this ){
        it = I.it;          //copia punteros
        list = I.list;
    }
    return *this;
}

template <typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator=( LinkedList<T>::Iterator &&I ){  //intercambia valores de iteradores
    if ( &I != this ){
        it = I.it;              //intercambia punteros
        list = I.list;
        I.it = nullptr;
        I.list = nullptr;
    }
    return *this;
}

template <typename T>
T& LinkedList<T>::Iterator::operator*(){  
    return it->value;      //devuelve rvalue modificable permite *it = algo
}

template <typename T>
T* LinkedList<T>::Iterator::operator->(){  
    return &it->value;      //devuelve rvalue modificable permite it->algo
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(){          //devuelve el iterador
    it = list->find( it , true );               //apunta al sig elemento
    return *this;                                  
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++( int ){     //devuelve copia del iterador, despues avanza
    LinkedList<T>::Iterator temp = *this;           //crea copia del iterador actual
    it = list->find( it , true );                   //apunta al sig elemento
    return temp;                                    //devuelve el anterior por si se quiere modificar 
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--(){       //devuelve el iterador
    it = list->find( it , false );           //apunta al sig elemento
    return *this;          
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--( int ){     //devuelve copia del iterador, despues retrocede
    LinkedList<T>::Iterator temp = *this;       //crea copia del iterador actual
    it = list->find( it , false );              //apunta al ant elemento
    return temp;                                //devuelve el anterior por si se quiere modificar
}

template <typename T>
bool LinkedList<T>::Iterator::operator==( const LinkedList<T>::Iterator& N ) const{ //sobrcarga del operador de igualdad
    if ( it == N.it )       //si los punteros son diferentes
        return true;
    return false;
}

template <typename T>
bool LinkedList<T>::Iterator::operator!=( const LinkedList<T>::Iterator& N ) const{ //sobrcarga del operador de diferencia
    return !(it == N.it);  
}

#endif