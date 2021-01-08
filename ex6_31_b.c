// this is the diy version of recursive palindrome
#include <stdio.h>

#define SIZE 80

void printChar( char s[] );
int testPalindrome( char a[] , int left , int right );

int main( void )
{
    char string[ SIZE ];
    char copyString[ SIZE ];
    int i , j = 0 , k = 0;
    int c;

    while ( (c = getchar() ) != '\n' ){
        string[ k ] = c;
        ++k;
    }
    string[ k ] = '\0';

    for ( i = 0; string[ i ] != '\0'; ++i ){
        if ( string[ i ] != ' ' ){
            copyString[ j ] = string[ i ];
            ++j;
        }
    }

    printChar( copyString );
    printf( "*" );

    if ( testPalindrome( copyString , 0 , j - 1 ) ){
        printf( "this is a palindrome" );
    }else{
        printf( "This is not a palindrome" );
    }

    return 0;
}

void printChar( char s[] )
{
    printf( "%s" , s );
}

int testPalindrome( char a[] , int left , int right )
{
    if ( left == right || left > right ){
        return 1;
    }else if ( a[ left ] != a[ right ] ){
        return 0;
    }else{
        return testPalindrome( a , left + 1 , right - 1 );
    }
}
