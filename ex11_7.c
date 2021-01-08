#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int masterAccount; //account from old master file
    int transactionAccount; //account from transaction file
    double masterBalance; //balance from old master file
    double transactionBalance; //balance from transaction file
    char masterName[ 30 ]; //name from master file
    FILE *ofPtr; //old master file pointer
    FILE *tfPtr; //transaction file pointer
    FILE *nfPtr; //new master file pointer

    // if old master file can't be opened , terminate application
    if ( ( ofPtr = fopen( "oldmast.dat" , "r" ) ) == NULL ){
        printf( "Unable to open oldmast.dat\n" );
        exit( 1 );
    }

    //terminate application if transaction file can't be opened
    if ( ( tfPtr = fopen( "trans.dat" , "r" ) ) == NULL ){
        printf( "Unable to open trans.dat\n" );
        exit( 1 );
    }

    //terminate application if new master file can't be opened
    if ( ( nfPtr = fopen( "newmast.dat" , "w" ) ) == NULL ){
        printf( "Unable to open newmast.dat\n" );
        exit( 1 );
    }

    //display account currently being processed
    printf( "Processing...\n" );
    fscanf( tfPtr , "%d%lf" , &transactionAccount , &transactionBalance );

    //while not the end of transaction file
    while ( !feof( tfPtr ) ){

        //read next record from old master
        fscanf( ofPtr , "%d%[^0-9-]%lf" , &masterAccount , masterName ,
               &masterBalance );
        //^0-9- means input character selain dari nombor dan '-'. Once dashed is encountered , stop scanf()

        //display accounts from master file until number of new account is reached
        while ( masterAccount < transactionAccount && !feof( ofPtr ) ){
            fprintf( nfPtr , "%d %s %.2f\n" , masterAccount , masterName ,
                    masterBalance );
            printf( "%d %s %.2f\n" , masterAccount , masterName ,
                   masterBalance );
            //read next record from old master file
            fscanf( ofPtr , "%d%[^0-9-]%lf" , &masterAccount , masterName ,
                    &masterBalance );
        }//end while master account

        //if matching account found , update balance and output account info
        if ( masterAccount == transactionAccount ){
            masterBalance += transactionBalance;
            fprintf( nfPtr , "%d %s %.2f\n" , masterAccount , masterName ,
                    masterBalance );
            printf( "%d %s %.2f\n" , masterAccount , masterName , masterBalance );
        }else if ( masterAccount > transactionAccount ){
            printf( "Unmatched transaction record for account %d\n" ,
                  transactionAccount );
            fprintf( nfPtr , "%d %s %.2f\n" , masterAccount , masterName ,
                    masterBalance );
            printf( "%d %s %.2f\n" , masterAccount , masterName , masterBalance );
        }else{
            printf( "Unmatched transaction record for account %d\n" ,
                   transactionAccount );
        }//end else
        //get next account and balance from transaction file
        fscanf( tfPtr , "%d%lf" , &transactionAccount , &transactionBalance );

    }//end while

    //loop through file and display account number , name and balance
    while ( !feof( ofPtr ) ){
        fscanf( ofPtr , "%d%[^0-9-]%lf" , &masterAccount , masterName ,
               &masterBalance );
        fprintf( nfPtr , "%d %s %.2f" , masterAccount , masterName ,
                masterBalance );
        printf( "%d %s %.2f" , masterAccount , masterName , masterBalance );
    }//end while

    fclose( ofPtr );
    fclose( tfPtr );
    fclose( nfPtr );

    return 0;
}
