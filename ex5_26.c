#include <stdio.h>
void perfectNumber( int number );

int main( void )
{
    int num = 1;

    for ( ; num <= 10000; num++ ){
        perfectNumber( num );
    }

    return 0;
}

void perfectNumber( int number )
{
    int perfect , sum = 0;
    for ( int i = 1; i <= number; i++ ){
        if ( number % i == 0 && i != number ){
            sum += i;
        }
    }//end for
    if ( sum == number ){
        perfect = sum;
        printf( "%d\n" , perfect );
        printf( "factors: \n" );
        for ( int i = 1; i <= perfect; i++ ){
            if ( perfect % i == 0 ){
                printf( "%d " , i );
            }//end if
        }//end for
        printf( "\n" );
    }//end if
}//end function perfectNumber
