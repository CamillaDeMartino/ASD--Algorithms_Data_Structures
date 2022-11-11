/*
    • Progettare un algoritmo ricorsivo che dato un ABR sommi le k
      chiavi più piccole
*/


#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\ES. Albero\BinarySearchTree\BinarySearchTree.h"
#include <iostream>

using namespace std;

template<class T>
T sumMinum(BinarySearchTree<T> ABR, Nodo<T> *x, int k)
{
    if(x == nullptr)
      return 0;  
    if(k == 0)
      return x->getInfo();
    else 
      return x->getInfo() + sumMinum(ABR, ABR.successor(x), k-1);

}

int main()
{
    BinarySearchTree<int> ABR;
    ABR.insert(13);
    ABR.insert(12);
    ABR.insert(16);
    ABR.insert(10);
    ABR.insert(11);
    ABR.insert(14);
    ABR.insert(17);

    cout<<"PREORDER: ";
    ABR.preorderVisit(ABR.getRoot());
    cout<<endl<<"INORDER: ";
    ABR.inorderVisit(ABR.getRoot());

    auto *min = ABR.minimumTree(ABR.getRoot());
    int k = 3;
    cout<<endl<<"La somma dei "<<k<<" minimi sono: "<<sumMinum(ABR,min,k-1);

  return 0;
}