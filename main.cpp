#include <iostream>
#include <iomanip>
using namespace std;

char board[9];

void show_board()
{
    cout<<" "<<board[1]<<" "<<"|"<<" "<<board[2]<<" "<<"|"<<" "<<board[3]<<"\n ";
    cout<<"----------\n";
    cout<<" "<<board[2]<<" "<<"|"<<" "<<board[3]<<" "<<"|"<<" "<<board[5]<<"\n ";
    cout<<"----------\n";
    cout<<" "<<board[6]<<" "<<"|"<<" "<<board[7]<<" "<<"|"<<" "<<board[8]<<"\n ";
}


int main()
{
    //default values for array plansza
    for(int i=0; i<9; i++)
    {
    board[i] = '-';
    }

    show_board();



}
