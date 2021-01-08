#include <stdio.h>

#define SENTINEL -99999
#define SIZE 100
#define TRUE 1
#define FALSE 0
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void load( int *memoryPtr );
void execute( int *memoryPtr ,  int *acPtr , int *icPtr , int *irPtr , int *opCodePtr , int *opPtr );
void dump( int *memoryPtr , int *acPtr , int *icPtr , int *irPtr , int *opCodePtr , int *opPtr );
int validWord( int number );

int main( void )
{
    int memory[ 100 ] = { 0 };
    int ac = 0; //accumulator
    int ic = 0; //instruction counter
    int ir = 0; // instruction register
    int opCode = 0; //operation code
    int op = 0; //operand

    load( memory );
    execute( memory , &ac , &ic , &ir , &opCode , &op );
    dump( memory , &ac , &ic , &ir , &opCode , &op );

    return 0;
}

void load( int *memoryPtr )
{
    int i = 0;
    long int instruction;

    printf( "\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n" ,
           "*** Welcome to Simpletron ***" ,
           "*** Please enter your program one instruction ***" ,
           "*** (or data word) at a time. I will type the ***" ,
           "*** location number and the question mark (?). ***" ,
           "*** You then type the word of that location ***" ,
           "*** Type the sentinel -99999 to stop entering ***" ,
           "*** your program. ***" );

    printf( "00 ? " );
    scanf( "%ld" , &instruction );

    while ( instruction != SENTINEL ){
        if ( !validWord( instruction ) ){
            printf( "*** Number not valid ***\n" );
        }else{
            memoryPtr[ i++ ] = instruction;
        }

        printf( "%02d ? " , i );
        scanf( "%ld" , &instruction );
    }

    printf( "*** PROGRAM LOADING COMPLETED ***\n" );
}

void execute( int *memoryPtr ,  int *acPtr , int *icPtr , int *irPtr , int *opCodePtr , int *opPtr )
{
    int fatal = FALSE;
    int temp;

    printf( "\n**** PROGRAM EXECUTION BEGINS ****\n" );

    *irPtr = memoryPtr[ *icPtr ];
    *opCodePtr = *irPtr / 100;
    *opPtr = *irPtr % 100;

    while ( *opCodePtr != HALT && fatal == FALSE ){
        switch ( *opCodePtr ){

            case READ:
                printf( "Enter an integer: " );
                scanf( "%d" , &temp );

                while ( !validWord( temp ) ){
                    printf( "Number out of range. Please enter again: " );
                    scanf( "%d" , &temp );
                }

                memoryPtr[ *opPtr ] = temp;
                ++( *icPtr );
                break;

            case WRITE:
                printf( "Contents of %02d: %d\n" , *opPtr , memoryPtr[ *opPtr ] );
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
        *opCodePtr = *irPtr / 100;
        *opPtr = *irPtr % 100;
    }//end while

    printf( "\n*** PROGRAM EXECUTION ENDS ***\n" );
}

void dump( int *memoryPtr , int *acPtr , int *icPtr , int *irPtr , int *opCodePtr , int *opPtr )
{
    int i;

    printf( "%s\n%-25s%+05d\n%-25s%5.2d\n%-25s%+05d\n%-25s%5.2d\n%-25s%5.2d\n" ,
            "REGISTERS:" , "accumulator" , *acPtr , "instructionCounter" , *icPtr ,
            "instructionRegister" , *irPtr , "operationCode" , *opCodePtr ,
            "operand" , *opPtr );

    printf( "\nMEMORY:\n" );

    //print column header
    printf( "   " );
    for ( i = 0; i <= 9; ++i ){
        printf( "%5d " , i );
    }

    //print row header
    for ( i = 0; i < SIZE; ++i ){

        if ( i % 10 == 0 ){
            printf( "\n%2d " , i );
        }
        printf( "%+05d " , memoryPtr[ i ] );
    }
}

int validWord( int number )
{
    return number >= -9999 && number <= 9999;
}
