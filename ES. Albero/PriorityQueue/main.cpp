/*
    • Progettare una classe PriorityQueue che implementi una coda
        di priorità basata su BinarySearchTree
*/

#include "MinPriorityQueue.h"
#include <iostream>

using namespace std;

int main(){

    MinPriorityQueue<int> albero = MinPriorityQueue<int>();
    albero.insert(10);
    albero.insert(13);
    albero.insert(14);
    albero.insert(16);
    albero.insert(12);
    albero.insert(17);
    albero.insert(11);
    
    cout<<endl<<"INORDER: ";
    albero.print();
    cout<<endl;

    cout<<endl<<"Minimo: "<<albero.getMinimum()<<endl;

    cout<<endl<<"ESTRAI MINIMO"<<endl;
    albero.extractMin();
    albero.print();
    cout<<endl;

    cout<<endl<<"DECREMENTO 12 -> 4"<<endl;
    albero.decreaseKey(12,4);
    albero.print();
    return 0;
}