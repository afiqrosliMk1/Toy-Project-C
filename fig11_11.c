#include <stdio.h>

struct clientData{
    int acctNum;
    char lastName[ 15 ];
    char firstName[ 10 ];
    double balance;
};

int main( void )
{
    int i;

    struct clientData blankClient = { 0 , "" , "" , 0.0 };

    FILE *cfPtr;

    if ( ( cfPtr = fopen( "credit.dat" , "wb" ) ) == NULL ){
        printf( "File could not be found\n" );
    }else{
        //output 100 blank records to file
        for ( i = 1; i <= 100; ++i ){
            fwrite( &blankClient , sizeof( struct clientData ) , 1 , cfPtr );
        }
        fclose( cfPtr );
    }//end if else

    return 0;
}

