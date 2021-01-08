#include <stdio.h>

int main( void )
{
    int passed = 0 , failed = 0;
    //int failed = 0;
    int counter = 10;
    int result;

    while ( counter > 0 ){
        printf( "Enter result ( 1 - passed , 2 - failed )" );
        scanf( "%d" , &result );
        if ( result == 1 ){
            passed++;
            counter--;
        }
        else if ( result == 2 ){
            failed++;
            counter--;
        }
        else{
            printf( "Invalid result entered\n" );
        }
    }
    printf( "total passed: %d" , passed );
    printf( "\ntotal failed: %d" , failed );

    if ( passed >= 8 ){
        printf( "\nBonus to instructor!" );
    }
    return 0;
}
