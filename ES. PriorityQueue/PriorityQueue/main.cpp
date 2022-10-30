/*
  • Progettare ed implementare una classe Priority-queue che implementi le seguenti operazioni
    • Insert(S,x)
    • Maximum(S) / Minimum(S)
    • Extract-Max(S) / Extract-Min(S)
    • Increase-priority(S,x,k) / Decrease-priority(S,x,k)
*/

#include "MaxPriorityQueue.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> tree;

    MaxPriorityQueue<int> albero = MaxPriorityQueue<int>(tree);


    albero.maxHeapInsert(106);
    albero.maxHeapInsert(105);
    albero.maxHeapInsert(104);
    albero.maxHeapInsert(103);
    albero.maxHeapInsert(110);
    albero.maxHeapInsert(109);
    albero.maxHeapInsert(108);
    albero.maxHeapInsert(107);

    albero.printArray();

    cout<<"Massimo: "<<albero.extractMax()<<endl;
    albero.printArray();
    
    albero.increaseKey(2, 120);
    albero.printArray();

    return 0;
}