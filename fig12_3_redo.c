#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *link;
};

void count_of_nodes( struct node *head );


int main( void )
{
    struct node *head = NULL;
    //first node
    head = malloc( sizeof( struct node ) ); //create first node

    head->data = 'A';
    head->link = NULL;

    printf( "%c\n" , head->data );

    //second node
    struct node *current = NULL;
    current = malloc( sizeof( struct node ) ); //create second node

    current->data = 'B';
    current->link = NULL;
    head->link = current;

    printf( "%c\n" , current->data );

    //third node
    current = malloc( sizeof( struct node ) ); //create third node

    current->data = 'C';
    current->link = NULL;
    head->link->link = current;

    printf( "%c\n" , current->data );

    //make a fourth node
    struct node *temp = NULL;
    temp = malloc( sizeof( struct node ) );

    temp->data = 'D';
    temp->link = NULL;
    printf( "%c\n" , temp->data );

    struct node *ptr = NULL;
    ptr = head;

    while ( ptr->link != NULL ){
        ptr = ptr->link;
    }
    //once the last node is found, update link with the address of newly created node
    ptr->link = temp;



    //print no of nodes
    count_of_nodes( head );


    return 0;
}

void count_of_nodes( struct node *head )
{
    int count = 0;

    if ( head == NULL ){
        //if head is not pointing to anything, then the linked list is empty
        printf( "Node is empty\n" );
    }else{
        struct node *sPtr = NULL;
        sPtr = head;
        while( sPtr != NULL ){
            count++;
            sPtr = sPtr->link; //assign the address of next node to sPtr
        }
        printf( "count = %d\n" , count );
    }

}
