#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "Occorrenza.h"

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
    Nodo(T info):parent(nullptr),left(nullptr),right(nullptr),info(info){}

    ~Nodo()
    {    
    delete parent;
    delete left;
    delete right;

    };

    void setParent(Nodo<T> *parent){this->parent = parent;}
    void setLeft(Nodo<T> *left){this->left = left;}
    void setRight(Nodo<T> *right){this->right = right;}

    Nodo<T> *getParent(){return parent;}
    Nodo<T> *getLeft(){return left;}
    Nodo<T> *getRight(){return right;}
    T getInfo(){return info;}
    
};

/*template<class T> Nodo<T>::Nodo(T info)
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;

    this->info = info;

}*/


/*template<class T> Nodo<T>::~Nodo()
{
    delete parent;
    delete left;
    delete right;
}*/




#endif