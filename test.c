#include <stdio.h>
#include <string.h>

int main( void )
{
    char *aPtr[ 6 ] = { "to" , "be" , "or" , "not" , "to" , "be" };
    int wordCount[ 6 ] = { 0 };
    int pass;
    int i;

    for ( pass = 0; pass < 6; ++pass ){
        if ( aPtr[ pass ] != NULL ){
            ++wordCount[ pass ];
        }
        for ( i = pass + 1; i < 6; ++i ){
            if ( aPtr[ pass ] != NULL && aPtr[ i ] != NULL ){ //make sure both are not NULL before calling strcmp()
                if ( strcmp( aPtr[ pass ] , aPtr[ i ] ) == 0 ){
                    aPtr[ i ] = NULL;
                    ++wordCount[ pass ];
                }
            }
        }// end for i
    }//end for pass

    for ( i = 0; i < 6; ++i ){
        if ( aPtr[ i ] != NULL ){
            printf( "%-5s%5d\n" , aPtr[ i ] , wordCount[ i ] );
        }
    }printf( "\n" );

    return 0;
}
