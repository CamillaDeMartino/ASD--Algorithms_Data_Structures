//#include "HeapSort2.h"
#include "MinPriority.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> vect = {30, 25, 20, 3, 2, 4};
    /*HeapSort2<int> tree = HeapSort2<int>(vect);

    cout<<"***MinHeap***"<<endl;
    tree.buildMinHeap();
    tree.printArray();

    cout<<"Ordinato decrescente"<<endl;
    tree.heapSort();
    tree.printArray();

    cout<<"***MinHeap con inserimento"<<endl;
    HeapSort2<int> tree2 = HeapSort2<int>();
    tree2.insert(30);
    tree2.insert(25);
    tree2.insert(20);
    tree2.insert(3);
    tree2.insert(2);
    tree2.insert(4);
    tree2.printArray();*/

    cout<<"***Con coda di MIN priorita'***"<<endl;
    MinPriority<int> queue = MinPriority<int>();
    queue.insert(30);
    queue.insert(25);
    queue.insert(20);
    queue.insert(2);
    queue.insert(3);
    queue.insert(4);

    queue.printArray();
    cout<<"Minimo: "<<queue.getMinimum()<<endl;
    
    cout<<"Estrazione minimo"<<endl;
    queue.extractMinimum();
    queue.printQueue();

    cout<<"Decremento 25-->1"<<endl;
    queue.decrease(4, 1);
    queue.printQueue();
    return 0;
}