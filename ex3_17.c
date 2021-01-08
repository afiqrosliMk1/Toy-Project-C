#include <stdio.h>

int main( void )
{
    float gallons , miles_per_gallon = 0 , total_gallons = 0;
    int miles , total_miles = 0;

    printf( "Enter gallons used: " );
    scanf( "%f" , &gallons );
    while ( gallons != EOF ){
        if ( gallons >= 0 ){
            printf( "Enter miles travelled: " );
            scanf( "%d" , &miles );
            miles_per_gallon = miles / gallons;
            printf( "Miles / gallon for this tank was: %f" , miles_per_gallon );
            total_gallons = total_gallons + gallons;
            total_miles = total_miles + miles;
        } else {
            printf( "Invalid value" );
        }

        printf( "\n\nEnter gallons used: " );
        scanf( "%f" , &gallons );
    }

    printf( "\n\nAverage miles / gallon = %f \n\n" , total_miles / total_gallons );


    return 0;
}
