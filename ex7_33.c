//carbon footprint
#include <stdio.h>
void cfBuilding( void );
void cfCar( void );
void cfBicycle( void );
void promptUser( void );

#define EF_ELECTRICITY 0.6 //kg.CO2e/kWh
#define EF_WASTE  0.23//kg CO2e/kg
#define EF_WATER  0.2//kg CO2e/kWh
#define EF_LPG  1.8//kg CO2e/litre

#define EF_FUEL 2.32//kg CO2e/litre

#define EF_CALORIE 0.05//kg CO2e/kCal

int main( void )
{
    void ( *f[ 3 ] )( void ) = { cfBuilding , cfCar , cfBicycle };
    int choice;

    promptUser();
    scanf( "%d" , &choice );

    while( choice != -1 ){
        if ( choice >= 0 && choice <= 2 ){
            ( *f[ choice ] )();
        }else{
            printf( "Invalid value entered\n\n" );
        }
        promptUser();
        scanf( "%d" , &choice );
    }
}

void promptUser( void )
{
    printf( "Choose carbon footprint that you want to calculate\n"
           "0 Building\n1 Car\n2 Bicycle\n-1 End\n" );
}

void cfBuilding( void )
{
    int electricity; //kWh/yr
    int waste;
    int water;
    int lpg; //liter/yr
    int use_electricity;
    int use_waste;
    int use_water;
    int use_lpg;

    printf( "Enter electricity usage [kWh/yr]: " );
    scanf( "%d" , &use_electricity );
    printf( "Enter waste usage [kg/week]: " );
    scanf( "%d" , &use_waste );
    printf( "Enter water usage [liter/day]: " );
    scanf( "%d" , &use_water );
    printf( "Enter LPG usage [kg.CO2e/liter]: " );
    scanf( "%d" , &use_lpg );

    electricity = use_electricity * EF_ELECTRICITY;
    waste = use_waste * 52 * EF_WASTE;
    water = use_water * 365 * EF_WATER;
    lpg = use_lpg * EF_LPG;

    printf( "Carbon footprint for your building: %d [kg.CO2e/yr]\n" , electricity + waste + water + lpg );
}

void cfCar( void )
{
    float fuel;
    float use_fuel , distance;

    printf( "Enter fuel usage [liter/100km]: " );
    scanf( "%f" , &use_fuel );
    printf( "Enter distance travelled [km/yr]: " );
    scanf( "%f" , &distance );
    fuel = use_fuel * EF_FUEL;

    printf( "Carbon footprint for your car: %.2f [kg.CO2e/yr]\n" , fuel );
}

void cfBicycle( void )
{
    float use_calorie;
    float calorie; //co2 emission

    printf( "Enter calorie burnt [kCal]: " );
    scanf( "%f" , &use_calorie );
    calorie = use_calorie * EF_CALORIE * 365;

    printf( "Carbon footprint by cycling: %.2f [kg.CO2e/yr]\n" , calorie );
}
