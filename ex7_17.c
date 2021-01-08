#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define COURSE_LENGTH 70

void moveTortoise( int *tortoisePtr );
void moveHare( int *harePtr );
void printPosition( int *harePtr , int *tortoisePtr );

int main( void )
{
    int hare = 1;
    int tortoise = 1;

    srand( time( NULL ) );
    printf( "BANG !!!!\n"
           "AND THEY'RE OFF !!!!\n" );

    while ( hare != COURSE_LENGTH && tortoise != COURSE_LENGTH ){
        moveTortoise( &tortoise );
        moveHare( &hare );
        printPosition( &hare , &tortoise );
    }

    if ( tortoise > hare ){
        printf( "TORTOISE WINS!\n" );
    }else{
        printf( "HARE WINS!\n" );
    }

}

void moveTortoise( int *tortoisePtr )
{
    int x;
    x = rand() % 10 + 1;

    if ( x >= 1 && x <= 5 ){
        *tortoisePtr += 3;
    }else if ( x == 6 || x == 7 ){
        *tortoisePtr -= 6;
    }else{
        ++( *tortoisePtr );
    }

    if ( *tortoisePtr < 1 ){
        *tortoisePtr = 1;
    }else if ( *tortoisePtr > COURSE_LENGTH ){
        *tortoisePtr = COURSE_LENGTH;
    }
}

void moveHare( int *harePtr )
{
    int y;
    y = rand() % 10 + 1;

    if ( y == 1 || y == 2 ){
        ;
    }else if ( y == 3 || y == 4 ){
        *harePtr += 9;
    }else if ( y == 5 ){
        *harePtr -= 12;
    }else if ( y >= 6 && y <= 8 ){
        ++( *harePtr );
    }else{
        *harePtr -= 2;
    }

    if ( *harePtr < 1 ){
        *harePtr = 1;
    }else if ( *harePtr > COURSE_LENGTH ){
        *harePtr = COURSE_LENGTH;
    }
}

void printPosition( int *harePtr , int *tortoisePtr )
{
    int i;

    for ( i = 1; i <= COURSE_LENGTH; ++i ){
        if ( i == *harePtr && i == *tortoisePtr ){
            printf( "OUCH!" );
        }else if ( i == *harePtr ){
            printf( "H" );
        }else if ( i == *tortoisePtr ){
            printf( "T" );
        }else{
            printf( " " );
        }
    }printf( "\n" );
    Sleep( 1000 );
}
