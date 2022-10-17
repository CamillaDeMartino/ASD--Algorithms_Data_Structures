#ifndef MERGERICORSIVO_H
#define MERGERICORSIVO_H

template <class Item>
class MergeRicorsivo
{
private:
    static void merge(Item *,Item *, int , Item *, int);
public:
    static void mergeSort(Item [], int, int);
};


template <class Item> void MergeRicorsivo<Item> ::mergeSort(Item A[], int left, int right){

    if(left < right ){

        int center = (left + right)/2;

        mergeSort(A,left,center);
        mergeSort(A,center+1,right);

        int tot_elem_sx = center - left+1;
        int tot_elem_dx = right - center;
        int dim_ot = right-left+1;

        Item *out = new Item [dim_ot];

        merge(out, A+left, tot_elem_sx, A+(center+1), tot_elem_dx);

        for(int idx = 0; idx < right-left+1; idx++)
            A[left+idx] = out[idx];

        delete[]out;
    }
}


template <class Item> void MergeRicorsivo <Item>::merge(Item *C, Item *A, int N, Item *B, int M)
{
    if(N > 0 && M > 0)
    {
        if(A[0] < B[0])
        {
            C[0] = A[0];
            merge(C+1, A+1, N-1, B,M);
        }
        else
        {
            C[0] = B[0];
            merge(C+1, A, N, B+1, M-1);
        }
    }
    else if(M > 0)
    {
        C[0] = B[0];
        merge(C+1, A, N, B+1, M-1);
    }
    else if(N > 0)
    {
        C[0] = A[0];
        merge(C+1, A+1, N-1, B,M);
    }
}

#endif