/*
    • Un'azienda è quotata in borsa. Si supponga di avere un array
    A[1...N] contenente la quotazione delle azioni in un periodo di
    N giorni e che A[1]<A[N]. È possibile dimostrare che esiste
    almeno una coppia di giorni consecutivi i, i+1 tali che
    A[i]<A[i+1].

    • Progettare ed implementare un algoritmo divide-et-impera che
    trovi un indice i che verifichi la condizione data.
*/

#include <iostream>
#include <vector>

using namespace std;

int Ricerca(int A[], int low, int high)
{
    int mid, ind;

    if((high+1) - low == 1)
    {
        if (A[low] < A[high])
            return low;
        else
            return -1;
    }
    else 
    {
        mid = (high+low)/2;
        if(A[mid] < A[mid+1])
            return mid;
        else 
            ind = Ricerca(A,low,mid);
            if(ind < 0)
                return Ricerca(A, mid+1, high);
            else 
                return ind;
    }
}

int main(){

    /*vector<int> A;
    int elem;

    cout<<"Inserire un elemento: ";
    cin>>elem;
    cout<<endl;

    A.push_back(elem);*/

    int A[] = {20, 15, 13, 12, 21};
    int i;

    i = Ricerca(A, 0, 4);

    if(i < 0)
        cout<<"Non esiste soluzione"<<endl<<endl;
    else 
        cout<<endl<<"Indice: "<< i <<endl<< A[i] << " < "<< A[i+1]<<endl<<endl;

    return 0;
}

