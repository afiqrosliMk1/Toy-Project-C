#include <stdio.h>
#include <math.h>

#define SENTINEL -99999
#define SIZE 1000
#define TRUE 1
#define FALSE 0
#define READ 10
#define WRITE 11
#define NEWLINE 12
#define INPUT_STRING 13
#define PRINT_STRING 14
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define REMAINDER 34//NEW!!!
#define EXPONENT 35//NEW!!!
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void load( float *memoryPtr );
void execute( float *memoryPtr ,  float *acPtr , int *icPtr , float *irPtr , int *opCodePtr , int *opPtr );
void dump( float *memoryPtr , float *acPtr , int *icPtr , float *irPtr , int *opCodePtr , int *opPtr );
int validWord( int number );

int main( void )
{
    float memory[ SIZE ] = { 0 }; //changed to float
    float ac = 0; //accumulator //changed to float
    int ic = 0; //instruction counter
    float ir = 0; // instruction register
    int opCode = 0; //operation code
    int op = 0; //operand

    load( memory );
    execute( memory , &ac , &ic , &ir , &opCode , &op );
    dump( memory , &ac , &ic , &ir , &opCode , &op );

    return 0;
}

void load( float *memoryPtr )
{
    int i = 0;
    float instruction; //changed to float

    printf( "\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n" ,
           "*** Welcome to Simpletron ***" ,
           "*** Please enter your program one instruction ***" ,
           "*** (or data word) at a time. I will type the ***" ,
           "*** location number and the question mark (?). ***" ,
           "*** You then type the word of that location ***" ,
           "*** Type the sentinel -99999 to stop entering ***" ,
           "*** your program. ***" );

    printf( "000 ? " );
    scanf( "%f" , &instruction );

    while ( instruction != SENTINEL ){
        if ( !validWord( instruction ) ){
            printf( "*** Number not valid ***\n" );
        }else{
            memoryPtr[ i++ ] = instruction;
        }

        printf( "%03d ? " , i );
        scanf( "%f" , &instruction );
    }

    printf( "*** PROGRAM LOADING COMPLETED ***\n" );
}

