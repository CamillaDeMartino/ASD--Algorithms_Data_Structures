#include <iostream>
#include "Nodo.h"
#include "GrafoOrientato.h"
#include "Vertice.h"
#include <string>

using namespace std;

int main(){

    //Vertice<string> a("A");
    //Vertice<string> b("B");
    //Vertice<string> c("C");
    //Nodo<string> n(&a);
    //n.append(&b);
    //n.append(&c);

    //cout<<a.getValue()<<endl;
    //cout<<a.getDistanza()<<endl;
    //cout<<a.getPredecessor()<<endl;

    //cout<<a<<endl;
    //cout<<n<<endl;

    GrafoOrientato<string> grafo;

    Vertice<string> a("A");
    Vertice<string> b("B");
    Vertice<string> c("C");
    Vertice<string> d("D");
    Vertice<string> e("E");
    Vertice<string> f("F");

    grafo.addNodo(Nodo<string>(&a));
    grafo.addNodo(Nodo<string>(&b));
    grafo.addNodo(Nodo<string>(&c));
    grafo.addNodo(Nodo<string>(&d));
    grafo.addNodo(Nodo<string>(&e));
    grafo.addNodo(Nodo<string>(&f));

    grafo.addArco(0, &b);         // 0|A|--->|B|   |--->|E|   |--->NULL
    grafo.addArco(0, &e);         // 1|B|--->|C|   |--->NULL
    grafo.addArco(1, &c);         // 2|C|--->|D|   |--->|E|   |--->NULL
    grafo.addArco(2, &d);         // 3|D|--->NULL
    grafo.addArco(2, &e);         // 4|E|--->|F|   |--->NULL
    grafo.addArco(4, &f);         // 5|F|--->NULL

    //cout<<"BFS"<<endl;
    //grafo.BFS(&a);

    cout<<"DFS"<<endl;
    grafo.DFS();
    cout << grafo << endl;



    return 0;
}