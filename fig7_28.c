#include <stdio.h>
void function1( int a );
void function2( int a );
void function3( int a );

int main( void )
{
    int choice;
    void (*f[ 3 ])( int ) = { function1 , function2 , function3 };
    printf( "Enter a number 0 - 2 , 3 to end: " );
    scanf( "%d" , &choice );

    while ( choice >= 0 && choice < 3 ){
        (*f[ choice ])( choice );
        printf( "Enter a number 0 - 2 , 3 to end: " );
        scanf( "%d" , &choice );
    }

    return 0;
}

void function1( int a )
{
    printf( "You select %d , hence function1 is called\n\n" , a );
}

void function2( int a )
{
    printf( "You select %d , hence function2 is called\n\n" , a );
}

void function3( int a )
{
    printf( "You select %d , hence function3 is called\n\n" , a );
}
