#include <stdio.h>
//#include <stdlib.h>

double my_atof( char *sPtr );
int my_atoi( char *sPtr );
long my_atol( char *sPtr );

int main( void )
{
    char s[] = "-120";
    double f;
    int n;
    long m;

    f = my_atof( s );
    printf( "f = %lf\n" , f );

    n = my_atoi( s );
    printf( "n = %d\n" , n );

    m = my_atol( s );
    printf( "m = %ld\n" , m );

    //printf( "%d" , sizeof( m ) );

    return 0;
}

double my_atof( char *sPtr )
{
    int i = 0;
    int sign = 1;
    //int length = 0;
    //int number;
    double value = 0;
    //int coefficient = 1;

    //===***GOLDEN SAMPLE***===//
    //int h=( (s[0]-'0') + (s[1]-'0') + (s[2]-'0') + (s[3]-'0') ) ;

    /*while ( sPtr[ i ] != '\0' ){
        ++length;
        ++i;
    }

    for ( i = 0; i < length; ++i ){
        number = ( sPtr[ length - 1 - i ] - '0' ); //start adding from lowest order ( that is position == length - 1 )
        value += ( double )number * coefficient;
        coefficient *= 10;
    }*/
    if ( sPtr[ i ] == '-' ){
        sign = -1;
        ++i;
    }

    for ( ; sPtr[ i ] != '\0'; ++i ){
        value = value * 10 + sPtr[ i ] - '0';
    }

    return value * sign;
}

int my_atoi( char *sPtr )
{
    int value = 0;
    //int coefficient = 1;
    //int number;
    int i = 0;
    int sign = 1;
    //int length = 0;

    /*while ( sPtr[ i ] != '\0' ){
        ++length;
        ++i;
    }

    for ( i = 0; i < length; ++i ){
        number = sPtr[ length - 1 - i ] - '0';
        value += number * coefficient;
        coefficient *= 10;
    }*/

    if ( sPtr[ i ] == '-' ){
        sign = -1;
        ++i;
    }

    for ( ; sPtr[ i ] != '\0'; ++i ){
        value = value * 10 + sPtr[ i ] - '0';
    }

    return value * sign;
}

long my_atol( char *sPtr )
{
    long value = 0;
    int i = 0;
    int sign = 1;
    //int length = 0;
    //int number = 0;
    //int coefficient = 1;

    /*while ( sPtr[ i ] != '\0' ){
        ++length;
        ++i;
    }

    for ( i = 0; i < length; ++i ){
        number = sPtr[ length - 1 - i ] - '0';
        value += (long)number * coefficient;
        coefficient *= 10;
    }*/

    if ( sPtr[ i ] == '-' ){
        sign = -1;
        ++i;
    }

    for ( ; sPtr[ i ] != '\0'; ++i ){
        value = value * 10 + sPtr[ i ] - '0';
    }

    return value * sign;
}

