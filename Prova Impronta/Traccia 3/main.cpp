/*
    • Utilizzando il paradigma della programmazione ad oggetti ed il linguaggio C++ 11, progettare ed implementare una classe coda di minima 
      priorità minQ che erediti da una classe virtuale coda di priorità Q, in modo che gli oggetti di classe minQ non possano accedere agli
      attributi ed ai metodi della classe Q.
      La struttura dati verrà popolata leggendo il contenuto del file priorita.txt.
      Utilizzare la classe minQ per trovare il massimo numero di elementi distinti dopo aver rimosso k elementi(k<=n)

      • Es.: {5,4,4,3,4,6,2,1,2}, 
                per k=2 maxnum= 6(5,4,3,6,2,1), 
                per k=3 maxnum= 5(5,3,6,2,1)

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

    vector<int> vect;
    map<int,int> amap;
    map<int, int>::iterator it;
    vector<int>::iterator jt;

    myfile.open(file.c_str(), ios::in);
    while(getline(myfile, num))
        vect.push_back(stof(num));


    for(int i = 0; i < vect.size(); i++)
    {
        int elem = vect.at(i);
        it = amap.find(elem);

        if(it == amap.end())
            amap.insert(make_pair(elem, 1));
        else
            amap.at(elem)++;
    }   

    for (it = amap.begin(); it != amap.end(); it++)
    {
        cout<<"Numero: "<<(*it).first<<" =>> Occorrenza: "<<(*it).second<<endl;
        heap->insertHeap((*it).second);
    }

    cout<<"***MINHEAP***"<<endl;
    heap->print();
    



    

    myfile.close();


    return 0;
}