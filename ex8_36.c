#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( void )
{
    char date[ 20 ] = "12/5/2020";
    int dateInt[ 3 ] = { 0 };
    char *tokenPtr;
    int i = 0;
    char *months[ 13 ] = { "" , "January" , "February" , "March" , "April" , "May", "June" , "July" , "August" ,
                            "September" , "October" , "November" , "Disember" };

    puts( "Enter date in dd/mm/yyyy format\n" );
    scanf( "%19s" , date );

    tokenPtr = strtok( date , "/" );
    while ( tokenPtr != NULL ){
        dateInt[ i++ ] = atoi( tokenPtr );
        tokenPtr = strtok( NULL , "/" );
    }

    for ( i = 0; i < 3; ++i ){
        if ( i == 1 ){
            printf( "%s " , months[ dateInt[ i ] ] );
        }else{
            printf( "%d " , dateInt[ i ] );
        }
    }printf( "\n" );

    return 0;
}
