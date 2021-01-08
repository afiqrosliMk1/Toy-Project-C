//computer assisted instruction
//this is a continuation from ex5_50 and ex5_51
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generateQuestion( int lv , int type );
void printWrong( void );
void printRight( void );
void reset( int *correctPtr , int *wrongPtr );

int main( void )
{
    int schema , answer , correctCounter = 0 , wrongCounter = 0 , level , problem;
    float percentage;
    char choice = 1;

    printf( "Select problems you would like to study\n" );
    printf( "1. Addition\n2. Subtraction\n3. Multiplication\n4. Random\n" );
    printf( "Choice: " );
    scanf( "%d" , &problem );

    printf( "Select difficulty level ( 1 or 2 ): " );
    scanf( "%d" , &level );

    while ( choice != 'n' ){
        schema = generateQuestion( level , problem );
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
        }else{
            printf( "Please ask your teacher for help\n" );
        }
        reset( &correctCounter , &wrongCounter );
        printf( "Another question? ('n' to end)\n" );
        scanf( " %c" , &choice );
    }
    return 0;
}

int generateQuestion( int lv , int type )
{
    int a , b , size;

    if ( type > 3 ){
        type = rand() % 3 + 1;
    }//end if

    if ( lv == 1 ){
        size = 10;
    }else{
        size = 100;
    }//end if else

    switch ( type ){
        case 1:
            a = rand() % size;
            b = rand() % size;
            printf( "%d + %d = ?\n" , a , b );
            return a + b;
            break;
        case 2:
            a = rand() % size;
            b = rand() % size;
            printf( "%d - %d = ?\n" , a , b );
            return a - b;
            break;
        case 3:
            a = rand() % size;
            b = rand() % size;
            printf( "%d x %d = ?\n" , a , b );
            return a * b;
            break;
     }//end switch
     return 0;
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


