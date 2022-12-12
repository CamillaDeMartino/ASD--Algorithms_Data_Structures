/*
    • Utilizzando il paradigma della programmazione ad oggetti ed il linguaggio C++ 11, progettare ed implementare una classe coda di minima 
      priorità minQ che erediti da una classe virtuale coda di priorità Q, in modo che gli oggetti di classe minQ non possano accedere agli
      attributi ed ai metodi della classe Q.
      La struttura dati verrà popolata leggendo il contenuto del file priorita.txt.
      Utilizzare la classe minQ per trovare il massimo numero di elementi distinti dopo aver rimosso k elementi(k<=n)

*/

#include "MinPriorityQueue.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

    MinPriorityQueue<int> Heap;
    string file = "priorita.txt";
    string num;
    fstream myfile;

    myfile.open(file.c_str(), ios::in);
    while(getline(myfile, num))
       Heap.insertHeap(stof(num));


    cout<<"***MINHEAP***"<<endl;
    //Heap.printArray();

    myfile.close();


    return 0;
}