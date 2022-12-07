#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\Prova Impronta\Heap\HeapSort.h"
#include <iostream>
#include <vector>

using namespace std;
int main(){

    vector<int> tree = {30, 25, 20, 3, 2, 4};

    HeapSort<int> t = HeapSort<int>(tree);
    t.heapSort();
    cout<<"Alberello ordinato "<<endl;
    t.printArray();

    cout<<endl<<"Max Heap"<<endl;
    HeapSort<int> t2 = HeapSort<int>();

    for(int i = 0; i < tree.size(); i++)
      t2.insert(tree.at(i));

    t2.printArray();
    return 0;
}