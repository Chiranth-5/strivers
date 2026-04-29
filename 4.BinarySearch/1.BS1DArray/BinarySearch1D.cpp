#include "BinarySearch1D.h"

void BinarySearch1D::display( vector<int>A)
{   
    for( int i=0; i< A.size(); i++)
    {
        cout << A[i] <<" ";
    }
    cout <<endl;
}

int BinarySearch1D::binarySearchR(vector<int>& A, int low, int high, int target)
{
    // 1 2 3 4 5
    // t=4
    // low =0,
    // high=4

    // recusrive implementation:



    //base case
    if( low>high)
    {
        //Not found
        return -1;
    }


    int mid = (mid = low + (high - low) / 2);

    if( A[mid] == target)
    {
        return mid;
    }
    else if( A[mid] < target)
    {
        // mid less than target
        // eleminate low to mid values
        low = mid+1;
        return binarySearchR(A,low,high,target);
    }
    else
    {
        // mid value is greater than the target. Meaning right of middel can be eleminated.
        high = mid-1;
        return binarySearchR(A,low,high,target);
    }

}

int BinarySearch1D::binarySearchI(vector<int>& A, int target)
{
    // iterative implementation of binary seaarch
    
    // 1 2 3 4 5
    // t=4


    //calculate low and high
    
    int low = 0;
    int high = A.size()-1;

    while( low<=high)
    {
        //we have valid array tha need to be searched.
        
        //calculate mid
        int mid = low+(high-low) /2;

        //check the value in middle and compare it with the sorted array
        if( A[mid] == target)
        {
            // found
            return mid;
        }
        else if( A[mid]< target)
        {
            //eleminate left
            low = mid+1;
        }
        else
        {
            //elimate right
            high = mid-1;
        }

    }

    return -1;

}


int BinarySearch1D::lowerBound(vector<int> A, int n, int target)
{
    // Example 1:
    // Input Format: N = 4, arr[] = {1,2,2,3}, target = 2
    // Result: 1

    // lower bound :
    // find the smallest_value which is greater than or equal to target.
    // return the index of that smallest value.

    // search for the x using binary serarch.
    // if the middle value >= x then this may be my answer.
    // elimnate right and keep searching right.

    // search space is from low to high.
    int low =0;
    int high = n-1;
    
    // this is my default lower_bound of x till i find new one.
    int ans =n;

    while( low<=high )
    {
        
        int mid = (low +high) /2;

        if( A[mid] >= target)
        {
            // this may be my new lower bound
            ans = mid;
            // elimante right seach space
            high = mid-1;

        }
        else
        {
            // eliminate right search space
            low = mid+1;
        }


    }

    return ans;


}

int BinarySearch1D::upperBound(vector<int> A, int n, int target)
{
    // Example 1:
    // Input Format: N = 4, arr[] = {1,2,2,3}, target = 2
    // Result: 1

    // upper bound :
    // find the smallest_value which is greater than to target.
    // return the index of that smallest value.

    // search for the x using binary serarch.
    // if the middle value > x then this may be my answer.
    // elimnate right and keep searching right.

    // search space is from low to high.
    int low =0;
    int high = n-1;
    
    // this is my default lower_bound of x till I find new one.
    int ans =n;

    while( low<=high )
    {
        
        int mid = (low +high) /2;

        if( A[mid] > target)
        {
            // this may be my new upper_bound
            ans = mid;
            // elimante right seach space
            high = mid-1;

        }
        else
        {
            // eliminate right search space
            low = mid+1;
        }


    }

    return ans;

}

int BinarySearch1D::searchInsert(vector<int> A, int x)
{
    //10 20 30 40 

    // find the position of insert.
    // if the x already present then insert at that location.
    // if  x is not present then insert at the location where the A[smallest_value_index] >= x;
    // so ineed to insert at lower bound.
    
    int low =0;
    int high =A.size()-1;
    int ans;

    while( low <= high)
    {
        int mid = low+(high-low)/2;
        if( A[mid] >= x)
        {
            // update my ans
            ans = mid;
            // eliminate right . 
            high = mid-1;
        }
        else
        {
            // eliminate left
            low = mid+1;
        }
    }

    return ans;
}

