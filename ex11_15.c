#include <stdio.h>
int promptuser( void );

int main( void )
{
    char c;
    char sentence[ 80 ];
    char inputFile[ 20 ];
    char outputFile[ 20 ];
    int i;
    FILE *fpOut;
    FILE *fpIn;
    int userChoice;



    while( ( userChoice = promptuser() ) != EOF ){

        if ( userChoice == 1 ){
            i = 0;
            fpOut = stdout;
            fpIn = stdin;
            fputs( "\nEnter a line of text: " , stdout );

            while ( ( c = fgetc( fpIn ) ) != '\n' ){
                sentence[ i++ ] = c;
            }
            sentence[ i ] = '\0';

            fputs( "\nThe line entered was:" , fpOut );
            fputs( sentence , fpOut );
            fputs( "\n\n" , fpOut );

        }else if ( userChoice == 2 ){

            //get input file name
            i = 0;
            fputs( "Enter input file name: " , stdout );
            while ( ( c = fgetc( stdin ) ) != '\n' ){
                inputFile[ i++ ] = c;
            }
            inputFile[ i ] = '\0';

            //get output file name
            i = 0;
            fputs( "Enter output file name: " , stdout );
            while ( ( c = fgetc( stdin ) ) != '\n' ){
                outputFile[ i++ ] = c;
            }
            outputFile[ i ] = '\0';

            //open input file
            if ( ( fpIn = fopen( inputFile , "r+" ) ) == NULL ){
                printf( "file could not be opened\n" );
            }

            //open output file
            if ( ( fpOut = fopen( outputFile , "w" ) ) == NULL ){
                printf( "file could not be opened\n" );
            }

            //get strings from file
            fputs( "\ngetting strings from input file...\n" , stdout );

            i = 0;
            while ( ( c = fgetc( fpIn ) ) != EOF ){
                sentence[ i++ ] = c;
            }sentence[i] = '\0';
            printf("%s" , sentence);

            fputs( "\nwriting strings to output file...\n" , stdout );
            fprintf( fpOut , "%s" , sentence );

        }else{
            printf( "Invalid choice");
        }

    }//end while



    return 0;
}


int promptuser( void )
{
    int choice;
    int temp;

    printf( "Enter 1 for stdin & stdout\nEnter 2 for read and write from a file\nEOF to end\n:" );
    scanf( "%d" , &choice );
    //flush newline from stdin buffer
    temp = fgetc( stdin );

    return choice;
}
