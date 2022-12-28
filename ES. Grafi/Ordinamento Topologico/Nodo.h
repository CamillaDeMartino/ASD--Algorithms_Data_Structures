#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <list>
#include "Vertice.h"

using namespace std;

template<class T>
class Nodo
{
private:
    Vertice<T> *vertice;
    list<Vertice<T>*> listAdj;
public:
    Nodo(Vertice<T> *);
    Vertice<T> *getVertice(){return vertice;}
    list<Vertice<T>*> getListAdj(){return listAdj;}
    void append(Vertice<T> *);

    friend ostream &operator<<(ostream& out, const Nodo<T>& obj)
    {
        out<<*obj.vertice<<" --> ";
        for(auto i : obj.listAdj)
            out<<*i<<" --> ";
        out<<" NULL";

        return out;
    }
};

template<class T> Nodo<T>::Nodo(Vertice<T> *vertice)
{
    this->vertice = vertice;
}

template<class T> void Nodo<T>::append(Vertice<T> *vertice)
{
    listAdj.push_back(vertice);
}




#endif