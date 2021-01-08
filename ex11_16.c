#include <stdio.h>

int main( void )
{
    FILE *fPtr;

    fPtr = fopen( "datasize.txt" , "w" );

    fprintf( fPtr , "%-20s%4s\n" , "Data type" , "Size" );
    fprintf( fPtr , "%-20s%d\n" , "char" , sizeof( char ) );
    fprintf( fPtr , "%-20s%d\n" , "short" ,  sizeof( short ) );
    fprintf( fPtr , "%-20s%d\n" , "unsigned short" , sizeof( unsigned short ) );
    fprintf( fPtr , "%-20s%d\n" , "int" , sizeof( int ) );
    fprintf( fPtr , "%-20s%d\n" , "unsigned" , sizeof( unsigned ) );
    fprintf( fPtr , "%-20s%d\n" , "long" , sizeof( long ) );
    fprintf( fPtr , "%-20s%d\n" , "unsigned long" , sizeof( unsigned long ) );
    fprintf( fPtr , "%-20s%d\n" , "float" , sizeof( float ) );
    fprintf( fPtr , "%-20s%d\n" , "double" , sizeof( double ) );
    fprintf( fPtr , "%-20s%d\n" , "long double" , sizeof( long double ) );

    fclose( fPtr );

}
