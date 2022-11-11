/*
    • Progettare un algoritmo che dato un ABR ed una chiave k
      restitusca il successore dispari di k
*/

#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\ES. Albero\BinarySearchTree\BinarySearchTree.h"
#include <iostream>

using namespace std;

template<class T>
T shotsSuccessor(BinarySearchTree<T> ABR, Nodo<T> *x)
{
    auto *succ = ABR.successor(x);

    if(succ->getInfo()%2 != 0)
        return succ->getInfo();
    else
        return shotsSuccessor(ABR, succ);

}


int main(){

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

    auto *x = ABR.treeSearch(ABR.getRoot(), 11); //k=11
    cout<<endl;
    cout<<endl<<"Il successore dispari di "<<x->getInfo()<<" e' "<<shotsSuccessor(ABR,x)<<endl;
    cout<<endl;
    return 0;
}
