#include <stdio.h>

//WORK IN PROGRESS: LAST UPDATE 16/9/2020. Continue with updateRecord, still need some correction

int enterChoice( void );
void textFile( FILE *readPtr );
void updateRecord( FILE *fPtr );
void newRecord( FILE *fPtr );
void deleteRecord( FILE *fPtr );

struct clientData{
    int acctNum;
    char lastName[ 15 ];
    char firstName[ 10 ];
    double balance;
};

int main( void )
{
    int choice;
    FILE *cfPtr;

    if ( ( cfPtr = fopen( "credit.dat" , "rb+" ) ) == NULL ){
        printf( "File could not be opened\n" );
    }else{
        while ( ( choice = enterChoice() ) != 5 ){
            switch ( choice ){
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
                    fprintf( stdout , "Invalid value\n" );
                    break;
            }//end switch
        }//end while
    }
    return 0;
}

void textFile( FILE *readPtr )
{
    struct clientData client = { 0 , "" , "" , 0.0 };
    FILE *tPtr;

    if ( ( tPtr = fopen( "accounts.txt" , "w" ) ) == NULL ){
        printf( "File could not be opened\n" );
    }else{
        rewind( readPtr ); //set pointer to the beginning of file

        while ( !feof( readPtr ) ){
            fread( &client , sizeof( struct clientData ) , 1 , readPtr );
            if ( client.acctNum != 0 ){
                fprintf( tPtr , "%d %s %s %.2f\n" , client.acctNum , client.lastName , client.firstName , client.balance );
            }
        }//end while
        fclose( tPtr );
    }//end else

}//end function textFile

void updateRecord( FILE *fPtr )
{
    struct clientData client = { 0 , "" , "" , 0.0 };
    int accNoToUpdate;
    double amount;

    printf( "Please enter account no ( 1 - 100 ) to update: " );
    scanf( "%d" , &accNoToUpdate );

    //move file pointer to correct location in credit.dat
    fseek( fPtr , ( accNoToUpdate - 1 ) * sizeof( struct clientData ) , SEEK_SET );

    fread( &client , sizeof( struct clientData ) , 1 , fPtr );

    if ( client.acctNum == 0 ){
        printf( "Account didn't exist\n" );
    }else{
        printf( "%d %s %s %.2f\n" , client.acctNum , client.lastName , client.firstName , client.balance );
        printf( "Enter charge (+) or payment(-): " );
        scanf( "%lf" , &amount );

        client.balance += amount;
        printf( "%d %s %s %.2f\n" , client.acctNum , client.lastName , client.firstName , client.balance );

        //move file pointer to correct record in file
        fseek( fPtr , ( accNoToUpdate - 1 ) * sizeof( struct clientData ) , SEEK_SET );
        //write updated record over old record in file
        fwrite( &client , sizeof( struct clientData ) , 1 , fPtr );
    }
}

void newRecord( FILE *fPtr )
{
    int account;
    struct clientData client = { 0 , "" , "" , 0.0 };;

    printf( "Enter account number to add: " );
    scanf( "%d" , &account );

    //move file pointer to correct record
    fseek( fPtr , ( account - 1 ) * sizeof( struct clientData ) , SEEK_SET );
    //read records from file to struct client
    fread( &client , sizeof( struct clientData ) , 1 , fPtr );

    if ( client.acctNum != 0 ){
        printf( "Account %d already exist\n" , client.acctNum );
    }else{
        printf( "Enter last name , first name , balance:\n?" );
        scanf( "%s%s%lf" , client.lastName , client.firstName , &client.balance );
        client.acctNum = account;
        fseek( fPtr , ( account -1 ) * sizeof( struct clientData ) , SEEK_SET );
        fwrite( &client , sizeof( struct clientData ) , 1 , fPtr );
    }
}

void deleteRecord( FILE *fPtr )
{
    struct clientData client;
    struct clientData blankClient = { 0 , "" , "" , 0.0 };
    int account;

    printf( "Enter account no to delete: " );
    scanf( "%d" , &account );

    //move file pointer to correct record
    fseek( fPtr , ( account - 1 ) * sizeof( struct clientData ) , SEEK_SET );
    //read record into structure client
    fread( &client , sizeof( struct clientData ) , 1 , fPtr );

    if ( client.acctNum == 0 ){
        printf( "file does not exist\n" );
    }else{
        printf( "The following record will be erased:\n" );
        printf( "%d %s %s %.2f\n" , client.acctNum , client.lastName , client.firstName , client.balance );
        printf( "\nErasing...\n" );
        //move file pointer to correct record
        fseek( fPtr , ( account - 1 ) * sizeof( struct clientData ) , SEEK_SET );
        //write blank record to the existing record
        fwrite( &blankClient , sizeof( struct clientData ) , 1 , fPtr );
    }
}

int enterChoice( void )
{
    int menuChoice;
    fprintf( stdout , "1 - read\n2 - update\n3 - add\n4 - delete\n5 - terminate\n?" );
    fscanf( stdin , "%d" , &menuChoice );
    return menuChoice;
}
