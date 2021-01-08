//recursive binary search

#include <stdio.h>
#define SIZE 13
void bubbleSort( int b[] , int arraySize );
void printArray( int b[] , int arraySize );
int binarySearch( int key , int b[] , int lower , int upper );
void printRow( int c[] , int arraySize , int midVal , int up , int low );

int main( void )
{
    int a[ SIZE ] = { 8 , 6 , 7 , 4 , 1 , 12 , 34 , 2 , 9 , 3 , 2 , 10 , 14 };
    int searchKey = 1;
    int returnIndex;
    bubbleSort( a , SIZE );
    printArray( a , SIZE );
    printf( "search key: %d\n" , searchKey );
    returnIndex = binarySearch( searchKey , a , 0 , SIZE - 1 );
    if ( returnIndex != -1 ){
        printf( "value %d is found at element a[%d]\n" , searchKey , returnIndex );
    }else{
        printf( "value not found\n" );
    }

    return 0;
}

void bubbleSort( int b[] , int arraySize )
{
    int j , pass , hold;
    for ( pass = 1; pass < SIZE; ++pass ){
        for ( j = 0; j < SIZE - 1; ++j ){
            if ( b[ j ] > b[ j + 1 ] ){
                hold = b[ j ];
                b[ j ] = b[ j + 1 ];
                b[ j + 1 ] = hold;
            }//end if
        }//end j for
    }//end pass for
}

void printArray( int b[] , int arraySize )
{
    int k;
    for ( k = 0; k < arraySize; ++k ){
        printf( "%3d" , b[ k ] );
    }printf( "\n" );
}

int binarySearch( int key , int b[] , int lower , int upper )
{
    int mid;

    mid = ( upper + lower ) / 2;

    if ( b[ mid ] == key ){
        return mid;
    }else if ( b[ mid ] < key && lower < upper ){
        return binarySearch( key , b , mid + 1 , upper );
    }else if ( b[ mid ] > key && lower < upper ){
        return binarySearch( key , b , lower , mid - 1 );
    }else{
        return -1;
    }
}

void printRow( int c[] , int arraySize , int midVal , int up , int low )
{
    int i;
    for ( i = 0; i < arraySize; ++i ){
        if ( i == midVal ){
            printf( "%3d*" , c[ i ] );
        }else if ( i <= up && i >= low ){
            printf( "%3d" , c[ i ] );
        }else{
            printf( "   " );
        }
    }printf( "\n" );
}
