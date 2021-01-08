#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{
    int number , guess , counter;
    char gameStatus = 'y';

    while ( gameStatus == 'y' ){ //keep playing as long as gameStatus is 'y'
        counter = 1;
        srand( time(NULL) );
        number = rand() % 10 + 1;
        printf( "I have a number between 1-10\nCan you guess my number?\n" );
        printf( "Please type your first guess: " );
        scanf( "%d" , &guess );

        while ( guess != number ){
            if ( guess > number ){
                printf( "Too high. Try again: " );
                scanf( "%d" , &guess );
            }else if ( guess < number ){
                printf( "Too low. Try again: " );
                scanf( "%d" , &guess );
            }
            counter++;
        }
        if ( guess == number ){
            printf( "Excellent! You guessed it right!\n" );
            if ( counter < 10 ){
                printf( "Either you now the secret or you got lucky\n" );
            }else if ( counter == 10 ){
                printf( "Ahah! You know the secret!\n" );
            }else if ( counter > 10 ){
                printf( "You should be able to do it better\n" );
            }
            printf( "Would you like to play again? (y/n): " );
            scanf( " %c" , &gameStatus );
        }
    }

    return 0;
}
