//polling
#include <stdio.h>

#define RESPONSE_SIZE 11

void polling( int wResponse[][ RESPONSE_SIZE ] , const char *wTopics[] , int *const counter );
void promptUser( void );
void printResult( int wResponse[][ RESPONSE_SIZE ] , const char *wTopics[] );
void resetPoll( int wResponse[][ RESPONSE_SIZE ] , int *counter );
void currentCount( int *const wCount );
void printAverage( int wResponse[] , int size , int point[] );
void printHighest( int a[] , const char *wTopics[] );
void printLowest( int a[] , const char *wTopics[] );

int main( void )
{
    const char *topics[ 5 ] = { "Politics" , "Religion" , "Economy" , "Sports" , "Knowledge" };
    int response[ 5 ][ RESPONSE_SIZE ] = { 0 };
    int choice;
    static int count = 0;

    promptUser();
    scanf( "%d" , &choice );

    while ( choice != -1 ){
        if ( choice == 0 ){
            polling( response , topics , &count );
        }else if ( choice == 1 ){
            printResult( response , topics );
        }else if ( choice == 2 ){
            resetPoll( response , &count );
        }
        promptUser();
        scanf( "%d" , &choice );
    }

    return 0;
}

void polling( int wResponse[][ RESPONSE_SIZE ] , const char *wTopics[] , int *const counter )
{
    int rating;
    int i;

    *counter += 1;
    currentCount( counter );
    for ( i = 0; i < 5; ++i ){
        printf( "Enter 1-10 for %s :" , wTopics[ i ] );
        scanf( "%d" , &rating );
        ++wResponse[ i ][ rating ];
    }
}

void promptUser( void )
{
    printf( "What you would like to do?\n"
           "0 Vote poll\n1 Print result\n"
           "2 Reset poll\n"
           "-1 to end\n" );
}

void printResult( int wResponse[][ RESPONSE_SIZE ] , const char *wTopics[] )
{
    int i , j;
    int totalPoints[ 5 ] = { 0 };

    printf( "          1  2  3  4  5  6  7  8  9  10 Average\n" );

    for ( i = 0; i < 5 ; ++i ){
            printf( "%-10s" , wTopics[ i ] );
        for ( j = 1; j < RESPONSE_SIZE; ++j ){
            printf( "%-3d" , wResponse[ i ][ j ] );
        }
        printAverage( wResponse[ i ] , RESPONSE_SIZE , &totalPoints[ i ] );
        printf( "\n" );
    }printf( "\n" );

    //just to show the total points array
    for ( i = 0; i < 5; ++i ){
        printf( "%3d" , totalPoints[ i ] );
    }printf( "\n" );

    printHighest( totalPoints , wTopics );
    printLowest( totalPoints , wTopics );
}

void resetPoll( int wResponse[][ RESPONSE_SIZE ] , int* counter )
{
    int i , j;

    for ( i = 0; i < 5; ++i ){
        for ( j = 0; j < RESPONSE_SIZE; ++j ){
            wResponse[ i ][ j ] = 0;
        }
    }
    *counter = 0;
}

void currentCount( int *const wCount )
{
    printf( "# person taken part: %d\n" , *wCount );
}

void printAverage( int wResponse[] , int size , int point[] )
{
    int totalPoint = 0;
    int totalFrequency = 0;
    int i;
    float average;

    for ( i = 1; i < size; ++i ){
        totalFrequency += wResponse[ i ];
        totalPoint += i * wResponse[ i ];
    }

    *point = totalPoint;

    average = ( float )totalPoint / totalFrequency;
    if ( totalFrequency != 0 ){
        printf( "%f" , average );
    }else{
        printf( "Zero frequency" );
    }
}

void printHighest( int a[] , const char *wTopics[] )
{
    int highest = 0;
    int i;
    int index = 0;

    for ( i = 0; i < 5; ++i ){
        if ( a[ i ] > highest ){
            highest = a[ i ];
            index = i;
        }
    }
    printf( "%s has the highest total points: %d\n" , wTopics[ index ] , highest );
}

void printLowest( int a[] , const char *wTopics[] )
{
    int lowest = 15000;
    int i;
    int index = 0;

    for ( i = 0; i < 5; ++i ){
        if ( a[ i ] < lowest ){
            lowest = a[ i ];
            index = i;
        }
    }
    printf( "%s has the lowest total points: %d\n" , wTopics[ index ] , lowest );
}

