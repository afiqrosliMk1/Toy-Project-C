//this program calculate greatest common divisor using Euclid's Algorithm
//this program uses iterative approach. for recursive approach, see ex5_39.c (more compact)
#include <stdio.h>
int gcdEuclid( int big , int small );

int main( void )
{
    //int number1 = 3768 , number2 = 1701 ,
    int gcd;

    gcd = gcdEuclid( 4441 , 8888 );
    printf( "gcd: %d\n" , gcd );

    return 0;
}

int gcdEuclid( int big , int small )
{
    int intermediate;
    if ( small > big ){ //swap value if needed
        intermediate = big;
        big = small;
        small = intermediate;
    }
    int quotient = big / small;
    int remainder = big % small;

    printf( "%d = %d(%d) + %d\n" , big , small , quotient , remainder );

    while ( remainder > 0 ){
        intermediate = small;
        small = remainder;
        big = intermediate;
        quotient = big / small;
        remainder = big % small;
        printf( "%d = %d(%d) + %d\n" , big , small , quotient , remainder );
    }

    return small; // small is equal to remainder in the iteration before
}
