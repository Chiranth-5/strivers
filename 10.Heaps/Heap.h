#include <iostream>
#include <vector>
using namespace std;


class Heap
{
    private:
        vector<int> A;

    public :
        void initializeHeap();

        void insert(int key);

        void changeKey(int index, int new_val);

        void extractMin();

        bool isEmpty();

        int getMin();

        int heapSize();


        void heapifyDown(int index);



        //2. Check array represents a minheap
            // apply heapify to every value in the given array

        //3. Convert minheap to maxheap
            // treat min heap as normal array
            // use helpify to convert every element from last index having children to root index.

        //4. kth largest element in the array
        int kthLargestElementInTheArray ( vector<int> vec, int k);
            // 1.use min heap
            // 2. Use quick slect algo.
        //5. kth smallest element in the array
            // same as 4
        
        //6. sort k sorted array
            //. use min heap fo size k
    
        //7. merge k sorted lists
            // push all the heads of the list to minheap. 
            // then pop each and attach it to the dummy.
            // later push the next of the head which was popped into the mminheap
        
        //8.Replace elements vai its rank.
        vector<int> replaceWithRank(vector<int>& arr) ;


};