/*
    • Progettare ed implementare un algoritmo ricorsivo che dato
       un array verifichi se rappresenta un heap binario
*/

#include "isHeap.h"
#include <vector>

using namespace std;

int main()
{
    //vector<int> tree{60, 50, 30, 10, 20};
    vector<int> tree{10, 20, 50, 60, 30};
    IsHeap<int> Tree;

    Tree.printIsHeap(tree, tree.size(), 0);
    cout<<endl;
    

}