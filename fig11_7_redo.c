#include <stdio.h>

int main( void )
{
    FILE *cfPtr;
    int account;
    char name[ 30 ];
    double balance;


    if ( ( cfPtr = fopen( "clients.dat" , "r" ) ) == NULL ){
        printf( "file could not be opened\n" );
    }else{
        fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
        while ( !feof( cfPtr ) ){
            printf( "%d %s %.2f\n" , account , name , balance );
            fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
        }
        fclose( cfPtr );
    }

    return 0;
}
