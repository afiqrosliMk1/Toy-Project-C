#include <stdio.h>

int main( void )
{
    char character = 'A';
    char string[] = "This is a string";
    const char *stringPtr = "Hello semua";

    printf( "%c\n" , character );
    printf( "%s\n" , "Gapo?" );
    printf( "%s\n" , string );
    printf( "%s\n" , stringPtr );

    return 0;
}
