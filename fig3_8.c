#include <stdio.h>

int main( void )
{
    int grade;
    int total = 0;
    float average = 0;
    int counter = 0;

    printf( "Enter grade:" );
    scanf( "%d" , &grade );

    while ( grade != -1 ){
        total = total + grade;
        counter++;
        printf( "Enter grade: " );
        scanf( "%d" , &grade );
    }

    if ( counter > 0 ){
        average = (float)total / counter;
    }

    printf( "Average: %f" , average );
    printf( "\ncounter: %d" , counter );


    return 0;
}
