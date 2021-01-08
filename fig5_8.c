#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int frequency1 = 0 , frequency2 = 0 , frequency3 = 0 , frequency4 = 0 , frequency5 = 0 , frequency6 = 0;
    int face , i;

    for ( i = 1; i <= 6000; i++ ){
        face = rand() % 6 + 1;
        switch ( face ){
            case 1:
                ++frequency1;
                break;
            case 2:
                ++frequency2;
                break;
            case 3:
                ++frequency3;
                break;
            case 4:
                ++frequency4;
                break;
            case 5:
                ++frequency5;
                break;
            case 6:
                ++frequency6;
                break;
        }//end switch
    }//end for

    printf("Face\tFrequency\n" );
    printf("1\t%d\n2\t%d\n3\t%d\n4\t%d\n5\t%d\n6\t%d\n" , frequency1 , frequency2 , frequency3 ,
           frequency4 , frequency5 , frequency6 );

    return 0;
}
