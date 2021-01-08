#include <stdio.h>
int even( int num );
int main( void )
{
    int n = 0;

    while ( n != EOF ){
        printf( "Enter an integer to know if it is even: " );
        scanf( "%d" , &n );
        switch ( even( n ) ){
            case 1:
                printf( "EVEN\n" );
                break;
            case 0:
                printf( "ODD\n" );
                break;
        }//end switch
    }//end while

    return 0;
}

int even( int num )
{
    if ( num % 2 == 0 ){
        return 1;
    }else{
        return 0;
    }
}
