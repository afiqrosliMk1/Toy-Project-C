#include <stdio.h>

int main()
{
    int grade;
    int total = 0;
    int counter = 10;
    int average;

    while( counter >= 1 ){
        printf( "Enter grade: " );
        scanf( "%d" , &grade );
        total = total + grade;
        counter--;
    }

    average = total / 10;
    printf( "Class average: %d" , average );
    return 0;
}
