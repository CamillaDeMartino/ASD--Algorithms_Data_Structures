//#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\Prova Impronta\Heap\HeapSort.h"
#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\Prova Impronta\Heap\MaxPriority.h"
#include <iostream>
#include <vector>

using namespace std;
int main(){

    vector<int> tree = {25, 30, 20, 3, 2, 4};

    HeapSort<int> t = HeapSort<int>(tree);
    cout<<"Alberello: "<<endl;
    t.printArray();

    t.heapSort();
    cout<<"Alberello ordinato "<<endl;
    t.printArray();

    cout<<endl<<"Max Heap"<<endl;
    //HeapSort<int> t2 = HeapSort<int>();
    //for(int i = 0; i < tree.size(); i++)
      //t2.insert(tree.at(i));
    //t2.printArray();


    cout<<endl<<"Coda di priorita' MASSIMA"<<endl;
    vector<int> t1;
    MaxPriority<int> coda = MaxPriority<int>(t1);
    for(int i = 0; i < tree.size(); i++)
          coda.insertMax(tree.at(i));
    
    coda.print();
    cout<<"Massimo: "<<coda.getMaximum()<<endl;

    cout<<"Estratto massimo: "<<coda.extractMax()<<endl;
    coda.print();

    cout<<"Incrementa 4->30: "<<endl;
    coda.increaseKey(1, 30);
    coda.print();

    return 0;
}