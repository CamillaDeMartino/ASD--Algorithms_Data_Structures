#ifndef QUICKSORT_H
#define QUICKSORT_H

template<class Item>
class QuickSort
{
private:
    static int partition(Item *A, int, int, int *);
    static void swapp(Item *, Item *);
public:
    static void quickSort(Item *, int , int);
    
};

template<class Item> void QuickSort<Item>::quickSort(Item *A, int l, int r)
{
    int i, j;

    if (r <= l)
        return;
    
    i = partition(A,l,r,&j); 
    quickSort(A,l,j-1);
    quickSort(A,j+1,i); 
    quickSort(A,i+1,r); 
    
}

template<class Item> void QuickSort<Item>:: swapp(Item *A, Item *B)
{
    Item temp = *A;
    *A = *B;
    *B = temp;

}

template<class Item> int QuickSort<Item>::partition(Item *A, int low, int high, int *secondPivot)
{
    //la condizione è che il primo elemento sia più piccolo dell'ultimo elemento
    if(A[low] > A[high])
        swapp(&A[low], &A[high]);

    //i indicherà l'ultimo elemento della prima parte(quella a sinistra)
    //k si muove insieme ad i e ci permette di scorrere tutti gli elemnti non presi in esame
    //j verrà usato per realizzare la parte di destra
    auto i = low + 1;
    auto k = low + 1;
    auto j = high - 1;

    //scelgo 2 pivot: uno uguale al primo elemento e l'altro uguale all'ultimo
    Item lpivot = A[low];
    Item rpivot = A[high];

    while(k <= j){
        //lo scopo è di far in modo che il nostro k contenga sempre elementi compresi tra il pivot di sinistra e quello di destra

        // sei gli elementi sono più piccoli del pivot di sinistra, scambia 
        // N.B i pivot non sono scambiati se non all'inizio prima di entrare nel while
        if(A[k] < lpivot){
            swapp(&A[k], &A[i]);
            i++;
        }
        //se gli elementi sono più grandi del pivot di destra allora scorriamo A finche non troviamo un numero più piccolo
        else if(A[k] >= rpivot){
            while(A[j] > rpivot && k < j)
            {
                    j--;
            }
            swapp(&A[k], &A[j]);
            j--;
            //ripristiniamo a questo punto k se, a causa degli scambi, sarà più piccolo del pivot di sinistra
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

    //riposiziono i pivot
    swapp(&A[low], &A[i]);
    swapp(&A[high], &A[j]);

    *secondPivot = i; //poiché non posso ritornare due valori con una funzione

    return j;
}


#endif