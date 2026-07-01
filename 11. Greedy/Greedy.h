#include <iostream>
#include <vector>
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
        pair < int, int > JobScheduling(vector<Job> list, int n);
    

};