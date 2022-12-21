/*
    Problema della selezione delle attività
    (Greedy Activity Selector)
    • Siano date n attività in competizione tra loro per l’utilizzo
    di una certa risorsa (e.g. processi in un sistema di
    elaborazione in competizione per la CPU)
    • Trovare l’allocazione ottimale della risorsa, cioè il più
    grande sottoinsieme di attività che possono condividere
    la risorsa senza creare conflitti
*/

#include <iostream>
#include <vector>
#include "Activity.h"
#include "Scheduler.h"

using namespace std;

int main(){

    vector<Activity> activity;
    vector<int> s = {1, 3, 0, 5, 3, 5, 6, 8, 8, 12};
    vector<int> f = {4, 5, 6, 7, 8, 9, 10, 11, 12, 14};

    for(int i = 0; i < s.size(); i++)
        activity.push_back(Activity(i+1, s.at(i), f.at(i)));

    vector<Activity> scheduler = Scheduler::scheduler(activity);

    cout<<"**ATTIVITA***"<<endl;
    for(auto i:activity)
        cout<<i;

    cout<<"***SCHEDULER***"<<endl;
    for(auto i:scheduler)
        cout<<i;



    return 0;
}