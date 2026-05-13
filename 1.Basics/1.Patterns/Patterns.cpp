#include "Patterns.h"
using namespace std;
// Patterns



void Patterns::pattern1(int n)
{   
    //1 .
    // * * * *
    // * * * *
    // * * * *
    // * * * *

    for (int i=0; i<n ; i++)
    {
        cout << "* * * *" << endl;
    }
}

void Patterns::pattern2(int n)
{
    //*
    //* *
    //* * * 
    //* * * *
    for ( int i=1; i<=n; i++)
    {
        
        for (int j=1; j<=i; j++)
        {
            cout << "* ";
        }
        cout<<endl;

    }
}

void Patterns::pattern3(int n)
{
    //1
    //1 2
    //1 2 3 
    //1 2 3 4 

    for(int i=1; i<=n; i++)
    {
        for( int j = 1; j<=i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void Patterns::pattern4( int n )
{
    //n =3

    //1
    //2 2
    //3 3 3

    //for loop to reach each row

    for( int i=1; i<=n; i++)
    {
        //1st row 1 item print
        // 2nd 2 item print

        for( int j=1; j<=i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }

}

void Patterns::pattern5( int n)
{
    //* * *
    //* *
    //*

    for ( int i=n; i>0 ; i--)
    {
        for ( int j=i; j>0 ; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void Patterns::pattern6( int n)
{
    //1 2 3
    //1 2 
    //1


}

void Patterns::pattern7MyUnderstanding( int n)
{
    //*
    //* * *
    //* * * * *
    //* * * * * * *



    // 1 1
    // 2 3
    // 3 5
    
    // n 2n-1

    //*
    //* * *

    //rows
    for( int i=1; i<=n; i++)
    {
        // 
        for( int j=1; j<= (2*i) -1 ; j++)
        {
            cout << "* " ;
        }
        // ending each row
        cout << endl;
    }


    
    
}

void Patterns::pattern7( int n)
{
    //n=3
    //    *        [2, 1, 2]
    //  * * *       [1, 3, 1]
    //* * * * *     [0, 5, 0]

                    //  n-i   2i-1  n-i

    //n=2
    //  *         [1, 1, 1]
    //* * *       [0, 3, 0]

    for( int i=0; i<=n ;i++)
    {


        // space
        for( int j=1; j<= n-i; j++)
        {
            cout << " " ;
        }

        // star
        for( int j=1; j<=(2*i)-1; j++)
        {
            cout << "* ";
        }

        // //space
        // for (int j=1; j<= n-i; j++)
        // {
        //     cout << " ";
        // }

        // ends the row
        cout << endl;
    }

    


    
}

void Patterns::pattern8( int n)
{
    //* * * * *     [0, 5, 0]
    //  * * *       [1, 3, 1]
    //    *         [2, 1, 0]

    //space = i-1
    //star = 2*(n - (i-1)) -1

    // n number of rows.   i  .
    // 1 , 3 , 5, 7, 9:  
    

    for ( int i=1; i<=n; i++)
    {
        //space
        for ( int j=1; j<= i-1; j++)
        {
            cout << "  ";
        }
        //star
        for ( int j=1; j<= (2*(n-(i-1)) -1); j++)
        {
            cout << "* ";
        }
        //space
        for ( int j=1; j<= i-1; j++)
        {
            cout << "  ";
        }

        cout << endl;
    }

}

void Patterns::pattern9( int n)
{
    // 3
    //    *         [2, 1, 2]
    //  * * *       [1, 3, 1]
    //* * * * *     [0, 5, 0]
    //* * * * *     [0, 5, 0]
    //  * * *       [1, 3, 1]
    //    *         [2, 1, 0]



    
    //asscending
    //    *         [2, 1, 2]
    //  * * *       [1, 3, 1]
    //* * * * *     [0, 5, 0]

    

    for ( int i=1; i<=n; i++)
    {
        //space = n-i
        for ( int j=1; j<=n-i; j++)
        {
            cout << "  ";
        }

        //star = 2i-1
        for ( int j=1; j<= 2*i-1; j++)
        {
            cout << "* ";
        }

        //space = n-i
        for ( int j=1; j<n-i; j++)
        {
            cout << " ";
        }

        cout << endl;
    }


    //* * * * *     [0, 5, 0]
    //  * * *       [1, 3, 1]
    //    *         [2, 1, 0]

    
    
    for ( int i=1; i<=n; i++)
    {
        //space = i-1
        for ( int j=1; j<= i-1; j++)
        {
            cout << "  ";
        }
        //star = 2*(n - (i-1)) -1
        for ( int j=1; j<= (2*(n-(i-1)) -1); j++)
        {
            cout << "* ";
        }
        //space
        for ( int j=1; j<= i-1; j++)
        {
            cout << "  ";
        }

        cout << endl;
    }

}

void Patterns::pattern10( int n)
{
    //*
    //* * 
    //* * * 
    //* * 
    //* 

    // n =3
    // i , star , space
    //[1, 1, 2]
    //[2, 2, 1]
    //[3, 3, 0]

    //[2, 2, 1]
    //[1, 1, 2]

    

    // 2 halfs 
    //[1, 1, 2]
    //[2, 2, 1]
    //[3, 3, 0]
    //[i, i, n-i ]

    //[2, 2, 1]
    //[1, 1, 2]
    //[n-i, n-i, i]

    // second half star decreases.
    // so we cannot map the number of stars printed to i directly.

    int star = 1;
    for ( int i=1; i<=n ; i++)
    {
        // star
        for( int j=1; j<= star; j++)
        {
            cout << "* ";
        }

        //end of line
        if ( star <=n)
        {
            star++;
        }
        else
        {
            star--;
        }
        cout << endl;
    }




    
    
}

void Patterns::pattern11( int n)
{
    //n=3
    //          [i, 1, 0 ]
    //1         [1, 1,  ]
    //1 1       [2, 2,  ]
    //1 1 1     [3, 3,  ]

    for( int i=1; i<=n; i++)
    {

        //print 1
        //if i is even it starts from 0
        //if i is odd it starts from 1
        int start =  ( i%2 == 0) ? start = 0 : start = 1 ;

        // j runs i times.
        for ( int j=1; j<=i ;j++)
        {
            cout << start << " ";
            start = 1-start;
        }
        cout << endl;
    }
}

void Patterns::pattern12(int n)
{
    // 1             1
    // 1 2         2 1
    // 1 2 3     3 2 1
    // 1 2 3 4 4 3 2 1

    // outer loop runs as many rows are present
    for ( int i=1; i<=n; i++)
    {
        // each row prints number, space , number
        
        // i=3, row, i=3 ,numbers printed will be three
        for ( int j=1; j<=i ; j++)
        {
            cout << j << " ";
        }
        
        // i =1. space = 4  2(n-i)
        // i =2, space = 2
        // i =3, space = 0  2(n-i)
        for ( int j=1; j<= 2*(n-i)  ; j++)
        { 
            cout << "  " ;
        }


        for ( int j=1; j<=i ; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }

}

void Patterns::pattern13( int n)
{
    // n =4;

    // 1 
    // 2 3 
    // 4 5 6
    // 7 8 9 10

    int number=1;

    //outer loop prints 4 row
    for ( int i=1; i<=n ;i++)
    {
        //number of prints in each row are  1 , 2,3 ,4 ,n
        
        for( int j=i; j<=i; j++)
        {
            cout << number << " " << endl;
            number++;
        }

    }

}

void Patterns::pattern14( int n)
{
    // A 
    // A B  
    // A B C
    // A B C D

    // outer loop runs n times
    for ( int i=1; i<=n; i++)
    {
        // i=1 , A(1)
        // i=2 , A B(2) 
        // i=3 , A B C(3) = i
        
        string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int start=0;
        for ( int j=1; j<=i ; j++)
        {
            cout << s[start] << " ";
            start++;
        }

        // end of the line
        cout << endl;
    }

}

void Patterns::pattern15( int n)
{
    // A B C 
    // A B  
    // A 

    //outer loop runs n times
    for ( int i=1; i<=n; i++)
    {
        // n=3
        // i=1, 3, A B C
        //   2, 2, A B
        //   3, 1, A

        string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int start=0;
        
        // loop runs till n-i+1
        for ( int j=1; j<=n-i+1; j++)
        {
            cout << s[start] << " ";
            start++;
        }

        // end of each line
        cout << endl;

    }
    
}

void Patterns::pattern16( int n)
{
    // A 
    // B B  
    // C C C

    int start=0;
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // outer loop runs n times
    for ( int i=1; i<=n; i++)
    {
        // i=1, 1, A
        // i=2, 2, B B
        // i=3, 3, C C C 


        //inner loop runs i time
        for ( int j=1; j<=i; j++)
        {
            cout << s[start] << " ";
        }
        // move to next charachter
        start++;

        // End of line
        cout << endl;
    }
    
}

void Patterns::pattern17( int n)
{
    //     A 
    //   A B A 
    // A B C B A

    //string
    int start=0;
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // outer loop runs n times
    for ( int i=1; i<=n; i++)
    {
        //n=3
        // i, space, charachter , space
        // 1, 2, 1, 2
        // 2, 1, 3, 1
        // 3, 0, 5, 0
         
        //space n-i
        for ( int j=1; j<= n-i; j++)
        {
            cout << "  ";
        }

        start = 0;
        //charachter 2i-1
        for ( int j=1; j<=2*i-1; j++)
        {
            cout << s[start] << " ";

            // A B A
            // i=1, A.      1
            // i=2, A B A , 1,2,1
            // i=3,         1,2,3,2,1
            //need to flip
            if( j<= i-1)
            {
                start++;
            }
            else
            {
                start--;
            }
            
        }

        //space n-i
        for ( int j=1; j<= n-i; j++)
        {
            cout << "  ";
        }

        //end of line
        cout << endl;

    }

}

void Patterns::pattern18( int n)
{
    // C 
    // B C 
    // A B C

    //outer loop runs n times.

    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";



    // number of lines
    for ( int i=1; i<=n; i++)
    {
        //staring letter for each line
        int letterStart = n-i;

        // each print in the line
        for (int j=1; j<=i ; j++)
        {
            cout << s[letterStart] << " ";
            letterStart++;
        }
        //endline
        cout << endl;
    }

}

void Patterns::pattern19( int n)
{
    //* * * * * *
    //* *     * *
    //*         *
    //* *     * *
    //* * * * * *

    //outer loop prints number of rows ie 2n
    for ( int i=1; i<=2*n ; i++)
    {
        //each line prints star , space , space , star.
        // i, star, space , space ,star
        // 1, 3, 0, 0, 3
        // 2, 2, 1, 1, 2
        // 3, 1, 2, 2, 1
        // 4, 
        // 5,
        // 6,
        // i,n-i+1, i-1, i-1, n-i+1

        int newR = i;
        if( newR > n)
        {
          newR = (2*n-i+1);  
        }

        //star
        for ( int j=1; j<= n-newR+1 ; j++)
        {
            cout << "* ";
        }

        //space
        for ( int j=1; j<= newR-1 ; j++)
        {
            cout << "  ";
        }

        //space
        for ( int j=1; j<= newR-1 ; j++)
        {
            cout << "  ";
        }

        //star
        for ( int j=1; j<= n-newR+1 ; j++)
        {
            cout << "* ";
        }

        //end of line
        cout << endl;
    }
}

void Patterns::pattern20( int n)
{

    //*         *
    //* *     * *
    //* * * * * *
    //* *     * *
    //*         *

    int star = 1;           // initial value, moves by 1
    int space = 2*(n-1);    // initial value, moves by 2
    int rows = (2*n) -1 ; 

    //outer loop prints number of rows 
    for ( int i=1; i<= rows ; i++)
    {
        //each line prints star , space , star.
        // i, star, space , space ,star
        // 1, 1, 4, 1
        // 2, 2, 2, 2
        // 3, 3, 0, 3
        // 4, 
        // 5,
        // 6,
        // i, i , 2(n-i), i

        // second haf cannot be mapped to i. so star and space follows its own pattern.
        // because i always increases.
        // the number of stars decreases by 1 and number of space increases by 2.


        // star
        for ( int j =1; j<=star; j++)
        {
            cout << "* ";
        }

        //space 
        for ( int j =1; j<=space; j++)
        {
            cout << "  "; 
        }

        // star
        for ( int j =1; j<=star; j++)
        {
            cout << "* ";
        }

        if( i<n)
        {
            star++;
            space = space -2;
        }
        else
        {
            star--;
            space = space +2;
        }

        cout << endl;


    }
}

void Patterns::pattern21( int n)
{


    //* * * * 
    //*     *
    //*     *
    //* * * *

    // outer loop runs n number of times.

    for( int i=1; i<=n; i++)
    {
        if( i == 1 || i == n)
        {
            // print n stars
            for ( int j=1 ; i<=n ; j++)
            {
                cout << "* " ;
            }
        }
        else
        {
            // print star
            cout << "* ";

            // print space
            int space = n-2;
            for( int j =1; j<= space ; j++)
            {
                cout << "  "; 
            }

            // print star
            cout << "* " <<endl;

        }

        cout <<endl;


    }

}

void Patterns::pattern22( int n)
{


    // 4       4 4 4 4 4    4 
    // 4 3       3 3 3    3 4
    // 4 3 2       2    2 3 4
    // 4 3 2 1          2 3 4
    // 4 3 2 2 2 3 4
    // 4 3 3 3 3 3 4
    // 4 4 4 4 4 4 4 


    // 4           4
    // 4 3       3 4
    // 4 3 2   2 3 4

    // 4 3 2 1 2 3 4

    // 4 3 2
    // 4 3
    // 4


    // starr
    int star = 1; //+1

    // space 
    int space = 2*(n-1) - 1; // -2

    

    for( int i=1; i<=(2*n)-1; i++)
    {

        if( i == n)
        {
            // 4321 234
            for ( int j=1; j<= n; j++)
            {
                cout << n-j+1 << " ";
            }

            // 4321 234
            for ( int j=1; j<= n-1; j++)
            {
                cout << j+1 << " ";
            }

            //fliped start increasing the value
            star--;
            space = space+2;

            cout << endl;
        }

        else
        {
            int valueBegin =n;
            for ( int j=1; j<=star; j++)
            {
                
                cout << valueBegin << " ";
                valueBegin--;
            }

            valueBegin = n-star+1;
            for ( int j=1 ; j<=space ; j++)
            {
                cout << valueBegin << " ";
            }

            valueBegin = n-star+1;
            for ( int j=1; j<=star; j++)
            {
                // number printed  ascending
                cout << valueBegin << " ";
                valueBegin++;
            }

            

            if( i<n)
            {
                star++;
                space = space -2;
            }
            else
            {
                star--;
                space = space+2;
            }

            cout <<endl;
        }
        
        
        
    

    }
    

        
    
    

}


