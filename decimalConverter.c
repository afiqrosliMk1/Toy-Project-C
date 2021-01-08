#include <stdio.h>
#include <math.h>
int main( void )
{
    int decimalNumber = 110 , binaryNumber = 0 , octalNumber = 0 , hexNumber = 0 , intermediate;
    int i , m , n , number;
    //=========================binary==================================
    for ( i = 1 , intermediate = decimalNumber; intermediate != 0; intermediate /= 2 , i *= 10 ){
        binaryNumber += intermediate % 2 * i;
    }

    printf( "%d\n" , binaryNumber );
    //============================octal================================

    for ( i = 1 , intermediate = decimalNumber; intermediate != 0; i *= 10 , intermediate /= 8 ){
        octalNumber += intermediate % 8 * i;
    }

    printf( "%d\n" , octalNumber );

    //=============================hex========================
    intermediate = decimalNumber;
    for ( i = 1; intermediate != 0; intermediate /= 16 , i *= 100 ){
        hexNumber += intermediate % 16 * i;
    }
    //printf( "%d\n" , hexNumber );

    for ( m = 0; pow( 10 , m ) <= hexNumber; m += 2 ){
    }n = m - 2;

    while ( n >= 0 ){
        number = hexNumber / (int)( pow( 10 , n ) + 0.5 ); //number is the 2 digit that is picked off from hexNumber
        if ( number == 10 ){
            printf( "A" );
        }else if ( number == 11 ){
            printf( "B" );
        }else if ( number == 12 ){
            printf( "C" );
        }else if ( number == 13 ){
            printf( "D" );
        }else if ( number == 14 ){
            printf( "E" );
        }else if ( number == 15 ){
            printf( "F" );
        }else{
            printf( "%d" , number );
        }
        hexNumber %= (int)( pow( 10 , n ) + 0.5 );
        n -= 2;
    }

    return 0;
}

