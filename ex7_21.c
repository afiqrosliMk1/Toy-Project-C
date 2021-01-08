#include <stdio.h>

int main( void )
{
    /*int value;
    int *number = &value;
    printf( "%d\n" , *number );*/

    /*float a;
    float *realPtr = &a;
    long *integerPtr;
    integerPtr = (long*)realPtr;
    printf( "&integerPtr = %p\n" , integerPtr );
    printf( "&realPtr = %p\n" , realPtr );*/

    /*int *x , y;
    x = &y;
    printf( "%d" , *x );*/

    /*char s[] = "this is a character array";
    char *count = s;
    for ( ; *count != '\0'; count++ ){
        printf( "%c" , *count );
    }; //REMEMBER! Array name cannot be incremented! Because it is constant pointer. To change it, assign the address of the
    //array name, ( or &s[ 0 ] to another pointer ) , then that pointer can be incremented */

    short *numPtr , result = 0;
    printf( "result = %d\n" , result );
    numPtr = &result;
    void *genericPtr  = numPtr;
    result = *( (short*)genericPtr ) + 7;
    printf( "result = %d\n" , result ); //result will be 7

    /*float x = 19.34;
    float *xPtr = &x;
    printf( "%f\n" , *xPtr );*/

    /*char *s = "abc";
    printf( "%s\n" , s );*/

    return 0;
}
