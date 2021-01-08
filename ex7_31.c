#include <stdio.h>

void add( double n1 , double n2 );
void subtract( double n1 , double n2 );
void multiply( double n1 , double n2 );
void divide( double n1 , double n2 );
void promptUser( void );

int main( void )
{
    double num1 , num2;
    int choice;
    void ( *operation[] )( double n1 , double n2 ) = { add , subtract , multiply , divide };

    printf( "Enter first number: " );
    scanf( "%lf" , &num1 );
    printf( "Enter second number: " );
    scanf( "%lf" , &num2 );

    promptUser();
    scanf( "%d" , &choice );

    while ( choice != 4 ){
        if ( choice >= 0 && choice <= 3 ){
            ( *operation[ choice ] )( num1 , num2 );
        }
        printf( "Enter first number: " );
        scanf( "%lf" , &num1 );
        printf( "Enter second number: " );
        scanf( "%lf" , &num2 );

        promptUser();
        scanf( "%d" , &choice );
    }

    return 0;
}

void add( double n1 , double n2 )
{
    printf( "%.3lf + %.3lf = %.3lf\n" , n1 , n2 , n1 + n2 );
}

void subtract( double n1 , double n2 )
{
    printf( "%.3lf - %.3lf = %.3lf\n" , n1 , n2 , n1 - n2 );
}

void multiply( double n1 , double n2 )
{
    printf( "%.3lf x %.3lf = %.3lf\n" , n1 , n2 , n1 * n2 );
}

void divide( double n1 , double n2 )
{
    printf( "%.3lf / %.3lf = %.3lf\n" , n1 , n2 , n1 / n2 );
}

void promptUser( void )
{
    printf( "0 Add\n1 Subtract\n2 Multiply\n3 Divide\n4 End\n" );
}
