//random maze generator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMaze( char maze[][ 8 ] );

int main( void )
{
    static int xCoord;
    int column , count , loopTimes;

    char maze[ 8 ][ 8 ] =
    { { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } ,
      { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } ,
      { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } ,
      { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } ,
      { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } ,
      { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } ,
      { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } ,
      { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } };

    //srand( time( NULL ) );

    for ( column = 0; column <= 7; ++column ){
        if ( column == 0 ){
            xCoord = rand() % 8;
            maze[ xCoord ][ column ] = '0';
        }else if ( column == 7 ){
            maze[ xCoord ][ column ] = '0';
        }else{
            maze[ xCoord ][ column ] = '0';
            loopTimes = rand() % 4;
            for ( count = 0; count < loopTimes; ++count ){
                xCoord = rand() % 2 + xCoord;
                maze[ xCoord ][ column ] = '0';
            }
        }
    }

    printMaze( maze );

    return 0;
}

void printMaze( char maze[][ 8 ] )
{
    int i , j;

    for ( i = 0; i < 8; ++i ){
        for ( j = 0; j < 8; ++j ){
            printf( "%c" , maze[ i ][ j ] );
        }printf( "\n" );
    }printf( "\n" );
}
