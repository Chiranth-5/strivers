#include "BinarySearch1D.h"
using namespace std;


int main()
{
    BinarySearch1D obj;

    // vector<int> A = {10,20,30,40,50,60};
    // cout << "Target is 40 and Vector A is: "<< endl;
    // obj.display(A);
    // cout <<endl;
    // int midValue = obj.binarySearchR(A,0,5,40);
    // cout << "The index of the target value is : " << midValue <<  endl;

    // vector<int> A = {10,20,30,40,50,60};
    // cout << "Target is 40 and Vector A is: "<< endl;
    // obj.display(A);
    // cout <<endl;
    // int midValue = obj.binarySearchI(A,10);
    // cout << "The index of the target value is : " << midValue <<  endl;

    // vector<int> A = {10,30,30,30,50,60};
    // cout << "Target is 30 and Vector A is: "<< endl;
    // obj.display(A);
    // cout <<endl;
    // int lowerBound = obj.lowerBound(A,6,30);
    // cout << "The lower bond index of the target is : " << lowerBound <<  endl;


    // cout << "Target is 30 and Vector A is: "<< endl;
    // obj.display(A);
    // cout <<endl;
    // int upperBound = obj.upperBound(A,6,30);
    // cout << "The upper bond of the target is : " << upperBound <<  endl;

    // vector<int> A = {10,30,30,30,50,60};
    // cout << "Target is 30 and Vector A is: "<< endl;
    // obj.display(A);
    // cout <<endl;
    // int searchInsert = obj.searchInsert(A,30);
    // cout << "The lower bond of the target is : " << searchInsert <<  endl;

    vector<int> A = {10,30,30,30,50,60};
    cout << "Target is 30 and Vector A is: "<< endl;
    obj.display(A);
    cout <<endl;
    int firstOccurance = obj.solveFirstOccurance(A,6,30);
    cout << "The lower bond index of the target is : " << firstOccurance <<  endl;





}