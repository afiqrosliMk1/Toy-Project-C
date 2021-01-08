#include <stdio.h>

int main( void )
{
    int number , reversed = 0 , remainder , original;

    printf( "Insert number to know if it is a palindrome: " );
    scanf( "%d" , &number );
    original = number;

    while ( number != 0 ){
        remainder = number % 10;
        number = number / 10;
        reversed = reversed * 10 + remainder;
    }

    if ( original == reversed ){
        printf( "yes it is a palindrome\n" );
    }else{
        printf( "no it is not\n" );
    }
    return 0;
}
