#include <stdio.h>
int primeNumber( int );

int main( void )
{
    int val , number , i = 1;
    //printf( "Insert a number: " );
    //scanf( "%d" , &number );
    for ( number = 1; number <= 10000; number++ ){
        val = primeNumber( number );
        if ( val == 1 ){
            printf( "%5d" , number );
            if ( i % 10 == 0 ){
                printf( "\n" );
            }i++;
        }/*else if ( val == 0 ){
            printf( "%d is not a prime number\n" , number );
        }*/
    }

    return 0;
}

int primeNumber( int num )
{
    int count = 0;
    for ( int i = 2; i < num; i++ ){
        if ( num % i == 0 ){
            count++;
            break;
        }
    }
    if ( count != 0 ){
        return 0; //not prime
    }else{
        return 1; //prime
    }
}
