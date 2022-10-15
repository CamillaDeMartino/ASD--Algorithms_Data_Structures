#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> A = {7,9,1,3};
    typename vector<int>::iterator i;
    typename vector<int>::iterator j;
    typename vector<int>::iterator k;
    vector<int> aux(A.size());

    int center = A.size()/2;
    auto mid = A.begin();
    advance(mid, center);

    cout<<"Center: "<< center<<endl;
    cout<<"mid = "<<*mid<<endl;
    cout<<endl;

    for (auto& v : A){
        cout << v << " ";
    }
    cout << endl<<endl;

    for(i = mid-1; i != A.begin()-1; i--)
    {
        cout<<"i: "<< *i;
        cout<<" center: "<<center<<endl;
        aux.at(center-1) = *i;
        center--; 
    }

     for (auto& v : aux){
        cout << v << " ";
    }
   cout << endl;

    center = A.size();
    for(j = mid; j != A.end(); j++)
    {   
        cout<<"j= "<<*j;
        cout<<"center: "<<center<<endl;
        aux.at(center-1) = *j;
        center--;

    }
    i = aux.begin();
    j = aux.end()-1;

    for (auto& v : aux){
    cout << v << " ";
    }
    cout << endl;
    cout << endl;
    
    cout<<"j: " << *j << " "<<endl;
    cout <<"i: "<< *i << " "<<endl;

    
    for(k = A.begin(); k != A.end(); k++){
        if(*j < *i)
        {
            *k = *j;
            j--;
        }
        else
        {
            *k = *i;
            i++;
        }
        cout << *k;
    }



    return 0;
}