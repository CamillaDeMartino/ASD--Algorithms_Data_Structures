#include <iostream>
#include <vector>

using namespace std;

struct entry{
    int a,b;
};

struct exit{
    int a,b;
};

vector<int>fastestWay(vector<vector<int>> Aij, vector<vector<int>> tempoTrasferimento, struct entry entry, struct exit exit, int n)
{
    vector<int> catena1, catena2;
    vector<int> l1, l2;             //scelta catena 1 e 2  

    catena1.push_back(entry.a + Aij[0][0]);
    catena2.push_back(entry.b + Aij[1][0]);

    for(int j = 1; j < n; j++)
    {
        //catena di sopra
        if(catena1.at(j-1) + Aij[0][j] <= catena2.at(j-1) + Aij[0][j] + tempoTrasferimento[1][j-1])
        {
            catena1.push_back(catena1.at(j-1) + Aij[0][j]);
            l1.push_back(1);
        }
        else 
        {
            catena1.push_back(catena2.at(j-1) + Aij[0][j] + tempoTrasferimento[1][j-1]);
            l1.push_back(2);
        }

        //catena di sotto
        if(catena2.at(j-1) + Aij[1][j] <= catena1.at(j-1) + Aij[1][j] + tempoTrasferimento[0][j-1])
        {
            catena2.push_back(catena2.at(j-1) + Aij[1][j]);
            l2.push_back(1);
        }
        else
        {
            catena2.push_back(catena1.at(j-1) + Aij[1][j] + tempoTrasferimento[0][j-1]);
            l2.push_back(2);
        }
    }

    if(catena1.at(n-1) + exit.a <= catena2.at(n-1) + exit.b)
    {
        l1.push_back(1);
        cout<<"Vince la prima catena"<<endl;
        return l1;
    }
    else
    {
        l2.push_back(2);
        cout<<"Vince la seconda catena"<<endl;
        return l2;
    }


}