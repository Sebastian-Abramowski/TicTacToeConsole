#include <iostream>
#include <iomanip>
#include <stdlib.h> //in order to use system("cls")
#include <conio.h> //getch() - it doesnt need enter unlike normal getchar()
#include <windows.h> //sleep()
using namespace std;

char board[9];
char who;
int where;

void show_board()
{
    cout<<" "<<board[0]<<" "<<"|"<<" "<<board[1]<<" "<<"|"<<" "<<board[2]<<"\n ";
    cout<<"----------\n";
    cout<<" "<<board[3]<<" "<<"|"<<" "<<board[4]<<" "<<"|"<<" "<<board[5]<<"\n ";
    cout<<"----------\n";
    cout<<" "<<board[6]<<" "<<"|"<<" "<<board[7]<<" "<<"|"<<" "<<board[8]<<"\n ";
}

void how_to_play()
{
    system("cls");
    cout<<"\x1B[31m Every round a player needs to pick a number which represents one of the 9 spaces in the board.\n At the very top will be information about whose turn it is. \n Here is the board filled with numbers representing each space.\033[0m\t\t";
    int ascii_start=49;
    for(int i=0; i<9; i++)
    {
        board[i] = char(ascii_start); //char(int) - zwraca chara po kodach ASCII
        ascii_start++;
    }
    cout<<endl<<endl;
    show_board();
}

void default_values_board()
{
    for(int i=0; i<9; i++)
    {
        board[i] = '-';
    }
}

void one_move()
{
    show_board();
    cout<<"\n Where do you want to put your mark (enter a number from 1 to 9): ";
    cin>>where;

    switch(where)
    {
    case 1:
        if(board[0]=='-')
        {
            board[0] = who;
        }
        else
        {
            cout<<"This place is already taken! Try again!\n";
            one_move();
        }
        break;
    case 2:
        if(board[1]=='-')
        {
            board[1] = who;
        }
        else
        {
            cout<<"This place is already taken! Try again!\n";
            one_move();
        }
        break;
    case 3:
        if(board[2]=='-')
        {
            board[2] = who;
        }
        else
        {
            cout<<"This place is already taken! Try again!\n";
            one_move();
        }
        break;
    case 4:
        if(board[3]=='-')
        {
            board[3] = who;
        }
        else
        {
            cout<<"This place is already taken! Try again!\n";
            one_move();
        }
        break;
    case 5:
        if(board[4]=='-')
        {
            board[4] = who;
        }
        else
        {
            cout<<"This place is already taken! Try again!\n";
            one_move();
        }
        break;
    case 6:
        if(board[5]=='-')
        {
            board[5] = who;
        }
        else
        {
            cout<<"This place is already taken! Try again!\n";
            one_move();
        }
        break;
    case 7:
        if(board[6]=='-')
        {
            board[6] = who;
        }
        else
        {
            cout<<"This place is already taken! Try again!\n";
            one_move();
        }
        break;
    case 8:
        if(board[7]=='-')
        {
            board[7] = who;
        }
        else
        {
            cout<<"This place is already taken! Try again!\n";
            one_move();
        }
        break;
    case 9:
        if(board[8]=='-')
        {
            board[8] = who;
        }
        else
        {
            cout<<"This place is already taken! Try again!\n";
            one_move();
        }
        break;
    default:
        cout<<"Wrong number! Try again!\n";
        one_move();
    }


}

void check_win()
{
    //check horizotal win
    if(((board[0]==board[1]&&board[1]==board[2])&&(board[0]!='-'))||
      ((board[3]==board[4]&&board[4]==board[5])&&(board[3]!='-'))||
      ((board[6]==board[7]&&board[7]==board[8])&&(board[6]!='-')))
    {
        cout<<who<<" won\n";
        show_board();
        Sleep(3000);
        exit(0);

    }

    //check vertical
    if(((board[0]==board[3]&&board[3]==board[6])&&(board[0]!='-'))||
      ((board[1]==board[4]&&board[4]==board[7])&&(board[1]!='-'))||
      ((board[2]==board[5]&&board[5]==board[8])&&(board[2]!='-')))
    {
        cout<<who<<" won\n";
        show_board();
        Sleep(3000);
        exit(0);

    }

    //check diagonal
    if(((board[0]==board[4]&&board[4]==board[8])&&(board[0]!='-'))||
      ((board[2]==board[4]&&board[4]==board[6])&&(board[2]!='-')))
    {
        cout<<who<<" won\n";
        show_board();
        Sleep(3000);
        exit(0);

    }
}

void who_start()
{
    srand(time(NULL));
    if((rand() % 2)==0) //wynik 0 albo 1
    {
        who ='O';
    }
    else
    {
        who = 'X';
    }
}

void play_game()
{
    int round=1;
    system("cls");
    default_values_board();
    who_start();

    while((check_win!='O')&&(check_win!='X')&&(round<=9))
    {
        cout<<"Round number "<<round<<endl;
        if(who=='O')
        {
            cout<<"TURN: O\n";
        }
        else
        {
            cout<<"TURN: X\n";
        }

        one_move();
        check_win();

        //changing turn and adding one round
        if(who=='O')
        {
            who = 'X';
        }
        else
        {
            who = 'O';
        }

        round++;
        system("cls");
    }
}


int main()
{
    how_to_play();
    cout<<"\n\x1B[32mPress any key to continue...\033[0m\t\t";
    getch();

    play_game();

}
