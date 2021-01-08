#include <stdio.h>

int main( void )
{
    int hour;
    float rate , salary;

    printf( "Enter # of hours worked (-1 to end):" );
    scanf( "%d" , &hour );

    while( hour != EOF ){
        printf( "Enter hourly rate of the worker: " );
        scanf( "%f" , &rate );

        if ( hour > 40 ){
            salary = ( hour - 40 ) * 1.5 * rate + 40 * rate;
        }else{
            salary = hour * rate;
        }

        printf( "Salary is $%.2f" , salary );

        printf( "\n\nEnter # of hours worked (-1 to end):" );
        scanf( "%d" , &hour );
    }

    return 0;
}
