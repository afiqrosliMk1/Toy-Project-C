//Maze Traversal
#include <stdio.h>
#include <stdlib.h>

#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3

#define X_START 2
#define Y_START 0

void mazeTraversal( char maze[ 12 ][ 12 ] , int xCoord , int yCoord , int direction );
void printMaze( const char maze[][ 12 ] );
int validMove( const char maze[][ 12 ] , int r , int c );
int coordsAreEdge( int x , int y );

int main( void )
{
    char maze[ 12 ][ 12 ] =
    { { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } ,
    {   '1' , '0' , '0' , '0' , '1' , '0' , '0' , '0' , '0' , '0' , '0' , '1' } ,
    {   '0' , '0' , '1' , '0' , '1' , '0' , '1' , '1' , '1' , '1' , '0' , '1' } ,
    {   '1' , '1' , '1' , '0' , '1' , '0' , '0' , '0' , '0' , '1' , '0' , '1' } ,
    {   '1' , '0' , '0' , '0' , '0' , '1' , '1' , '1' , '0' , '1' , '0' , '0' } ,
    {   '1' , '1' , '1' , '1' , '0' , '1' , '0' , '1' , '0' , '1' , '0' , '1' } ,
    {   '1' , '0' , '0' , '1' , '0' , '1' , '0' , '1' , '0' , '1' , '0' , '1' } ,
    {   '1' , '1' , '0' , '1' , '0' , '1' , '0' , '1' , '0' , '1' , '0' , '1' } ,
    {   '1' , '0' , '0' , '0' , '0' , '0' , '0' , '0' , '0' , '1' , '0' , '1' } ,
    {   '1' , '1' , '1' , '1' , '1' , '1' , '0' , '1' , '1' , '1' , '0' , '1' } ,
    {   '1' , '0' , '0' , '0' , '0' , '0' , '0' , '1' , '0' , '0' , '0' , '1' } ,
    {   '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' , '0' , '1' } };

    mazeTraversal( maze , X_START , Y_START , LEFT );

    return 0;
}

void mazeTraversal( char maze[ 12 ][ 12 ] , int xCoord , int yCoord , int direction )
{
    static int flag = 0;

    maze[ xCoord ][ yCoord ] = 'X';
    printMaze( maze );

    //if maze completed
    if ( coordsAreEdge( xCoord , yCoord ) && xCoord != X_START && yCoord != Y_START ){
        printf( "\nMaze successfully exited!\n" );
        return;
    }else if ( xCoord == X_START && yCoord == Y_START && flag == 1 ){
        printf( "\nArrived back at the starting location\n" );
        return;
    }else{
        int move;
        int count;

        flag = 1;
        //loop 4 times and find first valid move
        for ( move = direction , count = 0; count < 4; ++count , ++move , move %= 4 ){
            switch ( move ){
                case DOWN:
                    //if move is valid,call mazeTraversal
                    if ( validMove( maze , xCoord + 1 , yCoord ) ){
                        mazeTraversal( maze , xCoord + 1, yCoord , LEFT );
                        return;
                    }
                    break;

                case RIGHT:

                    if ( validMove( maze , xCoord , yCoord + 1 ) ){
                        mazeTraversal( maze , xCoord , yCoord + 1 , DOWN );
                        return;
                    }
                    break;

                case UP:

                    if ( validMove( maze , xCoord - 1 , yCoord ) ){
                        mazeTraversal( maze , xCoord - 1 , yCoord , RIGHT );
                        return;
                    }
                    break;

                case LEFT:

                    if ( validMove( maze , xCoord , yCoord - 1 ) ){
                        mazeTraversal( maze , xCoord , yCoord - 1 , UP );
                        return;
                    }
                    break;
            }//end switch
        }//end for
    }//end else
}//end function mazeTraversal

int validMove( const char maze[][ 12 ] , int r , int c )
{
    return ( r >= 0 && r <= 11 && c >= 0 && c <= 11 && maze[ r ][ c ] != '1' );
}

//function to check coordinates
int coordsAreEdge( int x , int y )
{
    //if coordinate is not valid
    if ( ( x == 0 || x == 11 ) && ( y >= 0 && y <= 11 ) ){
        return 1;
    }else if ( ( y == 0 || y == 11 ) && ( x >= 0 || x <= 11 ) ){
        return 1;
    }else{
        return 0; //coordinate is valid
    }
}

void printMaze( const char maze[][ 12 ] )
{
    int x , y;

    for ( x = 0; x < 12; ++x ){
        for ( y = 0; y < 12; ++y ){
            printf( "%c" , maze[ x ][ y ] );
        }printf( "\n" );
    }

    printf( "\nHit return to see next move\n" );
    getchar();
}
