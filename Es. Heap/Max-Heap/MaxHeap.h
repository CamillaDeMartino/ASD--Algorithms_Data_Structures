#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MaxHeap
{
private:
    vector<T> tree;
    int heapsize;

    int parent(int);
    int left(int );
    int right(int );

    void swap(T&, T&);
    void max_Heapify(int );
    void build_Max_Heapify();
    
    void setHeapSize(int);
    int getHeapSize();
    vector<T> getTree();
public:
    MaxHeap(vector<T>);

    void insert(T);
    void printArray();
    //void printAsciiTree();
};

template<class T> MaxHeap<T>::MaxHeap(vector<T> t)
{
    tree = t;
    heapsize = 0;
}

template<class T> int MaxHeap<T>::parent(int i)
{
    return (i-1)/2;
}

template<class T> int MaxHeap<T>::left(int i)
{
    return (2*i) + 1 ;
}

template<class T> int MaxHeap<T>::right(int i)
{
    return (2*i) + 2;
}

template<class T> void MaxHeap<T>::swap(T &A, T &B)
{
    T temp;
    temp = A;
    A = B;
    B = temp;
}

template<class T> void MaxHeap<T>::setHeapSize(int hpsz)
{
    heapsize = hpsz;
}

template<class T> int MaxHeap<T>::getHeapSize()
{
    return heapsize;
}

template<class T> vector<T> MaxHeap<T>::getTree()
{
    return tree;
}

template<class T> void MaxHeap<T>::max_Heapify(int i)
{
    int max = i;
    int l = left(i);
    int r = right(i);

    if(l < getHeapSize() && getTree().at(max) < getTree().at(l) )
        max = l;
    
    if(r < getHeapSize() && getTree().at(max) < getTree().at(r))
        max = r;
    
    if(max != i)
    {
        swap(tree.at(i), tree.at(max));
        max_Heapify(max);
    }
}

template<class T> void MaxHeap<T>::build_Max_Heapify()
{
    setHeapSize((int)getTree().size());
    for(int j = (getHeapSize()/2); j >= 0; j--)
        max_Heapify(j);
    
}

template<class T> void MaxHeap<T>::insert(T nodo)
{
    setHeapSize(getHeapSize() + 1);
    tree.push_back(nodo);
    build_Max_Heapify();
}

template<class T> void MaxHeap<T>::printArray()
{
    cout<<endl << "**Alberello***" << endl;
    for (int i = 0; i <getHeapSize(); i++)
        cout<<getTree().at(i)<<" ";

    cout<<endl<<endl;
}
#endif