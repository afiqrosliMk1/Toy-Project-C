//implementation of getchar() with and without buffer, putchar() and puts()
#include <stdio.h>
#include <unistd.h>

int my_getchar( void );
int bgetchar(void);
int my_putchar( int c );
int my_puts( char *cPtr );

int main( void )
{
    char c;
    char s[ 100 ];
    char sentence[] = "Hello semua";
    int i = 0;

    while ( ( c = my_getchar() ) != '\n' ){
        s[ i++ ] = c;
    }
    s[ i ] = '\0';

    my_puts( s );
    my_puts( sentence );

    return 0;
}

int my_getchar( void )
{
    char a;

    return ( read( 0 , &a , 1 ) == 1 ) ? a : EOF;
}

int bgetchar(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) /* buffer is empty */
    {
        n = read( 0, buf, sizeof buf );
        bufp = buf;

    }
    //printf( "value of *bufp = %c\n" , *bufp );

    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int my_putchar( int c )
{
    write( 1 , &c , 1 );

    return c;
}

int my_puts( char *cPtr )
{
    int n;
    int i = 0;

    while ( cPtr[ i ] != '\0' ){
        ++i;
    }

    n = write( 1 , cPtr , i );
    write( 1 , "\n" , 1 );
    return n >= 0 ? n : EOF ;
}
