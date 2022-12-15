#ifndef MAXPRIORITY_H
#define MAXPRIORITY_H
#include "MaxHeap.h"
#include <iostream>

using namespace std;

template <class T>
class MaxPriority:public MaxHeap<T>
{
private:
    /* data */
public:
    MaxPriority(/* args */);

    void insertQueue(T);
    T getMaximum();
    T extractMax();
    void increase(int, T);
    //void decrease();

    void printQueue();
   
};

template<class T> MaxPriority<T>::MaxPriority():MaxHeap<T>()
{
}

template<class T> void MaxPriority<T>::insertQueue(T value)
{
    this->insert(value);
}

template<class T> T MaxPriority<T>::getMaximum()
{
    return this->getTree().at(0);
}

template<class T> T MaxPriority<T>::extractMax()
{
    if(this->getHeapSize() == 0)
        return -1;
    
    T max = getMaximum();
    int i = this->getHeapSize()-1;
    this->swap(this->tree.at(0), this->tree.at(i));
    this->setHeapSize(this->getHeapSize() - 1);
    this->heapify(0);

    return max;
}


template<class T> void MaxPriority<T>::increase(int i, T key)
{
    if(this->getTree().at(i) > key)
        cout<<"error"<<endl;
    
    this->tree.at(i) = key;

    while (i > 0 && this->getTree().at(this->parent(i)) < this->getTree().at(i))
    {
        this->swap(this->tree.at(this->parent(i)), this->tree.at(i));
        i = this->parent(i);
    }
    
}

template<class T> void MaxPriority<T>::printQueue()
{
    this->print();
}

#endif