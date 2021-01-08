#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main( void )
{
    char c = 'a';
    int x , y , z;
    double d ,e , f;
    char *ptr;
    char s1[ 100 ];
    char s2[ 100 ];

    printf( "original value of c = %c\n" , c );
    c = toupper( c );
    printf( "after toupper() = " );
    putchar( c );

    printf( "\n'%c' %s\n" , c , isdigit( c ) ? "is a digit" : "is not a digit" );

    printf( "\n%ld\n" , atol( "1234567" ) );

    printf( "\n%c %s\n" , c , iscntrl( c ) ? "is a control character" : "is not a control character" );

    printf( "\nEnter a line of text: \n" );
    fgets( s1 , 100 , stdin );
    puts( "\nLine of text stored in s1 is:" );
    puts( s1 );

    ptr = strrchr( s1 , c );

    printf( "\n%lf\n" , atof( "8.63582" ) );

    printf( "\n'%c' %s\n" , c , isalpha( c ) ? "is a letter" : "is not a letter" );

    printf( "enter a character to be placed into c: " );
    c = getchar();

    ptr = strstr( s1 , s2 );

    printf( "%c %s" , c , isprint( c ) ? "is a printing character" : "is not a printing character" );

    sscanf( "1.27 10.3 9.432" , "%lf%lf%lf" , &d , &e , &f );

    strcpy( s1 , s2 );

    ptr = strpbrk( s1 , s2 );

    printf( "\nstrcmp( s1 , s2 ) = \n" , strcmp( s1 , s2 ) );

    ptr = strchr( s1 , c );

    sprintf( s1 , "x:%7d\ny:%7d\nz:%7d\n" , x , y );

    strncat( s1 , s2 , 10 );

    printf( "%u" , strlen( s1 ) );

    printf( "%d" , atoi( "-21" ) );

    strtok( s2 , "," );

    return 0;
}
