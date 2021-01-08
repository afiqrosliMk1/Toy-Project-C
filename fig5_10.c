#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice();

int main( void )
{
    enum Status { WIN , LOST , CONTINUE };
    enum Status gameStatus;
    int faces , myPoint;

    srand( time(NULL) );

    faces = rollDice();
    printf( "First throw, faces = %d\n" , faces );
    if ( faces == 7 || faces == 11 ){
        gameStatus = WIN;
    }else if ( faces == 2 || faces == 3 || faces == 12 ){
        gameStatus = LOST;
    }else{
        gameStatus = CONTINUE;
        printf( "My Point: %d\n" , myPoint = faces );
    }

    while ( gameStatus == CONTINUE ){
        printf( "Next throw: %d\n" , faces = rollDice() );
        if ( faces == 7 ){
            gameStatus = LOST;
        }else if ( faces == myPoint ){
            gameStatus = WIN;
        }
    }//end while
    if ( gameStatus == WIN ){
        printf( "You WON!" );
    }else if ( gameStatus == LOST ){
        printf( "You LOST!" );
    }

    return 0;
}

int rollDice()
{
    int sum , dice1 , dice2;
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    sum = dice1 + dice2;
    return sum;
}
