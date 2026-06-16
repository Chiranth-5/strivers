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
};