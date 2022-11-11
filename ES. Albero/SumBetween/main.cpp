#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\ES. Albero\BinarySearchTree\BinarySearchTree.h"
#include <iostream>

using namespace std;

template<class T>
T sumBetween(Nodo<T> *x, int min, int max)
{
    if(x == nullptr) 
        return 0;
    
    if (x->getInfo() >= min && x->getInfo() <= max)
        return x->getInfo() + sumBetween(x->getLeft(),min,max) + sumBetween(x->getRight(),min,max);
    else if(x->getInfo() < min )                        //se è più piccolo del minimo, il figlio di sinistra sarà sicuramente minore del minimo
        return sumBetween(x->getRight(),min,max);      //poichè i figli sx sono più piccoli, quindi scendo a dx    
    else
         return sumBetween(x->getLeft(),min,max);
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

    int min = 11, max = 14;
    cout<<endl<<"Somma tra 11 e 14: "<< sumBetween(ABR.getRoot(), min, max);

    return 0;
}