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
    
    

    cout<<endl<<"***FILE CON 2 NUMERI PER RIGA***"<<endl;
    string file3 = "myFile2";
    fstream myFile2;
    int numc;
    int num;
    myFile2.open(file3.c_str(), ios::in);
    
    
    myFile2.seekg(0);
    while(true){
        for(int i = 0; i < 2; i++)
            myFile2>>num;
        
        if(myFile2.eof())
            break;

        cout<<"Valore: "<<num<<endl;
        //while(myFile2.get() != '\n');
    }


    myFile.close();
    output.close();
    myFile2.close();
    return 0;
}