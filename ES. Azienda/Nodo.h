#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "Impiegato.h"


class Nodo
{
private:
    Impiegato *info;
    Nodo *next;

public:
    Nodo(Impiegato *);

    void setInfo(Impiegato *);
    void setNext(Nodo *);

    Impiegato *getInfo(){return info;}
    Nodo *getNext(){return next;}

};

Nodo::Nodo(Impiegato *i)
{
    info = i;
    next = nullptr;
}

/*Nodo::~Nodo()
{
    delete info;
    delete next;
}*/

void Nodo::setInfo(Impiegato *i)
{
    info = i;
}

void Nodo::setNext(Nodo *n)
{
    next = n;
}





#endif