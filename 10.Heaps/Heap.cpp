
#include "Heap.h"

void Heap::initializeHeap()
{
    A.push_back(-1);
}

void Heap::insert(int key)
{
    A.push_back(key);

    // now arrage the vector tofollow heap rules

    int n = A.size();

    int temp = A[n-1];
    int i = A.size()-1;
    while( i>0 &&  temp < A[i/2])
    {
        // parent is smaller than child

        // move parent to child place
        A[i] = A[i/2];
        i = i/2;
    }
    
    A[i] = temp;

}

// Helper function to restore the heap property downwards
void Heap::heapifyDown(size_t index) 
{
    size_t size = A.size() - 1; // Effective size of the 1-indexed heap
    size_t smallest = index;
    size_t left = 2 * index;
    size_t right = 2 * index + 1;

    // Check if left child exists and is smaller than the current smallest
    if (left <= size && A[left] < A[smallest]) 
    {
        smallest = left;
    }

    // Check if right child exists and is smaller than the current smallest
    if (right <= size && A[right] < A[smallest]) 
    {
        smallest = right;
    }

    // If the smallest is not the current node, swap and recurse
    if (smallest != index) 
    {
        std::swap(A[index], A[smallest]);
        heapifyDown(smallest);
    }
}

void Heap::extractMin()
{
    // remove the min value from the top 
    if ( A.size() <=1)
    {
        cout << "No minimum value" <<endl;
        return;
    }

    if(A.size() <=2 )
    {
        A.pop_back();
        return;
    }

    
    A[1] = A[A.size()-1];
    A.pop_back();



    // 3. Restore the heap property by pushing the new root down
    if (A.size() > 1) 
    {
        heapifyDown(1);
    }




}