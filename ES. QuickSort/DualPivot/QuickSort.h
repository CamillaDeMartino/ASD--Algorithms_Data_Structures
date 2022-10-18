#ifndef QUICKSORT_H
#define QUICKSORT_H


class QuickSort
{
private:
    static int partition(int *A, int, int, int *);
    template<class Item> static void swapp(Item *, Item *);
public:
    static void quickSort(int *, int , int);
    
};

void QuickSort ::quickSort(int *A, int l, int r)
{
    int i, j;

    if (r <= l)
        return;
    
    i = partition(A,l,r,&j); 
    quickSort(A,l,j-1);
    quickSort(A,j+1,i); 
    quickSort(A,i+1,r); 
    
}

template<class Item> void QuickSort :: swapp(Item *A, Item *B)
{
    Item temp = *A;
    *A = *B;
    *B = temp;

}

int QuickSort::partition(int *A, int low, int high, int *secondPivot)
{
    if(A[low] > A[high])
        swapp(&A[low], &A[high]);

    int i = low + 1;
    int k = low + 1;
    int j = high - 1;

    int lpivot = A[low];
    int rpivot = A[high];

    while(k <= j){

        if(A[k] < lpivot){
            swapp(&A[k], &A[i]);
            i++;
        }
        else if(A[k] >= rpivot){
            while(A[j] > rpivot && k < j)
            {
                    j--;
            }
            swapp(&A[k], &A[j]);
            j--;
            if(A[k] < lpivot)
            {
                 swapp(&A[k], &A[i]);
                 i++;
            }
        }
        k++;
    }
    i--;
    j++;

    swapp(&A[low], &A[i]);
    swapp(&A[high], &A[j]);

    *secondPivot = i;

    return j;
}


#endif