void execute( float *memoryPtr ,  float *acPtr , int *icPtr , float *irPtr , int *opCodePtr , int *opPtr )
{
    int fatal = FALSE;
    float temp;
    char tempString[ 25 ];
    int i = 0 , j = 0 , k = 0;
    int string_size;
    int char_value;
    int sizeString = 0;

    printf( "\n**** PROGRAM EXECUTION BEGINS ****\n" );

    *irPtr = memoryPtr[ *icPtr ];
    *opCodePtr = ( int )( *irPtr  )/ 1000;
    *opPtr = ( int )( *irPtr ) % 1000;

    while ( *opCodePtr != HALT && fatal == FALSE ){
        switch ( *opCodePtr ){

            case READ:
                printf( "Enter an integer(or float): " );
                scanf( "%f" , &temp );

                while ( !validWord( temp ) ){
                    printf( "Number out of range. Please enter again: " );
                    scanf( "%f" , &temp );
                }

                memoryPtr[ *opPtr ] = temp;
                ++( *icPtr );
                break;

            case WRITE:
                printf( "Contents of %03d: %.2f\n" , *opPtr , memoryPtr[ *opPtr ] );
                ++( *icPtr );
                break;

            case NEWLINE:
                printf( "\n" );
                ++( *icPtr );
                break;

            case INPUT_STRING:
                printf( "Enter string: " );
                scanf( "%24s" , tempString );

                while ( tempString[ j ] != '\0' ){
                    ++sizeString;
                    ++j;
                }++sizeString;

                memoryPtr[ *opPtr ] = sizeString * 1000 + ( *tempString );
                ++i;
                while ( tempString[ i ] != '\0' ){
                    memoryPtr[ *opPtr + i ] = tempString[ i ];
                    ++i;
                }memoryPtr[ i ] = '\0';
                ++( *icPtr );
                break;

            case PRINT_STRING:
                string_size = ( int )( memoryPtr[ *opPtr ] ) / 1000;
                char_value = ( int )( memoryPtr[ *opPtr ] ) % 1000;

                for ( k = 1; k <= string_size; ++k ){
                    printf( "%c" , char_value );
                    char_value = ( int )( memoryPtr[ *opPtr + k ] ) % 1000;
                }
                ++( *icPtr );
                break;

            case LOAD:
                *acPtr = memoryPtr[ *opPtr ];
                ++( *icPtr );
                break;

            case STORE:
                memoryPtr[ *opPtr ] = *acPtr;
                ++( *icPtr );
                break;

            case ADD:
                temp = *acPtr + memoryPtr[ *opPtr ];

                if ( validWord( temp ) ){
                    *acPtr = temp;
                    ++( *icPtr );
                }else{
                    printf( "*** FATAL ERROR: (add)Accumulator overflow ****\n" );
                    fatal = TRUE;
                }
                break;

            case SUBTRACT:
                temp = *acPtr - memoryPtr[ *opPtr ];
                if ( validWord( temp ) ){
                    *acPtr = temp;
                    ++( *icPtr );
                }else{
                    printf( "*** FATAL ERROR: (subtract)Accumulator overflow ****\n" );
                    fatal = TRUE;
                }
                break;

            case DIVIDE:
                if ( memoryPtr[ *opPtr ] == 0 ){
                    printf( "*** FATAL ERROR: Attempt to divide by zero ****\n" );
                    fatal = TRUE;
                }else{
                    *acPtr /= memoryPtr[ *opPtr ];
                    ++( *icPtr );
                }
                break;

            case MULTIPLY:
                temp = *acPtr * memoryPtr[ *opPtr ];
                if ( !validWord( temp ) ){
                    printf( "*** FATAL ERROR: (multiply)Accumulator overflow ****\n" );
                    fatal = TRUE;
                }else{
                    *acPtr = temp;
                    ++( *icPtr );
                }
                break;

            case REMAINDER:
                if ( memoryPtr[ *opPtr ] == 0 ){
                    printf( "*** FATAL ERROR: (remainder)Attempt to divide by zero***\n" );
                    fatal = TRUE;
                }else{
                    *acPtr = (int)(*acPtr) % (int)(memoryPtr[ *opPtr ]);
                    ++( *icPtr );
                }
                break;

            case EXPONENT:
                temp = pow( *acPtr , memoryPtr[ *opPtr ] );
                if ( !validWord( temp ) ){
                    printf( "*** FATAL ERROR: (exponent)Accumulator overflow***\n" );
                    fatal = TRUE;
                }else{
                    *acPtr = temp;
                    ++( *icPtr );
                }
                break;

            case BRANCH:
                *icPtr = *opPtr;
                break;

            case BRANCHNEG:
                if ( *acPtr < 0 ){
                    *icPtr = *opPtr;
                }else{
                    ++( *icPtr );
                }
                break;

            case BRANCHZERO:
                if ( *acPtr == 0 ){
                    *icPtr = *opPtr;
                }else{
                    ++( *icPtr );
                }
                break;

            default:
                printf( "*** FATAL ERROR ***\n" );
                printf( "*** Invalid operation code***\n" );
                fatal = TRUE;

        }//end switch
        *irPtr = memoryPtr[ *icPtr ];
        *opCodePtr = (int)(*irPtr) / 1000;
        *opPtr = (int)(*irPtr) % 1000;
    }//end while

    printf( "\n*** PROGRAM EXECUTION ENDS ***\n" );
}

void dump( float *memoryPtr , float *acPtr , int *icPtr , float *irPtr , int *opCodePtr , int *opPtr )
{
    int i;

    printf( "%s\n%-25s%+06f\n%-25s%6.3d\n%-25s%+06f\n%-25s%6.2d\n%-25s%6.3d\n" ,
            "REGISTERS:" , "accumulator" , *acPtr , "instructionCounter" , *icPtr ,
            "instructionRegister" , *irPtr , "operationCode" , *opCodePtr ,
            "operand" , *opPtr );

    printf( "\nMEMORY:\n" );

    //print column header
    printf( "      " );
    for ( i = 0; i <= 9; ++i ){
        printf( "%9x " , i );
    }

    //print row header
    for ( i = 0; i < SIZE; ++i ){

        if ( i % 10 == 0 ){
            printf( "\n%#5x " , i );
        }
        printf( "%+09.2f " , memoryPtr[ i ] );
    }
}

int validWord( int number )
{
    return number >= -99999 && number <= 99999;
}
