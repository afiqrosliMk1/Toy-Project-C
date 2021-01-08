//max allowable value is 999.99 dollars
#include <stdio.h>

int main( void )
{
    char *digits[ 10 ] = { "" , "One" , "Two" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine" };
    char *teens[ 10 ] = { "Tens" , "Eleven" , "Twelve" , "Thirteen" , "Fourteen" , "Fifteen" , "Sixteen" , "Seventeen" , "Eighteen" , "Nineteen" };
    char *tens[ 10 ] = { "" , "Ten" , "Twenty" , "Thirty" , "Fourty" , "Fifty" , "Sixty" , "Seventy" , "Eighty" , "Ninety" };
    char *hundreds[ 10 ] = { "" , "One Hundred" , "Two Hundred" , "Three Hundred" , "Four Hundred" , "Five Hundred" , "Six Hundred" , "Seven Hundred" ,
                            "Eight Hundred" , "Nine Hundred" };
    int dollars;
    int cents = 0;
    int value1;
    int value2;
    int value3;
    int temp;

    printf( "Enter the check amount (0.00 to 999.99): " );
    scanf( "%d.%d" , &dollars , &cents );

    if ( dollars < 10 ){
        printf( "%s " , digits[ dollars ] );
    }else if ( dollars < 20 ){
        printf( "%s " , teens[ dollars - 10 ] );
    }else{
        if ( dollars % 10 == 0 ){
            printf( "%s " , tens[ dollars / 10 ] );
        }else{
            value3 = dollars / 100;
            temp = dollars % 100;
            value1 = temp / 10;
            value2 = temp % 10;
            printf( "%s " , hundreds[ value3 ] );
            printf( "%s " , tens[ value1 ] );
            printf( "%s " , digits[ value2 ] );
        }
    }

    printf( "and " );
    printf( "%d/100" , cents );

    return 0;
}
