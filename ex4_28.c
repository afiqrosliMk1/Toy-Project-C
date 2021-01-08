#include <stdio.h>

int main( void )
{
    int code , pieces;
    float workHours, weeklySale;

    printf( "Enter paycode ( 1-Manager 2-Hourly Worker 3-Commission Worker 4-Pieceworker EOF-to end\n" );
    scanf( "%d" , &code );

    while ( code != EOF ){
        switch ( code ){
            case 1 :
                printf( "Manager\tRM%d\n" , 5000 );
                break;
            case 2 :
                printf( "Enter work hours:" );
                scanf( "%f" , &workHours );
                printf( "Hourly Worker\tRM%.2f\n" , ( 40 * 8 ) + ( workHours - 40 ) * 8 * 1.5 );
                break;
            case 3 :
                printf( "Enter weekly sale:" );
                scanf( "%f" , &weeklySale );
                printf( "Commission Worker\tRM%.2f\n" , 250 + 0.057 * weeklySale );
                break;
            case 4 :
                printf( "Enter number of pieces finished this week:" );
                scanf( "%d" , &pieces );
                printf( "Pieceworkers\tRM%.2f\n" , pieces * 2.5 );   //rate is RM2.50 per piece
                break;
        }
        printf( "Enter paycode: " );
        scanf( "%d" , &code );

    }

    return 0;
}
