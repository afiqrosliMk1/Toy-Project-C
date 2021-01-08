#include <stdio.h>

int main( void )
{
    int productNum , quantity , i;
    float totalAllItem , totalEachItem , price;

    for ( i = 1; i <= 5; i++ ){
        printf( "Insert product number and quantity sold: " );
        scanf( "%d%d" , &productNum , &quantity );

        switch ( productNum )
        {
            case 1:
                price = 1.0;
                break;
            case 2:
                price = 1.0;
                break;
            case 3:
                price = 1.0;
                break;
            case 4:
                price = 1.0;
                break;
            case 5:
                price = 1.0;
                break;
        }
        totalEachItem = price * 7;
        totalAllItem += totalEachItem;
    }

     //total sold in one week
    printf( "%.2f" , totalAllItem );

    return 0;
}



