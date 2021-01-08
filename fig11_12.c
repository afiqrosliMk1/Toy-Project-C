#include <stdio.h>

struct clientData{
    int acctNum;
    char lastName[ 15 ];
    char firstName[ 10 ];
    double balance;
};

int main( void )
{
    FILE *cfPtr;

    struct clientData client = { 0 , "" , "" , 0.0 };

    if ( ( cfPtr = fopen( "clients.dat" , "rb+" ) ) == NULL ){
        printf( "File doesn't exist\n" );
    }else{
        printf( "Enter account number ( 1 to 100, 0 to end input )\n?" );
        scanf( "%d" , &client.acctNum );

        while ( client.acctNum != 0 ){
            printf( "Enter lastname, firstname, balance\n?" );

            fscanf( stdin , "%s%s%lf" , client.lastName , client.firstName , &client.balance );

            //seek position in file to user-specified record
            fseek( cfPtr , ( client.acctNum - 1 ) * sizeof( struct clientData ) , SEEK_SET );

            //write user-specified information in a file
            fwrite( &client , sizeof( struct clientData ) , 1 , cfPtr );

            //enable user to input another account number
            printf( "Enter account number\n?" );
            scanf( "%d" , &client.acctNum );
        }
    }//end else
    fclose( cfPtr );

    return 0;
}
