//online reservation system
#include <stdio.h>
void printSeat( const int seatingArray[] , int totalSeating );
int totalPassenger( const int seatingArray[] , int totalSeating );
void printBoardingPass( int seatClass , int seatNumber );

int main( void )
{
    int seat[ 11 ] = { 0 };
    int flightClass , i = 1;
    int sum;

    printf( "Please type 1 for first class\n" );
    printf( "Please type 2 for economy class\n" );
    printf( "EOF to end\n" );
    scanf( "%d" , &flightClass );

    while ( flightClass != EOF ){
        if ( flightClass == 1 ){
            i = 1;
            while ( flightClass != 0 && i <= 5 ){
                if ( seat[ i ] == 0 ){
                    seat[ i ] = 1;
                    printBoardingPass( flightClass , i );
                    flightClass = 0;
                }else{
                    ++i;
                }
                if ( i == 6 ){
                    printf( "-----No seat available-----\n" );
                }
            }//end while

        }else if ( flightClass == 2 ){
            i = 1;
            while ( flightClass != 0 && i <= 10 ){
                if ( seat[ i + 5 ] == 0 ){
                    seat[ i + 5 ] = 1;
                    printBoardingPass( flightClass , i + 5 );
                    flightClass = 0;
                }else{
                    ++i;
                }
                if ( i == 10 ){
                    printf( "-----No seat available-----\n" );
                }
            }//end while
        }
        printf( "Please type 1 for first class\n" );
        printf( "Please type 2 for economy class\n" );
        printf( "EOF to end\n" );
        scanf( "%d" , &flightClass );

        sum = totalPassenger( seat , 11 );
        if ( sum == 10 ){
            printf( "-----Next flight in 3 hours-----\n" );
            flightClass = EOF;
        }
    }

    printSeat( seat , 11 );
    return 0;
}

void printSeat( const int seatingArray[] , int totalSeating )
{
    int i;
    for ( i = 1; i < totalSeating; ++i ){
        printf( "%3d" , seatingArray[ i ] );
    }
}

int totalPassenger( const int seatingArray[] , int totalSeating )
{
    int j , total = 0;
    for ( j = 1; j < totalSeating; ++j ){
        total += seatingArray[ j ];
    }
    return total;
}

void printBoardingPass( int seatClass , int seatNumber )
{
    printf( "===============\n" );
    printf( "BOARDING PASS\n" );
    printf( "===============\n" );
    printf( "Seat Number: %d\n" , seatNumber );
    if ( seatClass == 1 ){
        printf( "First Class\n" );
    }else{
        printf( "Economy Class\n" );
    }printf( "===============\n" );

}
