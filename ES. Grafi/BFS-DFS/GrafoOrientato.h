#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H
#include "Nodo.h"
#include "Vertice.h"
#include <limits>
#include <queue>
#include <list>
#include <iostream>
#include <stack>

using namespace std;

template<class T>
class GrafoOrientato
{
private:
    vector<Nodo<T>> grafo;
    list<Vertice<T>* > getListAdj(Vertice<T> *);

    //DFS
    int time;                   //tempo per la scoperta DFS
    void DFSVisit(Vertice<T> *);

public:
    
    void addNodo(Nodo<T> );
    void addArco(int, Vertice<T> *);
    void BFS(Vertice<T> *);
    void BFSRecursive(queue<Vertice<T>*> );

    //DFS
    void DFS();
    void DFSIterative(Vertice<T> *);

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

    sorgente->setColor(Color::GRAY);
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
                v->setColor(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza() + 1);
                q.push(v);
            }
        }
        u->setColor(Color::BLACK);
    
    }

}

template<class T> void GrafoOrientato<T>::BFSRecursive(queue<Vertice<T> *> queue)
{
    static bool isFirst = true;

    if(isFirst)
    {
        for(auto u : grafo)
        {
            u.getVertice()->setColor(Color::WHITE);
            u.getVertice()->setPredecessore(nullptr);
            u.getVertice()->setDistanza(UINT16_MAX);
        }

        isFirst = false;
    }

    if(!queue.empty())
    {
        auto u = queue.front();
        queue.pop();

        list<Vertice<T>*> adj = getListAdj(u);

        for(auto v : adj)
        {
            if(v->getColor() == Color::WHITE)
            {
                v->setColor(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza() + 1);
                queue.push(v);
            }
        }
        u->setColor(Color::BLACK);
        BFSRecursive(queue);
    }
}



template<class T> void GrafoOrientato<T>::DFS()
{
    //inizializzazione
    for(auto u : grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        time = 0;
    }

    //chiama la visiita per ogni nodo i cui adiacenti sono bianchi
    for(auto u : grafo)
    {
        if(u.getVertice()->getColor() == Color::WHITE)
            DFSVisit(u.getVertice());
    }

}


template<class T> void GrafoOrientato<T>::DFSVisit(Vertice<T> *u)
{
    u->setColor(Color::GRAY);
    u->setTempInizio(time++);

    list<Vertice<T>*> adj = getListAdj(u);
    for(auto v: adj)
    {
        if(v->getColor() == Color::WHITE)
        {
            v->setPredecessore(u);
            DFSVisit(v);
        }
    }
    u->setColor(Color::BLACK);
    u->setTempFine(time++);
}

template<class T> void GrafoOrientato<T>::DFSIterative(Vertice<T> *sorgente)
{
    for(auto u : grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        time = 0;
    }

    //per implementare un dfs iterativa abbiamo bisogno di uno stack perché 
    //il primo elemento che vine colorato di nero è l'ulitmo inserito
    //necessitiamo dunque di una struttura LIFO tipica degli stack

    stack<Vertice<T> *> stack;
    stack.push(sorgente);

    while (!stack.empty())
    {
        auto u = stack.top();
        stack.pop();

        //ci serve il vertice bianco
        if(u->getColor() == Color::WHITE)
        {
            u->setColor(Color::GRAY);
            u->setTempInizio(time++);
        }
            //se un nodo adiacente non è sttao ancora visitato inseriscilo nello stack
            list<Vertice<T>*> adj = getListAdj(u);
            for(auto v: adj)
            {
                if(v->getColor() == Color::WHITE)
                    stack.push(v);
            }

            u->setColor(Color::BLACK);
            u->setTempFine(time++);
        
    }

}

#endif