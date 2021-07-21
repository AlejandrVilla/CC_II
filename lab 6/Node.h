#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>

template <typename T> class LinkedList;

template <typename T>
class Node{
    private:
        T value;
        Node<T>* next;
    public:
        Node( Node<T>* _next = nullptr ):next( _next ){}            //constructor recibe un parametro
        Node( T _value , Node<T>* _next = nullptr ):value( _value ),next( _next ){} //constructor recibe dos parametros
        void setValue( T );
        T getValue();
        void setNext( Node<T>* );
        Node<T>* getNext();

        friend class LinkedList<T>::Iterator;
};

template <typename T>
void Node<T>::setValue( T value ){ 
    this->value = value; 
}

template <typename T>
T Node<T>::getValue(){ 
    return value; 
}

template <typename T>
void Node<T>::setNext(Node<T>* next){ 
    this->next = next;  
}

template <typename T>
Node<T>* Node<T>::getNext(){ 
    return next; 
}

#endif