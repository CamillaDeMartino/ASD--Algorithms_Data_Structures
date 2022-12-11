#include "BinaryTree.h"
#include <iostream>

template<class T>
class MaxPriority
{
private:
    BinaryTree<T> ABR;
public:
    void insertMax(T);
    T getMaximum();
    void print();
};

template<class T> void MaxPriority<T>::insertMax(T value)
{
    this->ABR.insert(value);
}

template<class T> T MaxPriority<T>::getMaximum()
{ 
    return this->ABR.getMaximum(ABR.getRoot())->getInfo();
}

template<class T> void MaxPriority<T>::print()
{
    this->ABR.visitInorder(ABR.getRoot());
}


