//create random access file
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
    int i;
    struct clientData blankClient = { 0 , "" , "" , 0.0 };

    if ( ( cfPtr = fopen( "credit.dat" , "wb" ) ) == NULL ){
        printf( "File could not be opened\n" );
    }else{
        //write 100 blank records to file
        for ( i = 1; i <= 100; ++i ){
            fwrite( &blankClient , sizeof( struct clientData ) , 1 , cfPtr );
        }//end while
        fclose( cfPtr );
    }//end else

    return 0;
}
