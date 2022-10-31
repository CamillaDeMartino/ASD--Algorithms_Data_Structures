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

  vector<int> tree{106, 105, 104, 103, 110, 109, 108, 107};

  MinPriorityQueue<int> albero = MinPriorityQueue<int>(tree);


  /*albero.minHeapInsert(106);
  albero.minHeapInsert(105);
  albero.minHeapInsert(104);
  albero.minHeapInsert(103);
  albero.minHeapInsert(110);
  albero.minHeapInsert(109);
  albero.minHeapInsert(108);
  albero.minHeapInsert(107);*/

  albero.printArray();

  cout<<"Nuovo Albero"<<endl;
  albero.printArray();

  albero.decreaseKey(2, 100);
  cout<<"Nuovo Albero"<<endl;
  albero.printArray();



  return 0;
}