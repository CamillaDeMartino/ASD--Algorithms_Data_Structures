#ifndef SOLUZIONE_H
#define SOLUZIONE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Soluzione
{
private:
    fstream fmatrix;
    vector<int> vettore;

public:
    Soluzione(string );
    ~Soluzione();

    void getMatrix();
    void check();
};

Soluzione::Soluzione(string matrix)
{
    fmatrix.open(matrix.c_str(), ios::in);
    getMatrix();
}

Soluzione::~Soluzione()
{
    fmatrix.close();
    vettore.clear();
}

void Soluzione::getMatrix()
{
    int numero;
    for(int i = 0; i < 15; i++)
    {
        fmatrix>>numero;
        vettore.push_back(numero);
    }
}


void Soluzione::check()
{
    vector<int>::iterator it;
    int i = 1;
    for(it = vettore.begin(); it != vettore.end(); it++, i++)
    {
        cout<<*it<<" "<<i<<endl;
        if(*it != i)
        {
            cout<<"Matrice non ordinata"<<endl;
            break;
        }
        else
        {
            cout<<"Giusto"<<endl;
        }
    }
}

#endif