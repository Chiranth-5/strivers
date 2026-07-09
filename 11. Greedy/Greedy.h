#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct Job
{
    public:
        int id;
        int deadLine;
        int profit;
};


class Greedy
{

        // 1.assign cookies -leetcode
        // 2.lemonade bills - leetcode
    public:
        // 3.shortestest job first:
        float calculateAverageWaitTime(vector<int>& jobs) ;

        // 4.jumpgame 1 -leetcode
        // 5.jumpgame 2 -leetcode
    
        // 6.job sequence
        pair < int, int > jobScheduling(vector<Job> list, int n);

        // 7. N meetings in a room
        vector<int> nMeetingInARoom ( vector<int> start, vector<int> end);

        // 8. Non-Overlapping
        // 9. Insert Interval
        // 10. Merge Interval
        // 11. Minimum number of platforms for all sceduled trains.
        int minimumNumberOfPlatforms ( vector<float> arrival, vector<float> departure);
        

    

};