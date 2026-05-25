#include <iostream>
#include <vector>
using namespace std;

class RecursionEasy
{
    public:
        
        double power(double x, long n);

        int countGoodNumbers(int index, int n) ;

        void sortStack(stack<int>& s);

        void reverseStack(stack<int>& s);

        void generateL( int n , string curr, vector<string>& res);

        void generateParaenthesis(int n, string curr, vector<string>& res, int open, int close);

        vector<string> getSubsequences(string s);

        //1.find the subsequence whose sum is k
        //2.Count all the subsequence whose sum is k

        
        

};