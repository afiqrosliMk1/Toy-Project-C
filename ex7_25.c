#include <stdio.h>
#define STUDENT 3
#define EXAM 4

void printMinimum( int b[][ EXAM ] );
void printMaximum( int b[][ EXAM ] );
void printAverageEachStudent( int b[][ EXAM ] );
void printGrades( int b[][ EXAM ] );

int main( void )
{
    int studentGrade[ STUDENT ][ EXAM ] = { { 80 , 75 , 90 , 88 } , { 50 , 20 , 30 , 40  } , { 60 , 70 , 66 , 80 } };
    int choice;

    void (*f[ 4 ])( int b[][ EXAM ] ) = { printGrades , printMinimum , printMaximum , printAverageEachStudent };

    printf( "Enter a choice:\n" );
    printf( "0 Print the array of grades\n1 Find the minimum grade\n2 Find the maximum grade\n"
           "3 Print the average on all tests for each student\n4 End Program\n\n" );
    scanf( "%d" , &choice );

    while ( choice != 4 ){
        if ( choice >= 0 && choice <= 3 ){
            (*f[ choice ])( studentGrade );
        }

        printf( "Enter a choice:\n" );
        printf( "0 Print the array of grades\n1 Find the minimum grade\n2 Find the maximum grade\n"
           "3 Print the average on all tests for each student\n4 End Program\n\n" );
        scanf( "%d" , &choice );
    }

    return 0;
}

void printGrades( int b[][ EXAM ] )
{
    int i , j;

    for ( i = 0; i < STUDENT; ++i ){
        for ( j = 0; j < EXAM; ++j ){
            printf( "%3d" , b[ i ][ j ] );
        }printf( "\n" );
    }printf( "\n" );
}

void printMinimum( int b[][ EXAM ] )
{
    int min = 100; //set the min grade to highest possible
    int i , j;
    for ( i = 0; i < STUDENT; ++i ){
        for ( j = 0; j < EXAM; ++j ){
            if ( b[ i ][ j ] < min ){
                min = b[ i ][ j ];
            }
        }//for j
    }//for i
    printf( "%d\n" , min );
}

void printMaximum( int b[][ EXAM ] )
{
    int max = 0; //set the max grade to highest possible
    int i , j;
    for ( i = 0; i < STUDENT; ++i ){
        for ( j = 0; j < EXAM; ++j ){
            if ( b[ i ][ j ] > max ){
                max = b[ i ][ j ];
            }
        }// for j
    }//for i
    printf( "%d\n" , max );
}

void printAverageEachStudent( int b[][ EXAM ] )
{
    int i , j;
    int total = 0;

    for ( i = 0; i < STUDENT; ++i ){
        for ( j = 0; j < EXAM; ++j ){
            total += b[ i ][ j ];
        }
        printf( "Average for student %d = %f\n" , i , ( float )total / EXAM );
        total = 0;
    }
}
