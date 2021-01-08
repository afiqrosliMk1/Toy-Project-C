#include <stdio.h>

int multiple ( int num1 , int num2 );

int main( void )
{
    int a , b;

    while ( a != EOF ){
        printf( "Enter 2 values to know if the second one is a multiple of the first (-1 to end) :" );
        scanf( "%d%d" , &a , &b );

        switch ( multiple( a , b ) ){
            case 1:
                printf( "Yes. %d is a multiple of %d\n" , a , b );
                break;
            case 0:
                printf( "No. %d is not a multiple of %d" , a , b );
        }//end switch
    }//end while

    return 0;
}

int multiple ( int num1 , int num2 )
{
    if ( num2 % num1 == 0 ){
        return 1;
    }else{
        return 0;
    }
}
