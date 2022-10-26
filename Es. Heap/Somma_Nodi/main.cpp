/*
    • Progettare ed implementare una algoritmo che, dato un Min-Heap ed un valore X, 
      stampi la somma dei valori dei nodi minori di X.
    
    • Es.: X=8 -> S=13
*/
#include "MinHeap.h"
#include <vector>

using namespace std;

int main()
{
    vector<int> tree;
    MinHeap<int> minTree = MinHeap<int>(tree);

    minTree.insert(10);
    minTree.insert(30);
    minTree.insert(50);
    minTree.insert(60);
    minTree.insert(20);

    minTree.printArray();

    int sum;
    sum = minTree.sum(35,0);
    cout<<"somma elementi minori di 35: "<<sum<<endl;

    return 0;
}