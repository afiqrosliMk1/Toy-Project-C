//for figure 7.6 and 7.7
#include <stdio.h>
int callByValue( int x );
void callByRef( int *y );

int main( void )
{
    int a = 5;
    int aNew;
    aNew = callByValue( a );
    printf( "aNew = %d\n" , aNew );

    callByRef( &a );
    printf( "a after call by ref = %d" , a );
    return 0;
}

int callByValue( int x )
{
    return x + 5;
}

void callByRef( int *y )
{
    *y = *y * 3;
}
