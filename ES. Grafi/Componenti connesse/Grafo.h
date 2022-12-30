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
    vector<Nodo<T>> grafoTras;

    list<Vertice<T>*> getList(Vertice<T> *);
    int time;
    void DFSVisit(Vertice<T> *, stack<Vertice<T> *> *);
    void DFSVisit2(Vertice<T> *);
    
public:

    void addNodo(Nodo<T> );
    void addArco(int, Vertice<T> *);
    vector<Vertice<T>*> DFS();
    void printOrdTop();
    void ordinamentoTopologico();

    //componenti fortemente connesse
    void grafoTrasposto();
    int trovaIndice(Vertice<T> *v);
    vector<Nodo<T>> getGrafoT(){return grafoTras;}
    //vector<Vertice<T>*> getSSC(){return SSC;}

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


template<class T> vector<Vertice<T>*> Grafo<T>::DFS()
{
    stack<Vertice<T> *> L;
    
    vector<Vertice<T> *> SSC;
    for(auto u:grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessor(nullptr);
        time = 0;
    }

    for(auto u:grafo)
    {
        if(u.getVertice()->getColor() == Color::WHITE)
        {
            
            DFSVisit(u.getVertice(), &L);  
            auto *v = L.top();
        }  
         
    }
    
    this->grafoTrasposto();
   

    while(!L.empty())
    {
        auto *v = L.top();
        cout<<"coda: "<<*v<<endl;
        L.pop();
        
        if(v->getColor() == Color::WHITE)
        {
            cout<<"nel if "<<*v<<endl;
            DFSVisit2(v);
            SSC.push_back(v);
        }
    }

    return SSC;
    
}


template<class T> void Grafo<T>::DFSVisit(Vertice<T> *u, stack<Vertice<T> *> *L)
{
    
    u->setColor(Color::GRAY);
    u->setTempInzio(time++);

    list<Vertice<T>*> adj = getList(u);
    for(auto v: adj)
    {
        if(v->getColor() == Color::WHITE)
        {
            v->setPredecessor(u);
            DFSVisit(v, L);
        }
           
    }
    u->setColor(Color::BLACK);
    u->setTempFine(time++);
    L->push(u);


}

template<class T> void Grafo<T>::DFSVisit2(Vertice<T> *u)
{
    u->setColor(Color::GRAY);
    u->setTempInzio(time++);

    list<Vertice<T>*> adj = getList(u);
    for(auto v: adj)
    {
        if(v->getColor() == Color::WHITE)
        {
            v->setPredecessor(u);
            DFSVisit2(v);
        }
        
            
    }
    u->setColor(Color::BLACK);
    u->setTempFine(time++);
    
}

template<class T> void Grafo<T>::grafoTrasposto()
{
    for(auto u : grafo)
    {
        Nodo<T> n(new Vertice<T>(u.getVertice()->getValue()));
        grafoTras.push_back(n);
    }


    for(auto u:grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessor(nullptr);
        time = 0;
    }

    for(auto u:grafoTras)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessor(nullptr);
        u.getListAdj().clear();
        time = 0;
    }

    for(auto u : grafo)
    {
        list<Vertice<T>*> adj = getList(u.getVertice());
        for(auto v: adj)
            grafoTras.at(trovaIndice(v)).append(u.getVertice());
        
    }

    

    
}


template<class T> int Grafo<T>::trovaIndice(Vertice<T> *v)
{
    for(int i = 0; i < grafo.size(); i++)
    {
        if(v == grafo.at(i).getVertice())
            return i;
    }
    return -1;

}
#endif