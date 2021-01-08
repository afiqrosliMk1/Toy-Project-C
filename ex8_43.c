#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main( void )
{
    char text[ 100 ] = "1 sugar";
    char *ingredient[ 4 ] = { "sour cream" , "milk" , "lemon juice" , "sugar" };
    char *substitute[ 7 ] = { "yogurt" , "evaporated milk" , "water" , "vinegar" , "honey" , "molasses" , "agave nectar" };
    char *unit[ 4 ] = { "teaspoon" , "cup" , "tablespoons" , "unit" };
    double amount = 0;
    char *strPtr = NULL;
    int i , j;
    double ingredientCode[ 3 ][ 10 ] = {}; //ten ingredients. first row is code. second row is amount , third row is the unit

    for ( i = 0; i < 10; ++i ){
        for ( j = 0; j < 2; ++j ){
            ingredientCode[ j ][ i ] = -1; //initialize each elements to -1
        }
    }

    for ( i = 0; i < 10; ++i ){
           ingredientCode[ 2 ][ i ] = 3; //initialize each elements to "unit"
    }
    //==========================================================//
    //find digit in the text
    for ( i = 0; i < 100; ++i ){
        if ( isdigit( text[ i ] ) ){
            strPtr = text + i;
            i = 999;//break the loop
        }
    }

    amount = strtod( strPtr , NULL );
    printf( "%lf\n" , amount );
    //==========================================================//

    //==========================================================//
    //find the ingredient keyword
    for ( i = 0 , j = 0; i < 4; ++i ){
        strPtr = strstr( text , ingredient[ i ] );
        if ( strPtr != NULL ){ //means a match is found
            ingredientCode[ 0 ][ j ] = (double)i;
            ingredientCode[ 1 ][ j ] = amount;
            ++j;
        }
    }


    //find the ingredient keyword
    for ( i = 0 , j = 0; i < 4; ++i ){
        strPtr = strstr( text , unit[ i ] );
        if ( strPtr != NULL ){ //means a match is found
            ingredientCode[ 2 ][ j ] = (double)i;
            ++j;
        }
    }
    printf( "%.1lf %.1lf %.1lf\n" , ingredientCode[ 0 ][ 0 ] , ingredientCode[ 1 ][ 0 ] , ingredientCode[ 2 ][ 0 ] );

    //==============================================================//

    //interpret ingredientCode array
    for ( j = 0; j < 10; ++j ){
        switch ( ( int )ingredientCode[ 0 ][ j ] )
        {
            //sour cream
            case 0:
                printf( "%.2lf %s\n" , ingredientCode[ 1 ][ j ] , substitute[ 0 ] ); //yogurt
                break;

            //milk
            case 1:
                printf( "%.1lf %s and %.1lf %s\n" , ingredientCode[ 1 ][ j ] , substitute[ 1 ] , ingredientCode[ 1 ][ j ] , substitute[ 2 ] );
                break;
            //lemon juice
            case 2:
                printf( "%.1lf %s\n" , ingredientCode[ 1 ][ j ] , substitute[ 3 ] );
                break;

            //sugar
            case 3:
                printf( "%.3lf %s %s , %.3lf %s %s or %.3lf %s %s\n" ,
                       ingredientCode[ 1 ][ j ] * 0.5 , unit[ (int)ingredientCode[ 2 ][ j ] ] , substitute[ 4 ] ,
                       ingredientCode[ 1 ][ j ] , unit[ (int)ingredientCode[ 2 ][ j ] ] , substitute[ 5 ] ,
                       ingredientCode[ 1 ][ j ] * 0.125, unit[ (int)ingredientCode[ 2 ][ j ] ] , substitute[ 6 ] );
                break;

            default:
                break;
        }
    }


    return 0;
}
