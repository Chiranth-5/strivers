#include "Sort.h"

void Sort::display( vector<int>A)
{   
    for( int i=0; i< A.size(); i++)
    {
        cout << A[i] <<" ";
    }
}

void Sort::swap( int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


void Sort::selectionSort(vector<int> A)
{
    // 4 3 2 6 1

    // 4 3 2 6 1
    // i
    // 1 3 2 6 4
    // 1 2 3 6 4
    
    // 2 arrays.
    // select the minimum_index value for that position.
    // swap at once.
    int n= A.size();

    for (int i=0; i<n; i++)
    {
        //for each position select the least from the remaning
        //if ita already mininmu then dont change
        int min = i;


        for ( int j = i+1; j<n; j++)
        {
            // check if its less than the current value 
            if( A[j] < A[i])
            {
                min = j;
            }
        }

        swap( A[i], A[min]);


    }


    cout << "Values after selection sort " ;
    display(A);
    cout << endl << endl;
}

void Sort::bubbleSort( vector<int> A)
{
    // 4 3 2 6 1

    // compare 2 values and push the max to right.
    // do the above activity for A.size() we will get the sorted array.

    // if there is no values swaped in the inner loop then we can say the array is sorted and stop.


    for( int i=0; i<A.size(); i++)
    {

        int flag =0;
        // this loops compares the values with 1 less value and swaps.
        for ( int j=0; j<A.size()-1; j++)
        {
            
            if (A[j+1] < A[j] )
            {
                swap( A[j], A[j+1]);
                flag ++;
            }

        }

        if( flag!=0)
            break;
    }
    


    cout << "Values after  bubble sort " ;
    display(A);
    cout << endl << endl;
}
 
void Sort::insertionSort(vector<int> A)
{
    // 2 arrays
    // sorted array
    // value
    
    // insert the value to its correct postion in sorted arrray.

    for( int i=0; i<A.size(); i++)
    {

        int  key = A[i];

        int j=i-1;

        // loop makes space for key to be inserted by moving values to the end.
        for( ; j>=0 && A[j]>key; j--)
        {
            A[j+1] = A[j];
        }

        // add the values 
        A[j+1] = key;
    }


    cout << "Values after  insertion sort " ;
    display(A);
    cout << endl << endl;
}


void Sort::merge(vector<int>& A, int start, int mid, int secondStart, int end)
{
    // 1 2 3 4 5 6 7 8
    // 0 1 2 3 4 5 6 7
    // s     m ss    e

    // comparing the values from the left  array and right array merge it together


    vector<int> B(A.size());
    int i = start;       // Pointer for left half
    int j = secondStart; // Pointer for right half
    int k = start;       // Start filling B at the 'start' index

    while(i <= mid && j <= end)
    {
        if(A[i] <= A[j]) // Use <= for stability
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    // Copy remaining elements of left half
    while(i <= mid)
    {
        B[k++] = A[i++];
    }

    // Copy remaining elements of right half
    while(j <= end)
    {
        B[k++] = A[j++];
    }

    // Copy ONLY the merged part back to A
    for (int index = start; index <= end; index++)
    {
        A[index] = B[index];
    }
}

void Sort::mergeSort( vector<int>& A, int start, int end)
{
    //1. call mergeSort on first half
    //2. call mergeSort on second half
    //3. merge both sorted halfs using merge fucntion.
   
    if( start < end)
    {
        int mid =(start+end)/2;
        
        // Call mergeSorton left half
        mergeSort( A, start, mid);

        // Call mergeSorton right half
        mergeSort( A, mid+1, end);

        // once both the sort is ready. merge this merge logic
        merge( A, start, mid, mid+1, end);
    }

}


void Sort::recursiveBubbleSort(vector<int>A, int numberOfremaningCalls)
{
    // base case
    if (numberOfremaningCalls<0)
    {
        // array already sorted
        return; 
    }

    // write inner loop lofic here.

    numberOfremaningCalls--;

}

void Sort::recursiveInsertionSort(vector<int>A, int numberOfremaningCalls)
{
    // base case
    if (numberOfremaningCalls<0)
    {
        // array already sorted
        return; 
    }

    // write inner loop logic here.

    numberOfremaningCalls--;

}


int Sort::partitioning(vector<int>& A, int low, int high) 
{

    // pivot element must be placed in correct postion.
    // we can consider any value as pivot .Here we will consider first value as pivot.
    int pivot = A[low];

    // while finding the pivot postion swap values greater than pivot in the left with values less than the pivot on the right.

    // 4 3 5 2 6 8 1
    // 0 1 2 3 4 5 6
    // i           j



    // compare pivot with left and right and stop at the index when the condition is false
    


    int pivot = A[low];
    int i=low;
    int j=high;


    // find posistion of pivot element.
    while( i<j )
    {
        while( i<= high && A[i]<= pivot) // 4 3 5 2 6 8 1
        {
            // move i as long as A[i]<= pivot
            i++;
        }

        while( j>= low && A[j]>pivot ) // 10 1 2 3 . 
        {

            // move j( no need to swap)
            j--;

        }

        // wrong side of the partition so need to swap
        if( i<j) // if i is passed then the j value has to be swaped with the low value.
        {
            swap( A[i],A[j]);
        }

    }

    // swap this with j. As i has crossed the pivot position value.
    swap( pivot, A[j]);

    // correct posistion of the pivot.
    return j;

}


void Sort::quickSort(vector<int>& A, int low, int high) 
{
    // more than 1 element then it needs to be sorted on both the side
    if(low<high)
    {
        // need to find the partition position. after placing the low value at the partition position.
        int partition = partitioning( A, low, high);

        // sort the left side of the partition and the right side of the partition
        quickSort(A, low, partition-1);
        quickSort(A, partition+1, high );

    }

}


