#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Nodo.h"

template <class T>

class Lista
{
private:
    Nodo<T> *testa;
    Nodo<T> *coda;

    bool isVuota();
public:
    Lista();
    ~Lista();

    void Inserimento(T *);

    Nodo<T> *getTesta(){return testa;}
    Nodo<T> *getcoda(){return coda;}
};

template <class T> Lista<T> :: Lista()
{
    testa = nullptr;
    coda = nullptr;
}


template <class T> Lista<T>:: ~Lista()
{
    while(testa != nullptr)
    {
        Nodo<T> *temp = testa;
        testa = testa->getNext();
        delete temp;
    }

}

template <class T> bool Lista<T>::isVuota()
{
    if(this->testa == nullptr)
        return true;

    return false;
}


template <class T> void Lista<T>::Inserimento( T *bt)
{
    Nodo<T> *newNodo = new Nodo<T>(bt);

    if(!this->isVuota())
    {
        coda->setNext(newNodo);
        coda = newNodo;
    }
    else
    {
        testa = coda = newNodo;
    }
}
#endif