#include <stdio.h>

int main( void )
{
    int aCount = 0, bCount = 0 , cCount = 0 , dCount = 0 , fCount = 0;
    char grade;

    printf( "Enter grade (EOF) to End: " );
    while ( ( grade = getchar() ) != EOF ){
        if ( grade == 'A' || grade == 'a' ){
            aCount++;
        }if ( grade == 'B' || grade == 'b' ){
            bCount++;
        }if ( grade == 'C' || grade == 'c' ){
            cCount++;
        }if ( grade == 'D' || grade == 'd' ){
            dCount++;
        }if ( grade == 'F' || grade == 'f' ){
            fCount++;
        }if ( grade == '\n' || grade == '\t' || grade == ' ' ){
            ;
        }
    }//end of while

    printf( "A: %d\n" , aCount );
    printf( "B: %d\n" , bCount );
    printf( "C: %d\n" , cCount );
    printf( "D: %d\n" , dCount );
    printf( "F: %d\n" , fCount );


    return 0;
}
