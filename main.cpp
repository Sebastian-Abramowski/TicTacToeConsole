#include <iostream>
#include <iomanip>
#include <stdlib.h> //in order to use system("cls")
#include <conio.h> //getch() - it doesnt need enter unlike normal getchar()
#include <windows.h>
using namespace std;

char board[9];

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

void play_game()
{
    system("cls");
    default_values_board();
    show_board();


}


int main()
{
    how_to_play();
    cout<<"\n\x1B[32mPress any key to continue...\033[0m\t\t";
    getch();



}
