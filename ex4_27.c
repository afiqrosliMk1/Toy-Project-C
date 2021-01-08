//calculate all pythagoras triples <= 500 using brute force
#include <stdio.h>
#include <math.h>

int main( void )
{
    int a , b , h;

    printf( "a\tb\th\n" );

    for ( a = 1; a <= 500; a++ ){
        for ( b = 1; b <= 500; b++ ){
            for ( h = 1; h <= 500; h++ ){
                if ( (a % 3 == 0) && (b % 4 == 0) && ((int)(pow(a,2)+0.5) + (int)(pow(b,2)+0.5) == (int)(pow(h,2)+0.5)) ){
                    printf( "%d\t%d\t%d--------\n" , a , b , h );
                    continue;
                }
                if ( (a % 5 == 0) && (b % 12 == 0) && ((int)(pow(a,2)+0.5) + (int)(pow(b,2)+0.5) == (int)(pow(h,2)+0.5)) ){
                    printf( "%d\t%d\t%d*********\n" , a , b , h );
                    continue;
                }
                if ( (a % 8 == 0) && (b % 15 == 0) && ((int)(pow(a,2)+0.5) + (int)(pow(b,2)+0.5) == (int)(pow(h,2)+0.5)) ){
                    printf( "%d\t%d\t%d\n" , a , b , h );
                    continue;
                }
                if ( (a % 7 == 0) && (b % 24 == 0) && ((int)(pow(a,2)+0.5) + (int)(pow(b,2)+0.5) == (int)(pow(h,2)+0.5)) ){
                    printf( "%d\t%d\t%d%%%%%%\n" , a , b , h );
                    continue;
                }

            }
        }
    }


    return 0;
}
