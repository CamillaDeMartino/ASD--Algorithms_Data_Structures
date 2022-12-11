#ifndef NODO_H
#define NODO_H
#include <iostream>


using namespace std;

template<class T>
class Nodo{

private:
    Nodo<T> *parent;
    Nodo<T> *left;
    Nodo<T> *right;

    T info;

public:
    Nodo(T);
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
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

template<class T> Nodo<T>::~Nodo()
{
    delete left;
    delete right;
    delete parent;
    delete info;
}



#endif