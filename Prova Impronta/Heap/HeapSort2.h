#ifndef HEAPSORT2_H
#define HEAPSORT2_H
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class HeapSort2
{
    private:
        int heapsize;

        int left(int i){return (i*2)+1;}
        int right(int i){return (i*2)+2;}

    
    protected:
        vector<T> tree;
        int parent(int i){return (i-1)/2;}
        void swap(T &, T &);

        void setHeapSize(int hpsz){ heapsize = hpsz;}
        int getHeapSize(){return heapsize;}
        vector<T> getTree(){return tree;}

        void minHeapify(int);
    
    public:
        HeapSort2(vector<T>);
        HeapSort2();

        void buildMinHeap();
        void heapSort();
        void insert(T);
        void printArray();
};

template<class T> HeapSort2<T>::HeapSort2(vector<T> t)
{
    tree = t;
    heapsize = 0;
}

template<class T> HeapSort2<T>::HeapSort2()
{
    heapsize = 0;
}

template<class T> void HeapSort2<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T> void HeapSort2<T>::minHeapify(int i)
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

template<class T> void HeapSort2<T>::buildMinHeap()
{
    setHeapSize((int) tree.size());
    for(int i = getHeapSize()/2 - 1; i >= 0; i--)
        minHeapify(i);
}

template<class T> void HeapSort2<T>::insert(T nodo)
{
    setHeapSize(getHeapSize() + 1);
    tree.push_back(nodo);

    int i =  getHeapSize() - 1;
    while(i > 0 && getTree().at(parent(i)) > nodo)
    {
        swap(tree.at(parent(i)), tree.at(i));
        i = parent(i);

    }
}

template<class T> void HeapSort2<T>::heapSort()
{
    buildMinHeap();
    for(int i = getHeapSize()-1; i>= 0; i--)
    {
        swap(tree.at(i), tree.at(0));
        setHeapSize(getHeapSize()-1);
        minHeapify(0);
    }
}


template<class T> void HeapSort2<T>::printArray()
{
    for(auto i:tree)
        cout<<i<<" ";
    cout<<endl;
}

#endif