#include "RecursionEasy.h"



double RecursionEasy::power( double x,long n)
{
    // Base case: anything raised to 0 is 1
    if (n == 0) return 1.0;

    // Base case: anything raised to 1 is itself
    if (n == 1) return x;

    // to recude number of calls
    // If 'n' is even
    if (n % 2 == 0) 
    {
        // Recursive call: x * x, n / 2
        return power(x * x, n / 2);
    }
        
    // If 'n' is odd
    // Recursive call: x * power(x, n-1)
    return x * power(x, n - 1);

}

int RecursionEasy::countGoodNumbers( int index, int n) 
{
    int MOD = 1e9 + 7;
    // Base case: if we've reached the end of the string
    if (index == n) 
    {
        // Return 1 as we've formed a valid string
        return 1; 
    }

    int result = 0;
    // Even index: Use even digits
    if (index % 2 == 0) 
    {  
        // Even digits: 0, 2, 4, 6, 8
        for (int digit : {0, 2, 4, 6, 8}) 
        {
            result = (result + countGoodNumbers(index + 1, n)) % MOD;
        }
    } 
    // Odd index: Use prime digits
    else 
    {  
        // Prime digits: 2, 3, 5, 7
        for (int digit : {2, 3, 5, 7}) 
        {
            result = (result + countGoodNumbers(index + 1, n)) % MOD;
        }
    }
    return result;


}

void insertInDesendingOrder( stack <int> &s, int temp)
{
    // base case
    if( s.empty() || s.top()<= temp)
    {
        //add without the issue
        s.push(temp);
        return;
    }

    // we need to remove the values till temp>s.top and then insert

    int val = s.top();
    // remove
    s.pop();
    //add
    insertInDesendingOrder(s,temp);

    // push back what you removed
    s.push(val);

}


void RecursionEasy::sortStack(stack<int>& s)
{
    // remove all the elements from the stack

    if( !s.empty())
    {
        int temp = s.top();
        s.pop();
        sortStack(s);
        insertInDesendingOrder( s, temp);
    }
}


void insertAtBottom( stack <int> &s, int temp)
{
    // base case
    if( s.empty())
    {
        //add 
        s.push(temp);
        return;
    }

    // we need to remove values as its
    int val = s.top();
    // remove
    s.pop();
    //add
    insertAtBottom(s,temp);
    // push back what you removed
    s.push(val);

}


void RecursionEasy::reverseStack(stack<int>& s)
{
    // remove all the elements from the stack

    if( !s.empty())
    {
        int temp = s.top();
        s.pop();
        reverseStack(s);
        insertAtBottom( s, temp);
    }
}


void RecursionEasy::generateL( int n , string curr, vector<string>& res)
{
    //Problem Statement: 
    // Given an integer n, return all binary strings of length n that do not contain
    // consecutive 1s. Return the result in lexicographically increasing order.
    // A binary string is a string consisting only of characters '0' and '1'.

    // base case
    if( n== curr.length())
    {
        res.push_back(curr);
        return;
    }

    curr.push_back('0');
    generateL(n , curr, res);
    curr.pop_back();

    if( curr.empty() || curr.back()!= '1')
    {
        curr.push_back('1');
        generateL(n , curr, res);
        curr.pop_back();
    }


}

void RecursionEasy::generateParaenthesis( int n, string curr, vector<string>& res, int open, int close)
{
    if( 2*n == curr.size())
    {
        // found the string
        res.push_back(curr);
        return;
    }

        if( open <n)
    {
        // add open value
        // add '0' string
        // find recursively all values
        // remove last  value of sting ie '0'
        // open--;
        generateParaenthesis(n,curr+'(',res, open+1, close);
    }

    if( close <open)
    {
        // add open value
        // add '0' string
        // find recursively all values
        // remove last  value of sting ie '0'
        // open--;
        generateParaenthesis(n,curr+')',res, open, close+1);
    }
    

}


// Helper recursive function to generate subsequences
void helper(string &s, int index, string current, vector<string> &result) {
        // Base case: If index reaches string length, add current subsequence to result
        if (index == s.size()) 
        {
            if(current == "")
            {
                return;
            }
            result.push_back(current);
            return;
        }

        // Include current character and recurse
        current.push_back(s[index]);
        helper(s, index + 1, current, result);
        // Backtrack: remove last character before returning to previous call
        current.pop_back();

        // Exclude current character and recurse
        helper(s, index + 1, current, result);


    }

// Function to return all subsequences of string s
vector<string> RecursionEasy::getSubsequences(string s) 
{
    // Vector to store all subsequences
    vector<string> result;  
    // Current subsequence being built
    string current = "";    
    helper(s, 0, current, result);
    return result;
}





