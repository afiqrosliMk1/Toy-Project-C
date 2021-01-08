#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{
    int number , guess;
    char gameState = 'y';

    while ( gameState == 'y' ){
        srand( time(NULL) );
        number = rand() % 1000 + 1;
        printf( "I have a number between 1-1000\nCan you guess?\n" );
        printf( "Type your first guess: " );
        scanf( "%d" , &guess );
        while ( guess != number ){
            if ( guess > number ){
                printf( "Too high. Guess again: " );
                scanf( "%d" , &guess );
            }else if ( guess < number ){
                printf( "Too low. Guess again: " );
                scanf( "%d" , &guess );
            }
        }

        if ( guess == number ){
            printf( "Excellent! Want to play again (y/n) ?: " );
            scanf( " %c" , &gameState );
        }
    }

    return 0;
}
