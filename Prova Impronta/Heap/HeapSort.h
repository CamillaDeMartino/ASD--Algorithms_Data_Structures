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

    void setHeapsize(int hpsz){heapsize = hpsz;}
    int getHeapsize(){return heapsize;}
    vector<T> getTree(){return tree;}

    void swap(T&, T&);
    void maxHeapify(int);
    void buildMaxHeap();

public:
    HeapSort(vector<T>);
    HeapSort();

    void heapSort();
    void printArray();
    void insert(T);
};

template<class T> HeapSort<T>::HeapSort(vector<T> t)
{
    heapsize = 0;
    tree = t;
}

template<class T> HeapSort<T>::HeapSort(){
    heapsize = 0;
}

template<class T> void HeapSort<T>::swap(T &A, T &B)
{
    T temp = A;
    A = B;
    B = temp;
}

template<class T> void HeapSort<T>::maxHeapify(int i)
{
    int max = i;
    int l = left(i);
    int r = right(i);

    if(l <  getHeapsize() && getTree().at(max) < getTree().at(l))
        max = l;
    if(r < getHeapsize() && getTree().at(max) < getTree().at(r))
        max = r;
    
    if(max != i)
    {
        swap(tree.at(max), tree.at(i));
        maxHeapify(max);
    }
}

template<class T> void HeapSort<T>::buildMaxHeap()
{
    setHeapsize((int)getTree().size());
    
    for(int i = (getHeapsize()/2) -1; i >= 0; i--)
        maxHeapify(i);
}

template<class T> void HeapSort<T>::insert(T nodo)
{
    setHeapsize(getHeapsize() + 1);
    tree.push_back(nodo);

    int i = getHeapsize()-1;
    while(i > 0 && getTree().at(parent(i)) < nodo)
    {
        swap(tree.at(parent(i)), tree.at(i));
        i = parent(i);
    }

}

template<class T> void HeapSort<T>::heapSort()
{
    buildMaxHeap();

    for(int i = getHeapsize() -1; i >= 0; i--)
    {
        swap(tree.at(0), tree.at(i));
        setHeapsize(getHeapsize() - 1);
        maxHeapify(0);
    }
}

template<class T> void HeapSort<T>::printArray()
{
    for(int i = 0; i < tree.size(); i++)
       cout<<tree.at(i)<<" ";
    
    cout<<endl;
}
