//read sequential access file
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

    if ( ( cfPtr = fopen( "credit.dat" , "rb" ) ) == NULL ){
        printf( "File could not be opened\n" );
    }else{
        while ( !feof( cfPtr ) ){
            fread( &client , sizeof( struct clientData ) , 1 , cfPtr );
            if ( client.acctNum != 0 ){
                printf( "%d %s %s %.2f\n" , client.acctNum , client.lastName , client.firstName , client.balance );
            }
        }
        fclose( cfPtr );
        printf( "End of program\n" );
    }



    return 0;
}
