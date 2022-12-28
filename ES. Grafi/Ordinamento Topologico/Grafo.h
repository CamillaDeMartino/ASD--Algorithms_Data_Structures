#ifndef GRAFO_H
#define GRAFO_H
#include "Nodo.h"
#include "Vertice.h"
#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

template<class T>
class Grafo
{
private:
    vector<Nodo<T>> grafo;
    list<Vertice<T>*> getList(Vertice<T> *);
    int time;
    void DFSVisit(Vertice<T> *);
    bool isDAG();

    //è necessario per l'ordinamento topologico che il grafo sia una DAG ossia un grafo senza cicli
    //N.B i cicli si verificano quando tutti i nodi adiacenti sono grigi
    stack<Vertice<T> *>L;
    int cicli;
public:

    void addNodo(Nodo<T> );
    void addArco(int, Vertice<T> *);
    bool DFS();
    void printOrdTop();
    void ordinamentoTopologico();

    friend ostream &operator<<(ostream &out, Grafo<T> &obj)
    {
        for(auto i:obj.grafo)
            out<<i<<endl;

        return out;
    }
};

template<class T> list<Vertice<T>*> Grafo<T>::getList(Vertice<T> *vertice)
{
    for(auto i:grafo)
    {
        if(i.getVertice() == vertice)
            return i.getListAdj();
    }

    return grafo.at(0).getListAdj();
}

template<class T> void Grafo<T>::addNodo(Nodo<T> nodo)
{
    grafo.push_back(nodo);
}

template<class T> void Grafo<T>::addArco(int i, Vertice<T> *vertice)
{
    grafo.at(i).append(vertice);
}


template<class T> bool Grafo<T>::DFS()
{
    cicli = 0;
    for(auto u:grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessor(nullptr);
        time = 0;
    }

    for(auto u:grafo)
    {
        if(u.getVertice()->getColor() == Color::WHITE)
            DFSVisit(u.getVertice());
    
    }

    if(cicli > 0)
        return true;
    else
        return false;
    
}


template<class T> void Grafo<T>::DFSVisit(Vertice<T> *u)
{
    u->setColor(Color::GRAY);
    u->setTempInzio(time++);

    list<Vertice<T>*> adj = getList(u);
    for(auto v: adj)
    {
        if(v->getColor() == Color::WHITE)
        {
            v->setPredecessor(u);
            DFSVisit(v);
        }
        else if(v->getColor() == Color::GRAY)
            cicli++;
    }
    u->setColor(Color::BLACK);
    u->setTempFine(time++);
    L.push(u);
}

template<class T> bool Grafo<T>::isDAG()
{
    if(DFS())
        return false;
    else
        return true;
}

template<class T> void Grafo<T>::ordinamentoTopologico()
{
    if(DFS())
    {
        cout<<endl<<"ORDINAMENTO TOPOLOGICO"<<endl;
        while(!L.empty())
            cout<<L.pop()<<" --> ";
        cout<<"NULL"<<endl;
    }
    else
        cout<<"SONO PRESENTI CICLI"<<endl;
}

template<class T> void Grafo<T>::printOrdTop()
{
    while(!L.empty())
        cout<<L.pop()<<" --> ";
    cout<<"NULL"<<endl;
}


#endif