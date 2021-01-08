//this is a recursive power function
#include <stdio.h>

int power( int base , int exponent );

int main( void )
{
    int x = 2 , y = 8;
    printf( "power( %d , %d) = %d\n" , x , y , power( x , y ) );

    return 0;
}

int power( int base , int exponent )
{
    if ( exponent == 1 ){
        return base;
    }else if ( exponent == 0){
        return 1;
    }else{
        return base * power ( base , exponent - 1 );
    }
}
