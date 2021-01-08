//computer assisted instruction
//this is for ex5_50 and ex5_51
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generateQuestion( void );
void printWrong( void );
void printRight( void );

int main( void )
{
    int schema , answer;
    char choice = 1;

    while ( choice != 'n' ){
        schema = generateQuestion();
        scanf( "%d" , &answer );

        while ( answer != schema ){
            printWrong();
            scanf( "%d" , &answer );
        }
        printRight();
        printf( "Another question? ('n' to end)\n" );
        scanf( " %c" , &choice );
    }

    return 0;
}

int generateQuestion( void )
{
    int a , b , sum;
    a = rand() % 10;
    b = rand() % 10;
    printf( "%d + %d = ?\n" , a , b );
    sum = a + b;
    return sum;
}

void printWrong( void )
{
    int a;
    a = rand() % 4 + 1;
    switch ( a ){
        case 1:
            printf( "No, please try again\n" );
            break;
        case 2:
            printf( "Wrong. Try once more\n" );
            break;
        case 3:
            printf( "Don't give up\n" );
            break;
        case 4:
            printf( "Keep trying\n" );
            break;
    }
}


void printRight( void )
{
    int b;
    b = rand() % 4 + 1;
    switch ( b ){
        case 1:
            printf( "Very good!\n" );
            break;
        case 2:
            printf( "Excellent!\n" );
            break;
        case 3:
            printf( "Well done!\n" );
            break;
        case 4:
            printf( "Nice work!\n" );
            break;
    }
}

