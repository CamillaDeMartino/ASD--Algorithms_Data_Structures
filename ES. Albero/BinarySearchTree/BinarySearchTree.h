#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Nodo.h"
#include <iostream>

using namespace std;

template <class T>
class BinarySearchTree
{
private:
    Nodo<T> *root;
public:
    BinarySearchTree();
    //~BinarySearchTree();

    Nodo<T> *getRoot(){return root;}
    void insert(T);

    void preorderVisit(Nodo<T> *);
    void inorderVisit(Nodo<T> *);
};

template<class T> BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

/*BinarySearchTree::~BinarySearchTree()
{
}*/

template<class T> void BinarySearchTree<T>::insert(T value)
{
    Nodo<T> *nodeToInsert = new Nodo<T>(value);
    Nodo<T> *parent = nullptr;                   
    Nodo<T> *current = root;

    while( current != nullptr)
    {
        parent = current;
        if(nodeToInsert->getInfo() < current->getInfo())
            current = current->getLeft();
        else 
            current = current->getRight();        
    }

    //nodo inseguitore
    nodeToInsert->setParent(parent);
    if(parent == nullptr)
        root = nodeToInsert;
    else if(nodeToInsert->getInfo() < parent->getInfo())
    {
        parent->setLeft(nodeToInsert);
        //cout<<"Nodo: "<<nodeToInsert->getInfo()<<endl;
        //cout<<"Padre: "<<parent->getInfo()<<endl;
        //cout<<"scendo a sx"<<endl;
    }
    else
        {
            parent->setRight(nodeToInsert);
            //cout<<"Nodo: "<<nodeToInsert->getInfo()<<endl;
            //cout<<"Padre: "<<parent->getInfo()<<endl;
            //cout<<"scendo a dx"<<endl;
        }
}

template<class T> void BinarySearchTree<T>::preorderVisit(Nodo<T> *current)
{
    if(current != nullptr)
    {
        cout<<current->getInfo()<<" ";
        preorderVisit(current->getLeft());
        preorderVisit(current->getRight());
    }

}

template<class T> void BinarySearchTree<T>::inorderVisit(Nodo<T> *current)
{
    if(current != nullptr)
    {
        preorderVisit(current->getLeft());
        cout<<current->getInfo()<<" ";
        preorderVisit(current->getRight());
    }

}



#endif