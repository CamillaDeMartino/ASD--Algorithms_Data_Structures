/*
    • Utilizzando il paradigma della programmazione ad oggetti ed il linguaggio C++ 11, progettare ed implementare una classe coda di minima 
      priorità minQ che erediti da una classe virtuale coda di priorità Q, in modo che gli oggetti di classe minQ non possano accedere agli
      attributi ed ai metodi della classe Q.
      La struttura dati verrà popolata leggendo il contenuto del file priorita.txt.
       Data una sequenza di interi (rappresentata da un array), trovare il k-esimo elemento più grande per ogni i=0..N-1.
        • seq=[10, 3, 21, 1, -1, 45, 8, 12, 78]
        • k=2
        • i=1 k-max=3
        • i=2 k-max=10
        • i=3 k-max=10
        • ...
*/

#include "MinPriorityQueue.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main(){

    MinPriorityQueue<int> *heap = new MinPriorityQueue<int>();
    string file = "priorita.txt";
    string num;
    fstream myfile;
    int k = 3;
    vector<int> vect;

    myfile.open(file.c_str(), ios::in);
    while(getline(myfile, num))
        vect.push_back(stof(num));

    cout<<endl<<"**Vettore**"<<endl;
    for(auto i:vect)
        cout<<i<<" ";
    cout<<endl;


    for(int i = 0; i < k ; i++)
        heap->insertHeap(vect.at(i));
    cout<<endl;

    heap->print();
    cout<<k<<"-esimo massimo: "<<heap->getRoot()<<endl;
          
    
    for(int i = k ; i < vect.size(); i++)
    {   cout<<endl;
        if(vect.at(i) > heap->getRoot())
        {
            cout<<vect.at(i)<<" > "<<heap->getRoot()<<endl;
            heap->insertHeap(vect.at(i));
            heap->extractRoot();
            heap->print();
            cout<<k<<"-esimo massimo: "<<heap->getRoot()<<endl;
        }
        else
        {
            cout<<vect.at(i)<<" < "<<heap->getRoot()<<endl;
            cout<<k<<"-esimo massimo: "<<heap->getRoot()<<endl;
        }
    }

    

    myfile.close();


    return 0;
}