#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main( void )
{
    char telephoneNum[ 20 ] = "";
    char *strPtr;
    int areaCode;
    char numberString[ 8 ] = "";
    long number;

    puts( "Enter phone number in the form (555) 555-5555 : " );
    fgets( telephoneNum , 20 , stdin );

    strPtr = strtok( telephoneNum , "()" );
    areaCode = atoi( strPtr );
    printf( "area code: %d\n" , areaCode );

    strPtr = strtok( NULL , " -" );
    strcpy( numberString , strPtr );
    strPtr = strtok( NULL , " -" );
    strcat( numberString , strPtr );

    number = atol( numberString );

    printf( "phone number: %ld\n" , number );

    return 0;
}
