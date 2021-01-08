//ex 11_11 part 2. nameage.dat already created in part 1
#include <stdio.h>
#include <string.h>

void initRecord( FILE *initPtr );
void updateRecord( FILE *updatePtr );
void deleteRecord( FILE *deletePtr );
void writeText( FILE *writePtr );
int userChoice();

struct person{
    char lastName[ 15 ];
    char firstName[ 15 ];
    char age[ 4 ];
};

int main( void )
{
    FILE *fPtr;
    int selection;

    if ( ( fPtr = fopen( "nameage.dat" , "rb+" ) ) == NULL  ){
        printf( "file could not be opened\n" );
    }else{

        while ( ( selection = userChoice() ) != 5 ){

            switch( selection ){

                case 1:
                    initRecord( fPtr );
                    break;
                case 2:
                    updateRecord( fPtr );
                    break;
                 case 3:
                     deleteRecord( fPtr );
                    break;
                 case 4:
                    writeText( fPtr );
                    break;
                default:
                    printf( "invalid choice\n" );

            }//end switch

        }//end while

    }//end else

    return 0;
}

void initRecord( FILE *initPtr )
{
    int i;
    struct person blankPeople = { "" , "unassigned" , "0" };

            //input two records
    for ( i = 1; i <= 3; ++i ){
        printf( "Enter lastname , firstname , age: " );
        fscanf( stdin , "%s %s %s" , blankPeople.lastName , blankPeople.firstName , blankPeople.age );
        fwrite( &blankPeople , sizeof( struct person ) , 1 , initPtr );
    }
}

void updateRecord( FILE *updatePtr )
{
    char lastname[ 15 ];
    //int i;
    struct person blankPeople = { "" , "unassigned" , "0" };
    int found = 0;

        //update record
    printf( "Enter last name to update record: " );
    scanf( "%s" , lastname );
    rewind( updatePtr );
    printf( "DEBUG:%p\n" , updatePtr );

    while ( !feof( updatePtr ) && found == 0 ){
        fread( &blankPeople , sizeof( struct person ) , 1 , updatePtr );
        printf( "DEBUG:%p\n" , updatePtr );

        //if a match is found
        if ( strcmp( blankPeople.lastName , lastname ) == 0 ){
            found = 1; //set the found condition to true
        }

    }//end while

    if ( found == 0 ){
        printf( "No info\n" );
    }else{

        printf( "Updating current record: %s %s %s\n" , blankPeople.lastName , blankPeople.firstName , blankPeople.age );
        printf( "Enter new details: lastname , firstname , age: " );
        fscanf( stdin , "%s %s %s" , blankPeople.lastName , blankPeople.firstName , blankPeople.age );
        fwrite( &blankPeople , sizeof( struct person ) , 1 , updatePtr );

    }
}
void deleteRecord( FILE *deletePtr )
{
    char lastname[ 15 ];
    //int i;
    struct person blankPeople = { "" , "unassigned" , "0" };
    struct person temp;
    int found = 0;

        //update record
    printf( "Enter last name to delete record: " );
    scanf( "%s" , lastname );
    rewind( deletePtr );

    while ( !feof( deletePtr ) && found == 0 ){
        fread( &temp , sizeof( struct person ) , 1 , deletePtr );

        //if a match is found
        if ( strcmp( temp.lastName , lastname ) == 0 ){
            found = 1; //set the found condition to true
        }

    }//end while

    if ( found == 0 ){
        printf( "No info\n" );
    }else{
        printf( "Delete current record: %s %s %s\n" , temp.lastName , temp.firstName , temp.age );
        printf( "Deleting.." );
        //overwrite record with blankRecord
        fwrite( &blankPeople , sizeof( struct person ) , 1 , deletePtr );
        fread( &temp , sizeof( struct person ) , 1 , deletePtr );
        printf( "Record value after deleting: %s %s %s\n" , temp.lastName , temp.firstName , temp.age );
    }
}

void writeText( FILE *writePtr )
{
    FILE *tPtr;
    struct person blankPeople = { "" , "unassigned" , "0" };

    if ( ( tPtr = fopen( "people.txt" , "w" ) ) == NULL ){
        printf( "people.txt couldn't be opened\n" );
    }else{

        rewind( writePtr );
        while ( !feof( writePtr ) ){
            fread( &blankPeople , sizeof( struct person ) , 1 , writePtr );
            printf( "lastname , firstname , age: %s %s %s\n" , blankPeople.lastName , blankPeople.firstName , blankPeople.age );
            fprintf( tPtr , "%s %s %s\n" , blankPeople.lastName , blankPeople.firstName , blankPeople.age );
        }

    }
    fclose( tPtr );
}

int userChoice()
{
    int choice;

    printf( "Enter choice:\n1)initialize record\n2)update record\n3)delete record\n4)write to text file\n5)exit\n\n" );
    scanf( "%d" , &choice );
    return choice;
}
