#include <stdio.h>

int main( void )
{
    int grade;
    int aCount = 0 , bCount = 0 , cCount = 0 , dCount = 0;

    printf( "Enter grade (-1 to end): \n" );

    while ( ( grade = getchar() ) != EOF ){
        switch ( grade ){
            case 'A':
            case 'a':
                aCount++;
                break;

            case 'B':
            case 'b':
                bCount++;
                break;

            case 'C':
            case 'c':
                cCount++;
                break;

            case 'D':
            case 'd':
                dCount++;
                break;

            case '\n':
            case '\t':
            case ' ':
                break;

            default:
                printf( "Invalid grade entered\n" );
        }
    }

    printf( "A: %d\n" , aCount );
    printf( "B: %d\n" , bCount );
    printf( "C: %d\n" , cCount );
    printf( "D: %d\n" , dCount );

    return 0;
}
