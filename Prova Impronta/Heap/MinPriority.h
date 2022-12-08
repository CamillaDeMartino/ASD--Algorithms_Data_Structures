#ifndef MINPRIORITY_H
#define MINPRIORITY_H
#include "Heapsort2.h"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MinPriority:public HeapSort2<T>
{
private:
    /* data */
public:
    MinPriority();
    void insertQueue(T);
    T getMinimum();
    T extractMinimum();
    void decrease(int , T);
    void printQueue();

};

template<class T> MinPriority<T>::MinPriority():HeapSort2<T>()
{
}

template<class T> void MinPriority<T>::insertQueue(T nodo)
{
    this->insert(nodo);
}

template<class T> T MinPriority<T>::getMinimum()
{
    return this->getTree().at(0);
}

template<class T> T MinPriority<T>::extractMinimum()
{
    if(this->getHeapSize() == 0)
    {
        cout<<"Error"<<endl;
        return -1;
    }

    T min = getMinimum();
    int i = this->getHeapSize() - 1;
    this->swap(this->tree.at(0), this->tree.at(i));
    this->setHeapSize(this->getHeapSize() - 1);
    this->minHeapify(0);

    return min;

}

template<class T> void MinPriority<T>::decrease(int i, T key)
{
    if(key > this->getTree().at(i))
    {
        cout<<"error"<<endl;
        exit;
    }

    this->tree.at(i) = key;
    while(i > 0 && this->getTree().at(this->parent(i)) > this->getTree().at(i))
    {
        this->swap(this->tree.at(this->parent(i)), this->tree.at(i));
        i = this->parent(i);
    }
}


template<class T> void MinPriority<T>::printQueue()
{
    for(int i = 0; i < this->getHeapSize(); i++)
        cout<<this->getTree().at(i)<<" ";
    cout<<endl;
}





#endif