#include "Heap.h"
using namespace std;


int main()
{
    Heap obj;

    vector<int> nums = {20 ,15 ,26 ,2 ,98 ,6 };
   
    // int ans = obj.kthLargestElementInTheArray(nums,k);

    // cout << ans <<endl;

    vector<int> arr = {20 ,15 ,26 ,2 ,98 ,6 };
    // // Input: 20 15 26 2 98 6
    // // Output: 4 3 5 1 6 2

    vector<int> arr2 = {1 ,5 ,8 ,15 ,8 ,25 ,9};
    //                  1  2  3  5  3  6  4
    //                  1  2  0  6  4  7  5

   
    vector<int> ans = obj. replaceWithRank(arr2) ;
    
    for ( auto num : ans)
    {
        cout << num << " ";
    }



 


}