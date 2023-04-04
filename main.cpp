#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

char currentPlayer = 'X';

void drawBoard()
{
    cout << "-------------" << endl;
    for(int i=0; i<3; i++)
    {
        cout << "| ";
        for(int j=0; j<3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

void getPlayerChoice()
{
    int choice;
    cout << "Player " << currentPlayer << ", enter your choice: ";
    cin >> choice;

    int row = (choice-1) / 3;
    int col = (choice-1) % 3;

    if(board[row][col] == 'X' || board[row][col] == 'O')
    {
        cout << "That spot is already taken. Please choose another spot." << endl;
        getPlayerChoice();
    }
    else
    {
        board[row][col] = currentPlayer;
    }
}

void switchPlayer()
{
    if(currentPlayer == 'X')
    {
        currentPlayer = 'O';
    }
    else
    {
        currentPlayer = 'X';
    }
}

bool checkForWin()
{
    // check rows
    for(int i=0; i<3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
    }

    // check columns
    for(int i=0; i<3; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }

    // check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return true;
    }

    return false;
}

bool checkForTie()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cout << "Welcome to Tic Tac Toe!" << endl;
    drawBoard();

    while(true)
    {
        getPlayerChoice();
        drawBoard();

        if(checkForWin())
        {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        else if(checkForTie())
        {
            cout << "It's a tie!" << endl;
            break;
        }
        switchPlayer();
    }

    return 0;
}

