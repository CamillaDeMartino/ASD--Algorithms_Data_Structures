#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H
#include "Nodo.h"
#include "Vertice.h"
#include <limits>
#include <queue>
#include <list>
#include <iostream>

using namespace std;

template<class T>
class GrafoOrientato
{
private:
    vector<Nodo<T>> grafo;
    list<Vertice<T>* > getListAdj(Vertice<T> *);

public:
    
    void addNodo(Nodo<T> );
    void addArco(int, Vertice<T> *);
    void BFS(Vertice<T> *);

    friend ostream &operator<<(ostream &out, GrafoOrientato<T> &obj)
    {
        for(auto i:obj.grafo)
            out<<i<<endl;

        return out;
    }
};


//un grafo lo possiamo vedere come un vettore di nodi
//ogni volta noi inseriamo un nodo
template<class T> void GrafoOrientato<T>::addNodo(Nodo<T> nodo)
{
    grafo.push_back(nodo);
}


//per ogni nodo inserito, poiché ha una lista di vertici, ne dobbiamo tracciare gli archi
//gli archi collegheranno il nodo inserito alla sua lista di adicacenza
//i è dunque il nodo a cui è collegato il vertice che passiamo
//i = 0 append vertice(f) significa che il nodo 0 sarà collegato al vertice f (creiamo la su alista di adiacenza)
template<class T> void GrafoOrientato<T>::addArco(int i, Vertice<T> *vertice)
{
    grafo.at(i).append(vertice);
}


//estraggo la lista di adiacenza di quel vertice
template<class T> list<Vertice<T> *> GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for(auto i: grafo)
    {
        if( i.getVertice() == vertice)
            return i.getList();
    }

    return grafo.at(0).getList();
}

template<class T> void GrafoOrientato<T>::BFS(Vertice<T> *sorgente)
{
    //inizializzazione
    for(auto u : grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        u.getVertice()->setDistanza(UINT16_MAX);
    }

    sorgente->setColor(Color::GREY);
    sorgente->setDistanza(0);
    sorgente->setPredecessore(nullptr);
    queue<Vertice<T>*> q;
    //inserimento nella coda FIFO
    q.push(sorgente);

    //finché la coda non è vuota
    while(!q.empty())
    {
        //front è utilizzato per recuperare il primo elemento di una coda.
        auto u = q.front();
        q.pop();

        list<Vertice<T>*> adj = getListAdj(u);

        for(auto v : adj)
        {
            if(v->getColor() == Color::WHITE)
            {
                v->setColor(Color::GREY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza() + 1);
                q.push(v);
            }
        }
        u->setColor(Color::BLACK);
    
    }

}

#endif