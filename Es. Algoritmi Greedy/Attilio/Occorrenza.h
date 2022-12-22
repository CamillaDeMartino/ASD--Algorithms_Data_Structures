#ifndef OCCORRENZA_H
#define OCCORRENZA_H

#include <iostream>

using namespace std;

template<class T>
class Occorrenza
{
private:

    int freq;
    T data;

public:
    Occorrenza(T data, int freq)
    {
        this->data = data;
        this->freq = freq;
    };

    void setFrequenza(int freg){this->freq = freq;}
    void setData(T data){this->data = data;}

    int getFrequenza(){return freq;}
    T getData(){return data;}

    //....overload operatori;
    bool operator<(const Occorrenza &obj1)
    {
        return this->freq < obj1.freq;
    };

    bool operator<=(const Occorrenza &obj1)
    {
        return this->freq <= obj1.freq;    
    };

    bool operator>(const Occorrenza &obj1)
    {
        return this->freq > obj1.freq;
    };

    bool operator>=(const Occorrenza &obj1)
    {
        return this->freq >= obj1.freq;
    };

    void operator=(const Occorrenza &obj1)
    {
        this->freq = obj1.freq;
        this->data= obj1.data;
    };

    bool operator==(const Occorrenza &obj1)
    {
        return this->freq == obj1.freq;
    };

    friend ostream& operator<<(ostream& out, const Occorrenza &o)
    {
        out<<"Carattere: "<<o.data<<" Frequenza: "<<o.freq<<endl;
        return out;
    };
};




#endif