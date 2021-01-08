//exercise 11.11 part 1 - create people.dat
#include <stdio.h>
#define RECORD_SIZE 5

struct person {
  char lastName[ 15 ];
  char firstName[ 15 ];
  char age[ 4 ];
};

int main( void )
{
    FILE *fPtr;
    struct person blankPeople = { "unassigned" , "" , "0" };
    int i;

    if ( ( fPtr = fopen( "nameage.dat" , "wb" ) ) == NULL ){
        printf( "file could not be opened\n" );
    }else{

        for ( i = 1; i <= RECORD_SIZE; ++i ){
            fwrite( &blankPeople , sizeof( struct person ) , 1 , fPtr );
        }

    }
    fclose( fPtr );

    return 0;
}
