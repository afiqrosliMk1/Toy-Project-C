#include <stdio.h>

char *my_strcpy( char *s1 , const char *s2 );
char *my_strncpy( char *s1 , const char *s2 , int n );
char *my_strcat( char *s1 , char *s2 );
char *my_strncat( char *s1 , char *s2 , int n );

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

    my_strncat( stringC , stringB , 1 );
    printf( "stringC after my_strncat() = %s\n" , stringC );

    return 0;
}

char *my_strcpy( char *s1 , const char *s2 )
{
    char *temp;

    temp = s1;

    while ( *s2 != '\0' ){
        *s1 = *s2;
        ++s1;
        ++s2;
    }
    return temp;
}

char *my_strncpy( char *s1 , const char *s2 , int n )
{
    char *temp;

    temp = s1;

    while ( n > 0 ){
        *s1 = *s2;
        ++s1;
        ++s2;
        --n;
    }
    return temp;
}

char *my_strcat( char *s1 , char *s2 )
{
    char *temp = s1;

    while ( *s1 != '\0' ){
        ++s1;
    }

    for ( ; *s2 != '\0'; ++s1 , ++s2 ){
        *s1 = *s2;
    }*s1 = '\0';

    return temp;
}

char *my_strncat( char *s1 , char *s2 , int n )
{
    char *temp = s1;

    while ( *s1 != '\0' ){
        ++s1;
    }

    for ( ; n > 0; --n , ++s1 , ++s2 ){
        *s1 = *s2;
    }*s1 = '\0';

    return temp;
}
