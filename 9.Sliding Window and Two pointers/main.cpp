#include "SlidingWindowAndTwoPointers.h"
using namespace std;


int main()
{
    SlidingWindowAndTwoPointers obj;

    vector<char> Fruits = {'M','A','M'};
    vector<char> Fruits2 = { 'M', 'A', 'C', 'A', 'A'};
   
    int ans = obj.totalFruit(Fruits2);

    cout << ans <<endl;


}