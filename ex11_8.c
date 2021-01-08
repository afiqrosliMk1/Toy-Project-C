#include <stdio.h>

int main( void )
{
    int account;
    char name[ 30 ];
    double balance;
    double amount;
    FILE *ofPtr;
    FILE *tfPtr;

    ofPtr = fopen( "oldmast.dat" , "w" );
    tfPtr = fopen( "trans.dat" , "w" );

    printf( "Sample data for file oldmast.dat:\n" );
    printf( "Enter account , name and balance (EOF to end): " );

    //loop while EOF character not entered by user
    while( scanf( "%d%[^0-9-]%lf" , &account , name , &balance ) != EOF ){

        //write data to old master file
        fprintf( ofPtr , "%d %s %.2f\n" , account , name , balance );
        printf( "Enter account , name , and balance (EOF to end): " );
    }
    fclose( ofPtr );

    //prompt user for sample data
    printf( "\nSample data for file trans.dat:\n" );
    printf( "Enter account and transaction amount (EOF to end): " );

    while( scanf( "%d%lf" , &account , &amount ) != EOF ){
        //write data to transaction file
        fprintf( tfPtr , "%d %.2f\n" , account , amount );
        printf( "Enter account and transaction amount (EOF to end): " );
    }

    fclose( tfPtr );

    return 0;
}
