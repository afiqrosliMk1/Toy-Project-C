//global warming quiz
#include <stdio.h>

int main( void )
{
    char answer;
    int score = 0;

    printf( "5 + 5 = ?\n" );
    printf( "A. 13\nB. 12\nC. 8\nD. 25\n" );

    switch ( answer = getchar() )
    {
        case 'D':
        case 'd':
            score++;
            getchar(); //get \n to clear input buffer
            break;

        default:
            getchar(); //get \n to clear input buffer
            break;
    }

    printf( "Ibu negara Malaysia?\n" );
    printf( "A. Seoul\nB. Kabul\nC. Bangkok\nD. Kuala Lumpur\n" );

    switch ( answer = getchar() )
    {
        case 'D':
        case 'd':
            score++;
            getchar(); //get \n to clear input buffer
            break;

        default:
            getchar(); //get \n to clear input buffer
            break;
    }

    printf( "8 / 8 ?\n" );
    printf( "A. 1\nB. 7\nC. 0\nD. 2\n" );

    switch ( answer = getchar() )
    {
        case 'A':
        case 'a':
            score++;
            getchar(); //get \n to clear input buffer
            break;

        default:
            getchar(); //get \n to clear input buffer
            break;
    }

    printf( "Tarikh hari raya?\n" );
    printf( "A. 1 Syawal\nB. 12 Zulhijjah\nC. 8 Muharram\nD. 25 Safar\n" );

    switch ( answer = getchar() )
    {
        case 'A':
        case 'a':
            score++;
            getchar(); //get \n to clear input buffer
            break;

        default:
            getchar(); //get \n to clear input buffer
            break;
    }

    printf( "A + A?\n" );
    printf( "A. 2A\nB. A^2\nC. dy/dx\nD. 0.9\n" );

    switch ( answer = getchar() )
    {
        case 'A':
        case 'a':
            score++;
            getchar(); //get \n to clear input buffer
            break;

        default:
            getchar(); //get \n to clear input buffer
            break;
    }
    printf( "Your score: %d\n" , score );

    return 0;
}