int BinarySearch1D::findFloor(vector<int> A, int target)
{
    // write this
    return 0;
}
int BinarySearch1D::findCeil(vector<int> A, int target)
{
    //write this
    return 0;
}

int BinarySearch1D::solveFirstOccurance(vector<int>& A,int n, int target)
{
     //Given a sorted array of N integers, write a program to find the index of the first occurrence of the target key. 
     //If the target is not found then return -1. Note: Consider 0 based indexing

    // Input:
    // N = 7, target = 13, array[] = {3, 4, 13, 13, 13, 20, 40}  
    // Output:
    // 4  
    // Explanation:
    // The target value 13 appears for the first time at index number 2 in the array.  

    // Example 2:
    // Input:
    // N = 7, target = 60, array[] = {3, 4, 13, 13, 13, 20, 40}  
    // Output:
    // -1  

    int low =0; 
    int high=n-1;
    int firstO =-1;

    while( low<=high)
    {
        int mid = low+(high-low)/2;

        if ( A[mid] >= target)
        {
            if( A[mid] == target)
            {
                firstO = mid;
            }
            // eliminate right
            // check left side again
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }

    return firstO;


}

int BinarySearch1D::solveLastOccurance(vector<int>& A,int n, int target)
{
     //Given a sorted array of N integers, write a program to find the index of the first occurrence of the target key. 
     //If the target is not found then return -1. Note: Consider 0 based indexing

    // Input:
    // N = 7, target = 13, array[] = {3, 4, 13, 13, 13, 20, 40}  
    // Output:
    // 4  
    // Explanation:
    // The target value 13 appears for the first time at index number 2 in the array.  

    // Example 2:
    // Input:
    // N = 7, target = 60, array[] = {3, 4, 13, 13, 13, 20, 40}  
    // Output:
    // -1  

    int low =0; 
    int high=n-1;
    int lastO =-1;

    while( low<=high)
    {
        int mid = low+(high-low)/2;

        if ( A[mid] > target)
        {
            // eliminate right
            
            high = mid-1;
        }
        else
        {
            // but still check right
            if( A[mid] == target)
            {
                lastO = mid;
            }
            // elimnate left
            
            low = mid+1;
        }
    }

    return lastO;


}

vector<int> BinarySearch1D::firstAndLastPosition(vector<int>& A,int n, int target)
{
    int firstO = solveFirstOccurance( A, n, target);
    int lastO = solveLastOccurance( A, n, target);

    return {firstO,lastO};
}

int BinarySearch1D::countOfOccurence( vector<int>& A, int n, int target)
{
    int firstO = solveFirstOccurance( A, n, target);
    int lastO = solveLastOccurance( A, n, target);

    int count = lastO-firstO+1;
    
    return count;
}

int BinarySearch1D::bSRotatedArray(vector<int>& nums, int target)
{
    //  Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. 
    //  The array is rotated at some pivot point that is unknown. 
    //  Find the index at which k is present and if k is not present return -1.

    // [4, 5, 6, 7, 0, 1, 2], k = 0
    // Output :4

    // BS still works as one of the halfs is sorted.

    int n = nums.size();
    int low = 0;
    int high = n-1;

    while( low<=high)
    {
        int mid = low+(high-low)/2;

        if( nums[mid] == target)
        {
            return mid;
        }
        else if( nums[low] <= nums[mid] )
        {
            // left half is sorted.
            if( nums[mid] >=target && nums[mid]<=target) 
            {
                // elimnate right
                high = mid -1;
            }
            else
            {
                //elimnate left
                low = mid+1;
            }
        }
        else
        {
            // right half is sorted.
            if( nums[mid] < target)
            {
                // eliminate left
                low = mid +1;
            }
            else
            {
                //elimnate left
                high = mid-1;
            }
        }
    }

    return -1;


}














