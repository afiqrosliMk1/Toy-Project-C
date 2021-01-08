#include <stdio.h>

int main( void )
{
    double rate = 1.012; //growth rate
    int population = 75771304; //7577130400
    int year = 2019;
    int i;

    for ( i = 1; i <= 75; i++ ){
        printf( "%d\t" , year );
        printf( "%d\n" , population );
        year++;
        population *= rate;
    }

    return 0;
}
