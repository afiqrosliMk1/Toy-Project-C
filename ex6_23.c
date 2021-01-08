#include <stdio.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
void getCommands( int a[][ 2 ] );
int turnRight( int d );
int turnLeft( int d );
void movePen( int dist , int dir , int penStatus , int b[][ 50 ] );
void printShape( int c[][ 50 ] , int p , int q );

int main( void )
{
    int floor[ 50 ][ 50 ] = { 0 };
    int commandArray[ MAX ][ 2 ] = { 0 };
    int command;
    int penDown = FALSE;
    int direction = 0; //0 x , 1 -y , 2 -x , 3 y
    int distance;
    int turnRight( int d );
    int turnLeft( int d );
    int i = 0;

    getCommands( commandArray );
    command = commandArray[ i ][ 0 ];
    //process each command in commandArray
    while ( command != 9 ){
        switch ( command )
        {
            case 1:
                penDown = TRUE; //pen down
                break;
            case 2:
                penDown = FALSE; //pen up
                break;
            case 3:
                direction = turnRight( direction );
                break;
            case 4:
                direction = turnLeft( direction );
                break;
            case 5:
                distance = commandArray[ i ][ 1 ];
                movePen( distance , direction , penDown , floor );
                break;
            case 6:
                printShape( floor , 50 , 50 );
                break;
        }
        command = commandArray[ ++i ][ 0 ];
    }

    return 0;
}

void getCommands( int a[][ 2 ] )
{
    int tempCommand;
    int i = 0;

    printf( "Enter command ( 9 to end ): " );
    scanf( "%d" , &tempCommand );
    while ( tempCommand != 9 && i < MAX ){
        a[ i ][ 0 ] = tempCommand;
        if ( tempCommand == 5 ){
            scanf( ",%d" , &a[ i ][ 1 ] );
        }++i;
        printf( "Enter command ( 9 to end ): " );
        scanf( "%d" , &tempCommand );
    }
    a[ i ][ 0 ] = 9;
}

int turnRight( int d )
{
    return ++d > 3 ? 0 : d;
}

int turnLeft( int d )
{
    return --d < 0 ? 3 : d;
}

void movePen( int dist , int dir , int penStatus , int b[][ 50 ] )
{
    int i , j;
    static int posX = 0;
    static int posY = 0;

    switch ( dir )
    {
        case 0:
            if ( penStatus == TRUE ){
                for ( i = 0; i <= dist && posY + i < 50; ++i ){
                    b[ posX ][ posY + i ] = 1;
                }
            }
            posY += i - 1; //minus one because the value of i already exceeded the distance (hence loop failed) during last loop
            break;
        case 1:
            if ( penStatus == TRUE ){
                for ( j = 0; j <= dist && posX + j < 50; ++j ){
                    b[ posX + j ][ posY ] = 1;
                }
            }
            posX += j - 1;
            break;
        case 2:
            if ( penStatus == TRUE ){
                for ( i = 0; i <= dist && posY - i >= 0; ++i ){
                    b[ posX ][ posY - i ] = 1;
                }
            }
            posY -= i - 1;
            break;
        case 3:
            if ( penStatus == TRUE ){
                for ( j = 0; j <= dist && posX - j >= 0; ++j ){
                    b[ posX - j ][ posY ] = 1;
                }
            }
            posX -= j - 1;
            break;
    }
}

void printShape( int c[][ 50 ] , int p , int q )
{
    int i , j;

    for ( i = 0; i < p; ++i ){
        for ( j = 0; j < q; ++j ){
            putchar( c[ i][ j ] == 1 ? '*' : ' ' );
        }printf( "\n" );
    }
}
