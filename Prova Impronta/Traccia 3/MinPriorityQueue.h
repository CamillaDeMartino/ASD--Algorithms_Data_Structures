#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITUQUEUE_H
#include <iostream>
#include "PriorityQueue.h"
#include "MinHeap.h"

using namespace std;

template<class T>
class MinPriorityQueue:protected MinHeap<T>, protected PriorityQueue<T>
{
private:
    /* data */
public:
    MinPriorityQueue(/* args */);
   ~MinPriorityQueue();

   virtual void insertHeap(T); 
};

template<class T> MinPriorityQueue <T>::MinPriorityQueue():MinHeap<T>()
{
}

template<class T> void MinPriorityQueue<T>::insertHeap(T value)
{
    this->insert(value);
}






#endif