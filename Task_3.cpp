#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board(3, vector<char>(3));
char currentPlayer = 'X';

// Draw the board
void printBoard() {
    cout << "\n🧩 Current Board:\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---\n";
    }
}

// Initialize with numbers 1-9
void resetBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ch++;
}

// Check if a player has won
bool isWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    // Check diagonals
    return (board[0][0] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][2] == currentPlayer) ||
           (board[0][2] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][0] == currentPlayer);
}

// Check for draw
bool isDraw() {
    for (auto& row : board)
        for (char cell : row)
            if (cell != 'X' && cell != 'O')
                return false;
    return true;
}
bool makeMove(int pos) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "❗ Cell already taken. Try again.\n";
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}
int main() {
    char again;

    do {
        resetBoard();
        currentPlayer = 'X';

        cout << "🎮 Welcome to Two-Player Tic-Tac-Toe!\n";

        while (true) {
            printBoard();
            int move;
            cout << "🔁 Player " << currentPlayer << ", choose position (1-9): ";
            cin >> move;

            if (!makeMove(move))
                continue;

            if (isWinner()) {
                printBoard();
                cout << "🏆 Player " << currentPlayer << " wins!\n";
                break;
            } else if (isDraw()) {
                printBoard();
                cout << "🤝 It's a draw!\n";
                break;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "🔁 Do you want to play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "👋 Thanks for playing!\n";
    return 0;
}
