/*
    • Progettare un algoritmo ricorsivo che dato un ABR sommi le
      chiavi di tutte le foglie
*/


#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\ES. Albero\BinarySearchTree\BinarySearchTree.h"
#include <iostream>

using namespace std;

template<class T>
T sumLeavs(Nodo<T> *x)
{   if(x == nullptr)
        return 0;
    if(x->getLeft() == nullptr || x->getRight() == nullptr)
        return x->getInfo();
    else
        return sumLeavs(x->getLeft()) + sumLeavs(x->getRight());
};

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


    cout<<endl<<"Somma delle foglie: "<< sumLeavs(ABR.getRoot());
    return 0;
    
}