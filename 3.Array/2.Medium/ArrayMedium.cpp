#include "ArrayMedium.h"

void ArrayMedium::display( vector<int>A)
{   
    for( int i=0; i< A.size(); i++)
    {
        cout << A[i] <<" ";
    }
    cout <<endl;
}

void ArrayMedium::swap( int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool ArrayMedium::twoSum(vector<int>& A, int target)
{
    // Input: N = 5, arr[] = {2,6,5,8,11}, target = 14
    // Output : YES
    // Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for first variant for second variant output will be : [1,3].

    // Input: N = 5, arr[] = {2,6,5,8,11}, target = 15
    // Output : NO.
    // Explanation: There exist no such two numbers whose sum is equal to the target.
    

    //method 1
    //1. go thru each element
    //2. calculate the remaing value to reach target. check its present in the arrays before this.
    //3. Will end up using hashmap and then add values to has map if not found . 

    // map<int,int> remainingValues;
    // int n = A.size();

    // for( int i=0; i<n; i++)
    // {
    //     int rem = target-A[i];

    //     if( remainingValues.find(rem) != remainingValues.end())
    //     {
    //         //its found.
    //         return true;
    //     }
    //     remainingValues[A[i]] = i;

    // }

    // return false;

    //method 2  
    // 1. sort array
    //2. use two pointeer. one from either side.
    //3. comapre the sum if its less than target move the left one else move right one

    sort(A.begin(),A.end());

    int i=0;
    int j=A.size()-1;

    while(i<j)
    {
        int sum = A[i]+A[j];

        if( target == sum)
        {
            return true;
        }
        else if( target <sum)
        {
            //move tthe left
            i++;

        }
        else
        {
            j--;
        }
    }

    return false;


}

vector<int> ArrayMedium::dutchflag( vector<int>& A)
{
    // Input: nums = [1, 0, 2, 1, 0]
    // Output: [0, 0, 1, 1, 2]
    // Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two

    // Input: nums = [0, 0, 1, 1, 1]
    // Output: [0, 0, 1, 1, 1]
    // Explanation: The nums array in sorted order has 2 zeroes, 3 ones and zero twos.


    // method 1:
    // sort algo 
    // On2

    // // method 2:
    // // count the numbers ands then refill the values
    // int n=A.size();
    // int count0 = 0;
    // int count1 = 0;
    // int count2 = 0;
    // for( int i=0; i<n; i++)
    // {
    //     if( A[i] == 0)
    //     {
    //         count0++;
    //     }
    //     else if( A[i] == 1)
    //     {
    //         count1++;
    //     }
    //     else 
    //     {
    //         count2++;
    //     }
    // }

    // int i=0;
    // for ( int j=0; j<count0; j++)
    // {
    //     A[i] =0;
    //     i++;
    // }
    // for ( int j=0; j<count1; j++)
    // {
    //     A[i] =1;
    //     i++;
    // }
    // for ( int j=0; j<count2; j++)
    // {
    //     A[i] =2;
    //     i++;
    // }

    // return A;

    //method 3
    //consider three pointers
    // low
    // mid
    // high

    // assume everything till low is 0 and low points to start of middle section 
    // assume everything after high point is 2.
    
   

    int low = 0;
    int high = A.size()-1;
    int mid = 0;

    // now trverse from mid ie point just adter low till high .
    while( mid <= high)
    {
        // we can get three cases 0,1,2
        if( A[mid] == 0)
        {
            //swap low and mid value and moveboth values
            swap(A[low],A[mid]);
            low++;
            mid++;
        }
        else if ( A[mid]==1)
        {
            // remain same. move mid
            mid++;
        }
        else
        {
            // swap mid and high/ Dont move mid we need to check again if its lower or same.
            //move high backwards.
            swap(A[mid],A[high]);
            high--;
        }

    }

    return A;


}

int ArrayMedium::MajorityElementBoyerVoting( vector<int>A)
{
    // nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]  
    // Output: 7


    // majority element. 
    // pair wise destruction
    // Boyer moore voiting algorithm
    // if all the elemenets apart from the major element took out each major element then still we will have a mojor element remaining at the end.

    int n = A.size();
    int count =0;
    int element =-1;
    for( int i=0; i<n;i++)
    {
        if(count == 0)
        {
            count++;
            element = A[i];
        }
        else if (A[i] == element)
        {
            count ++;
        }
        else 
        {
            count--;
            if( count ==0)
            {
                count++;
                element = A[i];
            }
        }

    }

    return element;
}

int ArrayMedium::KadaneAlgorithm( vector<int> A)
{
    //  input:
    //  nums = [2, 3, 5, -2, 7, -4]  
    //  Output:
    //  15  
    //  Explanation:
    //  The subarray from index 0 to index 4 has the largest sum = 15, 
    //   which is the maximum sum of any contiguous subarray.

    //  kadanceAlgorithm

    // the idea is is it worth calculating the total by adding to old one or to start new fresh one.

    // In this case if the cumulative sum is less than 0 then start fresh.
    // keep track of exitIndex then we can find the complete subarray.


    int maxS=0;
    int sum =0;
    int n= A.size();
    int endIndex = 0;
    int startIndex = 0;

    for( int i=0; i<n; i++)
    {
        sum += A[i];

        if( sum ==0)
        {
            startIndex=i;
        }
        if( sum > maxS)
        {
            maxS = sum ;
            endIndex = i;
        }
        
        if( sum <0)
        {
            //start fresh
            sum = 0;
        }
    }

    return maxS;

}

int ArrayMedium::stockbuySell(vector<int>& A)
{
    // Input: prices = [7,1,5,3,6,4]
    // Output: 5
    // Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    // Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

    // Input: prices = [7,6,4,3,1]
    // Output: 0
    // Explanation: In this case, no transactions are done and the max profit = 0.

    // method-1
    // find all the difference of each subarrays and return the maximum one

    // method-2
    // keep track of the minimum value .
    // keep track of the maximum profit.
    // traverse thru once. while doing find out the profits in each secnerio and rememeber the maximum value.

    int minV= INT_MAX;
    int maxP= INT_MIN;

    for( int i=0; i<A.size(); i++)
    {
        // store the minimum value 
        minV = min(A[i], minV);

        // check profits
        if( A[i]>minV)
        {
            int p = A[i]-minV;
            //stroe the maximum profit
            maxP = max(maxP,p);
        }
    }

    return maxP;
    
}

vector<int> ArrayMedium::rearrangeBySign(vector<int>& A)
{
    // mehtod 1
    // traverse thru A.
    // if its negative  then fill this in asnwer array in the odd spaces
    // if its positive then fill this in answer array in the even spaces

    int n=A.size();
    vector<int> ans(n);
    int oddSpace =1;
    int evenSpace =0;

    for( int i=0; i<n; i++)
    {
        if( A[i]<0)
        {
            //odd space index
            ans[oddSpace] = A[i];
            oddSpace = oddSpace+2;
        }
        else
        {
            // even space
            ans[evenSpace] = A[i];
            evenSpace = evenSpace+2;
        }
    }

    return ans;
}

vector<int> ArrayMedium::nextPermutation(vector<int>& A)
{
    //2 1 5 4 3 0 0

    // next permutation is to find what will be the next value if its rearragned in the the dictionalry
    
    //1. will keep the prefix same till we find the break point.
    //2 . Break point on the left and the right .

    int n=A.size();

    int breakL=-1;
    for ( int i=1; i<n; i++)
    {
        if(A[i]>A[i-1])
        {
            breakL = i-1;
            break;
        }
    }
    //3. find the value which is greater than breakL from all the values from the right. And swap it
    // 2 1 5 4 3 0 0
    //   bL

    if( breakL !=-1)
    {
        // will start from the end as its in descending order
        for( int i =n-1; i>=0; i--)
        {
            if( A[i] >A[breakL] )
            {
                swap(A[i],A[breakL]);
                break;
            }
        }
    }
    //2 3 5 4 1 0 0

    //4. now all the values from breakL till end must be sorted.
    // As we know its in descending orderl Just reverse it

    //2 3 0 0 1 4 5  
    reverse(A.begin()+breakL+1, A.end());

    return A;
}

vector<int> ArrayMedium::leaders(vector<int>& A)
{
    // Input:
    // arr = [4, 7, 1, 0]  
    // Output:
    // 7 1 0  

    //method-1
    // traverse from the right
    int n = A.size();
    int maxi=-1;
    vector<int> ans;
    for ( int i=n-1; i>=0; i--)
    {
        if( A[i]>maxi)
        {
            ans.push_back(A[i]);
            maxi = A[i];
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int ArrayMedium::longestConsecutive(vector<int>& A)
{
    // // Input:
    // // nums = [100, 4, 200, 1, 3, 2]  
    // // Output:
    // // 4  
    // // Explanation:
    // // The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

    // // Example 2:
    // // Input:
    // // nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
    // // Output:
    // // 9 

    // menthod-1 : sort the values. Then find the consecutive using two varaibles streak and reset concept

    // sort( A.begin(), A.end());

    // int countOfConsecutiveValues=1;
    // int maxC=-1;
    // int n = A.size();
    // for( int i=1; i<n;i++)
    // {
    //     if( A[i]-A[i-1] == 1)
    //     {
    //         countOfConsecutiveValues++;
    //     }
    //     else
    //     {
    //         //reset
    //         countOfConsecutiveValues=1;
    //     }

    //     maxC= max(countOfConsecutiveValues,maxC);
    // }

    // return maxC;

    // method-2
    
    // 1. store the value in set.
    // 2. traverse thru this.
    // 3. if the element is start then count its conitnues values.

     
    int n = A.size(); 
    unordered_set<int> A_set;
    
   
    for (int i = 0; i < n; i++) 
    {
        A_set.insert(A[i]);
    }


    int maxlongest =1;
    // 1 2 3 8 7
    for (auto it : A_set)
    {
        // if its a start then count its cosecutive
        if( A_set.find(it - 1) == A_set.end())
        {
            int longest =1;
            int value = it;
            value++;
            while( A_set.find(value) !=A_set.end())
            {
                longest++;
                value++;
            }
            
            maxlongest = max(maxlongest,longest);
            //reset longest
            
        }
    }

    return maxlongest;
}

int ArrayMedium::subarraySum(vector<int>& A, int k)
{
    // Input : N = 4, array[] = {3, 1, 2, 4}, k = 6
    // Output: 2
    // Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

    // Input: N = 3, array[] = {1,2,3}, k = 3
    // Output: 2
    // Explanation: The subarrays that sum up to 3 are [1, 2], and [3].


    //    method 3
    // 1. while traversing keep calclauting the sum till there.
    // 2. check if its same as the sum and 

        int sum =0;
        int count =0;
        unordered_map<int,int> prefixCount;
        int n= A.size();

        //base case
        prefixCount[0] =1;

        for( int i=0; i<n; i++)
        {
            // calculate sum
            sum = sum +A[i];



            //check if the rem is present in prefixSum
            int rem = sum -k;

            if( prefixCount.find(rem) != prefixCount.end())
            {
                //found
                count = count + prefixCount[rem];
            }

            // update prefixsum count
            prefixCount[sum]++;

        }

        return count;
    
}