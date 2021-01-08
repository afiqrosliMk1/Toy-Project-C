#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int masterAccount;
    int transactionAccount;
    char masterName[ 30 ];
    double masterBalance;
    double transactionBalance;
    FILE *ofPtr; //old master file pointer
    FILE *nfPtr; //new master file pointer
    FILE *tfPtr; //transaction file pointer

    if ( ( nfPtr = fopen( "newmast_redo.dat" , "w" ) ) == NULL ){
        printf( "newmast_redo.dat could not be opened\n" );
        exit( 1 );
    }
    if ( ( ofPtr = fopen( "oldmast_redo.dat" , "r" ) ) == NULL ){
        printf( "newmast_redo.dat could not be opened\n" );
        exit( 1 );
    }
    if ( ( tfPtr = fopen( "trans_redo.dat" , "r" ) ) == NULL ){
        printf( "newmast_redo.dat could not be opened\n" );
        exit( 1 );
    }

    fscanf( tfPtr , "%d%lf" , &transactionAccount , &transactionBalance );

    while ( !feof( tfPtr ) ){

        fscanf( ofPtr , "%d%[^0-9-]%lf" , &masterAccount , masterName , &masterBalance );

        while ( masterAccount < transactionAccount && !feof( ofPtr ) ){
            fprintf( nfPtr , "%d %s %.2f\n" , masterAccount , masterName , masterBalance );
            //read the next record from old master file
            fscanf( ofPtr , "%d%[^0-9-]%lf" , &masterAccount , masterName , &masterBalance );
        }

        if ( masterAccount == transactionAccount ){
            //if match is found , add transaction balance to master balance
            masterBalance += transactionBalance;
            //write new balance to new master file
            fprintf( nfPtr , "%d %s %.2f\n" , masterAccount , masterName , masterBalance );

        }else if ( masterAccount > transactionAccount ){
            printf( "Match could not be found for account: %d\n" , transactionAccount );
            //write new balance to new master file
            fprintf( nfPtr , "%d %s %.2f\n" , masterAccount , masterName , masterBalance );

        }else{
            printf( "Match could not be found for account: %d\n" , transactionAccount );

        }
        //read the next transaction record
        fscanf( tfPtr , "%d%lf" , &transactionAccount , &transactionBalance );

    }//end while !feof

    //======================copy the rest of records from old master to new master=============================//

    while ( !feof( ofPtr ) ){
        fscanf( ofPtr , "%d%[^0-9-]%lf" , &masterAccount , masterName , &masterBalance );
        fprintf( nfPtr , "%d %s %.2f\n" , masterAccount , masterName , masterBalance );
    }

    fclose( ofPtr );
    fclose( nfPtr );
    fclose( tfPtr );

    //===================================print the records stored in new master===============================//

    if ( ( nfPtr = fopen( "newmast_redo.dat" , "r" ) ) == NULL ){
        printf( "newmast_redo.dat could not be opened\n" );
        exit( 1 );
    }

    if ( ( ofPtr = fopen( "oldmast_redo.dat" , "r" ) ) == NULL ){
        printf( "oldmast_redo.dat could not be opened\n" );
        exit( 1 );
    }

    printf( "------------old master file--------------\n");

    fscanf( ofPtr , "%d%[^0-9-]%lf" , &masterAccount , masterName , &masterBalance );
    while ( !feof( ofPtr ) ){
        fprintf( stdout , "%d %s %.2f\n" , masterAccount , masterName , masterBalance );
        fscanf( ofPtr , "%d%[^0-9-]%lf" , &masterAccount , masterName , &masterBalance );
    }

    printf( "------------new master file--------------\n");

    fscanf( nfPtr , "%d%[^0-9-]%lf" , &masterAccount , masterName , &masterBalance );
    while ( !feof( nfPtr ) ){
        fprintf( stdout , "%d %s %.2f\n" , masterAccount , masterName , masterBalance );
        fscanf( nfPtr , "%d%[^0-9-]%lf" , &masterAccount , masterName , &masterBalance );
    }

    fclose( nfPtr );
    fclose( ofPtr );

    return 0;
}
