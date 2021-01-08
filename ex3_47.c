#include <stdio.h>

int main( void )
{
    double annualGrowthRate = 1.08/100 + 1;
    long long worldPopulation = 7700000000; //7.7 billion
    int year = 1;

    printf( "current world population (2020): %lld\n" , worldPopulation );
    printf( "annual growth rate: %.5lf \n" , annualGrowthRate );


    while ( year <= 5 ){
        worldPopulation = annualGrowthRate * worldPopulation ;
        printf( "year %d: %lld\n" , 2020 + year , worldPopulation );
        year++;
    }
    return 0;
}
