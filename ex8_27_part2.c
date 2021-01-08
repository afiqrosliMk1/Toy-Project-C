#include <stdio.h>
#include <ctype.h>

double my_strtod( char *str , char **endPtr );
long my_strtol( char *strPtr , char **endPtr ); //this is a simplified version of strtol that doesn't include base conversion
unsigned long my_strtoul( char *strPtr , char **endPtr );

int main( void )
{
    char sentence[] = " 998.8 10.2";
    char *sentencePtr = NULL;
    char *sentencePtr2 = NULL;
    char *sentencePtr3 = NULL;
    double d1;
    long n1;
    long m1;


    d1 = my_strtod( sentence , &sentencePtr );
    printf( "%f\n" , d1 );
    printf( "%s\n" , sentencePtr );

    n1 = my_strtol( sentence , &sentencePtr2 );
    printf( "%ld\n" , n1 );
    printf( "%s\n" , sentencePtr2 );

    m1 = my_strtoul( sentence , &sentencePtr3 );
    printf( "%ld\n" , m1 );
    printf( "%s\n" , sentencePtr3 );

    return 0;
}

double my_strtod( char *strPtr , char **endPtr )
{
    int i = 0;
    double value1 = 0;
    double value2 = 0;
    double value;
    int sign = 1;
    int coefficient = 1;

    while ( strPtr[ i ] == ' ' ){
        ++i;
    }

    if ( strPtr[ i ] == '-' ){
        sign = 1;
        ++i;
    }

    //add the numbers before decimal point
    for ( ; strPtr[ i ] != '.' && isdigit( strPtr[ i ] ); ++i ){
        value1 = value1 * 10 + strPtr[ i ] - '0';
    }++i;

    //add the numbers after decimal point
    for ( ; strPtr[ i ] != '\0' && isdigit( strPtr[ i ] ); ++i ){
        value2 = value2 * 10 + strPtr[ i ] - '0';
        coefficient *= 10;
    }

    if ( endPtr != NULL ){
        *endPtr = &strPtr[ i ];
    }

    value = value1 + value2 / coefficient;

    return value * sign;
}

long my_strtol( char *strPtr , char **endPtr )
{
    int i = 0;
    long value = 0;
    int sign = 1;

    while ( strPtr[ i ] == ' ' ){
        ++i;
    }

    if ( strPtr[ i ] == '-' ){
        sign = 1;
        ++i;
    }

    //add the numbers before decimal point
    for ( ; strPtr[ i ] != '.' && isdigit( strPtr[ i ] ); ++i ){
        value = value * 10 + strPtr[ i ] - '0';
    };

    if ( endPtr != NULL ){
        *endPtr = &strPtr[ i ];
    }

    return value * sign;
}

unsigned long my_strtoul( char *strPtr , char **endPtr )
{
    int i = 0;
    unsigned long value = 0;
    int sign = 1;

    while ( strPtr[ i ] == ' ' ){
        ++i;
    }

    if ( strPtr[ i ] == '-' ){
        sign = 1;
        ++i;
    }

    //add the numbers before decimal point
    for ( ; strPtr[ i ] != '.' && isdigit( strPtr[ i ] ); ++i ){
        value = value * 10 + strPtr[ i ] - '0';
    };

    if ( endPtr != NULL ){
        *endPtr = &strPtr[ i ];
    }

    return value * sign;
}
