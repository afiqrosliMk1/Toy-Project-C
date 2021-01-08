#include <stdio.h>
#include <string.h>

int main( void )
{
    char *spamWords[ 30 ] = { "money" , "win" , "lottery" , "millions" , "dollars" , "rich" , "account number" , "congratulations" , "heir" , "paid" ,
                         "pay" , "transfer" , "win" , "million" , "share" , "contact" , "police" , "bank" , "transferred" , "account" ,
                         "free" , "easy" , "mlm" , "buy" , "stock" , "wealth" , "wealthy" , "salary" , "need" , "interest" };
    char text[ 100 ] = "";
    char *strPtr = NULL;
    int i = 0;
    int spamScore = 0;

    printf( "Enter message: \n" );
    fgets( text , 100 , stdin );

    for ( i = 0; i < 30; ++i ){
        strPtr = strstr( text , spamWords[ i ] );
        if ( strPtr != NULL ){
            ++spamScore;
        }
    }

    printf( "spam score: %d\n" , spamScore );

    if ( spamScore > 3 ){
        printf( "This is a scam!\n" );
    }

    return 0;
}
