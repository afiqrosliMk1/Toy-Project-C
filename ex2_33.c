#include <stdio.h>

int main( void )
{
    int range_km; //range driven per day in km
    int price_per_liter; //harga minyak seliter
    int km_per_liter; //range can go for every one liter
    int parking_fees;
    int toll;
    int total_cost; // total cost per day

    printf( "Range driven (km) per day:" );
    scanf( "%d" , &range_km );
    printf( "Price per liter:" );
    scanf( "%d" , &price_per_liter );
    printf( "Kilometer per liter:" );
    scanf( "%d" , &km_per_liter );
    printf( "Parking fees:" );
    scanf( "%d" , &parking_fees );
    printf( "Toll:" );
    scanf( "%d" , &toll );

    total_cost = range_km * price_per_liter / km_per_liter + parking_fees + toll;
    printf( "Total cost per day: %d" , total_cost );

    return 0;
}
