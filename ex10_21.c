#include <stdio.h>
#include <time.h>

struct HealthProfile{
    char firstName[20];
    char lastName[20];
    struct{
        unsigned day;
        unsigned month;
        unsigned year;
    }dateOfBirth;
    float height;
    float weight;
};

void setHealthProfile( struct HealthProfile * patient );
void getBMI( struct HealthProfile patient );
void getHeartRate( struct HealthProfile patient );

int main( void )
{
    struct HealthProfile pt1;

    setHealthProfile( &pt1 );
    //getBMI( pt1 );
    getHeartRate( pt1 );

    return 0;
}

void setHealthProfile( struct HealthProfile * patient )
{
    printf( "Enter first name: " );
    scanf( "%s" , patient->firstName );

    printf( "Enter last name: " );
    scanf( "%s" , patient->lastName );

    printf( "Enter date of birth:\nDay: " );
    scanf( "%u" , &patient->dateOfBirth.day );

    printf( "month: " );
    scanf( "%u" , &patient->dateOfBirth.month );

    printf( "year: " );
    scanf( "%u" , &patient->dateOfBirth.year );

    printf( "height: " );
    scanf( "%f" , &patient->height );

    printf( "weight: " );
    scanf( "%f" , &patient->weight );
}

void getBMI( struct HealthProfile patient )
{
    float bmi , weight , height;
    /*printf( "insert weight(kg): " );
    scanf( "%f" , &weight );
    printf( "\ninsert height(m):" );
    scanf( "%f" , &height );*/
    weight = patient.weight;
    height = patient.height;

    bmi = weight / ( height * height );
    printf( "\nBMI: %.2f\n" , bmi );

    printf( "BMI VALUES\n" );
    printf( "Underweight : Less than 18.5\n" );
    printf( "Normal : Between 18.5 and 24.9\n" );
    printf( "Overweight : Between 25 and 29.9\n" );
    printf( "Obese : 30 or greater\n" );
}

void getHeartRate( struct HealthProfile patient )
{
    int birthYear , birthMonth , birthDay;
    int currentYear , currentMonth , currentDay;
    int age , maxHeartRate , rangeMax , rangeMin;
    time_t rawtime;
    struct tm *info;

    time( &rawtime );
    info = localtime( &rawtime );

    birthYear = patient.dateOfBirth.year;
    birthMonth = patient.dateOfBirth.month;
    birthDay = patient.dateOfBirth.day;

    currentYear = info->tm_year + 1900;
    currentMonth = info->tm_mon;
    currentDay = info->tm_mday;
    printf("year is: %d\n" , currentYear );

    age = currentYear - birthYear;
    maxHeartRate = 220 - age;
    rangeMin = 0.5 * maxHeartRate;
    rangeMax = 0.85 * maxHeartRate;

    printf( "Age = %d" , age );
    printf( "\nMaximum heart rate = %d" , maxHeartRate );
    printf( "\nTarget heart rate range = %d - %d" , rangeMin , rangeMax );
}
