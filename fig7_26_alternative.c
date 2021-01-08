#include <stdio.h>
#define SIZE 5

void bubble( int work[] , const int size , int (*compare)( int a , int b ) );
int ascending( int a , int b );
int descending( int a , int b );
void swap( int *elementPtr1 , int *elementPtr2 );

int main( void )
{
    int order;
    int counter;

    int a[ SIZE ] = { 2 , 6 , 4 , 10 , 8 };

    printf( "Enter 1 to sort in ascending order\n"
           "Enter 2 to sort in descending order\n" );
    scanf( "%d" , &order );

    printf( "\nData item in original order\n" );

    for ( counter = 0; counter < SIZE; counter++ ){
        printf( "%5d" , a[ counter ] );
    }

    if ( order == 1 ){
        bubble( a , SIZE , ascending );
        printf( "\nData item in ascending order\n" );
    }else {
        bubble( a , SIZE , descending );
        printf( "\nData items in descending order\n" );
    }

     for ( counter = 0; counter < SIZE; counter++ ){
        printf( "%5d" , a[ counter ] );
    }

    return 0;
}

void bubble( int work[] , const int size , int (*compare)( int a , int b ) )
{
    int pass;
    int count;

    for ( pass = 1; pass < size; ++pass ){
        for ( count = 0; count < size - 1; ++count ){
            if ( (*compare)( work[ count ] , work[ count + 1 ] ) ){
                swap( &work[ count ] , &work[ count + 1 ] );
            }
        }
    }
}

int ascending( int a , int b )
{
    return b < a;
}

int descending( int a , int b )
{
    return b > a;
}

void swap( int *elementPtr1 , int *elementPtr2 )
{
    int hold;

    hold = *elementPtr1;
    *elementPtr1 = *elementPtr2;
    *elementPtr2 = hold;
}
