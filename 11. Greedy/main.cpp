#include "Greedy.h"

int main()
{
    Greedy obj;

    // vector<int> jobs = { 3,2,4,1,5};

    // float avgWaitingTime = obj.calculateAverageWaitTime(jobs);

    // cout << "avgWaitingTime : " << avgWaitingTime << endl;


    // vector<Job> list = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};


    // pair < int, int > totalProfitTotalJob = obj.JobScheduling(list,5);

    // cout << "totalProfitTotalJob : " << totalProfitTotalJob.first <<" " <<totalProfitTotalJob.second << endl;

  
    // vector<int> start = {1,3,0,5,8,5};
    // vector<int> end = {2,4,5,7,9,9};


    // vector <int> NMeetingInARoom = obj.nMeetingInARoom(start,end);

    // for (int val : NMeetingInARoom)
    // {
    //     cout << "NMeetingInARoomList : " << val << endl;
    // }

    vector<float> arrival = {9.0, 9.75, 9.916, 11.0, 15.0, 18.00};
    vector<float> departure = {9.33, 12.00, 11.50, 11.833, 19.00, 20.00};


    int minimumNumberOfPlatforms = obj.minimumNumberOfPlatforms(arrival,departure);
    cout << "minimumNumberOfPlatforms : " << minimumNumberOfPlatforms << endl;
  

}