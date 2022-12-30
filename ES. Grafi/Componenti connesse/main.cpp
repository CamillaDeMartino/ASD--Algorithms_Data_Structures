/*
    Componenti fortemente connesse
*/

/*
    • Implementare le visite BFS e DFS
        – Iterative e ricorsive
*/

#include <iostream>
#include "Nodo.h"
#include "Grafo.h"
#include "Vertice.h"
#include <string>
#include <queue>


using namespace std;

int main(){

    Grafo<string> grafo;

    Vertice<string> a("A");
    Vertice<string> b("B");
    Vertice<string> c("C");
    Vertice<string> d("D");
    Vertice<string> e("E");
    Vertice<string> f("F");
    Vertice<string> g("G");
    Vertice<string> h("H");

    grafo.addNodo(Nodo<string>(&a));
    grafo.addNodo(Nodo<string>(&b));
    grafo.addNodo(Nodo<string>(&c));
    grafo.addNodo(Nodo<string>(&d));
    grafo.addNodo(Nodo<string>(&e));
    grafo.addNodo(Nodo<string>(&f));
    grafo.addNodo(Nodo<string>(&g));
    grafo.addNodo(Nodo<string>(&h));

    grafo.addArco(0, &b);         
    grafo.addArco(1, &e);        
    grafo.addArco(1, &f);         
    grafo.addArco(1, &c);         
    grafo.addArco(2, &g);         
    grafo.addArco(2, &d);         
    grafo.addArco(3, &c);
    grafo.addArco(3, &h);
    grafo.addArco(4, &a);
    grafo.addArco(4, &f);
    grafo.addArco(5, &g);
    grafo.addArco(6, &f);
    grafo.addArco(6, &h);
    grafo.addArco(7, &h);

    
    //grafo.grafoTrasposto();
    //cout << grafo << endl;
    //grafo.grafoTrasposto();

    //cout<<"**Grafo trasposto**"<<endl;
    //for(auto i: grafo.getGrafoT())
      //  cout<<i<<endl;
    
    cout<<endl<<"***DFS***"<<endl;
    for(auto i:grafo.DFS())
        cout<<i->getValue()<<endl;

    
    return 0;
}