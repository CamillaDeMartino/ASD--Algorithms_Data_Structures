/* 
   • Data una sequenza di interi (rappresentata da un array),
     trovare il k-esimo elemento più grande per ogni i=0..N-1.
    • seq=[10, 3, 21, 1, -1, 45, 8, 12, 78]
    • k=2
    • i=1 k-max=3
    • i=2 k-max=10
    • i=3 k-max=10
    • ...
*/

#include "MinPriorityQueue.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){

  vector<int> tree{10, 3, 21};

  MinPriorityQueue<int> albero = MinPriorityQueue<int>(tree, 3);

  albero.buildMinHeap();
  albero.printArray();
  cout<<"K-massimo: "<<albero.getMinimum()<<endl<<endl;

  albero.minHeapInsert(1);
  albero.printArray();
  cout<<"K-massimo: "<<albero.getMinimum()<<endl<<endl;

  albero.minHeapInsert(45);
  albero.printArray();
  cout<<"K-massimo: "<<albero.getMinimum()<<endl<<endl;

  albero.minHeapInsert(50);
  albero.printArray();
  cout<<"K-massimo: "<<albero.getMinimum()<<endl<<endl;

  return 0;
}