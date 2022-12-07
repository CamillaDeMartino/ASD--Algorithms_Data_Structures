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

  vector<int> tree{10, 3, 21, 1, -1, 25, 8, 50};
  MinPriorityQueue<int> albero = MinPriorityQueue<int>();
  int k = 3;
  
  for(int i = 0; i < k; i++)
  {
    albero.minHeapInsert(tree.at(i));
  }
  albero.printArray();
  cout<<k<<"-elemento piu' grande: "<<albero.getMinimum()<<endl<<endl;


  for(int j = k; j < tree.size(); j++)
  {
    if(tree.at(j) > albero.getTree().at(0))
    {
      cout<<tree.at(j)<<" > "<<albero.getTree().at(0)<<endl;
      cout<<"Elemento piu' grande, inserito!"<<endl;   
      albero.minHeapInsert(tree.at(j));
      albero.extractMin();
 
    }
    else
    {
      cout<<tree.at(j)<<" < "<<albero.getTree().at(0)<<endl;
      cout<<"Elemento piu' piccolo, non inserito!"<<endl;
    }

    cout<<k<<"-elemento piu' grande: "<<albero.getMinimum()<<endl;
    albero.printArray(); 
  }
  

  return 0;
}