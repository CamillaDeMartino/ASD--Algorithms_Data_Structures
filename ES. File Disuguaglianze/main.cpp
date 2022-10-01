#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool controlloelementi(vector<int> elementi, vector<int> elementi1);

class Tester{
    private:
        ifstream fsP;
        ifstream fsS;
        ofstream fsE;
        bool simbolicorretti(string , string );
        bool numeriusati(string);
        bool logicacorretta(string, string);
    public:
        Tester(string strP, string strS, string strE);
        ~Tester(){/*...*/};
        void check();
};

Tester::Tester(string strP, string strS, string strE)
{
    fsP.open(strP.c_str(), ios::in);
    fsS.open(strS.c_str(), ios::in);
    fsE.open(strE.c_str(), ios::out);
}

void Tester::check()
{

    string P_riga, S_riga;
    while(getline(fsP, P_riga) && getline(fsS, S_riga))
    {
        if(simbolicorretti(P_riga,S_riga) && numeriusati(S_riga) && logicacorretta(P_riga, S_riga))
            fsE << "corretto"<< "\n";
        else
            fsE << "falso"<<"\n";
    }

    fsE.close();
    fsP.close();
    fsS.close();
}

bool Tester ::simbolicorretti(string p_riga, string s_riga)
{
    string soluzione;

     for(int i = 0; i < (int)s_riga.size(); i++)
    {
        if(s_riga.at(i) == '<' || s_riga.at(i) == '>')
            soluzione += s_riga.at(i);
    }
    if(p_riga != soluzione)
        return false;

    return true;
}

bool Tester ::numeriusati(string p_riga)
{
    vector<int> elementi, elementi1(elementi.size()+1);
    int i, numero;
    size_t sze;

    for(i = 0; i < (int)p_riga.size(); i+= sze+1)
    {
        numero = stoi(p_riga.substr(i),&sze);
        elementi.push_back(numero);
    }

   /*for(int k = 0; k < elementi.size(); k ++)
   {
        cout << "  "<< elementi[k];
   }
    cout <<  endl; */

    for(int j = 0; j < (int)elementi.size(); j++)
    {
        elementi1.push_back(1) ;
    }

   /*for(int k = 0; k < elementi1.size(); k ++)
   {
        cout << "  "<< elementi1[k];
   }
    cout <<  endl;
   */ 
   if(controlloelementi(elementi, elementi1))
        return true;

    return false;

}


bool Tester ::logicacorretta(string p_riga, string s_riga )
{
    int num1, num2, i, j = 0;
    size_t sze;

    num1 = stoi(s_riga.substr(0),&sze);

    for(i = 0; i < (int)p_riga.size(); i++)
    {
        j += sze +1;
        num2 = stoi(s_riga.substr(j),&sze);

        if((p_riga[i] == '>' && num1 > num2) || (p_riga[i] == '<' && num1 < num2))
            {
                num1 = num2;
                continue;
            }
        return false;
    }

    return  true;
}



bool controlloelementi(vector<int> elementi, vector<int> elementi1)
{

    for(int j = 0; j < (int)elementi.size(); j++)
    {
         elementi1[elementi[j]]-= 1;
    }


    for(int j = 0; j < (int)elementi1.size(); j++)
    {
        if(elementi1[j] != 0)
            return false;
    }
            return true;

}
int main()
{
    string p = "problema.txt";
    string s = "soluzione.txt";
    string e = "esito.txt";
    Tester tester(p,s,e);
    tester.check();

    return 0;
}
