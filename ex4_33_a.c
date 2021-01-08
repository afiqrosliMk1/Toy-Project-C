//roman numeral
#include <stdio.h>

int main( void )
{
    int number , divisor , count , n , i , j;
    for ( j = 1 , number = j; j <= 1000; j++ , number = j , count = 1 , divisor = 1000 ){
        printf( "%d\t" , j );

        while ( number > 0 ){
            n = number / divisor;
            for ( i = 1; i <= n; i++ ){
                if ( divisor == 1000 ){
                    printf( "M" );
                }else if ( divisor == 900 ){
                    printf( "CM" );
                }else if ( divisor == 500 ){
                    printf( "D" );
                }else if ( divisor == 400 ){
                    printf( "CD" );
                }else if ( divisor == 100 ){
                    printf( "C" );
                }else if ( divisor == 90 ){
                    printf( "XC" );
                }else if ( divisor == 50 ){
                    printf( "L" );
                }else if ( divisor == 40 ){
                    printf( "XL" );
                }else if ( divisor == 10 ){
                    printf( "X" );
                }else if ( divisor == 9 ){
                    printf( "IX" );
                }else if ( divisor == 5 ){
                    printf( "V" );
                }else if ( divisor == 4 ){
                    printf( "IV" );
                }else if ( divisor == 1 ){
                    printf( "I" );
                }
            }//end for
            count++;
            number %= divisor;
            if ( count == 1 ){
                divisor = 1000;
            }else if ( count == 2 ){
                divisor = 900;
            }else if ( count == 3 ){
                divisor = 500;
            }else if ( count == 4 ){
                divisor = 400;
            }else if ( count == 5 ){
                divisor = 100;
            }else if ( count == 6 ){
                divisor = 90;
            }else if ( count == 7 ){
                divisor = 50;
            }else if ( count == 8 ){
                divisor = 40;
            }else if ( count == 9 ){
                divisor = 10;
            }else if ( count == 10 ){
                divisor = 9;
            }else if ( count == 11 ){
                divisor = 5;
            }else if ( count == 12 ){
                divisor = 4;
            }else if ( count == 13 ){
                divisor = 1;
            }//end if
        }
        printf( "\n" );

    }//end of outermost for


    return 0;
}
