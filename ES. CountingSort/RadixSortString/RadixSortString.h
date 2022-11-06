#ifndef RADIXSORTSTRING_H
#define RADIXSORTSTRING_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RadixSortString
{
   
public:
    static void radixSortString(string *, int, int );
    static void printArray(string *, int);
    
};


void RadixSortString::radixSortString(string *A, int size, int maxDigits)
{
    
    string *output = new string[size]; 
    
    for(int i = maxDigits-1; i >= 0; i--)
    {
        int count[26] = {0};
        for(int j = 0; j < size; j++)
        {   
            if(A[j][i] == 'z') continue;
            count[(A[j][i]) - 96] ++;
        }
      
        for(int j = 1; j < 26; j++)
            count[j] += count[j -1];
        
        for(int j = 0; j < size; j++)
        {   
            output[count[ (A[j][i]) - 97]] = A[j];
            count[(A[j][i]) - 97] ++;
        }

        for(int j = 0; j < size; j++)
            A[j] = output[j];

    }


}

void RadixSortString::printArray(string *A, int size)
{
    for (int i = 0; i < size; i++) {
        cout << A[i] <<endl;
    }
    cout<<endl;
}







#endif