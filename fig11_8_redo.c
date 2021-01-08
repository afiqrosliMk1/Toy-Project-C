#include <stdio.h>

int main( void )
{
    int choice;
    int account;
    char name[ 30 ];
    double balance;
    FILE *cfPtr;

    printf( "Enter your choice 1-zero balance 2-credit balance 3-debit balance 4-exit:\n?" );
    fscanf( stdin , "%d" , &choice );

    while ( choice != 4 ){
        switch( choice )
        {
            case 1:
                if ( ( cfPtr = fopen( "clients.dat" , "r" ) ) == NULL ){
                    printf( "File could not be opened\n" );
                }else{
                    fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
                    while ( !feof( cfPtr ) ){
                        if ( balance == 0 ){
                            printf( "%3d%s%.2f\n" , account , name , balance );
                        }
                        fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
                    }//end while
                }//end else
                fclose( cfPtr );
                break;
            case 2:
                if ( ( cfPtr = fopen( "clients.dat" , "r" ) ) == NULL ){
                    printf( "File could not be opened\n" );
                }else{
                    fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
                    while ( !feof( cfPtr ) ){
                        if ( balance < 0 ){
                            printf( "%3d%s%.2f\n" , account , name , balance );
                        }
                        fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
                    }//end while
                }//end else
                fclose( cfPtr );
                break;
            case 3:
                if ( ( cfPtr = fopen( "clients.dat" , "r" ) ) == NULL ){
                    printf( "File could not be opened\n" );
                }else{
                    fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
                    while ( !feof( cfPtr ) ){
                        if ( balance > 0 ){
                            printf( "%3d%s%.2f\n" , account , name , balance );
                        }
                        fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
                    }//end while
                }//end else
                fclose( cfPtr );
                break;
            default:
                printf( "Invalid choice\n" );
                break;
        }//end switch
        rewind( cfPtr );
        printf( "Enter your choice 1-zero balance 2-credit balance 3-debit balance 4-exit:\n?" );
        fscanf( stdin , "%d" , &choice );
    }//end while

    printf( "End of run.\n" );
    return 0;
}
