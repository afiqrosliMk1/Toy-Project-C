// this program converts decimal integer into binary

#include <stdio.h>
#include <math.h>

int main( void )
{
    int decimalNumber = 1, binaryNumber, octalNumber, hexNumber = 0 , intermediate;
    int i , m , n , number;

    printf( "Decimal\tBinary\tOctal\tHexadecimal\n" );
    for ( ; decimalNumber <= 256; decimalNumber++ ){
        printf( "%d\t" , decimalNumber );
        //=========================binary==================================
        for ( i = 1 , binaryNumber = 0 , intermediate = decimalNumber; intermediate != 0; intermediate /= 2 , i *= 10 ){
            binaryNumber += intermediate % 2 * i;
        }
        printf( "%d\t" , binaryNumber );
        //============================octal================================
        for ( i = 1 , octalNumber = 0 , intermediate = decimalNumber; intermediate != 0; i *= 10 , intermediate /= 8 ){
            octalNumber += intermediate % 8 * i;
        }
        printf( "%d\t" , octalNumber );
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
        } //end while
        printf( "\n" );
    } //end outermost for







    return 0;
}
