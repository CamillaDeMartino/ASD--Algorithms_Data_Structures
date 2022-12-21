#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <iostream>
#include <vector>
//#include "../../ES-MergeSort/MergeSort-Vector/MergeSort.h"
#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\ES. MergeSort\MergeSort-Vector\MergeSort.h"
#include "Activity.h"

using namespace std;

class Scheduler
{
private:
    
public: 
    static vector<Activity> scheduler(vector<Activity>);
};


vector<Activity> Scheduler::scheduler(vector<Activity> activity)
{
    Algoritmi<Activity>::mergeSort(activity.begin(), activity.end()-1);

    vector<Activity> scheduling;
    scheduling.push_back(activity.at(0));

    int prev = 0;

    for(int i = 1; i < activity.size(); i++)
    {
        if(activity.at(i).getStart() >= activity.at(i-1).getEnd())
            scheduling.push_back(activity.at(i));
    }

    return scheduling;
}




#endif