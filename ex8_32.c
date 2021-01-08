#include <stdio.h>
#include <string.h>

void *my_memcpy( void *s1 , const void *s2 , size_t n );
void *my_memmove( void *s1 , const void *s2 , size_t n );
int my_memcmp( const void *s1 , const void *s2 , size_t n );
void *my_memchr( const void *s , int c , size_t n );
void *my_memset( void *s , int c , size_t n );
size_t my_strlen( const char *s );

int main( void )
{
    //char string1[ 20 ];
    char string2[] = "Hello";

    //my_memcpy( string1 , string2 , strlen( string2 ) + 1 );
    //my_memmove( string1 , string2 , strlen( string2 ) );

    //printf( "%s\n" , string1 );

    //printf( "%d\n" , my_memcmp( "Hello" , "Hell" , 7 ) );

    //printf( "%s\n" , my_memchr( string2 , 'e' , 5 ) );
    //printf( "%s\n" , my_memset( string2 , 'x' , 3 ) );
    printf( "length of string2 = %d\n" , ( int )my_strlen( string2 ) );

    return 0;
}

void *my_memcpy( void *s1 , const void *s2 , size_t n )
{
    int i = 0;
    char *cs1 = ( char * )s1;
    char *cs2 = ( char * )s2;

    while ( i < n ){
        cs1[ i ] = cs2[ i ];
        ++i;
    }

    return cs1;
}

void *my_memmove( void *s1 , const void *s2 , size_t n )
{
    char temp[ 1024 ];
    int i = 0;

    char *src = ( char * )s2;
    char *dest = ( char * )s1;

    for ( ; *src != '\0'; ++src , ++i ){
        temp[ i ] = *src;
    }temp[ i ] = '\0';

    for ( i = 0; i < n; ++i ){
        dest[ i ] = temp[ i ];
    }dest[ i ] = '\0';

    return dest;
}

int my_memcmp( const void *s1 , const void *s2 , size_t n )
{
    char *cs1 = ( char * )s1;
    char *cs2 = ( char * )s2;

    int i;

    for ( i = 1; i <= n; ++i , ++cs1 , ++cs2 ){
        if ( *cs1 > *cs2 ){
            return 1;
        }else if ( *cs1 < *cs2 ){
            return -1;
        }
    }
    return 0;
}

void *my_memchr( const void *s , int c , size_t n )
{
    char *string = ( char * )s;
    int i;

    for ( i = 1; i <= n; ++i , ++string ){
        if ( *string == ( unsigned char )c ){
            return string;
        }
    }
    return NULL;
}

void *my_memset( void *s , int c , size_t n )
{
    char *string = ( char * )s;
    int i;

    for ( i = 1 ; i <= n && *string != '\0'; ++string , ++i ){
        *string = ( unsigned char )c;
    }
    return s;
}

size_t my_strlen( const char *s )
{
    size_t i = 0;

    while ( *s != '\0' ){
        ++i;
        s++;
    }

    return i;
}
