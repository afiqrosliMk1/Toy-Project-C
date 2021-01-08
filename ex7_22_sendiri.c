#include <stdio.h>

#define X_START 2
#define Y_START 0

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

void mazeTraversal( int maze[][ 8 ] , int xCoord ,  int yCoord , int direction );
int validMove( const int maze[][ 8 ] , const int xCoord , const int yCoord );
void printMaze( const int maze[][ 8 ] );
int coordIsEdge( int x , int y );

int main( void )
{
    int maze[ 8 ][ 8 ] =
    { { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } ,
      { '1' , '1' , '1' , '0' , '0' , '0' , '0' , '1' } ,
      { '0' , '0' , '0' , '0' , '1' , '1' , '1' , '1' } ,
      { '1' , '1' , '1' , '0' , '1' , '0' , '0' , '0' } ,
      { '1' , '1' , '1' , '0' , '1' , '0' , '1' , '1' } ,
      { '1' , '0' , '0' , '0' , '0' , '0' , '0' , '1' } ,
      { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } ,
      { '1' , '1' , '1' , '1' , '1' , '1' , '1' , '1' } };

    mazeTraversal( maze , X_START , Y_START , RIGHT );

    return 0;
}

void mazeTraversal( int maze[][ 8 ] , int xCoord ,  int yCoord , int direction )
{
    int move , count;
    static int flag = 0;

    maze[ xCoord ][ yCoord ] = 'X';
    printMaze( maze );

    if ( coordIsEdge( xCoord , yCoord ) && xCoord != X_START && yCoord != Y_START ){
        printf( "Maze successfully exited!\n" );
        return;
    }else if ( xCoord == X_START && yCoord == Y_START && flag == 1 ){
        printf( "Back to the starting point\n" );
        return;
    }else{
        flag = 1;
        for ( move = direction , count = 1; count <= 4; ++move , ++count , move %= 4 ){
            switch ( move ){
                //if currently moving to the RIGHT , try to turn right to DOWN direction
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

                case DOWN:
                    if ( validMove( maze , xCoord + 1 , yCoord ) ){
                        mazeTraversal( maze , xCoord + 1 , yCoord , LEFT );
                        return;
                    }
                    break;
            }//end switch
        }//end for
    }




    return;
}

int validMove( const int maze[][ 8 ] , const int xCoord , const int yCoord )
{
    return xCoord >= 0 && xCoord <= 8 && yCoord >= 0 && yCoord <= 8 && maze[ xCoord ][ yCoord ] != '1';
}

void printMaze( const int maze[][ 8 ] )
{
    int i , j;
    for ( i = 0; i < 8; ++i ){
        for ( j = 0; j < 8; ++j ){
            printf( "%c" , maze[ i ][ j ] );
        }printf( "\n" );
    }printf( "\n" );

    printf( "Hit return to continue" );
    getchar();
}

int coordIsEdge( int x, int y )
{

    if ( ( y == 0 || y == 7 ) && ( x >= 0 && x <= 7 ) ){
        return 1;
    }else if ( ( x == 0 || x == 7 ) && ( y >= 0 && y <= 7 ) ){
        return 1;
    }else{
        return 0;
    }
}
