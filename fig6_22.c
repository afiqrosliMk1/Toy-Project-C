#include <stdio.h>
#define STUDENT 3
#define EXAM 4

int minimum( int b[][ EXAM ] );
int maximum( int b[][ EXAM ] );
float average( int b[] );

int main( void )
{
    int studentGrade[ STUDENT ][ EXAM ] = { { 80 , 75 , 90 , 88 } , { 50 , 20 , 30 , 40  } , { 60 , 70 , 66 , 80 } };
    int i;

    printf( "%d\n" , minimum( studentGrade ) );
    printf( "%d\n" , maximum( studentGrade ) );
    for ( i = 0; i < STUDENT; ++i ){
        printf( "%.2f\n" , average( studentGrade[ i ] ) );
    }

    return 0;
}

int minimum( int b[][ EXAM ] )
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
    return min;
}

int maximum( int b[][ EXAM ] )
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
    return max;
}

float average( int b[] )
{
    int j;
    int total = 0;

    for ( j = 0; j < EXAM; ++j ){
        total += b[ j ];
    }// for j

    return (float)total / EXAM;

}
