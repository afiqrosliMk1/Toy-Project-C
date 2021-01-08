#include <stdio.h>
#include <string.h>

void my_strcpy( char *s1 , const char *s2 );
void my_strncpy( char *s1 , const char *s2 , int n );
void my_strcat( char *s1 , char *s2 );
void my_strncat( char *s1 , char *s2 , int n );

int main( void )
{
    char x[] = "Selamat Hari Raya";
    char y[ 20 ];
    char z[ 20 ];

    char stringA[ 20 ] = "Selamat ";
    char stringB[] = "Hari Raya";
    char stringC[] = "";

    my_strcpy( y , x );
    printf( "After my_strcpy() , y = %s\n" , y );

    my_strncpy( z , x , 7 );
    z[ 7 ] = '\0';
    printf( "After my_strncpy() , z = %s\n" , z );

    my_strcat( stringA , stringB );
    printf( "stringA after my_strcat() = %s\n" , stringA );

    my_strncat( stringC , stringB , 4 );
    printf( "stringC after my_strncat() = %s\n" , stringC );

    return 0;
}

void my_strcpy( char *s1 , const char *s2 )
{
    int i;

    for ( i = 0; s2[ i ] != '\0'; ++i ){
        s1[ i ] = s2[ i ];
    }s1[ i ] = '\0';

}

void my_strncpy( char *s1 , const char *s2 , int n )
{
    int i;

    for ( i = 0; i <= n - 1; ++i ){
        s1[ i ] = s2[ i ];
    }s1[ i ] = '\0';
}

void my_strcat( char *s1 , char *s2 )
{
    int i = 0;
    int j;

    while ( s1[ i ] != '\0' ){
        ++i;
    }

    for ( j = 0; s2[ j ] != '\0'; ++j , ++i ){
        s1[ i ] = s2[ j ];
    }s1[ i ] = '\0';
}

void my_strncat( char *s1 , char *s2 , int n )
{
    int i = 0;
    int j;

    while ( s1[ i ] != '\0' ){
        ++i;
    }

    for ( j = 0; j <= n - 1; ++j , ++i ){
        s1[ i ] = s2[ j ];
    }s1[ i ] = '\0';
}
