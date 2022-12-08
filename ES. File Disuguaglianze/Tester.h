#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

class Tester{
    private:
        fstream fsP;
        fstream fsS;
        fstream fsE;

        bool NumeriCorretti(string, string );
        bool SimboliCorretti(string, string);
        bool CheckLogica(string, string);

    public:
        Tester(string strP,string strS,string strE);
        ~Tester();
        void check();
};

Tester::Tester(string strP,string strS,string strE){
	
    fsP.open(strP.c_str(), ios::in);
    fsS.open(strS.c_str(), ios::in);
    fsE.open(strE.c_str(), ios::out);

}

Tester::~Tester(){

    fsP.close();
    fsS.close();
    fsE.close();

}

void Tester::check(){
    
    string p_riga, s_riga;
    vector<int> numero;

    while(getline(fsS, s_riga) && getline(fsP, p_riga))
    {
        if (SimboliCorretti(s_riga, p_riga)  && NumeriCorretti(s_riga, p_riga) && CheckLogica(s_riga, p_riga))
            fsE << "corretto" << endl; 
        else 
            fsE << "falso" << endl;
    }
}

bool Tester::SimboliCorretti(string sol, string prob){

    string soluzione;

    for(int i = 0; i < (int)sol.size(); i++)
    {
        if(sol.at(i) == '<' || sol.at(i) == '>')
            soluzione += sol.at(i);
    }

    if (soluzione != prob)
        return false;
    
    return true;
}




bool Tester::NumeriCorretti(string sol, string prob){

    vector<int> numeri; 
    int numero;
    size_t size = 0;

    for(int i = 0; i < (int)sol.size(); i += size+1 )
    {
        numero = stoi(sol.substr(i), &size);
        numeri.push_back(numero);

    }

   /*for(int k = 0; k < numeri.size(); k ++)
   {
        cout << "  "<< numeri[k];
   }
    cout <<  endl;*/

   sort(numeri.begin(), numeri.end());

    for(int i = 0; i < (int)prob.size(); i++)
    {
        if(numeri.at(i) != (i+1))
            return false;
    }
    return true;

}


bool Tester::CheckLogica(string sol, string prob){

int num1, num2, j = 0;

size_t sze;

    num1 = stoi(sol.substr(0),&sze);

    for(int i = 0; i < (int)prob.size(); i++)
    {
        j += sze +1;
        num2 = stoi(sol.substr(j),&sze);

        if((prob[i] == '>' && num1 > num2) || (prob[i] == '<' && num1 < num2))
             {
                num1 = num2;
                continue;
             }
        return false;
    }

    return  true;
}




