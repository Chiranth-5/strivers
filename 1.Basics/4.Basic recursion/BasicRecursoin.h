#include <iostream>
using namespace std;

class BasicRecursion
{
    private:
        

    public:

        //revision ( start decending order):
        
        
        
        string ansRev="";
        
        int BS( int A[], int i , int j , int x);

        
        // Print name N times using recursion
        void recursionPrintName( string name , int count , int n);

        //forward recursion
        void oneToNForward(int count, int n);

        //backward recursion
        void backwardRecursion(string name, int count , int n);
        void NToOneBackward( int count, int n);

        // sum of firsnt n numbers using forward redursion
        int sumOffirstNNumbers(int n);

        // Factorial of a given number
        int factorialOfGivenNumber( int n);


        //reverse an array
        bool revAnArray( int count , int n , string rev);


        // Fibonacci Number
        int fibonacciNumber( int count,int n);

        // Fibonacci Number-2
        int fibonacciNumber2(int n);
};

