#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

int main( void );
int rollDice( void );
void gameOfCraps( int win[] , int lost[] , int currentGameNo );
void printArray( int a[] , int p );
int totalArray( int c[] , int q );

enum Status { WIN , LOST , CONTINUE };

int main( void )
{
    int i;
    int winArray[ SIZE ] = { 0 };
    int lostArray[ SIZE ] = { 0 };
    int frequencyWin[ 21 ] = { 0 };
    int frequencyLost[ 21 ] = { 0 };

    printf( "---------------\n" );
    for ( i = 0; i < SIZE; ++i ){
        printf( "Game #%d\n" , i + 1 );
        printf( "---------------\n" );
        gameOfCraps( winArray , lostArray , i );
        printf( "---------------\n" );
    }

    //===========================================//
    /*printf( "                        " );
    for ( i = 0; i < SIZE; ++i ){
        printf( "%-s%03d   " , "G" , i + 1 );
    }printf( "\n" );

    printf( "Win  (Times Rolled): " );
    printArray( winArray , SIZE );

    printf( "Lost (Times Rolled): " );
    printArray( lostArray , SIZE );*/

    //=============SUMMARIZE ARRAY================//
    for ( i = 0; i < SIZE; ++i ){
        if ( winArray [ i ] != 0 ){
            if ( winArray[ i ] >= 20 ){
                ++frequencyWin[ 20 ];
            }else{
                ++frequencyWin[ winArray[ i ] ];
            }
        }
    }

    for ( i = 0; i < SIZE; ++i ){
        if ( lostArray [ i ] != 0 ){
            if ( lostArray[ i ] >= 20 ){
                ++frequencyLost[ 20 ];
            }else{
                ++frequencyLost[ lostArray[ i ] ];
            }
        }
    }

    //===========PRINT RESULT===========//
    printf( "\n\nGAMES WON = %d\\%d\n\n" , totalArray( frequencyWin , 21 ) , SIZE );
    printf( "Won on *th roll" );
    for ( i = 0; i < 21; ++i ){
        printf( "%5d" , i );
        switch ( i ){
            case 1:
                printf( "st" );
                break;
            case 2:
                printf( "nd" );
                break;
            case 3:
                printf( "rd" );
                break;
            default:
                printf( "th" );
        }
    }printf( "\n" );

    printf( "Frequency      " );
    printArray( frequencyWin , 21 );

    printf( "\n\nGAMES LOST = %d\\%d\n\n" , totalArray( frequencyLost , 21 ) , SIZE );
    printf( "Lost on *th roll" );
    for ( i = 0; i < 21; ++i ){
        printf( "%5d" , i );
        switch ( i ){
            case 1:
                printf( "st" );
                break;
            case 2:
                printf( "nd" );
                break;
            case 3:
                printf( "rd" );
                break;
            default:
                printf( "th" );
        }
    }printf( "\n" );

    printf( "Frequency      " );
    printArray( frequencyLost , 21 );

    //==============CALCULATE AVERAGE LENGTH OF GAME OF CRAPS=============//
    int totalRollWin = totalArray( winArray , SIZE );
    int totalRollLost= totalArray( lostArray , SIZE );
    printf( "\n\nAverage length of game of craps = %d roll\n" , (totalRollWin + totalRollLost)/SIZE );

    return 0;
}

void gameOfCraps( int win[] , int lost[] , int currentGameNo )
{
    int sum , myPoint , timesRoll = 0;

    enum Status gameStatus;

    sum = rollDice();
    ++timesRoll;

    switch ( sum )
    {
        case 7:
        case 11:
            gameStatus = WIN;
            win[ currentGameNo ] = timesRoll;
            printf( "You Win!\n" );
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            lost[ currentGameNo ] = timesRoll;
            printf( "You Lost!\n" );
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sum;
            printf( "Your Point = %d\n" , myPoint );
    }

    while ( gameStatus == CONTINUE ){
        sum = rollDice();
        ++timesRoll;

        if ( sum == myPoint ){
            gameStatus = WIN;
            win[ currentGameNo ] = timesRoll;
            printf( "You win\n" );
        }else if ( sum == 7 ){
            gameStatus = LOST;
            win[ currentGameNo ] = timesRoll;
            printf( "You Lost\n" );
        }
    }
}

int rollDice( void )
{
    int dice1 , dice2 , total;
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    total = dice1 + dice2;
    printf( "You rolled %d\n" , total );
    return total;
}

void printArray( int a[] , int p )
{
    int j;

    for ( j = 0; j < p; ++j ){
        printf( "%7d" , a[ j ] );
    }printf( "\n" );
}

int totalArray( int c[] , int q )
{
    int k , total = 0;

    for ( k = 0; k < q; ++k ){
        total += c[ k ];
    }

    return total;
}

