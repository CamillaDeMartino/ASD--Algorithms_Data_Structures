#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){

    string file = "myFile";
    string file2 = "output";
    string prova;
    fstream myFile;
    fstream output;

    myFile.open(file.c_str(), ios::in);
    output.open(file2.c_str(), ios::out);

    vector<string> vect;

    while(getline(myFile, prova))
    {   
       output<<prova<<endl;      //qui lo metto in un file... è una semplice copia
       cout<<prova<<endl;        //qui lo stampo
       vect.push_back(prova);    //qui lo metto in un vettore
    }
    cout<<endl;

    for(auto i:vect)
        cout<<i<<" ";
    
    myFile.close();
    output.close();
    return 0;
}