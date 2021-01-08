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

    //open the file if exist, otherwise exits

    if ( ( cfPtr = fopen( "credit.dat" , "rb+" ) ) == NULL ){
        printf( "File could not be opened\n" );
    }else{
        printf( "Enter account number ( 1 - 100 , 0 to end )\n?" );
        fscanf( stdin , "%d" , &client.acctNum );

        while ( client.acctNum != 0 ){
            printf( "Enter last name , first name , balance\n?" );
            fscanf( stdin , "%s %s %lf" , client.lastName , client.firstName , &client.balance );
            fseek( cfPtr , ( client.acctNum - 1 ) * sizeof( struct clientData ) , SEEK_SET );
            fwrite( &client , sizeof( struct clientData ) , 1 , cfPtr );
            printf( "Enter account number ( 1 - 100 , 0 to end )\n?" );
            fscanf( stdin , "%d" , &client.acctNum );
        }//end while
        fclose( cfPtr );
    }//end else
    return 0;
}
