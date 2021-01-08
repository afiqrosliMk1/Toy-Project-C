#include <stdio.h>

int my_strcmp_pointer( const char *s1 , const char *s2 );
int my_strcmp_subscript( const char *s1 , const char *s2 );

int main( void )
{
    char string1[] = "A";
    char string2[] = "Af";
    int val;
    int val2;

    val = my_strcmp_pointer( string1 , string2 );
    val2 = my_strcmp_subscript( string2 , string1 );

    printf( "%d\n" , val );
    printf( "%d\n" , val2 );

    return 0;
}

int my_strcmp_pointer( const char *s1 , const char *s2 )
{
    while ( *s1 != '\0' && *s2 != '\0' ){
        if ( *s1 == *s2 ){
            s1++;
            s2++;
        }else if ( *s1 < *s2 ){
            return -1;
        }else{
            return 1;
        }
    }//end while

    if ( *s1 == '\0' && *s2 == '\0' ){
        return 0;
    }else if ( *s1 == '\0' && *s2 != '\0' ){
        return -1;
    }else{
        return 1;
    }

    return 0;
}

int my_strcmp_subscript( const char s1[] , const char s2[] )
{
    int i = 0;

    while ( s1[ i ] != '\0' && s2[ i ] != '\0' ){
        if ( s1[ i ] == s2[ i ] ){
            ++i;
        }else if ( s1[ i ] < s2[ i ] ){
            return -1;
        }else{
            return 1;
        }
    }//end while

    if ( s1[ i ] == '\0' && s2[ i ] == '\0' ){
        return 0;
    }else if ( s1[ i ] == '\0' && s2[ i ] != '\0' ){
        return -1;
    }else{
        return 1;
    }

    return 0;
}
