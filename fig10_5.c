#include <stdio.h>

union number {
    int x;
    double y;
};

int main( void )
{
    union number value; //define union variable

    value.x = 100; //put an integer into the union
    printf( "%s\n%s\n%s\n  %d\n\n%s\n  %f\n\n\n" ,
           "Put a value in the integer member" ,
           "and print both members." ,
           "int:" , value.x ,
           "double:" , value.y );

    value.y = 100.0; //put a double into the same union
    printf( "%s\n%s\n%s\n  %d\n\n%s\n  %f\n" ,
           "Put a value in the floating member" ,
           "and print both members." ,
           "int:" , value.x ,
           "double:" , value.y );

    return 0;
}
