//create sequential access file
#include <stdio.h>

int main( void )
{
    FILE *cfPtr;
    int account;
    char name[ 30 ];
    double balance;

    if ( ( cfPtr = fopen( "clients.dat" , "w" ) ) == NULL ){
        printf( "File could not be opened\n" );
    }else{
        printf( "Enter account , name , balance\n?" );
        scanf( "%d%s%lf" , &account , name , &balance );

        while ( !feof( stdin ) ){
            fprintf( cfPtr , "%3d %s %.2f\n" , account , name , balance );
            printf( "Enter account ( 1 - 100 ) , name , balance ( EOF to end )\n?" );
            scanf( "%d%s%lf" , &account , name , &balance );
        }
        fclose( cfPtr );
    }//end if






    return 0;
}
