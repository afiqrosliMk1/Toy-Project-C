#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void playGame( int , int* );
int rollDice( void );

enum Status { WIN , LOST , CONTINUE };

int main( void )
{
    int wager , bankBalance = 1000;

    printf( "How much would you like to bet?(EOF to end): " );
    scanf( "%d" , &wager );

    while ( wager != EOF ){
        if ( wager <= bankBalance && wager > 0 ){
            if ( (float)wager / bankBalance > 0.5 ){
                printf( "Oh, you are going for broke, huh?\n" );
            }else{
                printf( "Come on, take a chance!\n" );
            }
            playGame( wager , &bankBalance );
        }else{
            printf( "Invalid value\n" );
            printf( "Current balance: %d\n" , bankBalance );
        }
        printf( "How much would you like to bet?(EOF to end): " );
        scanf( "%d" , &wager );
    }//end of outermost while
    printf( "Your bank account: %d\n;." , bankBalance );
    printf( "Thanks for playing\n" );

    return 0;
}

void playGame( int bet , int *balance )
{
    int face , myPoint;
    enum Status gameStatus;

    srand( time(NULL) );
    face = rollDice();
    switch ( face )
    {
        case 7:
        case 11:
            gameStatus = WIN;
            break;

        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;

        default:
            gameStatus = CONTINUE;
    }//end switch
    myPoint = face;
    printf( "Your point: %d\n" , myPoint );

    while ( gameStatus == CONTINUE ){
        face = rollDice();
        if ( face == 7 ){
            gameStatus = LOST;
        }else if ( face == myPoint ){
            gameStatus = WIN;
        }
    }

    if ( gameStatus == WIN ){
        printf( "You win!\n" );
        *balance += bet;
        printf( "bank balance: %d\n" , *balance );
    }else if ( gameStatus == LOST ){
        printf( "You lost!\n" );
        *balance -= bet;
        printf( "bank balance: %d\n" , *balance );
    }
}

int rollDice( void )
{
    int dice1 , dice2;
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    printf( "Player rolled: %d + %d = %d\n" , dice1 , dice2 , dice1 + dice2 );

    return dice1 + dice2;
}
