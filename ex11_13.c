#include <stdio.h>

int main( void )
{
    char *phoneWord[ 10 ] = { "" , "" , "ABC" , "DEF" , "GHI" , "JKL" , "MNO" , "PRS" , "TUV" , "WXY" };
    int phoneNumber[ 7 ] = { 0 };
    int i , j , k , l , m , n , o;
    FILE *fPtr;

    printf( "Enter 7 digit phone number\n" );

    for ( i = 0; i < sizeof( phoneNumber ) / sizeof( phoneNumber[0] ) ; ++i ){
        printf( "?:" );
        scanf( "%d" , &phoneNumber[ i ] );

        while ( phoneNumber[ i ] < 2 || phoneNumber[ i ] > 9 ){
            printf( "invalid number, enter number between 2 - 9\n" );
            printf( "?:" );
            scanf( "%d" , &phoneNumber[ i ] );
        }
    }


    if ( ( fPtr = fopen( "phoneNoGenerator.txt" , "w" ) ) == NULL ){
        printf( "file could not be opened\n" );
    }else{
        for ( i = 0; i <=2; ++i ){
            for ( j = 0; j <= 2; ++j ){
                for ( k = 0; k <= 2; ++k ){
                    for ( l = 0; l <= 2; ++l ){
                        for ( m = 0; m <= 2; ++m ){
                            for ( n = 0; n <= 2; ++n ){
                                for ( o = 0; o <= 2; ++o ){
                                    fprintf( fPtr , "%c%c%c%c%c%c%c\n" ,
                                    phoneWord[ phoneNumber[0] ][ i ] ,
                                    phoneWord[ phoneNumber[1] ][ j ] ,
                                    phoneWord[ phoneNumber[2] ][ k ] ,
                                    phoneWord[ phoneNumber[3] ][ l ] ,
                                    phoneWord[ phoneNumber[4] ][ m ] ,
                                    phoneWord[ phoneNumber[5] ][ n ] ,
                                    phoneWord[ phoneNumber[6] ][ o ] );
                                }
                            }
                        }

                    }
                }

            }
        }
    }

    fprintf( fPtr , "phone number: " );

    for ( i = 0; i < sizeof( phoneNumber ) / sizeof( phoneNumber[0] ); ++i ){
        fprintf( fPtr , "%d" , phoneNumber[ i ] );
    }




    return 0;
}
