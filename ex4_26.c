//estimating pi value
#include <stdio.h>

int main( void )
{
    int i , j , noOfTerms = 10000, term;
    float pi = 0;

    printf( "Term\tPi\n" );
    for ( term = 1 , j  = 1; term <= noOfTerms; j += 2 , term++ ){
        if ( term % 2 != 0 ){
            i = 1;
        }else{
            i = -1;
        }
        pi += (float)4 / j * i;
        printf( "%d\t%f\n" , term , pi );
    }


    printf( "%f" , pi );
    return 0;
}
