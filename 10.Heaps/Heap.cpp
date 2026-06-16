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