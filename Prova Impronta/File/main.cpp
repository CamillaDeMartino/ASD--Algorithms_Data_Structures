#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

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
    cout<<endl;
    

    cout<<endl<<"***FILE CON 2 NUMERI PER RIGA***"<<endl;
    string file3 = "myFile2";
    fstream myFile2;
    string line;
    myFile2.open(file3.c_str(), ios::in);
    

    cout<<"**leggo una specifica linea**"<<endl;
    int current_line = 0, line_number;

    cout<<endl<<"Che linea vuoi leggere ?"<<endl;
    cin>>line_number;
    while(!myFile2.eof())
    {
        current_line++;
        getline(myFile2, line);
        if( current_line == line_number) break;

    }
    cout<<line;



    string file4 = "myFile2";
    fstream myFile3;
    string column;
    myFile3.open(file3.c_str(), ios::in);
    cout<<endl<<"**leggo le colonne**"<<endl;
    while(getline(myFile3, column))
    {
        istringstream iss(column);

        int column1, column2;
        iss>>column1>>column2;
        cout<<column2<<endl;
    }

     

    myFile.close();
    output.close();
    myFile2.close();
    myFile3.close();
    
    return 0;
}