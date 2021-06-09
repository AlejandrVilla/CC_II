#ifndef NODE_H
#define NODE_H

class Node{
    protected:
        int elem;       //valor
        Node* next;     //puntero al siguiente nodo
    public:
        Node(int _elem=0,Node* _next=NULL):elem(_elem),next(_next){}    //constructor
        Node(Node &);           //constructor copia
        void setElem(int);
        int getElem();
        void setNext(Node*);
        Node *getNext();

        friend std::ostream &operator<< (std::ostream &,const Node &);      //sobrecarga operador de insercion de flujo
};

Node::Node(Node &N){        //constructor copia
    elem=N.getElem();
    next=N.getNext();
}

void Node::setElem(int elem){
    this->elem=elem;
}

int Node::getElem(){
    return elem;
}

void Node::setNext(Node *next){
    this->next=next;
}

Node *Node::getNext(){
    return next;
}

std::ostream &operator<< (std::ostream &out,const Node &N){
    out<< N.elem ;
    return out;
}

#endif