#include <stdio.h>

int main( void )
{
    int counts[ 10 ] = { 0 };
    int bonus[ 15 ] = { 0 };
    for ( int i = 0; i < 15; ++i ){
        bonus[ i ] += 1;
    }
    float monthlyTemperatures[ 13 ];
    //for ( int j = 1; j < 13; ++j ){
    //    scanf( "%f" , &monthlyTemperatures[ j ] );
    //}
    int bestScores[ 5 ] = { 100 , 88 , 75 , 70 , 69 };
    for ( int k = 0; k < 5; ++k ){
        printf( "%4d" , bestScores[ k ] );
    }
    return 0;
}

