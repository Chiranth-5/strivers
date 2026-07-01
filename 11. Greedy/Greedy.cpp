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


pair < int, int > Greedy::JobScheduling(vector<Job> list, int n)
{
    // returns the total profit and the total number of jobs sceduled

    // sampple list:
    // {(1, 2, 100), (2, 1, 19), (3, 2, 27), (4, 1, 25), (5, 1, 15)}  

    // 1. Sort the list based on max profits
    sort ( list.begin(), list.end(), [] ( Job a, Job b) { return (a.profit > b.profit); });

    // 2. Create vector to mark the job running in each interval. SIze will be that of the job size.
    vector<int> ans(list.size()+1,-1);
    int totalProfit =0;
    int totalJob =0;


    // 3. sceduled job at there deadline if that interval is free or place it in any lower interval time.
    for ( int i=0; i<list.size(); i++)
    {
        int id = list[i].id;
        int deadLine = list[i].deadLine;
        int profit = list[i].profit;

        // from the deadline till 1 in the answer space scedule the job
        for ( int j=deadLine; j>=1; j--)
        {
            if( ans[j] ==-1)
            {
                // scedule it
                ans[j] = id;
                totalProfit += profit;
                totalJob ++;
                break;
            }
        }
    }

    return { totalProfit,totalJob};
    
}


