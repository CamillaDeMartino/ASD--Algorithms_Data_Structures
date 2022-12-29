/*
    • Implementare l'ordinamento topologico
*/

#include <iostream>
#include "Grafo.h"
#include "Nodo.h"
#include "Vertice.h"
#include <string>

using namespace std;

int main(){

    Grafo<string> grafo;

    /*Vertice<string> g("G");
    Vertice<string> h("H");
    Vertice<string> i("I");

    grafo.addNodo(Nodo<string>(&g));            
    grafo.addNodo(Nodo<string>(&h));
    grafo.addNodo(Nodo<string>(&i));

    grafo.addArco(0, &h);         
    grafo.addArco(1, &i);*/

    Vertice<string> shirt("shirt");
    Vertice<string> tie("tie");
    Vertice<string> jacket("jacket");
    Vertice<string> belt("belt");
    Vertice<string> pants("pants");
    Vertice<string> undershorts("undershorts");

    grafo.addNodo(Nodo<string>(&shirt));            
    grafo.addNodo(Nodo<string>(&tie));
    grafo.addNodo(Nodo<string>(&jacket));
    grafo.addNodo(Nodo<string>(&belt));            
    grafo.addNodo(Nodo<string>(&pants));
    grafo.addNodo(Nodo<string>(&undershorts));

    grafo.addArco(0, &tie);         
    grafo.addArco(0, &belt);
    grafo.addArco(1, &jacket);         
    grafo.addArco(3, &jacket);
    grafo.addArco(4, &belt);         
    grafo.addArco(5, &pants);
    
    grafo.ordinamentoTopologico();

    return 0;
}