#include <stdio.h>

char *my_strchr( char *s , int c );
size_t my_strcspn( char *s1 , const char *s2 );
size_t my_strspn( char *s1 , const char *s2 );
char *my_strpbrk( char *s1 , const char *s2 );
char *my_strrchr( char *s1 , int c );
char *my_strstr( char *s1 , char *s2 );
char *my_strtok( char *s1 , const char *s2 );

int main( void )
{
    //char letter = 's';
    //char word[] = "Selamat";
    char sentence1[] = "hel lo he  adfa ua";
    //char sentence2[] = "los";
    //char *wPtr;
    char *tokenPtr = NULL;

   // wPtr = my_strchr( word , letter );

    /*if ( wPtr != NULL ){
        printf( "letter %c is found in %s\n" , letter , word );
    }else{
        printf( "Letter not found\n" );
    }*/

    //printf( "lenght of initial segment of sentence1 not containing character from sentence2 is %d\n" , my_strspn( sentence1 , sentence2 ) );
    //printf( "of the characters in %s\n%c appears earliest in %s\n" , sentence2 , *my_strpbrk( sentence1 , sentence2 ) , sentence1 );

    //printf( "%s\n" , my_strchr( sentence1 , letter ) );
    //printf( "%s\n" , my_strstr( sentence1 , sentence2 ) );

    tokenPtr = my_strtok( sentence1 , " " );

    while ( tokenPtr != NULL ){
        printf( "%s\n" , tokenPtr );
        tokenPtr = my_strtok( NULL , " " );
    }

    return 0;
}

char *my_strchr( char *s , int c )
{
    char *ptr;

    while ( *s != '\0' ){
        if ( *s == c ){
            ptr = s;
            return ptr;
        }else{
            s++;
        }
    }//end while
    return NULL;
}

size_t my_strcspn( char *s1 , const char *s2 )
{
    char *temp = NULL;
    int i;

    for ( ; *s2 != '\0'; ++s2 ){
        for ( i = 0; s1[ i ] != '\0'; ++i ){
            if ( *s2 == s1[ i ] && temp == NULL ) { //first time
                temp = &s1[ i ];
            }else if ( *s2 == s1[ i ] && ( &s1[ i ] < temp ) ){
                temp = &s1[ i ];
            }
        }
    }

    if ( temp == NULL ){ //means temp never change
        return -1;
    }else{
        return temp - s1;
    }
}
size_t my_strspn( char *s1 , const char *s2 )
{
    char *temp = NULL;
    int i , j;
    int flag;

    for ( i = 0; s1[ i ] != '\0'; ++i){
        flag = 0;

        for ( j = 0; s2[ j ] != '\0'; ++j ){
            if ( s1[ i ] == s2[ j ] ) {
                flag = 1;
                temp = &s1[ i + 1 ];
            }
        }


        if ( flag == 0){ //no match found
            break;
        }
    }//end for

    if ( temp == NULL ){
        return 0;
    }else{
        return temp - s1;
    }
}

char *my_strpbrk( char *s1 , const char *s2 )
{
    char *temp = NULL;
    int i , j;

    for ( i = 0; s1[ i ] != '\0'; ++i ){
        for ( j = 0; s2[ j ] != '\0'; ++j ){
            if ( s1[ i ] == s2[ j ] ){
                temp = &s1[ i ];
                break;
            }
        }
    }

    return temp;
}

char *my_strrchr( char *s1 , int c )
{
    char *temp = NULL;

    for ( ; *s1 != '\0'; ++s1 ){
        if ( *s1 == c ){
            temp = s1;
        }
    }

    return temp;
}

char *my_strstr( char *s1 , char *s2 )
{
    //THIS IS JUST UTILITY FUNCTION TO COMPARE SEVERAL BYTES OF STRING
    int compareString( char *str1 , char *str2 )
    {
        int i;
        int length;
        int equal = 1;

        for ( length = 0 , i = 0; str2[ i ] != '\0'; ++i ){
            length = i;
        }

        for ( i = 0; i <= length; ++i ){
            if ( str1[ i ] != str2[ i ] ){
                equal = 0;
            }
        }

        return equal;
    }

    //THIS IS THE REAL CODE
    char *temp = NULL;
    int i;

    for ( i = 0; s1[ i ] != '\0'; ++i ){
        if ( s1[ i ] == *s2 ){
            if ( compareString( &s1[ i ] , s2 ) ){
                temp = &s1[ i ];
                break;
            }
        }
    }//end for

    return temp;
}

char *my_strtok( char *s1 , const char *s2 )
{
    char *temp = NULL;
    static char *afterNull = NULL;

    if ( s1 == NULL ){
        s1 = afterNull;
        if ( s1 == NULL ){
            return s1;
        }
    }

    //search for first non-whitespace character
    while ( *s1 == ' ' ){
        s1++;
    }
    temp = s1; //assign the address to temp (start of token)

    while ( *s1 != ' ' && *s1 != '\0' ){
        s1++;
    }

    if ( *s1 == '\0' ){
        afterNull = NULL; //END of string is reached, set temp to NULL to indicate this
    }else{
        //if space is found, set it equal to null character
        *s1 = '\0';
        afterNull = s1 + 1;
    }

    return temp;
}
