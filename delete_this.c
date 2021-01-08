#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    FILE *tfPtr;
    int transAccount;
    double transAmount;

    if ( ( tfPtr = fopen( "trans_redo.dat" , "r" ) ) == NULL ){
        printf( "file could not be opened\n" );
        exit( 1 );
    }

    fscanf( tfPtr , "%d%lf" , &transAccount , &transAmount );
    while ( !feof( tfPtr ) ){

        printf( "account = %d\namount = %.2f\n\n" , transAccount , transAmount );
        fscanf( tfPtr , "%d%lf" , &transAccount , &transAmount );
    }




    return 0;
}
