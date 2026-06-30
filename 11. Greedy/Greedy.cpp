#include "Greedy.h"

float Greedy::calculateAverageWaitTime(vector<int>& jobs)
{
    //jobs = [3, 1, 4, 2, 5]

    // find the least average waiting period

    // greedily choose the least value and calulate the wait time.

    //sort
    sort( jobs.begin(), jobs.end());

    int waitTime =0;
    int totalWaitTime=0;

    // find the wait time of each job
    for(int i=1; i< jobs.size(); i++)
    {
        waitTime += jobs[i-1];
        totalWaitTime += waitTime;
    }

    int ans = totalWaitTime / jobs.size();

    return ans;
}


