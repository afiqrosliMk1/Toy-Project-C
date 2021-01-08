#include <stdio.h>

int main( void )
{
    int aCount = 0 , bCount = 0 , cCount = 0 , dCount = 0 , fCount = 0;
    float averageMarks;
    char grade , averageGrade;

    printf( "Enter grade letter (EOF ctrl+z to end):" );

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
            case 'F':
            case 'f':
                fCount++;
                break;
            case '\t':
            case '\n':
            case ' ':
                break;
            default:
                printf( "Incorrect letter\n" );
        }
    }

    printf( "Total for each grade:\n" );
    printf( "A:%d\nB:%d\nC:%d\nD:%d\nF:%d\n" , aCount , bCount , cCount , dCount , fCount );

    //Calculating the average
    averageMarks = ( aCount * 5 + bCount * 4 + cCount * 3 + dCount * 2 + fCount * 1 ) / ( aCount + bCount + cCount + dCount + fCount );
    //printf( "Average: %.2f" , averageMarks );

    if ( averageMarks > 4 )
        averageGrade = 'A';
    else if ( averageMarks > 3 && averageMarks <= 4 )
        averageGrade = 'B';
    else if ( averageMarks > 2 && averageMarks <= 3 )
        averageGrade = 'C';
    else if ( averageMarks > 1 && averageMarks <= 2 )
        averageGrade = 'D';
    else if ( averageMarks > 0 && averageMarks <= 1 )
        averageGrade = 'E';
    else
        printf( "something is wrong...\n" );

    printf( "Average grade is: %c" , averageGrade );

    return 0;
}
