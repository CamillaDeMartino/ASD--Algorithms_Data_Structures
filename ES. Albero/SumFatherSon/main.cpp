/*
    • Dato un ABR, trovare la coppia di nodi padre-figlio con la
      minima differenza tra le chiavi
*/


#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\ES. Albero\BinarySearchTree\BinarySearchTree.h"
#include <iostream>
#include <limits.h>

using namespace std;

template<class T>
Nodo<T> *minNodo(Nodo<T> *nodo){

    Nodo<T> *diff1, *diff2;

    if (nodo == nullptr)       //Controllo se sono foglia allora restituisco me stesso, sarò il puù piccolo
        return nodo;       
    else
    {
        diff1 = minNodo(nodo->getLeft());           //cerco il minimo a sx
        diff2 = minNodo(nodo->getRight());          //cerco il minimo a dx
    }
    
    return minDiff(diff1, diff2, nodo);

}

//calcolo della differenza più piccola
template<class T>
Nodo<T> *minDiff(Nodo<T> *A,Nodo<T> *B, Nodo<T> *C)
{
    Nodo<T> *min_nodo;

    if (differenza(A) <= differenza(B))
        min_nodo = A;
    else
        min_nodo = B;
    
    if (differenza(C) <= differenza(min_nodo))
        min_nodo = C;

    return min_nodo;
    
}

template<class T>
int differenza(Nodo<T> *nodo)
{

    if (!nodo || !nodo->getParent())    //se non ha padre e se è nullo
        return UINT16_MAX;              //ritorna +infinito, nodo sentinella
    else
        return abs(nodo->getInfo() - nodo->getParent()->getInfo());    //altrimenti ritorna la differenza con te stesso e tuo padre    
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

    auto nodo = minNodo(ABR.getRoot())->getInfo();
    auto nodo_padre = minNodo(ABR.getRoot())->getParent()->getInfo();
    cout<<endl<<"Coppia con differenza minore: "<<nodo<<" e "<< nodo_padre<<endl;

    return 0;
}



