#include <stdio.h>

int main( void )
{
    char debtorName[] = "Mat Din";
    char debtorAddress[] = "Senai";
    int debtorAccount = 8888;
    int ageOfDebt = 10; //month overdue
    char warning[ 5 ][ 80 ] = { "Please pay" , "Remember, pay" , "Hey, don't forget!, pay" , "Oi, pay la oi" , "Nate ni, bayar laa!!" };

    //printing dunning letter
    printf( "%s\n%s\n%d\n%d month due\n\n" , debtorName , debtorAddress , debtorAccount , ageOfDebt );


    if ( ageOfDebt <= 1 ){
        printf( "%s" , warning[ 0 ] );
    }else if ( ageOfDebt <= 2 ){
        printf( "%s" , warning[ 1 ] );
    }else if ( ageOfDebt <= 3 ){
        printf( "%s" , warning[ 2 ] );
    }else if ( ageOfDebt <= 4 ){
        printf( "%s" , warning[ 3 ] );
    }else{
        printf( "%s" , warning[ 4 ] );
    }

    return 0;
}
