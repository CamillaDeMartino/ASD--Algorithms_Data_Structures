#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>

using namespace std;

template<class T>
class PriorityQueue
{
protected:
    
    virtual void insertHeap(T) = 0;
    virtual T getRoot() = 0;
    virtual T extractRoot() = 0;
    virtual void changePriority(int , T) = 0;

    //virtual PriorityQueue() = 0;
    //virtual ~PriorityQueue() = 0;
    //virtual void printQueue();   
};





#endif