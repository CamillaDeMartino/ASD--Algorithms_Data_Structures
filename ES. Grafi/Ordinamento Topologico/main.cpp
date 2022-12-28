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

    Vertice<string> g("G");
    Vertice<string> h("H");
    Vertice<string> i("I");

    grafo.addNodo(Nodo<string>(&g));            
    grafo.addNodo(Nodo<string>(&h));
    grafo.addNodo(Nodo<string>(&i));

    grafo.addArco(0, &h);         
    grafo.addArco(1, &i);         

    grafo.ordinamentoTopologico();
    cout<<grafo;

    return 0;
}