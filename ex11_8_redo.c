#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int accountNumber;
    double accountBalance;
    char name[ 30 ];
    int transactionNumber;
    double transactionValue;
    FILE *ofPtr; //pointer to old master file_redo
    FILE *tfPtr; //pointer to transaction file_redo

    //create old master file
    if ( ( ofPtr = fopen( "oldmast_redo.dat" , "w" ) ) == NULL ){
        printf( "old master redo file could not be opened\n" );
        exit( 1 );
    }

    printf( "Enter account number , name , balance (EOF to end): " );
    while ( scanf( "%d %[^0-9-]%lf" , &accountNumber , name , &accountBalance ) != EOF ){
        fprintf( ofPtr , "%d %s %.2f\n" , accountNumber , name , accountBalance );
        printf( "Enter account number , name , balance (EOF to end): " );
    }
    fclose( ofPtr );


    //transaction

    if ( ( tfPtr = fopen( "trans_redo.dat" , "w" ) ) == NULL ){
        printf( "transaction file redo could not be opened\n" );
        exit( 1 );
    }

    printf( "Enter account number and transaction value:\n" );
    while ( scanf( "%d%lf" , &transactionNumber , &transactionValue ) != EOF ){
        fprintf( tfPtr , "%d %.2f\n" , transactionNumber , transactionValue );
        printf( "DEBUG:%.2f\n" , transactionValue );
        printf( "Enter account number and transaction value:\n" );
    }
    fclose( tfPtr );

    return 0;
}
