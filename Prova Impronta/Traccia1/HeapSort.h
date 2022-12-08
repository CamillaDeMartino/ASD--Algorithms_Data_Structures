#ifndef HEAPSORT_H
#define HEAPASORT_H
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class HeapSort
{
private:
    int heapsize;
    vector<T> tree;

    int parent(int i){return (i-1)/2;}
    int left(int i){return (i*2)+1;}
    int right(int i){return (i*2)+2;}

    void setHeapSize(int hpsz){ heapsize = hpsz;}
    int getHeapSize(){return heapsize;}
    vector<T> getTree(){return tree;}

    void swap(T&, T &);
    void maxHeapify(int);
    void buildMaxHeap();
    void insert(T);

public:
    HeapSort(vector<T>);
    HeapSort();
    void heapSort();
    void printArray();
    
};

template<class T> HeapSort<T>::HeapSort(vector<T> t)
{
    tree = t;
    heapsize = 0;
}

template<class T> HeapSort<T>::HeapSort()
{
    heapsize = 0;
}

template<class T> void HeapSort<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T> void HeapSort<T>::maxHeapify(int i)
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
        swap(tree.at(max), tree.at(i));
        maxHeapify(max);
    }
}

template<class T> void HeapSort<T>::buildMaxHeap()
{
    setHeapSize((int)getTree().size());
    for(int i = getHeapSize()/2 - 1; i >=0; i--)
        maxHeapify(i);
}

template<class T> void HeapSort<T>::heapSort()
{
    buildMaxHeap();

    for(int i = getHeapSize()-1; i >= 0; i--)
    {
        swap(tree.at(0), tree.at(i));
        setHeapSize(getHeapSize()-1);
        maxHeapify(0);
    }
}

template<class T> void HeapSort<T>::insert(T nodo)
{
    setHeapSize(getHeapSize() + 1);
    tree.push_back(nodo);

    int i = getHeapSize()-1;
    while(i > 0 && getTree().at(parent(i)) < nodo)
    {
        swap(tree.at(parent(i)), tree.at(i));
        i = parent(i);
    }
}


template<class T> void HeapSort<T>::printArray()
{
    for(auto i:tree)
        cout<<i<<endl;
}
#endif