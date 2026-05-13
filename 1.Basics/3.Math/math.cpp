#include "math.h"

int Math::countDigits( int n)
{
    // n =5
    // return 1
    // n = 10 
    // return 2

    int count=0;
    while( n>0)
    {
        count ++;
        
        //moves by 10 numbers . need to track digits
        n =n/10;
    }

    return count;

}

//2. reverse a number
int Math::revNumber( int n)
{
    //reverse a number
    int rev=0;

    while( n>0)
    {
        int d = n%10;
        rev = rev*10 + d;

        n = n/10;
    }

    return rev;

}

//3. Palindrome
bool Math::palindrome( int n)
{
    // n = 121
    // return 1

    // of rev and the value are same

    int rev = revNumber(n);

    if ( n== rev)
    {
        return true;
    }
    else
    {
        return false;
    }
    

}

//4. Check if number is armstrong
bool Math::amrStrongNumber( int n )
{   
    // n 371
    // 9 + 49 +1

    // access each digit.

    int initValue=n;
    int sum=0;
    while ( n>0)
    {
        int d = n%10;

        //sum square of each digit
        sum+= d*d*d;

        n=n/10;
    }

    if( sum == initValue)
    {
        return true;
    }

    return false;

}

//5. Print all divisors
void Math::printDivisors( int n)
{


    //n=5
    //1,5 are the divisors of 5

    // n = 8 
    // 1,2,4,8 are the divisors

    //check all the numbers from 1 to n which are divisable frfom 8.
    
    //but if 1 is divisable then 8 is also diviabale 
    //similarly 2 and 4

    //6*6 = 36

    //so always check till the sure root of n and take both values as diviable.

    vector<int> divisor;
    
    for( int i=1; i*i<=n; i++)
    {
        if( (n%i ==0))
        {
            divisor.push_back(i);
            divisor.push_back(n/i);
        }
    }

    sort( divisor.begin(), divisor.end());


    for ( int i=0; i<divisor.size(); i++)
    {
        cout << divisor[i] << " ";
    }

}

//6. Check prime numbers
bool Math::primeNumber( int n)
{
    
    // prime numbers are all the numbers that are divisiable by 1 and n
    // divisor is are just 1 and n.

    int count=0;
    for(int i=1; i*i <= n; i++)
    {
        if( n%i ==0)
        {
            count ++;
        }
    }

    if( count ==1)
    {
        return true;
    }
    return false;

}

//7. GCD of two numbers
int Math::highestCommonFactor( int n, int m)
{




    // n=6, m=4
    // n = 1, 2, 3, 6
    // m = 1, 2, 4
    // highest common factor is 2.

    // n=28, m=44
    // n = 1, 2, 4, 7, 14, 28
    // m = 1, 2, 4, 11, 22, 44
    // highest common factor is 4


    // n=5, m=16
    // n = 1, 5
    // m = 1, 2, 4, 8, 16
    // highest common factor is 4

    // algo
    // find common divior of the both.
    // while doing that keep track of the largest one.
    // now we dont check till the bigger number we can just check till the smallest number.

    int gcd=1;
    for( int i=1; i*i <= min( n, m); i++)
    {
        if( n%i == 0 && m%i == 0)
        {
            gcd = n/i; // gretest will n/i as we are going till sqaureroot of n.
        }
    }

    return gcd;
}
