#include <iostream>

using namespace std;

// ================= GAME BOARD =================

char board[3][3];

// ================= RESET BOARD FUNCTION =================

void resetBoard()
{
    char position = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = position;
            position++;
        }
    }
}

// ================= DISPLAY BOARD FUNCTION =================

void displayBoard()
{
    cout << "\n";

    for (int i = 0; i < 3; i++)
    {
        cout << " ";

        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << "\n";

        if (i < 2)
            cout << "---|---|---\n";
    }

    cout << "\n";
}

// ================= PLAYER MOVE FUNCTION =================

void playerMove(char player)
{
    int choice;
    bool validMove = false;

    while (!validMove)
    {
        cout << "Player " << player << ", Enter Position (1-9): ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                if(board[0][0] == '1')
                {
                    board[0][0] = player;
                    validMove = true;
                }
                break;

            case 2:
                if(board[0][1] == '2')
                {
                    board[0][1] = player;
                    validMove = true;
                }
                break;

            case 3:
                if(board[0][2] == '3')
                {
                    board[0][2] = player;
                    validMove = true;
                }
                break;

            case 4:
                if(board[1][0] == '4')
                {
                    board[1][0] = player;
                    validMove = true;
                }
                break;

            case 5:
                if(board[1][1] == '5')
                {
                    board[1][1] = player;
                    validMove = true;
                }
                break;

            case 6:
                if(board[1][2] == '6')
                {
                    board[1][2] = player;
                    validMove = true;
                }
                break;

            case 7:
                if(board[2][0] == '7')
                {
                    board[2][0] = player;
                    validMove = true;
                }
                break;

            case 8:
                if(board[2][1] == '8')
                {
                    board[2][1] = player;
                    validMove = true;
                }
                break;

            case 9:
                if(board[2][2] == '9')
                {
                    board[2][2] = player;
                    validMove = true;
                }
                break;

            default:
                cout << "\nInvalid Position! Try Again.\n";
        }

        if (!validMove)
        {
            cout << "\nPosition Already Taken or Invalid!\n";
        }
    }
}

// ================= WIN CHECK FUNCTION =================

bool checkWinner(char player)
{
    // Check Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
        {
            return true;
        }
    }

    // Check Columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player)
        {
            return true;
        }
    }

    // Check Main Diagonal
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
    {
        return true;
    }

    // Check Secondary Diagonal
    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
    {
        return true;
    }

    return false;
}

// ================= DRAW CHECK FUNCTION =================

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

// ================= MAIN FUNCTION =================

int main()
{
    char playAgain;

    do
    {
        resetBoard();

        char currentPlayer = 'X';

        cout << "===================================";
        cout << "\n         TIC TAC TOE GAME";
        cout << "\n===================================\n";

        while (true)
        {
            displayBoard();

            playerMove(currentPlayer);

            // Check Winner
            if (checkWinner(currentPlayer))
            {
                displayBoard();

                cout << "\nPlayer " << currentPlayer << " Wins!\n";
                break;
            }

            // Check Draw
            if (checkDraw())
            {
                displayBoard();

                cout << "\nGame Draw!\n";
                break;
            }

            // Switch Player
            if (currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        }

        cout << "\nDo You Want To Play Again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks For Playing Tic Tac Toe!\n";

    return 0;
}