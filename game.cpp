#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char score;//current_marker;
int playing;//current_player;

// Function to display the board
void displayBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n-------------\n";
    }
}

// Function to place a marker on the board
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') 
    {
        board[row][col] = score;
        return true;
    }else 
    {
        return false;
    }
}

// Function to check for a win
int checkWinner() {
    // Rows and columns
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return playing;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return playing;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return playing;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return playing;

    return 0; // No winner yet
}

// Function to swap player turns
void swapPlayerTurn() 
{
    if(score=='X') 
        score='O';
    else
        score= 'X';

   // playing;//=(playing == 1) ? 2 : 1;
    if(playing==1)
    playing=2;
    else
    playing=1;
}

// Function to check for a draw
bool isDraw() {
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++) 
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}

// Function to handle computer's move (random move)
void computerMove() {
    int slot;

    do {
        slot = rand() % 9 + 1; // Random slot between 1 and 9
    } while (!placeMarker(slot)); // Ensure the slot is available

    cout << "Computer chooses slot " << slot << endl;
}

int main() {
    cout << "Welcome to Tic Tac Toe! You will play against the computer.\n";
    cout << "Choose your marker (X or O): ";
    char human_mark;
    cin >> human_mark;
    cout<<"You have chossen the symbel :"<<human_mark<<endl;
    playing= 1;
    score= human_mark;
    char computer_mark;// = (player_marker == 'X') ? 'O' : 'X';
    if(human_mark=='X')
    computer_mark='O';
    else
    computer_mark='X';
    cout<<"The opponent symbol is:"<<computer_mark<<endl;
    displayBoard();
    int winner = 0;
    while (winner == 0 && !isDraw()) {
        int slot;

        if (playing == 1) {
            // Human player's turn
            cout << "YOURTURN: ";
            cin >> slot;

            if (slot < 1 || slot > 9 || !placeMarker(slot)) 
            {
                cout << "Invalid move! Try again"<<endl;
                continue;
            }
        } else 
        {
            score=computer_mark;
            cout<<"COMPUTERTURN:   "<<endl;
            computerMove();
        }

        displayBoard();
        winner = checkWinner();

        if (winner == 0) {
            swapPlayerTurn();
        }
    }

    if (winner == 1) {
        cout << "Congratulations! You win"<<endl;
    } else if (winner == 2) {
        cout << "Computer wins"<<endl;;
    } else {
        cout << "It's a draw"<<endl;;
    }

    return 0;
}
