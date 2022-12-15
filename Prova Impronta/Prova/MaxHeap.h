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
    vector<T> tree;

    int parent(int i){return (i-1)/2;}
    int left(int i){return (i*2)+1;}
    int right(int i){return (i*2)+2;}

    int getHeapSize(){return heapSize;}
    void setHeapSize(int heapSize){this->heapSize = heapSize;}
    void buildMaxHeap();
    void heapify(int);
    void swap(T &, T &);

public:
    MaxHeap(vector<T>);
    MaxHeap();

    vector<T> getTree(){return tree;}
    void insert(T);
    void print();

};

template<class T> MaxHeap<T>::MaxHeap(vector<T> tree)
{
    this->tree = tree;
    heapSize = tree.size();
    buildMaxHeap();
}

template<class T> MaxHeap<T>::MaxHeap()
{
    heapSize = 0;
}

template<class T> void MaxHeap<T>::swap(T &A, T &B)
{
    T temp = A;
    A = B;
    B = temp;
}

template<class T> void MaxHeap<T>::heapify(int i)
{
    int max = i;
    int l = left(i);
    int r = right(i);

    if(l < getHeapSize() && getTree().at(max) < getTree().at(l))
        max = l;
    if(r< getHeapSize() && getTree().at(max) < getTree().at(r))
        max = r;

    if(max != i)
    {
        swap(tree.at(max), tree.at(i));
        heapify(max);
    }

}

template<class T> void MaxHeap<T>::insert(T value)
{
    setHeapSize(getHeapSize() + 1);
    tree.push_back(value);

    int i = getHeapSize()-1;
    while(i > 0 && getTree().at(parent(i)) < value)
    {
        swap(tree.at(parent(i)), tree.at(i));
        i = parent(i);

    }
}


template<class T> void MaxHeap<T>::buildMaxHeap()
{
    setHeapSize((int) tree.size());
    for(int i = getHeapSize()/2 - 1; i >= 0; i--)
        heapify(i);
}

template<class T> void MaxHeap<T>::print()
{
    for(int i = 0; i < getTree().size(); i++)
        cout<<getTree().at(i)<<" ";
    cout<<endl;    
}



#endif