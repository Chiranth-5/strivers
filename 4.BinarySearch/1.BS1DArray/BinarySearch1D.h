#include <iostream>
#include <vector>
using namespace std;


class BinarySearch1D
{
    
    public:

        void display( vector<int>A);

        int binarySearchR(vector<int>& A, int low, int high, int target);
        int binarySearchI(vector<int>& nums, int target);

        int lowerBound(vector<int> A, int n, int x);
        int upperBound(vector<int> A, int n, int x);

        int searchInsert(vector<int> A, int x) ;
        int findFloor(vector<int> A, int target);
        int findCeil(vector<int> A, int target);

        int solveFirstOccurance(vector<int>& A,int n, int target);
        int solveLastOccurance(vector<int>& A,int n, int target);

        vector<int> firstAndLastPosition(vector<int>& A,int n, int target);
        int countOfOccurence( vector<int>& arr, int n, int x);


        int bSRotatedArray(vector<int>& nums, int target);


        bool searchInARotatedSortedArrayII(vector<int>& arr, int k);
        int findMin(vector<int>& nums);
        int findRotations(vector<int>& arr);
        int singleNonDuplicate(vector<int>& arr);

        int findPeakElement(vector<int>& nums);

};