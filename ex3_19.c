#include <stdio.h>

int main( void )
{
    float sales , salary;
    printf( "Enter sales in dollars (-1 to end):" );
    scanf( "%f" , &sales );

    while ( sales != EOF ){
        salary = 200 + 0.09 * sales;
        printf( "Salary is %.2f" , salary );

        printf( "\n\nEnter sales in dollars (-1 to end):" );
        scanf( "%f" , &sales );
    }

    return 0;
}
