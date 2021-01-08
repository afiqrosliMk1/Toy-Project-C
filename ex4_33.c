#include <stdio.h>

int main( void )
{
    int number = 150 , divisor , n , i , digit , count;


    while ( number > 9 ){
        if ( (number >= 1 && number <= 39) || ( (number >= 50 && number <= 89)) ){ //only for range 1-39 and 50-100
            count = 1;
            if ( count == 1 ){
                divisor = 50;
            }else if ( count == 2 ){
                divisor = 10;
            }else{
                divisor = 1;
            }//end of inner if
            n = number / divisor;
            for ( i = 1; i <= n; i++ ){
                if ( divisor == 50 ){
                    printf( "L" );
                }else if ( divisor == 10 ){
                    printf( "X" );
                }
            }//end of for
            number %= divisor;
            count++;

        }//end of outer if

        if ( (number >= 40 && number <= 49) ){ //only for range 40-49
            count = 1;
            if ( count == 1 ){
                divisor = 50;
            }else if ( count == 2 ){
                divisor = 10;
            }else{
                divisor = 1;
            }//end of inner if
            n = number / divisor;
            for ( i = 1; i <= n; i++ ){
                if ( divisor == 40 ){
                    printf( "XL" );
                }else if ( divisor == 10 ){
                    printf( "X" );
                }
            }//end of for
            number %= divisor;
            count++;
        }//end of outer if

        if ( (number >= 90 && number <= 99) ){ //only for range 90-99
            count = 1;
            if ( count == 1 ){
                divisor = 90;
            }else if ( count == 2 ){
                divisor = 10;
            }else{
                divisor = 1;
            }//end of inner if
            n = number / divisor;
            for ( i = 1; i <= n; i++ ){
                if ( divisor == 90 ){
                    printf( "XC" );
                }else if ( divisor == 10 ){
                    printf( "X" );
                }
            }//end of for
            number %= divisor;
            count++;
        }//end of outer if

        if ( (number >= 100 && number <= 399 ) ){ //only for range 100-390
            count = 1;
            if ( count == 1 ){
                divisor = 100;
            }else if ( count == 2 ){
                divisor = 90;
            }else if ( count == 3 ){
                divisor = 50;
            }else if ( count == 4 ){
                divisor = 40;
            }else if ( count == 5 ){
                divisor = 10;
            }else{
                divisor = 1;
            }//end of inner if
            n = number / divisor;
            for ( i = 1; i <= n; i++ ){
                if ( divisor == 100 ){
                    printf( "C" );
                }else if ( divisor == 90 ){
                    printf( "XC" );
                }else if ( divisor == 50 ){
                    printf( "L" );
                }else if ( divisor == 40 ){
                    printf( "XL" );
                }else if ( divisor == 10 ){
                    printf( "X" );
                }
            }//end of for
            number %= divisor;
            count++;
        }//end of outer if


    }//end of while
    if ( number < 10 ){ //printing the balance number...
        switch ( number ){
            case 1:
                printf( "I" );
                break;
            case 2:
                printf( "II" );
                break;
            case 3:
                printf( "III" );
                break;
            case 4:
                printf( "IV" );
                break;
            case 5:
                printf( "V" );
                break;
            case 6:
                printf( "VI" );
                break;
            case 7:
                printf( "VII" );
                break;
            case 8:
                printf( "VIII" );
                break;
            case 9:
                printf( "IX" );
                break;
        }//end of switch
    }//end of if
    return 0;
}//end of main
