//recursive main
#include <stdio.h>

int main( void )
{
    printf( "calling main()\t" );
    static int x = 1;
    printf( "x = %d\n" , x );
    if ( x == 10 ){
        printf( "exiting main()" );
        return 0;
    }else{
        printf( "increment x..\t" );
        x++;
        main();
    }
}
