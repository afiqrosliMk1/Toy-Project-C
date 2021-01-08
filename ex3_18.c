#include <stdio.h>

int main( void )
{

    int account_no , beginning_balance , total_charges , total_credits , credit_limit , new_balance;

    printf( "Enter account number (-1 to end): " );
    scanf( "%d" , &account_no );

    while ( account_no != EOF ){
        printf( "Enter beginning balance: " );
        scanf( "%d" , &beginning_balance );
        printf( "Enter total charges: " );
        scanf( "%d" , &total_charges );
        printf( "Enter total credits: " );
        scanf( "%d" , &total_credits );
        printf( "Enter credit limits: " );
        scanf( "%d" , &credit_limit );

        printf( "Account: %d" , account_no );
        printf( "\nCredit limit: %d" , credit_limit );
        new_balance = beginning_balance + total_charges - total_credits;
        printf( "\nBalance: %d " , new_balance );

        if ( new_balance > credit_limit ){
            printf( "\nCredit limit Exceeded" );
        }

        printf( "\n\nEnter account number (-1 to end): " );
        scanf( "%d" , &account_no );
    }

    return 0;
}
