#include "Heap.h"
#include <iostream>  // Added for std::cout

void Heap::initializeHeap()
{
    A.clear(); // Ensure it's empty before initializing
    A.push_back(-1); // Dummy value for 1-indexing
}

void Heap::insert(int key)
{
    A.push_back(key);

    int i = A.size() - 1;
    int temp = A[i];
    
    //  i > 1 to prevent comparing against the dummy element at index 0
    while (i > 1 && temp < A[i / 2])
    {
        A[i] = A[i / 2]; // Move parent down
        i = i / 2;       // Move index up
    }
    
    A[i] = temp;
}

void Heap::heapifyDown(int index) 
{
    int size = A.size() - 1; 
    int smallest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= size && A[left] < A[smallest]) 
    {
        smallest = left;
    }

    if (right <= size && A[right] < A[smallest]) 
    {
        smallest = right;
    }

    if (smallest != index) 
    {
        std::swap(A[index], A[smallest]);
        heapifyDown(smallest); // Recursive call
    }
}

void Heap::extractMin()
{
    // Case 1: Heap is empty (only contains dummy element)
    if (A.size() <= 1)
    {
        std::cout << "No minimum value" << std::endl;
        return;
    }

    // Case 2: Heap has exactly one valid element
    if (A.size() == 2)
    {
        A.pop_back();
        return;
    }

    // Case 3: Heap has multiple elements
    A[1] = A[A.size() - 1]; // Move last element to root
    A.pop_back();           // Remove last element

    heapifyDown(1);         // Restabilize from the root down
}


void Heap::changeKey(int index, int new_val)
{
    //given 0 beased index
    
    // index = 2;
    // new_val =4;

    index = index+1;

    if( index < A.size())
    {
        A[index] = new_val;
        heapifyDown(index);
    }

    return;

}

bool Heap::isEmpty()
{
    if (A.size() <=1) return true;

    return false;
}

int Heap::getMin()
{
    // top value is the minimum in min heap

    if( A.size()>1)
    {
        return A[1];
    }
    else return -1;
}

int Heap::heapSize()
{
    return A.size() -1;
}


int Heap::kthLargestElementInTheArray ( vector<int> nums, int k)
{

    // nums = [1, 2, 3, 4, 5], k = 2 

    // 1. Use min heap data structure.
    // 2. check if each elment is greater than top value of the element  and add it.
    // 3. maintian this at


    priority_queue< int, vector<int>, greater<int> > pq;

    for ( int i = 0; i<nums.size(); i++)
    {
        if ( pq.size() < k)
        {
            // we can just insert the value to the pq.
            pq.push( nums[i] );
        }
        else
        {
            // we reached max size of the priority que  ie k. 
            // check if the top element is smaller than the current nums value. if it is then replace it.
            // else move on.

            if(pq.top() < nums[i])
            {
                pq.pop();
                pq.push( nums[i]);
            }

            //else ignore nums[i]

        }
    }

    return pq.top();


}

vector<int> Heap::replaceWithRank(vector<int>& arr) 
{
    // Input: 20 15 26 2 98 6
    // Output: 4 3 5 1 6 2
    // Explanation: When sorted,the array is 2,6,15,20,26,98. So the rank of 2 is 1,rank of 6 is 2,rank of 15 is 3 and so.

    // Input: 1 5 8 15 8 25 9
    // Output: 1 2 3 5 3 6 4
    // Explanation :When sorted,the array is 1,5,8,8,9,15,25. So the rank of 1 is 1,rank of 5 is 2,rank of 8 is 3 and so


    // repeats wojnt work in this case

    //vector to store the solution;
    vector<int> sol(arr.size());
    // hashmap to store the vector and its index value;

    unordered_map<int,int> valueIndex;

    for ( int i =0; i<arr.size(); i++ )
    {
        valueIndex[ arr[i]] = i;
    }

    // priority queue to heapify the current array
    priority_queue<int ,vector<int> , greater<int> > pqMinHeap( arr.begin(), arr.end());

    int rank =1;
    while( !pqMinHeap.empty() )
    {
        sol[ valueIndex[ pqMinHeap.top() ] ] = rank;
        rank++;
        pqMinHeap.pop();
    }

    return sol;

    
    // TC : n + n + n
    // sc = n




}