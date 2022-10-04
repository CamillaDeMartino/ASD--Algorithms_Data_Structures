#ifndef NODO_H
#define NODO_H
#include <iostream>

template <class T>

class Nodo
{
private:
    T *info;
    Nodo<T> *next; 
public:
    Nodo(T *);
    //~Nodo();

    void setInfo(T *);
    void setNext(Nodo<T> *);

    T *getInfo(){return info;}
    Nodo<T> *getNext(){return next;}
};

template <class T> Nodo<T>::Nodo(T *bt)
{
    info = bt;
    next = nullptr;
}

/*
Nodo::~Nodo()
{
}
*/

template <class T> void Nodo<T>::setInfo( T *bt)
{
    info = bt;
}

template <class T> void Nodo<T>::setNext(Nodo<T> *n)
{
    next = n;
}
#endif