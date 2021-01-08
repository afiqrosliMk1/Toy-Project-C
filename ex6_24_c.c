#include <stdio.h>

#define TRUE 1
#define FALSE 0

int validMove( int row , int col , int a[][ 8 ] );
void printBoard( int b[][ 8 ] , int accs[][ 8 ] );

int main( void )
{
    int board[ 8 ][ 8 ] = { 0 };
    int horizontal[ 8 ] = { 2 , 1 , -1 , -2 , -2 , -1 , 1 , 2 };
    int vertical[ 8 ] = { -1 , -2 , -2 , -1 , 1  , 2 , 2 , 1 };
    int accessibility[ 8 ][ 8 ] = { { 2 , 3 , 4 , 4 , 4 , 4 , 3 , 2 } ,
                                    { 3 , 4 , 6 , 6 , 6 , 6 , 4 , 3 } ,
                                    { 4 , 6 , 8 , 8 , 8 , 8 , 6 , 4 } ,
                                    { 4 , 6 , 8 , 8 , 8 , 8 , 6 , 4 } ,
                                    { 4 , 6 , 8 , 8 , 8 , 8 , 6 , 4 } ,
                                    { 4 , 6 , 8 , 8 , 8 , 8 , 6 , 4 } ,
                                    { 3 , 4 , 6 , 6 , 6 , 6 , 4 , 3 } ,
                                    { 2 , 3 , 4 , 4 , 4 , 4 , 3 , 2 } };

    int moveType;
    int currentRow = 3;
    int currentColumn = 4;
    int testRow;
    int testColumn;
    int minRow;
    int minColumn;
    int accessNumber;
    int done = FALSE;
    int moveCounter = 0;

    board[ currentRow ][currentColumn ] = ++moveCounter;

    while ( !done ){
        accessNumber = 9;
        for ( moveType = 0; moveType <= 7; ++moveType ){
            testRow = currentRow + vertical[ moveType ];
            testColumn = currentColumn + horizontal[ moveType ];

            if ( validMove( testRow , testColumn , board ) ){
                if ( accessibility[ testRow ][ testColumn ] < accessNumber ){
                    accessNumber = accessibility[ testRow ][ testColumn ];
                    minRow = testRow;
                    minColumn = testColumn;
                }--accessibility[ testRow ][ testColumn ];
            }
        }//end for
        if ( accessNumber == 9 ){
            done = TRUE;
        }else{
            currentRow = minRow;
            currentColumn = minColumn;
            board[ currentRow ][ currentColumn ] = ++moveCounter;
            printBoard( board , accessibility );
        }

    }//end while

    //printBoard( board , accessibility );


    return 0;
}

int validMove( int row , int col , int a[][ 8 ] )
{
    return row >= 0 && row <= 7 && col >= 0 && col <= 7 && a[ row ][ col ] == 0;
}

void printBoard( int b[][ 8 ] , int accs[][ 8 ] )
{
    int i , j , k;
    for ( i = 0; i < 8; ++i ){
        for ( j = 0; j < 8; ++j ){
            printf( "%3d" , b[ i ][ j ] );
            if ( j == 7 ){
                printf( "   " );
                for ( k = 0; k < 8; ++k ){
                    printf( "%3d" , accs[ i ][ k ] );
                }printf( "\n" );
            }
        }//printf( "\n" );
    }printf( "\n" );
}
