/*
    Progettare un algoritmo ricorsivo per contare il numero id scambi necessari per ordinare un'array
*/

#include <iostream>

using namespace std;

typedef int Item;
int count = 0;


int conta_scambi(Item a[], int j)
{
    int prec = j-1;

    while(a[j+1] < a[prec])
    {
        swap(a[j], a[prec]);
        count++;
        prec--;
        j--;
    }


    return count;
}

void merge(Item a[], int left, int center, int right)
{
    const int n = 4;
    static Item aux[n];


    int i,j;


    for(i = center + 1; i > left; i--)
        aux[i-1] = a[i-1];

    for(j = center; j < right; j++)
        aux[right+center-j] = a[j+1];


    
    //conto quanti possibili scambi devono essere effettuati per ordinare l'array 
    //ma senza ordinarlo perché non è richiesto
    if(aux[j] < aux[i])
    {           
        count = conta_scambi(aux,j);
        i++;
    }
    else 
    {
        j--;
    }
 
   
}


void mergesort(Item a[], int left, int right)
{
    if(left < right)
    {
        int center = (left+right)/2;
        mergesort(a,left, center);
        mergesort(a,center+1, right);
        merge(a,left,center,right);
    }
}

int main(){
    const int n = 4;

    int a[n] = {9,7,3,1};

    
    for(int k = 0; k < n; k++)
    {
      cout <<" [" << a[k] << "]";
    }
    cout<<endl;

    mergesort(a,0,n-1);
    cout<<endl<< " n. scambi tot  = " << count << " ";

    return 0;
}