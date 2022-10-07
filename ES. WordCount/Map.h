#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

class Map
{
private:
    fstream myfile;
    map<string, int> amap;

public:
    Map(string);
    ~Map();

    void occorrenze();
};

Map::Map(string mf)
{
    myfile.open(mf, ios::in);
}

Map::~Map()
{
    myfile.close();
    amap.clear();
}


void Map::occorrenze()
{
    map<string, int>::iterator it;
    string word;

    while (myfile>>word)
    {
        it = amap.find(word);
    
        if ( it == amap.end())
            amap.insert(make_pair(word,1));
        else   
            amap.at(word)++;
    }

    for(it =amap.begin(); it!=amap.end(); it++)
        cout << (*it).first << " => " << (*it).second << endl;
}

#endif