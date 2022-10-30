#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MaxHeap
{
private:
    
    int heapSize;

    int left(int);
    int right(int);

protected:
   vector<T> tree;
    int parent(int);
    
    void swap(T&, T&);
    void setHeapSize(int);
    int getHeapSize();
    vector<T> getTree();

    void insert(T);
    void buildMaxHeap();
    void maxHeapify(int);

public:
    MaxHeap(vector<T>);

    void printArray();
 
};


template<class T> MaxHeap<T>::MaxHeap(vector<T> t)
{
    tree = t;
    heapSize = 0;
}

template<class T> void MaxHeap<T>::swap(T &A, T &B)
{
    T temp = A;
    A = B;
    B = temp;
}

template<class T> void MaxHeap<T>::setHeapSize(int hpsz)
{
    heapSize = hpsz;
}

template<class T> int MaxHeap<T>::getHeapSize()
{
    return heapSize;
}

template<class T> vector<T> MaxHeap<T>::getTree()
{
    return tree;
}

template<class T> int MaxHeap<T>::parent(int i)
{
    return(i-1)/2;
}

template<class T> int MaxHeap<T>::left(int i)
{
    return (i*2) + 1;
}

template<class T> int MaxHeap<T>::right(int i)
{
    return (i*2) + 2; 
}

template<class T> void MaxHeap<T>::maxHeapify(int i)
{
    int max = i;
    int l = left(i);
    int r = right(i);

    if(l < getHeapSize() && getTree().at(max) < getTree().at(l))
        max = l;

    if(r < getHeapSize() && getTree().at(max) < getTree().at(r))
        max = r;
    
    if(max != i)
    {
        swap(tree.at(i), tree.at(max));
        maxHeapify(max);
    }
}

template<class T> void MaxHeap<T>::buildMaxHeap()
{
    setHeapSize((int) getTree().size());

    for(int j = (getHeapSize()/2); j >= 0; j--)
        maxHeapify(j);
        
}

template<class T> void MaxHeap<T>::insert(T nodo)
{
    setHeapSize(getHeapSize() + 1);
    tree.push_back(nodo);

    int i = getHeapSize()-1;

    while(i > 0 && getTree().at(parent(i)) < nodo)
    {
        swap(tree.at(i), tree.at(parent(i)));
        i = parent(i);
    }

}

template<class T> void MaxHeap<T>::printArray()
{
    cout<<endl << "**Alberello***" << endl;
    for (int i = 0; i < getHeapSize(); i++) 
        cout << getTree().at(i) <<endl;
    cout<<endl<<endl;
}


#endif