#include <iostream>
using namespace std;

int currentPlayer;
char currentMarker;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

bool placeMarker(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentMarker;
        return true;
    }
    else
    {
        return false;
    }
}

int winner()
{
    // rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return currentPlayer;
        }
    }
    // columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return currentPlayer;
        }
    }
    // diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return currentPlayer;
    }
    return 0;
}

void swapPlayerandMarker()
{
    if (currentMarker == 'X')
    {
        currentMarker = 'O';
    }
    else
    {
        currentMarker = 'X';
    }
    if (currentPlayer == 1)
    {
        currentPlayer = 2;
    }
    else
    {
        currentPlayer = 1;
    }
}

void game()
{
    cout << "Player1 choose your marker: X or O" << endl;
    ;
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;
    drawBoard();
    int playerwon;
    for (int i = 0; i < 9; i++)
    {
        cout << "Its player " << currentPlayer << "'s turn. Enter your Slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "Not a valid slot, you may try again";
            i--;
            continue;
        }
        if (!placeMarker(slot))
        {
            cout << "Slot Occupied! Try Again\n";
            i--;
            continue;
        }
        drawBoard();
        playerwon = winner();

        if (playerwon == 1)
        {
            cout << "Player1 Wins!";
            break;
        }
        if (playerwon == 2)
        {
            cout << "Player2 Wins!";
            break;
        }
        swapPlayerandMarker();
    }
    if (playerwon == 0)
    {
        cout << "It's a Tie!";
    }
}

int main()
{
    game();
    return 0;
}