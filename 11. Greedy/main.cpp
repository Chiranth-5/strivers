#include "Greedy.h"

int main()
{
    Greedy obj;

    vector<int> jobs = { 3,2,4,1,5};

    float avgWaitingTime = obj.calculateAverageWaitTime(jobs);

    cout << "avgWaitingTime : " << avgWaitingTime << endl;

}