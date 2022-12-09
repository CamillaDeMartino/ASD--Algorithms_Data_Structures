#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main(){

    BinaryTree<int> ABR;

    ABR.insert(13);
    ABR.insert(12);
    ABR.insert(16);
    ABR.insert(10);
    ABR.insert(11);
    ABR.insert(14);
    ABR.insert(17);

    cout<<endl<<"RADICE: "<<ABR.getRoot()->getInfo()<<endl;
    cout<<"ABR: ";
    ABR.visitInorder(ABR.getRoot());

    cout<<endl<<endl<<"Minimo: "<<ABR.getMinimum(ABR.getRoot())->getInfo()<<endl;
    cout<<"Massimo: "<<ABR.getMaximum(ABR.getRoot())->getInfo()<<endl;

    Nodo<int> *nodo = ABR.treeSearch(ABR.getRoot(), 14);
    cout<<endl<<"Successore di "<<nodo->getInfo()<<" : "<<ABR.successor(nodo)->getInfo()<<endl;
    Nodo<int> *nodo1 = ABR.treeSearch(ABR.getRoot(), 11);
    cout<<"Predecessore di " << nodo1->getInfo()<<": "<<ABR.predecessor(nodo1)->getInfo()<<endl;
    cout<<endl;
    


    return 0;
}