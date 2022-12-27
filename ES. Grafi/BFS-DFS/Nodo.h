//ogni nodo è collegato ad un insieme di vertici/nodi tramite una lista di adiacenza
//ogni nodo ha un vertice e una lista di adiacenza di quei vertici
#ifndef NODO_H
#define NODO_H
#include "Vertice.h"
#include <iostream>
#include <list>

template<class T>
class Nodo
{
private:
    Vertice<T> *vertice;
    list<Vertice<T>*> listaAdiacenza;


public:
    Nodo(Vertice<T> *vertice){
        this->vertice = vertice;
    }
   
   Vertice<T> *getVertice(){return vertice;}
   list<Vertice<T>*> getList(){return listaAdiacenza;}
   void append(Vertice<T> *);

   friend ostream &operator<<(ostream &out, const Nodo<T> &obj)
   {
        out<<*obj.vertice<<" --> ";
        for(auto i : obj.listaAdiacenza)
            out<<*i<<" --> ";
        out<<"NULL";
        return out;
   }

   
};

//aggiungo i vertici alla lista di adiacenza di QUEL ndoo
template<class T> void Nodo<T>::append(Vertice<T> *vertice)
{
    listaAdiacenza.push_back(vertice);
}

#endif