//loop until get the desired move counter
//Knight's Tour Brute Force
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define KEEP_TRACK_SIZE 30000

int validMove( int row , int col , int chessBoard[][ 8 ] );
int evaluateAttempt( int a[ 8 ] );
void printBoard( const int chessBoard[][ 8 ] );
void resetArray( int b[] , int size );
void printArray( const int c[] , int p );
void clearBoard( int bord[][ 8 ] );

int main( void )
{
    int board[ 8 ][ 8 ] = { 0 };
    int horizontal[ 8 ] = { 2 , 1 , -1 , -2 , -2 , -1 , 1 , 2 };
    int vertical[ 8 ] = { -1 , -2 , -2 , -1 , 1  , 2 , 2 , 1 };
    int moveCounter = 0;
    int currentRow = 3;
    int currentColumn = 4;
    int nextRow;
    int nextColumn;
    int moveType;
    int done = FALSE;
    int typeTried[ 8 ] = { 0 };
    int keepTrack[ KEEP_TRACK_SIZE ] = { 0 };
    int attempt;

    //srand( time( NULL ) );

    for ( attempt = 0; attempt < KEEP_TRACK_SIZE && moveCounter <= 60; ++attempt ){
        clearBoard( board );
        resetArray( typeTried , 8 );
        moveCounter = 0;
        currentRow = rand() % 8;
        currentColumn = rand() % 8;
        board[ currentRow ][ currentColumn ] = ++moveCounter;
        done = FALSE;

        while ( !done ){

            moveType = rand() % 8; //generate a random move type
            typeTried[ moveType ] = 1; //assign 1 to indicate that this type is already tried
            nextRow = currentRow + vertical[ moveType ]; //next resulting row for the generated move type
            nextColumn = currentColumn + horizontal[ moveType ]; //next resulting column for the generated move type

            if ( validMove( nextRow , nextColumn , board ) ){ //if the move is valid,
                board[ nextRow ][ nextColumn ] = ++moveCounter; //assign the current counter value to the board square
                currentRow = nextRow; //update current row
                currentColumn = nextColumn; //update current column
                resetArray( typeTried , 8 ); //reset array typeTried to 0 because this move type already succeed
            }

            if ( evaluateAttempt( typeTried ) ){ //if the type tried all are 1, it means no more attempt is possible, the done
                done = TRUE;
            }

        }//end while

        printBoard( board );
        keepTrack[ attempt ] = moveCounter;
    }//end outermost for

    printArray( keepTrack , KEEP_TRACK_SIZE );

    return 0;
}

int validMove( int row , int col , int chessBoard[][ 8 ] )
{
    return row >= 0 && row <= 7 && col >= 0 && col <= 7 && chessBoard[ row ][ col ] == 0;
}

int evaluateAttempt( int a[ 8 ] )
{
    //evaluate if there is any moveType that still can be tried
    //return TRUE if there is no more attempt possible
    int i;
    int truth = TRUE;
    for ( i = 0; i < 8; ++i ){
        if ( a[ i ] == 0 ){
            truth = FALSE;
        }
    }
    return truth;
}

void printBoard( const int chessBoard[][ 8 ] )
{
    int i , j;

    for ( i = 0; i < 8; ++i ){
        for ( j = 0; j < 8; ++j ){
            printf( "%3d" , chessBoard[ i ][ j ] );
        }printf( "\n" );
    }printf( "\n" );
}

void resetArray( int b[] , int size )
{
    int i;

    for ( i = 0; i < size; ++i ){
        b[ i ] = 0;
    }
}

void printArray( const int c[] , int p )
{
    int i;

    for ( i = 0; i < p; ++i ){
        printf( "%3d" , c[ i ] );
    }printf( "\n" );
}

void clearBoard( int bord[][ 8 ] )
{
    int i , j;

    for ( i = 0; i < 8; ++i ){
        for ( j = 0; j < 8; ++j ){
            bord[ i ][ j ] = 0;
        }
    }
}

