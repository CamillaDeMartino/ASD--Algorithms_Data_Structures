#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

template<class T>
class Nodo
{
private:
    Nodo<T> *parent;
    Nodo<T> *left;
    Nodo<T> *right;

    T info;
    
public:
    Nodo(T info);
    ~Nodo();

    void setParent(Nodo<T> *p){parent = p;}
    void setLeft(Nodo<T> *l){left = l;}
    void setRight(Nodo<T> *r){right = r;}
    
    Nodo<T> *getParent(){return parent;}
    Nodo<T> *getLeft(){return left;}
    Nodo<T> *getRight(){return right;}
    T getInfo(){return info;}
};

template<class T> Nodo<T>::Nodo(T info)
{
    this->info = info;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

template<class T> Nodo<T>::~Nodo()
{
    delete parent;
    delete left;
    delete right;
}




#endif