#include "ArrayEasy.h"
#include <map>
using namespace std;

void ArrayEasy::display( vector<int>A)
{   
    for( int i=0; i< A.size(); i++)
    {
        cout << A[i] <<" ";
    }
    cout <<endl;
}

void ArrayEasy::swap( int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void ArrayEasy::reverseInPlace(vector<int>& A, int i, int j)
{
    //A = 1 2 3 4
    // i = 0
    // j = 3

    while(i<j)
    {
        swap(A[i],A[j]);
        i++;
        j--;
    }
}

int ArrayEasy::largestElement(vector<int> A)
{
    //largest element of the array a

    //optimal
    // 1. access ech element and compare to find the maximum

    int maxi=0;
    int n = A.size();

    for( int i=0; i<n;i++)
    {
        if( A[i]>maxi)
        {
            maxi=A[i];
        }
    }


    return maxi;
}

int ArrayEasy::secondLargestElement( vector<int> A)
{
    // brute force
    // 1.sort
    // 2. second largest value 
    // sort( A.begin(), A.end());
    int n = A.size();
    // return A[n-2];

    // optimal
    // 1. go thrue eachvalue while doing that stor  the largest and second largest values.

    //only 1 element or 0 element

    if( n==0 || n==1)
    {
        return -1;
    }

    int largest=0;
    int secondLargest=0;

    for( int i=0; i<n; i++)
    {
        if( A[i]>largest )
        {
            //update largest and the second largest
            secondLargest = largest;
            largest = A[i];
        }
        else if( A[i]>secondLargest)
        {
            //update secondlargest
            secondLargest = A[i];
        }
    }

    return secondLargest;
}

void ArrayEasy::sortArray( vector<int>A)
{
    sort( A.begin(), A.end());

    // buble sort
     
    // run theloop n times
    int n = A.size();
    for( int i=0; i<n; i++)
    {
        
        int flag =0;
        for( int j=i+1; j<n ; j++)
        {
            if( A[j]<A[j-1])
            {
                swap( A[j],A[j-1]);
                flag =1;
            }
        }
        
        // no swaps in the inner loop means the array is already sorted
        if( flag ==0)
        {
            break;
        }
    }

    display(A);
}

bool ArrayEasy::checkSortArray(vector<int>A)
{
    // check if the array is sorted.
    // 4 3 2 5 1

    // 1 access each element and then check if its previus element is smaller if not its not sorted in ascending order

    int n = A.size();
    for( int i=1; i<n; i++)
    {
        if( A[i] < A[i-1])
        {
            return false;
        }
    }

    return true;
}

int ArrayEasy::uniqueArray( vector<int>A)
{
    //A    = 4 2 2 1 5


    int j=1;
    int n= A.size();

    for( int i=1; i<n; i++)
    {
        if( A[i] == A[i-1])
        {
            continue;   
        }
        else
        {
            A[j] = A[i]; 
            j++;
        }
    }

    display(A);
    return j;
}

void ArrayEasy::leftRotate( vector<int>&A)
{
    // 1 2 3 4
    // 2 3 4 1

    int value = A[0];

    int n= A.size();

    // move all values of a from positon 2 till to its left
    for( int i=1; i<n; i++)
    {
        A[i-1] = A[i];
    }

    // last one must be the value
    A[n-1] = value;

    display(A);
}

void ArrayEasy::leftRotate( vector<int>& A, int k)
{
    // k =2
    // a = 1,2,3,4
    // a = 3 4 2 1

    // int n = k;

    // // move two places to left
    // while (k>0)
    // {
    //     leftRotate(A);
    //     k--;
    // }

    // rotate array in place 
    //1. revese full array
    //2. reverse k elements a
    //3. reverse n-k elements

    int n = A.size();

    reverseInPlace(A,0, n-1);
    reverseInPlace(A,n-k, n-1);
    reverseInPlace(A,0, n-k-1);

    display(A);


   
}

void ArrayEasy::moveAllZerosToEnd( vector<int>& A)
{
    // A = 1 3 4 0 1 0

    // two pointers
    // let i form the left stop at 0
    // let j from the roght stop at values.
    // let these two values be swaped if i<j

    // repeat this till i<j

    int i=0;
    int j=A.size()-1;

    while( i<j )
    {
        //move if its number
        if( A[i] != 0)
        {
            i++;
        }
        //move if its 0
        if( A[j] == 0)
        {
            j--;
        }

        if( i<j)
        {
            swap(A[i],A[j]);
        }
    }

    display(A);

}

vector<int> ArrayEasy::findUnion(vector<int> A, vector<int> B)
{
    // // A = 1 2 3
    // // B = 2 3 4 5

    // // ans = 1 2 3 4 5 

    // //travesse thru arr1 and arr2
    // // compare both the values 
    // // 3 cases
    // // 1. if its less then add it to ans and move i. now keep moving i if its still same as old.
    // // 2. if its more then add it to ans and move j. now keep moving j if its still same as old.
    // // now take care of remaning vlaues of each A and B.

    // int i=0;
    // int j=0;
    // int n = A.size();
    // int m = B.size();

    // vector<int> ans;

    // while ( i<n && j<m)
    // {
    //     if( A[i] == B[j] )
    //     {
    //         ans.push_back(A[i]);
    //         i++;
    //         j++;
    //     }
    //     else if( A[i] < B[j])
    //     {
    //         ans.push_back(A[i]);
    //         i++;
    //         // if values in A repeat it must be skipped

    //         while( i<n && A[i] == A[i-1])
    //         {
    //             i++;
    //         }
    //     }
    //     else
    //     {
    //         ans.push_back(B[j]);
    //         j++;
    //         // if values in A repeat it must be skipped

    //         while( j<m && B[j] == B[j-1] )
    //         {
    //             j++;
    //         }
    //     }
    // }

    // while( i<n)
    // {
    //     //if the A is still remaning
    //     ans.push_back(A[i]);
    //     i++;
    //     // if values in A repeat it must be skipped

    //     while( i<n && A[i] == A[i-1])
    //     {
    //         i++;
    //     }
    // }

    // while( j<m)
    // {
    //     //if the A is still remaning
    //     ans.push_back(B[j]);
    //     j++;
    //     // if values in A repeat it must be skipped

    //     while( j<m && B[j] == B[j-1] )
    //     {
    //         j++;
    //     }
    // }

    // return ans;

    // A = 1 2 3
    // B = 2 3 4 5

    // ans = 1 2 3 4 5 

    //travesse thru arr1 and arr2
    // compare both the values 
    // 3 cases
    // 1. if its less and check if its not the last value in ans then add. move i.
    // 2. if its more and check if its not the last value in ans then add. move j.
    // now take care of remaning vlaues of each A and B.

    int i=0;
    int j=0;
    int n = A.size();
    int m = B.size();
    vector<int> ans;

    while( i<n && j<m)
    {
        if( A[i] == B[j])
        {

            // add to ans if the ans does not have this value alreadu
            if( ans.empty() || A[i] != ans.back())
            {
                ans.push_back(A[i]);
            }
            i++;
            j++;
        }
        else if( A[i] < B[j] )
        {

            if( ans.empty() || A[i] != ans.back())
            {
                ans.push_back(A[i]);
            }
            i++;
        }
        else
        {
            if( ans.empty() || B[j] != ans.back())
            {
                ans.push_back(B[j]);
            }
            j++;
        }
    }

    // remaning A values
    while( i<n)
    {
        if( ans.empty() || A[i] != ans.back())
        {
            ans.push_back(A[i]);
        }
        i++;
    }

    // remaning j values
    while( j<m)
    {
        if( ans.empty() || B[j] != ans.back())
        {
            ans.push_back(B[j]);
        }
        j++;
    }

    return ans;

}

int ArrayEasy::missingNum(vector<int>& A)
{
    // Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
    // Output: 6
    // Explanation: All the numbers from 1 to 8 are present except 6.

    // Input: arr[] = [1, 2, 3, 5]
    // Output: 4
    // Explanation: Here the size of the array is 4, so the range will be [1, 5]. The missing number between 1 to 5 is 4


    // 1.sort the values in A
    sort( A.begin(), A.end());

    // 2.now check if the difference is grater than 
    for( int i=1; i<A.size(); i++)
    {
        if( A[i] - A[i-1] >1 )
        {
            return A[i] -1;
        }
    }

    return -1;

    // sum of n numbers summation
}

int ArrayEasy::findMaxConsecutiveOnes(vector<int>& A)
{
    // Example 1:
    // Input: prices = {1, 1, 0, 1, 1, 1}
    // Output: 3
    // Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

    // Example 2:
    // Input: prices = {1, 0, 1, 1, 0, 1} 
    // Output: 2
    // Explanation: There are two consecutive 1's in the array. 

    // // two pointers
    // // traverse thru prices with i
    // // if there is 1 encountered then traverse with j and check if its the same value

    //method 1:
    // int i=0;
    // int maxCount = 0;

    // while( i< A.size())
    // {
    //     if( A[i] == 1)
    //     {
    //         int j = i+1;
    //         int count = 1;
    //         while( A[j] == 1)
    //         {
    //             count++;
    //             j++;
    //         }
    //         i=j;
    //         maxCount = max(maxCount,count);
    //     }

    //     i++;
    // }

    // return maxCount;

    //method 2
    // traverse thru once
    // add count if its 1 or reset cont to 0
    // keep the maximum count

    int maxC=0;
    int count =0;

    for( int i=0; i< A.size(); i++)
    {
        if( A[i] == 1)
        {
            //add count 
            count ++;
        }
        else 
        {
            //reset count 
            count = 0;
        }

        maxC = max( count , maxC);
    }
    return maxC;

}

int ArrayEasy::getSingleElement(vector<int>& A)
{
    // Example 1:
    // Input Format: arr[] = {2,2,1}
    // Result: 1
    // Explanation: In this array, only the element 1 appear once and so it is the answer.


    // Example 2:
    // Input Format: arr[] = {4,1,2,1,2}
    // Result: 4
    // Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.

    // use map datastructure to store the frequency of each number in the vector.

    std::map<int,int> mpF;

    for( int i=0; i<A.size(); i++)
    {
        mpF[A[i]]++;
    }
    // use this hasmap value to find the frequnce 1

    for ( auto it : mpF)
    {
        if( it.second == 1)
        {
            return it.first;
        }
    }

    return -1;

    // best method is using xor

}

int ArrayEasy::longestSubarray(vector<int>& A, int requiredSum)
{
    // Example 1:
    // Input:
    // nums = [10, 5, 2, 7, 1, 9], k = 15  
    // Output:
    // 4  

    // // method 1
    // // i fixes start of an array
    // // j fixies end of an array
    // // k travese from i to j and calculates the sum
    // // On3

    // int n = A.size();
    // int maxCount =0;

    // for( int i=0; i<n; i++)
    // {
    //     for ( int j=i; j<n; j++)
    //     {
    //         int sum =0;
    //         int count =0;
    //         for( int k =i; k<=j; k++)
    //         {
    //             sum += A[k];
    //         }
    //         if( sum == requiredSum)
    //         {
    //             count = j-i+1;
    //         }

    //         maxCount = max(count,maxCount);
    //     }
    // }

    // return maxCount;


    // // method 2
    // // i fixes start of an array
    // // j fixies end of an array .while doing it already moves from i till the end.
    // // On2

    // int n = A.size();
    // int maxCount =0;

    // for( int i=0; i<n; i++)
    // {
    //     int sum =0;
    //     int count =0;
    //     for ( int j=i; j<n; j++)
    //     {
    //         sum += A[i];

    //         if( sum == requiredSum)
    //         {
    //             count = j-i+1;
    //         }

    //         maxCount = max(count,maxCount);
    //     }
    // }

    // return maxCount;

    // method 3

    int n = A.size();
    int sum = 0;
    unordered_map<int,int> prefixSum; // prefix sum and index

    for (int i =0 ; i<n; i++)
    {
        sum =+ A[i];

        int rem = sum -requiredSum;

        // check if rem is value is found in the prefix sum else add it

        int maxl = INT_MIN;

        if( prefixSum.find(rem) != prefixSum.end())
        {
            // found

            // calculate length

            int length = i- prefixSum[sum];
            maxl = max(length , maxl);

        }
        else
        {
            // add it
            prefixSum[sum]=i;
        }
        

    }

















    // 1. while traversing keep calclauting the sum till there.
    // 2. check if its same as the sum and 

    // int n = A.size();
    // int maxLen =0;
    // int sum = 0;

    // unordered_map<int,int> prefixSum ; // key , value ---> preSum , index_number

    // for( int i=0; i<n; i++)
    // {
    //     sum += A[i];
    //     if( sum == requiredSum)
    //     {
    //         maxLen = max( maxLen, i+1);
    //     }

    //     int rem = sum - requiredSum;
    //     // if the remaning sum value is present before that means the reSum is present from that location till here.
    //     if( prefixSum.find(rem) != prefixSum.end())
    //     {
    //         //found
    //         // calclutle the new length fromt hat location

    //         maxLen = max( maxLen, i-prefixSum[rem]);

    //     }

    //     // add only if the presum is not there.
    //     if( prefixSum.find(sum) ==  prefixSum.end())
    //     {
    //         prefixSum[sum] = i;
    //     }

    // }

    // return maxLen;



    // method 4
    // 1. take two pionters .
    // move right one as long as the sum is less than the total required.
    // if it crosses then stop it.

    int n = A.size();
    int maxLen =0;
    int sum = 0;

    int i=0;
    int j=0;

    while( i<n )
    {
        sum += A[i];

        while( sum > requiredSum)
        {
            sum = sum-A[j];
            j++;
        }
        if( sum < requiredSum)
        {
            i++;
        }
        else
        {
            maxLen = max(maxLen,i-j+1);
            i++;
        }
    }

    return maxLen;


}