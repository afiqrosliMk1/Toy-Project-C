#include <stdio.h>

int main( void )
{
    int account;
    char name[ 30 ];
    double balance;

    FILE *cfPtr; //clients.dat file pointer

    if ( ( cfPtr = fopen( "clients.dat" , "r" ) ) == NULL ){
        printf( "file doesn't exits\n" );
    }else{
        printf( "%-10s%-13s%s\n" , "Account" , "Name" , "Balance" );
        fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );

        while( !feof( cfPtr ) ){
            printf( "%-10d%-13s%7.2f\n" , account , name , balance );
            fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
        }//end while

        fclose( cfPtr );
    }

    return 0;
}
