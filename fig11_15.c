#include <stdio.h>

struct clientData {
    int acctNum;
    char lastName[ 15 ];
    char firstName[ 10 ];
    double balance;
};

int main( void )
{
    FILE *cfPtr;

    struct clientData client = { 0 , "" , "" , 0.0 };

    if ( ( cfPtr = fopen( "credit.dat" , "rb" ) ) == NULL ){
        printf( "File could not be opened\n" );
    }else{
        printf( "---------------\n" );
        //printf( "%u" , sizeof(struct clientData));

        while( !feof( cfPtr ) ){
            fread( &client , sizeof( struct clientData ) , 1 , cfPtr );

            printf( "%d" , client.acctNum );
            if ( client.acctNum != 0 ){
                printf( "%d%s%s%f\n" , client.acctNum , client.lastName , client.firstName , client.balance );
            }
        }//end while

        fclose( cfPtr );

    }//end else


    return 0;
}
