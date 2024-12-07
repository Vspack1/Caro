#include <iostream>  
#include <vector>  

using namespace std;

// Function to print the game board  
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check for a win  
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns  
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals  
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Main function to run the tic-tac-toe game  
int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char player = 'X';
    int row, col;
    int turns = 0;

    while (true) {
        printBoard(board);
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> row >> col;

        // Validate input  
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Place the move  
        board[row][col] = player;
        turns++;

        // Check for a win  
        if (checkWin(board, player)) {
            printBoard(board);
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        // Check for a draw  
        if (turns == 9) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players  
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}