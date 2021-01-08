#include <stdio.h>
void printShape ( int choice , int size , char ch );

int main( void )
{
    int patternNo , sizeOfPattern;
    char characterPattern;
    printf( "Enter the pattern choice 1-8: " );
    scanf( "%d" , &patternNo );
    printf( "Enter size: " );
    scanf( "%d" , &sizeOfPattern );
    printf( "Enter character: " );
    scanf( " %c" , &characterPattern );

    printShape( patternNo , sizeOfPattern , characterPattern );
    return 0;
}

void printShape ( int choice , int size , char ch )
{
    int i , j;
    int mid = size / 2 + 1;

    //case 1-4 is right angle triangles , 5-6 also triangles , 7 is diamond , 8 is rectangle
    switch ( choice ){
        case 1:
            for ( i = 1; i <= size; i++ ){
                for ( j = 1; j <= i; j++ ){
                    printf( "%c" , ch );
                }
                printf( "\n" );
            }break;
        case 2:
            for ( i = 1; i <= size; i++ ){
                for ( j = 1; j <= size; j++ )
                    if ( j > size - i ){
                        printf( "%c" , ch );
                    }else{
                        printf( " " );
                    }
                printf( "\n" );
            }break;
        case 3:
            for ( i = 1; i <= size; i++ ){
                for ( j = 1; j <= size; j++ )
                    if ( j <= size - i + 1 ){
                        printf( "%c" , ch );
                    }else{
                        printf( " " );
                    }
                printf( "\n" );
            }break;
        case 4:
            for ( i = 1; i <= size; i++ ){
                for ( j = 1; j <= size; j++ )
                    if ( j >= i ){
                        printf( "%c" , ch );
                    }else{
                        printf( " " );
                    }
                printf( "\n" );
            }break;
        case 5:
            for ( i = 1; i <= mid; i++ ){
                for ( j = 1; j <= size; j++ ){
                    if ( j > mid - i && j < mid + i ){
                        printf( "%c" , ch );
                    }else{
                        printf( " " );
                    }
                }
                printf( "\n" );
            }break;
        case 6:
            for ( i = mid; i >= 1; i-- ){
                for ( j = 1; j <= size; j++ ){
                    if ( j > mid - i && j < mid + i ){
                        printf( "%c" , ch );
                    }else{
                        printf( " " );
                    }
                }
                printf( "\n" );
            }break;
        case 7:
            for ( i = 1; i <= size; i++ ){
                if ( i <= mid ){
                    for ( j = 1; j <= size; j++ ){
                        if ( j > mid - i && j < mid + i ){
                            printf( "%c" , ch );
                        }else{
                            printf( " " );
                        }
                    }
                }if ( i > mid ){
                    for ( j = 1; j <= size; j++ ){
                        if ( j > i - mid && j <= mid + ( size - i ) ){
                            printf( "%c" , ch );
                        }else{
                            printf( " " );
                        }
                    }
                }
                printf( "\n" );
            }break;
        case 8:
            for ( i = 1; i <= size; i++ ){
                for ( j = 1; j <= size; j++ ){
                    printf( "%c" , ch );
                }
                printf( "\n" );
            }break;
    }








}
