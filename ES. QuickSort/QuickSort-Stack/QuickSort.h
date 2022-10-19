#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Stack.h"

template<class Item>
class QuickSort
{
private:
    static int partition(Item [], int, int);
    static void swap(Item &, Item &);
public:
    static void quickSort_iter(Item [], int , int);
};


template<class Item> void QuickSort<Item>:: swap(Item &A, Item &B)
{
    Item temp = A;
    A = B;
    B = temp;

}

template<class Item> void QuickSort<Item>::quickSort_iter(Item A[], int l, int r)
{
    Stack<Item> Sti;

    Sti.Push(r);
    Sti.Push(l);

    //finché ci sono elementi nello stack
    //LIFO
    while(!Sti.isEmpty()){
        Sti.Pop(l);
        Sti.Pop(r);

        int i = partition(A,l,r);

        if(l < i)
        {
            Sti.Push(l);
            Sti.Push(i-1);
        }

        else if(i < r)
        {
            Sti.Push(i+1);
            Sti.Push(r);
        }
    }
}

template <class Item> int QuickSort<Item>::partition(Item A[], int l, int r)
{
    int i= l-1, j=r;
    auto v = A[r];

    for(;;)
    {
        while (A[++i] < v);
        while (v < A[--j])
            if(j == l)
                break;
        if (i >= j)
            break;
        swap (A[i],A[j]);
    }
    swap(A[i],A[r]);
    return i;
}



#endif