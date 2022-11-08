#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Nodo.h"
#define vuoto 5
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
    void printAsciiTree();
    void inOrderAscii(Nodo<T>* root, int spazio);
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
        parent->setLeft(nodeToInsert);
    else
        parent->setRight(nodeToInsert);
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

template <typename T>
void BinarySearchTree<T>::printAsciiTree(){
    cout << endl << "***Min Ascii Heap***" << endl;
    inOrderAscii(root,0);
}

template <typename T>
void BinarySearchTree<T>::inOrderAscii(Nodo<T>* root, int spazio){

    if (root == nullptr)
        return;

    spazio += vuoto;

    inOrderAscii(root->getRight(),spazio);

    cout << endl;
    for (int i = vuoto; i < spazio; i++)
        cout << " ";
    cout << root->getInfo() << endl;

    inOrderAscii(root->getLeft(),spazio);
}

#endif