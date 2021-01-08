#include <stdio.h>

int my_isdigit( int c );
int my_isalpha( int c );
int my_isalphanum( int c );
int my_isxdigit( int c );
int my_islower( int c );
int my_isupper( int c );
int my_tolower( int c );
int my_toupper( int c );
int my_isspace( int c );
int my_iscntrl( int c );
int my_ispunct( int c );
int my_isprint( int c );
int my_isgraph( int c );

int main( void )
{
    char a[ 2 ] = "";
    int r; //value returned by function

    printf( "Enter a character: " );
    scanf( "%c" , &a[ 0 ] );

    r = my_isdigit( a[ 0 ] );
    printf( "According to my_isdigit() , %c %s" , a[ 0 ] , r != 0 ? "is a digit\n" : "is not a digit\n" );

    r = my_isalpha( a[ 0 ] );
    printf( "According to my_isalpha() , %c %s" , a[ 0 ] , r != 0 ? "is a letter\n" : "is not a letter\n" );

    r = my_isalphanum( a[ 0 ] );
    printf( "According to my_isalphanum() , %c %s" , a[ 0 ] , r != 0 ? "is a digit or a letter\n" : "is not a digit nor a letter\n" );

    r = my_isxdigit( a[ 0 ] );
    printf( "According to my_isxdigit() , %c %s" , a[ 0 ] , r != 0 ? "is a hexadecimal digit\n" : "is not a hexadecimal digit\n" );

    r = my_islower( a[ 0 ] );
    printf( "According to my_islower() , %c %s" , a[ 0 ] , r != 0 ? "is a lowercase letter\n" : "is not a lowercase letter\n" );

    r = my_isupper( a[ 0 ] );
    printf( "According to my_isupper() , %c %s" , a[ 0 ] , r != 0 ? "is an uppercase letter\n" : "is not an uppercase letter\n" );

    r = my_tolower( a[ 0 ] );
    printf( "According to my_tolower() , %c %s" , r , r != a[ 0 ] ? "has been converted to lowercase\n" : "is unchanged\n" );

    r = my_toupper( a[ 0 ] );
    printf( "According to my_toupper() , %c %s" , r , r != a[ 0 ] ? "has been converted to uppercase\n" : "is unchanged\n" );

    r = my_isspace( a[ 0 ] );
    printf( "According to my_isspace() , %c %s" , a[ 0 ] , r != 0 ? "is a white-space character\n" : "is not a white-space character\n" );

    r = my_iscntrl( a[ 0 ] );
    printf( "According to my_iscntrl() , %c %s" , a[ 0 ] , r != 0 ? "is a control character\n" : "is not a control character\n" );

    r = my_ispunct( a[ 0 ] );
    printf( "According to my_ispunct() , %c %s" , a[ 0 ] , r != 0 ? "is a punctuation character\n" : "is not a punctuation character\n" );

    r = my_isprint( a[ 0 ] );
    printf( "According to my_isprint() , %c %s" , a[ 0 ] , r != 0 ? "is a printing character\n" : "is not a printing character\n" );

    r = my_isgraph( a[ 0 ] );
    printf( "According to my_isgraph() , %c %s" , a[ 0 ] , r != 0 ? "is a printing character other than space\n" : "is not a printing character other than space\n" );

    return 0;
}

int my_isdigit( int c )
{
    return ( c >= 48 && c <= 57 );
}

int my_isalpha( int c )
{
    return ( ( c >= 65 && c <= 90 ) || ( c >= 97 && c <= 122 ) );
}

int my_isalphanum( int c )
{
    return ( ( c >= 65 && c <= 90 ) || ( c >= 97 && c <= 122 ) || ( c >= 48 && c <= 57 ) );
}

int my_isxdigit( int c )
{
    return ( ( c >= 65 && c <= 70 ) || ( c >= 48 && c <= 57 ) || ( c >= 97 && c <= 102 ) );
}

int my_islower( int c )
{
    return ( c >= 97 && c <= 122 );
}

int my_isupper( int c )
{
    return ( c >= 65 && c <= 90 );
}

int my_tolower( int c )
{
    if ( ( c >= 65 && c <= 90 ) ){
        return c + 32;
    }else{
        return c;
    }
}

int my_toupper( int c )
{
    if ( c >= 97 && c <= 122 ){
        return c - 32;
    }else{
        return c;
    }
}

int my_isspace( int c )
{
    if ( c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v' ){
        return 1;
    }else{
        return 0;
    }
}

int my_iscntrl( int c )
{
    if ( c == '\a' || c == '\b' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v' ){
        return 1;
    }else{
        return 0;
    }
}

int my_ispunct( int c )
{
    if ( ( c >= 33 && c <= 47 ) || ( c >= 58 && c <= 64 ) || ( c >= 91 && c <= 96 ) || ( c >= 123 && c <= 126 ) ){
        return 1;
    }else{
        return 0;
    }
}

int my_isprint( int c )
{
    if ( c >= 32 && c <= 126 ){
        return 1;
    }else{
        return 0;
    }
}

int my_isgraph( int c )
{
    if ( c >= 33 && c <= 126 ){
        return 1;
    }else{
        return 0;
    }
}
