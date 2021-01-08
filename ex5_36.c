#include <stdio.h>

void towerOfHanoi( int n , char from , char to , char temp );

int main( void )
{
    int disks;
    printf( "Tower of hanoi solver: Peg A to C using B as holder\n" );
    printf( "Enter the number of disks:" );
    scanf( "%d" , &disks );
    towerOfHanoi( disks , 'A' , 'C' , 'B' );

    return 0;
}

void towerOfHanoi( int n , char from , char to , char temp )
{
    if ( n == 1 ){
        printf( "%c -> %c\n" , from , to );
        return;
    }else{
        towerOfHanoi( n - 1 , from , temp , to );
        printf( "%c -> %c\n" , from , to );
        towerOfHanoi( n - 1 , temp , to , from );
    }
}

/*void towerOfHanoi( int n , char from , char to , char temp )
{
    if ( n > 1 ){
        towerOfHanoi( n - 1 , from , temp , to );
    }
    printf( "%c -> %c\n" , from , to );
    if ( n > 1 ){
        towerOfHanoi( n - 1 , temp , to , from );
    }
    return;
}*/
