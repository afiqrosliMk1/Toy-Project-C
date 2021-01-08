#include <stdio.h>
int qualityPoints( int grade );

int main( void )
{
    int marks = 0;
    while ( marks != EOF ){
        printf( "Enter marks: " );
        scanf( "%d" , &marks );
        printf( "Pointer: %d\n" , qualityPoints( marks ) );
    }

    return 0;
}

int qualityPoints( int grade )
{
    if ( grade >= 90 && grade <= 100 ){
        return 4;
    }else if ( grade >= 80 && grade <= 89 ){
        return 3;
    }else if ( grade >= 70 && grade <= 79 ){
        return 2;
    }else if ( grade >= 60 && grade <= 69 ){
        return 1;
    }else if ( grade >= 0 && grade <= 59 ){
        return 0;
    }
}
