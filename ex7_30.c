#include <stdio.h>

#define PI 3.142

void circumference( double r );
void areaCircle( double r );
void volumeSphere( double r );
void promptUser( void );

int main( void )
{
    double radius;
    int choice;
    void ( *selection[] )( double r ) = { circumference , areaCircle , volumeSphere };

    printf( "Enter radius: " );
    scanf( "%lf" , &radius );
    promptUser();
    scanf( "%d" , &choice );

    while ( choice != 3 ){
        if ( choice >= 0 && choice <= 3 ){
            ( *selection[ choice ] )( radius );
        }
        printf( "Enter radius: " );
        scanf( "%lf" , &radius );
        promptUser();
        scanf( "%d" , &choice );
    }//end while choice
}

void circumference( double r )
{
    printf( "Circumference = %f\n" , 2 * PI * r );
}

void areaCircle( double r )
{
    printf( "Area of circle = %f\n" , PI * r * r );
}

void volumeSphere( double r )
{
    printf( "Volume of sphere = %f\n" , (float)2 / 3 * PI * r * r * r );
}

void promptUser( void )
{
    printf( "0 circumference\n1 Area circle\n2 Volume sphere\n3 To End\n" );
}
