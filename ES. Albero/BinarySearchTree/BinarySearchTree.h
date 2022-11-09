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
    bool isEmpty(){return root == nullptr;}

    Nodo<T> *minimumTree(Nodo<T> *);
    Nodo<T> *maximumTree(Nodo<T> *);

    Nodo<T> *successor(Nodo<T> *);
    Nodo<T> *findSuccessor(Nodo<T> *);
    Nodo<T> *predecessor(Nodo<T> *);
    Nodo<T> *findPredecessor(Nodo<T> *);

    void treeDelete(Nodo<T> *);
    void transplant(Nodo<T> *, Nodo<T> *);

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
        parent->setLeft(nodeToInsert);
    else
        parent->setRight(nodeToInsert);    
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


template<class T> Nodo<T> *BinarySearchTree<T>::treeSearch(Nodo<T> *x, T key)
{
    if(x == nullptr || key == x->getInfo())
        return x;
    if(key < x->getInfo())
        return treeSearch(x->getLeft(), key);
    else
        return treeSearch(x->getRight(), key);
}

template<class T> Nodo<T> *BinarySearchTree<T>::minimumTree(Nodo<T> *x)
{
    if(isEmpty())
        return nullptr;
    else if(x->getLeft() == nullptr)
        return x;
    else 
        return minimumTree(x->getLeft());
}

template<class T> Nodo<T> *BinarySearchTree<T>::maximumTree(Nodo<T> *x)
{
    if(isEmpty())
        return nullptr;
    else if(x->getRight() == nullptr)
        return x;
    else 
        return maximumTree(x->getRight());
}

template<class T> Nodo<T> *BinarySearchTree<T>::successor(Nodo<T> *x)
{
    if(x->getRight() != nullptr)
        return minimumTree(x->getRight());
    else 
        return findSuccessor(x);
}

template<class T> Nodo<T> *BinarySearchTree<T>::findSuccessor(Nodo<T> *x)
{
    if(x == nullptr)
        return nullptr;

    Nodo<T> *y = x->getParent();

    if(y == nullptr)
        return nullptr;
    else if(x == y->getLeft())
        return y;
    else 
        return findSuccessor(y);
}

template<class T> Nodo<T> *BinarySearchTree<T>::predecessor(Nodo<T> *x)
{
    if(x->getLeft() != nullptr)
        return maximumTree(x->getLeft());
    else 
        return findPredecessor(x);
}

template<class T> Nodo<T> *BinarySearchTree<T>::findPredecessor(Nodo<T> *x)
{
    if(x == nullptr)
        return nullptr;

    Nodo<T> *y = x->getParent();
    
    if(y == nullptr)
        return nullptr;
    else if(x == y->getRight())
        return y;
    else 
        return findPredecessor(y);
}

template<class T> void BinarySearchTree<T>::treeDelete(Nodo<T> *x)
{
    if(x  == nullptr)
        x = nullptr;
    if(x->getLeft() == nullptr)
    {
        transplant(x, x->getRight());
        //treeDelete(x);
    }
    else if(x->getRight() == nullptr)
    {
        transplant(x, x->getLeft());
        //treeDelete(x);
    }
    else
    {
        Nodo<T> *y = successor(x);
        if(y->getParent() != x)
        {
            transplant(y, y->getRight());
            y->setRight(x->getRight());
            (y->getRight())->setParent(y);
            //treeDelete(x);
        }
        transplant(x,y);
        y->setLeft(x->getLeft());
        (y->getLeft())->setParent(y);
        //treeDelete(x);
    }
    
}

template<class T> void BinarySearchTree<T>::transplant(Nodo<T> *x, Nodo<T> *y)
{
    if(x->getParent() == nullptr)
        root = y;
    else if( x  == (x->getParent())->getLeft())
        (x->getParent())->setLeft(y);
    else
        (x->getParent())->setRight(y);

    if(y != nullptr)
        y->setParent(x->getParent());
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