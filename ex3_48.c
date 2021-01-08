#include <stdio.h>

int main( void )
{
    int birthYear , birthMonth , birthDay;
    int currentYear , currentMonth , currentDay;
    int age , maxHeartRate , rangeMax , rangeMin;

    printf( "Insert birth Year: " );
    scanf( "%d" , &birthYear );
    printf( "Insert birth Month: " );
    scanf( "%d" , &birthMonth );
    printf( "Insert birth Day: " );
    scanf( "%d" , &birthDay );

    printf( "Insert current Year: " );
    scanf( "%d" , &currentYear );
    printf( "Insert current Month: " );
    scanf( "%d" , &currentMonth );
    printf( "Insert current Day: " );
    scanf( "%d" , &currentDay );

    age = currentYear - birthYear;
    maxHeartRate = 220 - age;
    rangeMin = 0.5 * maxHeartRate;
    rangeMax = 0.85 * maxHeartRate;

    printf( "Age = %d" , age );
    printf( "\nMaximum heart rate = %d" , maxHeartRate );
    printf( "\nTarget heart rate range = %d - %d" , rangeMin , rangeMax );

    return 0;
}
