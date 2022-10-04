#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H
#include <iostream>
#include <string>

using namespace std;

class Transazione
{
private:
    string FROM;
    string TO;
    int QT;

public:
    Transazione(string, string, int);
    //~Transazione();

    void setFrom(string);
    void setTo(string);
    void setQt(int);

    string getFrom(){return FROM;}
    string getTo(){return TO;}
    int getQt(){return QT;}

    void printTransazione();
};

Transazione::Transazione(string F, string T, int Q)
{
    FROM = F;
    TO = T;
    QT = Q;
}

/*
Transazione::~Transazione()
{
}
*/

void Transazione::setFrom(string F)
{
    FROM = F;
}

void Transazione::setTo(string T)
{
    TO = T;
}

void Transazione::setQt(int Q)
{
    QT = Q;
}


void Transazione::printTransazione()
{
    cout<<"FROM: "<< FROM << " TO: "<< TO << " QT: "<< QT <<endl;
}

#endif