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
    void insertRic(T, Nodo<T>*, Nodo<T>*);
    void insertNode(T, Nodo<T>*, Nodo<T>*);
    Nodo<T> *treeSearch(Nodo<T> *, T);

    void preorderVisit(Nodo<T> *);
    void inorderVisit(Nodo<T> *);
    void postorderVisit(Nodo<T> *);
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

//versione ricorsiva dell'inserimento
template<class T> void BinarySearchTree<T>::insertRic(T value, Nodo<T> *prev, Nodo<T> *curr)
{
    if(root == nullptr)
        root = new Nodo<T>(value);
    if(curr == nullptr)
        insertNode(value, prev, curr);
    else if(curr->getInfo() > value)
        insertRic(value, curr, curr->getLeft());
    else 
        insertRic(value, curr, curr->getRight());
}

//nodo inseguitore
template<class T> void BinarySearchTree<T>::insertNode(T value, Nodo<T> *prev, Nodo<T> *curr)
{
    curr = new Nodo<T>(value);
    curr->setParent(prev);

    if(prev == nullptr)
        root = curr;
    else if(curr->getInfo() > prev->getInfo())
            prev->setRight(curr);
        else
            prev->setLeft(curr);
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

template<class T> void BinarySearchTree<T>::postorderVisit(Nodo<T> *current)
{
    if(current != nullptr)
    {
        postorderVisit(current->getLeft());
        postorderVisit(current->getRight());
        cout<<current->getInfo()<<" ";
    }

}


#endif