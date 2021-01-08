#include <stdio.h>

#define SIZE 100
#define SENTINEL -99999
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

void load( int *loadMemory );
void execute( int *memory , int *acPtr , int *icPtr , int *irPtr , int *opCodePtr , int *opPtr );
void dump( int *memory , int accumulator , int instructionCounter , int instructionRegister , int operationCode , int operand );
int validWord( int word );

int main( void )
{
    int memory[ SIZE ]; //memory array
    int ac = 0; //accumulator
    int ic = 0; //instruction counter
    int opCode = 0; //operation code
    int op = 0; //operand
    int ir = 0; //instruction register
    int i = 0; //counter

    //clear memory
    for ( i = 0; i < SIZE; ++i ){
        memory[ i ] = 0;
    }

    load( memory );
    execute( memory , &ac , &ic , &ir , &opCode , &op );
    dump( memory , ac , ic , ir , opCode , op );

    return 0;
}

void load( int *loadMemory )
{
    long int instruction; //current instruction
    int i = 0;

    printf( "%s\n%s\n%s\n%s\n%s\n%s\n%s\n" ,
           "***         Welcome to Simpletron          ***" ,
           "*** Please enter your program one instruction ***" ,
           "*** (or data word) at a time. I will type the ***" ,
           "*** location number and a question mark ( ? ). ***" ,
           "*** You then type the word for that location. ***" ,
           "*** Type the sentinel -99999 to stop entering ***" ,
           "*** your program.                             ***" );

    printf( "00 ? " );
    scanf( "%ld" , &instruction );

    while ( instruction != SENTINEL ){
        if ( !validWord( instruction ) ){
            printf( "Number out of range. Please enter again.\n" );
        }else{
            loadMemory[ i++ ] = instruction;
        }
        printf( "%02d ? " , i );
        scanf( "%ld" , &instruction );
    }
}

void execute( int *memory , int *acPtr , int *icPtr , int *irPtr , int *opCodePtr , int *opPtr )
{
    int fatal = FALSE; //fatal error handling flag
    int temp; //temporary holding space

    printf( "\n**********START SIMPLETRON EXECUTION*************\n\n" );

    //separate operation code and operand;
    *irPtr = memory[ *icPtr ];
    *opCodePtr = *irPtr / 100;
    *opPtr = *irPtr % 100;

    while ( *opCodePtr != HALT && !fatal ){
        switch ( *opCodePtr ){
            //read data from terminal to memory location
            case READ:
                printf( "Enter an integer: " );
                scanf( "%d" , &temp );

                while ( !validWord( temp ) ){
                    printf( "Number out of range. Please enter again: " );
                    scanf( "%d" , &temp );
                }

                memory[ *opPtr ] = temp;
                ++( *icPtr );
                break;

            //write data from memory to screen
            case WRITE:
                printf( "Contents of %02d: %d\n" , *opPtr , memory[ *opPtr ] );
                ++( *icPtr );
                break;

            //load data from memory into accumulator
            case LOAD:
                *acPtr = memory[ *opPtr ];
                ++( *icPtr );
                break;

            //store data from accumulator into memory
            case STORE:
                memory[ *opPtr ] = *acPtr;
                ++( *icPtr );
                break;

            case ADD:
                temp = *acPtr + memory[ *opPtr ];

                if ( !validWord( temp ) ){
                    printf( "*******FATAL ERROR: Accumulator overflow********\n" );
                    printf( "********Simpletron execution abnormally terminated*****\n" );
                    fatal = TRUE;
                }else{
                    *acPtr = temp;
                    ++( *icPtr );
                }
                break;

            case SUBTRACT:
                temp = *acPtr - memory[ *opPtr ];

                if ( !validWord( temp ) ){
                    printf( "***********FATAL ERROR: Accumulator overflow******\n" );
                    printf( "*********Simpletron execution abnormally terminated*******\n" );
                    fatal = TRUE;
                }else{
                    *acPtr = temp;
                    ++( *icPtr );
                }
                break;

            case DIVIDE:
                if ( memory[ *opPtr ] == 0 ){
                    printf( "*********FATAL ERROR: Attempt to divide by zero******\n" );
                    printf( "**********Simpletron execution abnormally terminated********\n" );
                    fatal = TRUE;
                }else{
                    *acPtr /= memory[ *opPtr ];
                    ++( *icPtr );
                }
                break;

            case MULTIPLY:
                temp = *acPtr * memory[ *opPtr ];

                if ( !validWord( temp ) ){
                    printf( "*************FATAL ERROR: Accumulator overflow*******\n" );
                    printf( "*************Simpletron execution abnormally terminated*******\n" );
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
                printf( "******FATAL ERROR: Invalid opcode detected *******\n" );
                printf( "*********Simpletron Execution abnormally terminated****\n" );
                fatal = TRUE;
                break;

        }//end switch

        //separate next operation code and operand
        *irPtr = memory[ *icPtr ];
        *opCodePtr = *irPtr / 100;
        *opPtr = *irPtr % 100;

    }//end while

    printf( "\n***************END SIMPLETRON EXECUTION**************\n" );
}

void dump( int *memory , int accumulator , int instructionCounter , int instructionRegister , int operationCode , int operand )
{
    int i;
    printf( "\n%s\n%-23s%+05d\n%-23s%5.2d\n%-23s%+05d\n%-23s%5.2d\n%-23s%5.2d" ,
           "REGISTERS:" , "accumulator" , accumulator , "instructionCounter" ,
           instructionCounter , "instructionRegister" , instructionRegister ,
           "operationCode" , operationCode , "operand" , operand );
    printf( "\n\nMEMORY:\n  " );

    for ( i = 0; i <= 9; ++i ){
        printf( "%5d " , i );
    }//end for

    for ( i = 0; i < SIZE; ++i ){
        if ( i % 10 == 0 ){
            printf( "\n%2d " , i );
        }

        printf( "%+05d " , memory[ i ] );
    }//end for

    printf( "\n" );
}//end function dump

int validWord( int word )
{
    return word >= -9999 && word <= 9999;
}
