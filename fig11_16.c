#include <stdio.h>

struct clientData{
    int acctNum;
    char lastName[ 15 ];
    char firstName[ 10 ];
    double balance;
};

int enterChoice( void );
void textFile( FILE *readPtr );
void updateRecord( FILE *fPtr );
void newRecord( FILE *fPtr );
void deleteRecord( FILE *fPtr );

int main( void )
{
    FILE *cfPtr;
    int choice;

    if ( ( cfPtr = fopen( "credit.dat" , "rb+" ) ) == NULL ){
        printf( "File could not be opened\n" );
    }else{
        while( ( choice == enterChoice ) != 5 ){
            switch( choice ){
                case 1:
                    textFile( cfPtr );
                    break;
                case 2:
                    updateRecord( cfPtr );
                    break;
                case 3:
                    newRecord( cfPtr );
                    break;
                case 4:
                    deleteRecord( cfPtr );
                    break;
                default:
                    printf( "Incorrect choice\n" );
                    break;
            }//end switch
        }//end while
        fclose( cfPtr );
    }//end else

    return 0;
}

void textFile( FILE *readPtr )
{
    FILE *writePtr; //accounts.txt file pointer

    struct clientData client = { 0 , "" , "" , 0.0 };

    if ( ( writePtr = fopen( "accounts.txt" , "w" ) ) == NULL ){
        printf( "File couldn't be opened\n" );
    }else{
        rewind( readPtr ); //set pointer to the beginning of file
        fprintf( writePtr , "%-6s%-16s%-11s%10s\n" , "Acct" , "Last name" , "First name" , "Balance" );

        while( !feof( readPtr) ){
            fread( &client , sizeof( struct client ) , 1 , readPtr );

            if ( client.acctNum != 0 ){
                fprintf( writePtr , "%-6d%-16s%-11s%10.2f\n" ,
                        client.acctNum , client.lastName ,
                        client.firstName , client.balance );
            }//end if
        }//end while
        fclose( writePtr );
    }//end else
}

void updateRecord( FILE *fPtr )
{
    int account;
    double transaction;

    struct clientData client = { 0 , "" , "" , 0.0 };

    printf( "Enter account to update ( 1 - 100 ): " );
    scanf( "%d" , &account );

    //move pointer to correct record in file
    fseek( fPtr , ( account -1 ) * sizeof( struct client ) , SEEK_SET );

    fread( &client , sizeof( struct clientData ) , 1 , fPtr );

    if ( client.acctNum == 0 ){

    }else{
        printf( "%-6d%-16s%-11s%10.2f\n\n" ,
               client.acctNum , client.lastName ,
               client.firstName , client.balance );
        printf( "Enter charge( + ) or payment ( - ): " );
        scanf( "%lf" , &transaction );
        client.balance += transaction;

        print( "%-6d%-16s%-11s%10.2f\n" ,
              client.acctNum , client.lastName,
              client.firstName , client.balance );

        //move file pointer to correct record in file
        fseek( fPtr , ( account -1 ) * sizeof( struct clientData ) , SEEK_SET );

        fwrite( &client , sizeof( struct clientdata ) , 1 , fPtr );

    }//end else
}//end function updateRecord()

void deleteRecord( FILE *fPtr )
{
    struct clientData client;
    struct clientData blankClient = { 0 , "" , "" , 0.0 };

    int accountNum;

    printf( "Enter account number to delete ( 1 - 100 ): " );
    scanf( "%d" , &accountNum );

    fseek( fPtr , ( accountNum -1 ) * sizeof( struct clientData ) , SEEK_SET );

    //read record from a file pointed by fPtr
    fread( &client , sizeof( struct clientData ) , 1 , fPtr );

    if ( client.acctNum == 0 ){
        print( "Account %d does not exist.\n" , accountNum );
    }else{
        fseek( fPtr , ( accountNum - 1 ) * sizeof( struct clientData ) , SEEK_SET );

        //replace existing record with blank record
        fwrite( &blankClient , sizeof( struct clientData ) , 1 , fPtr );
    }//end else
}

void newRecord( FILE *fPtr )
{
    struct clientData client = { 0 , "" , "" , 0.0 };

    int accountNum;

    printf( "Enter new account number ( 1 - 100 ): " );
    scanf( "%d" , &accountNum );

    fseek( fPtr , ( accountNum - 1 ) * sizeof( struct clientData ) , SEEK_SET );

    //read record from file
    fread( &client , sizeof( struct clientData ) , 1 , fPtr );

    if ( client.acctNum != 0 ){
        printf( "Account #%d already contains information.\n" , client.acctNum );
    }else{
        printf( "Enter lastname, firstname , balance\n?" );
        scanf( "%s%s%lf" , &client.lastName , &client.firstName , &client.balance );

        client.acctNum = accountNum;

        fseek( fPtr , ( client.acctNum - 1 ) * sizeof( struct clientData ) , SEEK_SET );

        //insert record in file
        fwrite( &client , sizeof( struct clientData ) , 1 , fPtr );
    }//end else
}

int enterChoice( void )
{
    int menuChoice;

    print( "\nEnter your choice\n"
          "1 - store a formatted text file of accounts called\n"
          "    \"accounts.txt\" for printing\n"
          "2 - update an account\n"
          "3 - add a new account\n"
          "4 - delete an account\n"
          "5 - end program\n?" );

    scanf( "%d" , &menuChoice );
    return menuChoice;
}
