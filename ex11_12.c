#include <stdio.h>

//prototype
void initRecord( FILE *readPtr );
void listRecord( FILE *readPtr );
void deleteRecord( FILE *readPtr );
void updateRecord( FILE *readPtr );
void textFile( FILE *readPtr );
int userChoice( void );
void newRecord( FILE *readPtr );

struct inventory {
    int id;
    char name[ 30 ];
    int quantity;
    double cost;
};

int main( void )
{
    FILE *fPtr;
    int i;
    struct inventory blankInventory = { 0 , "" , 0 , 0.0 };
    int choice;

    //================creating file===========================
    if ( ( fPtr = fopen( "hardware.dat" , "wb" ) ) == NULL ){
        printf( "file could not be opened\n" );
    }else{
        for ( i = 1; i <= 100; ++i ){
            fwrite( &blankInventory , sizeof( struct inventory ) , 1 , fPtr );
        }
    }
    //=====================closing file=======================

    //====================reopen file in write mode===========

    if ( ( fPtr = fopen( "hardware.dat" , "rb+" ) ) == NULL ){
        printf( "file could not be opened\n" );
    }else{
        initRecord( fPtr );
    }

    while ( ( choice = userChoice() ) != 6 ){

        switch ( choice ){
            case 1:
                textFile( fPtr );
                break;
            case 2:
                updateRecord( fPtr );
                break;
            case 3:
                newRecord( fPtr );
                break;
            case 4:
                deleteRecord( fPtr );
                break;
            case 5:
                listRecord( fPtr );
            default:
                printf( "invalid choice\n" );
                break;
        }//end switch choice
    }//end while


    fclose( fPtr );

    return 0;
}//end of main()

int userChoice( void )
{
    int userInput;

    printf( "Please select the options below:\n" );
    printf( "1)print record to a text file\n2)update record\n3)add new record\n"
           "4)delete record\n5)list record to terminal\n6)EXIT\n" );
    scanf( "%d" , &userInput );

    return userInput;
}

void textFile( FILE *readPtr )
{
    FILE *txPtr;
    struct inventory blankInventory = { 0 , "" , 0 , 0.0 };

    if ( ( txPtr = fopen( "hardware_list.txt" , "w" ) ) == NULL ){
        printf( "text file could not be created" );
    }else{
        rewind( readPtr );

        while ( !feof( readPtr ) ){
            fread( &blankInventory , sizeof( struct inventory ) , 1 , readPtr );
            fprintf( txPtr , "%3d%15s%3d%.2f\n" , blankInventory.id , blankInventory.name , blankInventory.quantity , blankInventory.cost );
        }
    }//end else

}

void updateRecord( FILE *readPtr )
{
    int toolID;
    struct inventory blankInventory = { 0 , "" , 0 , 0.0 };

    printf( "Enter tool id to update: " );
    scanf( "%d" , &toolID);

    fseek( readPtr , ( toolID - 1 ) * sizeof( struct inventory ) , SEEK_SET );
    fread( &blankInventory , sizeof( struct inventory ) , 1 , readPtr );

    if ( blankInventory.id == 0 ){
        printf( "tool doesn't exist\n" );
    }else{
        fprintf( stdout , "update record for: %3d%s%3d%10.2f\n" , blankInventory.id ,
                blankInventory.name , blankInventory.quantity , blankInventory.cost );

        printf( "Enter new values to update: " );
        printf( "Tool id: " );
        scanf( "%d" , &blankInventory.id );
        printf( "Tool name: " );
        scanf( "%s" , blankInventory.name );
        printf( "Tool quantity: " );
        scanf( "%d" , &blankInventory.quantity );
        printf( "Tool cost: " );
        scanf( "%lf" , &blankInventory.cost );

        fseek( readPtr , ( blankInventory.id - 1 ) * sizeof( struct inventory ) , SEEK_SET );
        fwrite( &blankInventory , sizeof( blankInventory ) , 1 , readPtr );

    }//end else

}

void deleteRecord( FILE *readPtr )
{
    struct inventory blankInventory = { 0 , "" , 0 , 0.0 };
    int toolID;

    printf( "Enter the tool ID to delete: " );
    scanf( "%d" , &toolID );

    if ( toolID == 0 ){
        printf( "tool does not exist\n" );
    }else{
        fseek( readPtr , ( toolID - 1 ) * sizeof( struct inventory ) , SEEK_SET );
        fwrite( &blankInventory , sizeof( blankInventory ) , 1 , readPtr );
    }//end else

}

void listRecord( FILE *readPtr )
{
    struct inventory blankInventory = { 0 , "" , 0 , 0.0 };

    rewind( readPtr );

    printf( "%3s%15s%3s%3s\n" , "ID" , "Tool Name" , "Quantity" , "Cost" );

    while ( !feof( readPtr ) ){
        fread( &blankInventory , sizeof( struct inventory ) , 1 , readPtr );
        fprintf( stdout , "%3d%s%3d%10.2f\n" , blankInventory.id ,
                blankInventory.name , blankInventory.quantity , blankInventory.cost );
    }

}

void initRecord( FILE *readPtr )
{
    struct inventory blankInventory = { 0 , "" , 0 , 0.0 };
    printf( "Enter tool id , name , quantity , cost:( EOF to end ): " );

    while ( scanf( "%d%[^0-9]%d%lf" , &blankInventory.id , blankInventory.name ,
            &blankInventory.quantity , &blankInventory.cost ) != EOF ){


        fseek( readPtr , ( blankInventory.id - 1 ) * sizeof( struct inventory ) , SEEK_SET );
        fwrite( &blankInventory , sizeof( struct inventory ) , 1 , readPtr );

        printf( "Enter tool id , name , quantity , cost:( EOF to end ): " );

    }//end while
}

void newRecord( FILE *readPtr )
{
    struct inventory blankInventory = { 0 , "" , 0 , 0.0 };
    int toolID;

    printf( "Enter tool ID: " );
    scanf( "%d" , &toolID );

    fseek( readPtr , ( toolID - 1 ) * sizeof( struct inventory ) , SEEK_SET );
    fread( &blankInventory , sizeof( struct inventory ) , 1 , readPtr );

    if ( blankInventory.id != 0 ){
        printf( "Record already exist!\n" );
    }else{
        printf( "Enter name , quantity , cost: " );
        scanf( "%s%d%lf" , blankInventory.name , &blankInventory.quantity , &blankInventory.cost );

        fseek( readPtr , ( toolID - 1 ) * sizeof( struct inventory ) , SEEK_SET );
        fwrite( &blankInventory , sizeof( struct inventory ) , 1 , readPtr );
    }

}
