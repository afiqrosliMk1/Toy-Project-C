#include <stdio.h>
#include <math.h>

float parkingCharges( float hour );

int main( void )
{
    float hourParked1 , hourParked2 , hourParked3;
    float charge1 , charge2 , charge3;
    float totalHour , totalCharges;

    printf( "Enter parking hours for\n" );
    printf( "Customer 1 : " );
    scanf( "%f" , &hourParked1 );
    printf( "Customer 2 : " );
    scanf( "%f" , &hourParked2 );
    printf( "Customer 3 : " );
    scanf( "%f" , &hourParked3 );

    charge1 = parkingCharges( hourParked1 );
    charge2 = parkingCharges( hourParked2 );
    charge3 = parkingCharges( hourParked3 );

    printf( "Car\tHours\tCharge\n" );
    printf( "1\t%.1f\t%.2f\n" , hourParked1 , charge1 );
    printf( "2\t%.1f\t%.2f\n" , hourParked2 , charge2 );
    printf( "3\t%.1f\t%.2f\n" , hourParked3 , charge3 );

    totalHour = hourParked1 + hourParked2 + hourParked3;
    totalCharges = charge1 + charge2 + charge3;
    printf( "TOTAL\t%.1f\t%.2f\n" , totalHour , totalCharges );

    return 0;
}

float parkingCharges( float hour )
{
    float charges;
    if ( hour >= 3 ){
        charges = 2 + ceil( hour - 3 ) * 0.5; // RM0.50 for next hour after 3 hours
    }else{
        charges = 2; // RM2 per hour for max 3 hour
    }
    if ( charges > 10 ){
        charges = 10;
    }
    return charges;
}
