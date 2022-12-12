#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MinHeap
{
private:
    int heapSize;
    vector<T> tree;

    int parent(int i){return (i-1)/2;}
    int left(int i){return (i*2)+1;}
    int right(int i){return (i*2)+2;}

    void swap(T&, T&);
    void minHeapify(int);
    void buildMinHeap();

private:
    
    vector<T> getTree(){return tree;}
    void setHeapSize(int heapSize){this->heapSize = heapSize;}
    int getHeapSize(){return heapSize;}


public:
    MinHeap(vector<T>);
    MinHeap();

    void insert(T);
    void printArray();
};

template<class T> MinHeap<T>::MinHeap(vector<T> tree)
{
    heapSize = tree.size();
    this->tree = tree;
    buildMinHeap();
}

template<class T> MinHeap<T>::MinHeap()
{
    heapSize = 0;
}

template<class T> void MinHeap<T>::swap(T &A, T &B)
{
    T temp = A;
    A = B;
    B = temp;
}

template<class T> void MinHeap<T>::minHeapify(int i)
{
    int min = i;
    int l = left(i);
    int r = right(i);

    if(l < getHeapSize() && getTree().at(min) > getTree().at(l))
        min = l;
    if(r < getHeapSize() && getTree().at(min) > getTree().at(r))
        min = r;

    if(min != i)
    {
        swap(tree.at(min), tree.at(i));
        minHeapify(min);
    }
}

template<class T> void MinHeap<T>::insert(T value)
{
    setHeapSize(getHeapSize() + 1);
    tree.push_back(value);

    int i = getHeapSize()-1;
    while(i > 0 && getTree().at(parent(i)) > value)
    {
        swap(tree.at(parent(i)), tree.at(i));
        i = parent(i);
    }
}

template<class T> void MinHeap<T>::buildMinHeap()
{
    setHeapSize((int) tree.size());
    for(int i = getHeapSize()/2-1; i >= 0; i--)
        minHeapify(i);
}

template<class T> void MinHeap<T>::printArray()
{
    for(auto i:tree)
        cout<<i<<" ";
    cout<<endl;
}



#endif