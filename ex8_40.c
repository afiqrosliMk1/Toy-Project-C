#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main( void )
{
    char *keyword[] = { "millimeter" , "inches" , "kilogram" , "pound" };
    char text[ 80 ] = "how many pound in 2.2 kilogram?";
    int i;
    char *posPtr = NULL;
    const char *keyword1;
    const char *keyword2;
    int kw1;
    int kw2;
    double magnitude;
    int temp;
    double value;

    printf( "%s\n" , text );

    //search for first keyword
    for ( i = 0; i < 4; ++i ){
        posPtr = strstr( text , keyword[ i ] );
        if ( posPtr != NULL ){ //means strstr found a match
            keyword1 = posPtr;
            kw1 = i; //save the subscript
            i = 5; //break the loop
        }
    }

    //search for second keyword
    for ( i = 0; i < 4; ++i ){
        posPtr = strstr( text , keyword[ i ] );
        if ( posPtr != NULL && posPtr != keyword1 ){
            keyword2 = posPtr;
            kw2 = i;
            i = 5; //break the loop
        }
    }

    //determine which word occurs first
    if ( keyword1 > keyword2 ){
        temp = kw1;
        kw1 = kw2;
        kw2 = temp;
    }

    //search for magnitude
    for ( i = 0; !isdigit( text[ i ] ); ++i ){ //search for first occurrence of a digit
        ;
    }
    posPtr = text + i; //save pointer to the first element which is a digit

    //printf( "i = %d\n" , i );
    printf( "%s\n" , posPtr );

    magnitude = strtod( posPtr , NULL ); //convert string starting from number, to long int


    printf( "kw1 = %s\nkw2 = %s\nmagnitude = %lf\n" , keyword[ kw1 ] , keyword[ kw2 ] , magnitude );

    //conversion happens...
    if ( kw1 == 2 && kw2 == 3 ){
        value = magnitude * 2.2;
    }else if ( kw1 ==3 && kw2 == 2 ){
        value = 2.2 / magnitude;
    }else{
        printf( "--invalid conversion--\n" );
    }

    printf( "%lf %s\n" , value , keyword[ kw1 ] );

    return 0;
}
