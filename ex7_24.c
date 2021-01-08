//with random maze generator
//GENERALIZED FOR ANY SIZE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3
#define POSSIBLE_ZEROS 100
#define SIZE 4

void mazeTraversal( char maze[][ SIZE ] , const int xCoord , const int yCoord , int row , int col , int direction );
int coordIsEdge( int row , int column );
int validMove( char maze[][ SIZE ] , int row , int column );
void printMaze( char maze[][ SIZE ] );
void mazeGenerator( char maze[][ SIZE ] , int *xPtr , int *yPtr );

int main( void )
{
    char maze[ SIZE ][ SIZE ];
    int i , j;
    int x , y;
    int xStart , yStart;

    for ( i = 0; i < SIZE; ++i ){
        for ( j = 0; j < SIZE; ++j ){
            maze[ i ][ j ] = '1';
        }
    }

    mazeGenerator( maze , &xStart , &yStart );

    x = xStart;
    y = yStart;

    mazeTraversal( maze , xStart , yStart , x , y , RIGHT );

    return 0;
}

void mazeTraversal( char maze[][ SIZE ] , const int xCoord , const int yCoord , int row , int col , int direction ) //direction means, our next X will be to the "direction" of current X
{
    static int flag = 0;
    int move , count;

    maze[ row ][ col ] = 'X';
    printMaze( maze );

    if ( row == xCoord && col == yCoord && flag != 0 ){
        printf( "No exit\n" );
        return;
    }else if ( coordIsEdge( row , col ) && row != xCoord && col != yCoord ){
        printf( "Successfully exited!\n" );
        return;
    }else{
        flag = 1;
        for ( move = direction , count = 0; count < 4; ++count , ++move , move %= 4 ){
            switch ( move ){
                case RIGHT:
                    if ( validMove( maze , row , col + 1 ) ){
                        mazeTraversal( maze , xCoord , yCoord , row , col + 1 , DOWN );
                        return;
                    }
                    break;

                case UP:
                    if ( validMove( maze , row - 1 , col ) ){
                        mazeTraversal( maze , xCoord , yCoord , row - 1 , col , RIGHT );
                        return;
                    }
                    break;

                case LEFT:
                    if ( validMove( maze , row , col - 1 ) ){
                        mazeTraversal( maze , xCoord , yCoord , row , col - 1 , UP );
                        return;
                    }
                    break;

                case DOWN:
                    if ( validMove( maze , row + 1 , col ) ){
                        mazeTraversal( maze , xCoord , yCoord , row + 1 , col , LEFT );
                        return;
                    }
                    break;
            }//end switch move
        }//end for count
    }


}

int coordIsEdge( int row , int column )
{
    if ( ( row == 0 || row == SIZE - 1 ) && column >= 0 && column <= SIZE - 1 ){
        return 1;
    }else if( ( column == 0 || column == SIZE - 1 ) && row >= 0 && row <= SIZE - 1 ){
        return 1;
    }else{
        return 0;
    }
}

int validMove( char maze[][ SIZE ] , int row , int column )
{
    return maze[ row ][ column ] != '1' && row >= 0 && row <= SIZE - 1 && column >= 0 && column <= SIZE - 1;
}

void printMaze( char maze[][ SIZE ] )
{
    int i , j;

    for ( i = 0; i < SIZE; ++i ){
        for ( j = 0; j < SIZE; ++j ){
            printf( "%c" , maze[ i ][ j ] );
        }printf( "\n" );
    }printf( "\n" );
}

void mazeGenerator( char maze[][ SIZE ] , int *xPtr , int *yPtr )
{
    int a , x , y; //random number
    int entry , exit;
    int loop;

    srand( time( NULL ) );

    do{
        entry = rand() % 4;
        exit = rand() % 4;
    }while ( entry == exit );

    if ( entry == 0 ){
        *xPtr = 1 + rand() % ( SIZE - 2 );
        *yPtr = 0;
    }else if ( entry == 1 ){
        *xPtr = 0;
        *yPtr = 1 + rand() % ( SIZE - 2 );
    }else if ( entry == 2 ){
        *xPtr = 1 + rand() % ( SIZE - 2 );
        *yPtr = SIZE - 1;
    }else{
        *xPtr = SIZE - 1;
        *yPtr = 1 + rand() % ( SIZE - 2 );
    }

    if ( exit == 0 ){
        a = 1 + rand() % ( SIZE - 2 );
        maze[ a ][ 0 ] = '0';
    }else if ( exit == 1 ){
        a = 1 + rand() % ( SIZE - 2 );
        maze[ 0 ][ a ] = '0';
    }else if ( exit == 2 ){
        a = 1 + rand() % ( SIZE - 2 );
        maze[ a ][ SIZE - 1 ] = '0';
    }else{
        a = 1 + rand() % ( SIZE - 2 );
        maze[ SIZE - 1 ][ a ] = '0';
    }

    for ( loop = 1; loop < POSSIBLE_ZEROS; ++loop ){
        x = 1 + rand() % ( SIZE - 2 );
        y = 1 + rand() % ( SIZE - 2 );
        maze[ x ][ y ] = '0';
    }
}
