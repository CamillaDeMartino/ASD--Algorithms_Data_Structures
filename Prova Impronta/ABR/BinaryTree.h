#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Nodo.h"
#include <iostream>

using namespace std;

template<class T>
class BinaryTree
{
private:
    Nodo<T> *root;

    void insertRic(T, Nodo<T>*, Nodo<T>*);
    void insertNode(T, Nodo<T>*, Nodo<T>*);
    Nodo<T> *findSuccessor(Nodo<T> *);
    Nodo<T> *findPredecessor(Nodo<T> *);

public:
    BinaryTree();

    Nodo<T> *getRoot(){return root;}

    void insert(T);
    Nodo<T> *treeSearch(Nodo<T> *, T);
    Nodo<T> *getMinimum(Nodo<T> *);
    Nodo<T> *getMaximum(Nodo<T> *);
    Nodo<T> *successor(Nodo<T> *);
    Nodo<T> *predecessor(Nodo<T> *);

    void visitInorder(Nodo<T> *);
    void visitPreorder(Nodo<T> *);
    
};

template<class T> BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template<class T> void BinaryTree<T>::insert(T value)
{
    insertRic(value, nullptr, root);
}

template<class T> void BinaryTree<T>::insertRic(T value, Nodo<T> *prev, Nodo<T> *curr)
{
    if(root == nullptr)
        root = new Nodo<T>(value);
    else if(curr == nullptr)
        insertNode(value, prev, curr);
    else if(curr->getInfo() > value)
        insertRic(value, curr, curr->getLeft());
    else
        insertRic(value, curr, curr->getRight());
}

template<class T> void BinaryTree<T>::insertNode(T value, Nodo<T> *prev, Nodo<T> *curr)
{
    curr = new Nodo<T>(value);
    curr->setParent(prev);

    if(curr->getInfo() < prev->getInfo())
        prev->setLeft(curr);
    else
        prev->setRight(curr);
}

template<class T> Nodo<T> *BinaryTree<T>::treeSearch(Nodo<T> *x, T key)
{
    if(x == nullptr || key == x->getInfo())
        return x;
    else if(key < x->getInfo())
        return treeSearch(x->getLeft(), key);
    else 
        return treeSearch(x->getRight(), key);
}

template<class T> Nodo<T> *BinaryTree<T>::getMinimum(Nodo<T> *x)
{
    if(root == nullptr)
        return nullptr;
    else if(x->getLeft() == nullptr)
        return x;
    else
        return getMinimum(x->getLeft());
}

template<class T> Nodo<T> *BinaryTree<T>::getMaximum(Nodo<T> *x)
{
    if(root == nullptr)
        return nullptr;
    else if(x->getRight() == nullptr)
        return x;
    else 
        return getMaximum(x->getRight());
}

template<class T> Nodo<T> *BinaryTree<T>::successor(Nodo<T> *x)
{
    if(x == nullptr)
        return nullptr;
    else if(x->getRight() != nullptr)
        return getMinimum(x->getRight());
    else
        return findSuccessor(x);
}

template<class T> Nodo<T> *BinaryTree<T>::findSuccessor(Nodo<T> *x)
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

template<class T> Nodo<T> *BinaryTree<T>::predecessor(Nodo<T> *x)
{
    if(x == nullptr)
        return nullptr;
    else if(x->getLeft() != nullptr)
        return getMaximum(x->getLeft());
    else 
        return findPredecessor(x);
}

template<class T> Nodo<T> *BinaryTree<T>::findPredecessor(Nodo<T> *x)
{
    if(x == nullptr)
        return nullptr;
    
    Nodo<T> *y = x->getParent();
    if(y == nullptr)
        return nullptr;
    else if(x = y->getRight())
        return y;
    else 
        return findPredecessor(y);
}

template<class T> void BinaryTree<T>::visitInorder(Nodo<T> *x)
{
    if(x != nullptr)
    {
        visitInorder(x->getLeft());
        cout<<x->getInfo()<<" ";
        visitInorder(x->getRight());
    }
}

template<class T> void BinaryTree<T>::visitPreorder(Nodo<T> *x)
{
    if(x != nullptr)
    {
        cout<<x->getInfo()<<" ";
        visitPreorder(x->getLeft());
        visitPreorder(x->getRight());
    }
}



#endif