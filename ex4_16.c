#include <stdio.h>

int main( void )
{
    int i , n;
    for ( n = 1; n <= 10; n++ ){
        for ( i = 1; i <= n; i++ ){
            printf( "*" );
        }
        printf( "\n" );
    }

    for ( n = 10; n >= 1; n-- ){
        for ( i = 1; i <= n; i++ ){
            printf( "*" );
        }
        printf( "\n" );
    }

    for ( n = 1; n <= 10; n++ ){
        for ( i = 1; i <= 10; i++ ){
            if ( i < n ){
                printf( " " );
            }else{
                printf( "*" );
            }
        }
        printf( "\n" );
    }

    for ( n = 1; n <= 10; n++ ){
        for ( i = 1; i <= 10; i++ ){
            if ( i > 10 - n ){
                printf( "*" );
            }else{
                printf( " " );
            }
        }
        printf( "\n" );
    }
    return 0;
}
