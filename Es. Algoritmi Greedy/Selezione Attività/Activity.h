#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <iostream>
#include <vector>

using namespace std;

class Activity
{
private:
    int s;
    int f;
    int id;

public:
    Activity();
    Activity(int s, int f, int id);

    //get
    int getStart(){return s;}
    int getEnd(){return f;}
    int getId(){return id;}

    //overload di operatore <
    //N.B Friend non era necessario, se avessimo avuto solo un parametro, avrebbe fatto
    //    riferimento a quello
    friend bool operator<(const Activity &obj1, const Activity &obj2)
    {
        //paragoniamo i tempi di fine di ciascuna attività
        return obj1.f < obj2.f;
    }

    friend ostream &operator <<(ostream& out, const Activity &a)
    {
        out<<"Inizio: "<<a.s<<" Fine: "<<a.f<<" ID: "<<a.id<<endl;
        return out;

    }
};

Activity::Activity()
{
    this->s = 0;
    this->f = 0;
    this->id = 0;
}

Activity::Activity(int s, int f, int id)
{
    this->s = s;
    this->f = f;
    this->id = id;
}


#endif