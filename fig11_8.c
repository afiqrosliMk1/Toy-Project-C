#include <stdio.h>

int main( void )
{
    int request;
    int account;
    double balance;
    char name[ 30 ];
    FILE *cfPtr; //clients.dat pointer

    if ( ( cfPtr = fopen( "clients.dat" , "r" ) ) == NULL ){
        printf( "Cannot open the file\n" );
    }else{
        fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
        while ( !feof( cfPtr ) ){
            printf( "%d %s %.2f\n" , account , name , balance );
            fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
        }

        printf( "Enter request\n"
               " 1 - List accounts with zero balances\n"
               " 2 - List accounts with credit balances\n"
               " 3 - List accounts with debit balances\n"
               " 4 - End of run\n?" );
        scanf( "%d" , &request );

        while( request != 4 ){
            fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );

            switch( request ){
                case 1:
                    printf( "\nAccounts with zero balances:\n" );

                    while( !feof( cfPtr ) ){
                        if ( balance == 0 ){
                            printf( "%-10d%-13s%7.2f\n" , account , name , balance );
                        }
                        fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
                    }
                    break;
                case 2:
                    printf( "\nAccounts with credit balances:\n" );

                    while ( !feof( cfPtr ) ){
                        if ( balance < 0 ){
                            printf( "%-10d%-13s%7.2f\n" , account , name , balance );
                        }
                        fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
                    }


                    break;
                case 3:
                    printf( "\nAccounts with debit balances:\n" );

                    while( !feof( cfPtr ) ){
                        if ( balance > 0 ){
                            printf( "%-10d%-13s%7.2f\n" , account , name , balance );
                        }
                        fscanf( cfPtr , "%d%s%lf" , &account , name , &balance );
                    }
                    break;
            }//end switch

            rewind( cfPtr ); //return file pointer to the beginning of the file
            printf( "\n?" );
            scanf( "%d" , &request );
        }//end while

    }

    printf( "End of run\n" );
    fclose( cfPtr ); //closes the file
    return 0;
}
