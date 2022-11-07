#ifndef COUNTINGSORTSTRING_H
#define COUNTINGSORTSTRING_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class CountingSortString
{
private:
    static int getMax(vector<string>);
    static bool isSubString(vector<string> *);
public:
    static void countingSortString(vector<string> *);
    static void printArr(vector<string>);
    
};

int CountingSortString::getMax(vector<string> A)
{
    int max = A.at(0).length();         //il massimo non è l'elemento iniziale, ma la lunghezza della prima stringa

    for(int i = 1; i < A.size(); i++)
    {
        if(A.at(i).length() > max)
            max = A.at(i).length();
    }

    return max;

}

//i procedimenti sono gli stessi ma nell'array delle occerenze non conto in base alla singola lettera,
//ma alla lunghezza della stringa contenuta nella singola cella
void CountingSortString::countingSortString(vector<string> *A)
{
    
    int sizeA = A->size();
    int max = getMax(*A);
    int sizeC = max + 1;

    vector<int> count(sizeC);
    vector<string> output(sizeA);

    for(int i = 0; i < sizeC; i++)
        count.at(i) = 0;
    
    for(int i = 0; i < sizeA; i++)
        count.at(A->at(i).length())++;

    for(int i = 1; i < sizeC; i++)   
        count.at(i) += count.at(i-1);

    for(int i = sizeA-1; i >= 0; i--)
    {
        output.at(count.at(A->at(i).length())-1) = A->at(i);
        count.at(A->at(i).length())--;
    }

    if(isSubString(A))
    {
        for(int i = 0; i < sizeA; i++)
            A->at(i) = output.at(i);
    }
    else
        cout<<"No sottostringa"<<endl;
}

bool CountingSortString::isSubString(vector<string> *A)
{
    
    for(int i = 0; i < A->size()-1; i++)
    {
        auto it = A->at(i+1).find(A->at(i));
        if(it == string::npos)
            return false;
    }

    return true;
}

void CountingSortString::printArr(vector<string> A)
{
    cout<<endl;

    for(auto i:A)
        cout<<i<<" ";
    cout<<endl<<endl;
}


#endif