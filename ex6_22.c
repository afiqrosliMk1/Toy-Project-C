#include <stdio.h>
#define ITEMS 2
#define SALES_PERSON 3

void inputSales( int itemsArray[] );
void printTable( int salesArray[][ SALES_PERSON ] );
int totalRow( const int b[] );
int totalColumn( const int c[][ SALES_PERSON ] , int column );

int main( void )
{
    int k;
    int sales[ ITEMS ][ SALES_PERSON ] = { 0 };

    for ( k = 0; k < ITEMS; ++k ){ //loop salesperson 1 to 4
        printf( "Product %d\n" , k );
        printf( "-------------------\n" );
        inputSales( sales[ k ] );//pass sales as individual array
        printf( "\n" );
    }
    printTable( sales );

    return 0;
}

void inputSales( int itemsArray[] )
{
    int day , j , hold = 0;

    for ( day = 1; day <= 1; ++day ){//limit days to 2 days
        printf( "Enter sales for DAY %d\n" , day );
        for ( j = 0; j < SALES_PERSON; ++j ){
            printf( "Salesperson #%d: " , j + 1  );
            scanf( "%d" , &hold );
            itemsArray[ j ] += hold;
        }
    }

}

void printTable( int salesArray[][ SALES_PERSON ] )
{
    int i , j;

    //print header
    printf( "              " );
    for ( i = 0; i < SALES_PERSON; i++ ){
        printf( "Sp%d" , i );
        printf( "      " );
        if ( i == SALES_PERSON - 1 ){
            printf( "Total" );//total in column header
        }
    }printf( "\n" );

    for ( i = 0; i < ITEMS; i++ ){
        printf( "Product %d" , i );

        for ( j = 0; j < SALES_PERSON; j++ ){
            printf( "%8d " , salesArray[ i ][ j ] );

            if ( j == SALES_PERSON - 1 ){
                printf( "%8d" , totalRow( salesArray[ i ] )  );
            }

        }printf( "\n" );

        if ( i == ITEMS - 1 ){
            printf( "Total    " );//total in row header
            for ( j = 0; j < SALES_PERSON; ++j ){
                printf( "%8d " , totalColumn( salesArray , j ) );
            }printf( "\n" );
        }
    }
}

int totalRow( const int b[] )
{
    int i;
    int total = 0;
    for ( i = 0; i < SALES_PERSON; i++ ){
        total += b[ i ];
    }
    return total;
}

int totalColumn( const int c[][ SALES_PERSON ] , int column )
{
    int i , total = 0;
    for ( i = 0; i < ITEMS; ++i ){
        total += c[ i ][ column ];
    }
    return total;
}
