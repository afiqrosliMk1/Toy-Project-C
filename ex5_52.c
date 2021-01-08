//computer assisted instruction
//this is a continuation from ex5_50 and ex5_51
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generateQuestion( void );
void printWrong( void );
void printRight( void );
void reset( int *correctPtr , int *wrongPtr );

int main( void )
{
    int schema , answer , correctCounter = 0 , wrongCounter = 0;
    float percentage;
    char choice = 1;

    while ( choice != 'n' ){
        schema = generateQuestion();
        scanf( "%d" , &answer );

        while ( answer != schema ){
            printWrong();
            ++wrongCounter;
            scanf( "%d" , &answer );
        }
        printRight();
        ++correctCounter;
        percentage = (float)correctCounter / ( correctCounter + wrongCounter );
        printf( "Percentage: %.2f\n" , percentage );
        if ( percentage >= 0.75 ){
            printf( "Congratulations, you are ready to go to the next level\n" );
        }
        reset( &correctCounter , &wrongCounter );
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

void reset( int *correctPtr , int *wrongPtr )
{
    *correctPtr = 0;
    *wrongPtr = 0;
}

