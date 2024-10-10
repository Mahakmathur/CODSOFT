#include <iostream>
#include <vector>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<string>& board) {
    cout << endl;
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << endl;
    cout << endl;
}

// Function to check if a move is valid
bool isValidMove(int move, const vector<string>& board) {
    return (move >= 1 && move <= 9 && board[move] != "X" && board[move] != "O");
}

// Function to make a move on the board
void makeMove(int move, const string& playerSymbol, vector<string>& board) {
    board[move] = playerSymbol;
}

// Function to check for a winner
string checkWinner(const string& symbol, const vector<string>& board) {
    const vector<vector<int>> winningCombos = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Rows
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Columns
        {1, 5, 9}, {3, 5, 7}             // Diagonals
    };
    for (const auto& combo : winningCombos) {
        if (board[combo[0]] == symbol && board[combo[1]] == symbol && board[combo[2]] == symbol) {
            return symbol;
        }
    }
    return "0";
}

int main() {
    vector<string> board(10); // Initialize board for 1 to 9
    for (int i = 1; i < 10; ++i) {
        board[i] = to_string(i);
    }

    char play;
    cout << "Press any key to start the game or 'q' to quit: ";
    cin >> play;

    while (play != 'q') {
        int roundCount = 0;
        int player1Wins = 0, player2Wins = 0;
        displayBoard(board);

        while (roundCount < 9) {
            int playerMove;
            cout << "Player 1, enter your move (X): ";
            cin >> playerMove;

            while (!isValidMove(playerMove, board)) {
                cout << "Invalid move. Try again, Player 1: ";
                cin >> playerMove;
            }

            makeMove(playerMove, "X", board);

            if (checkWinner("X", board) == "X") {
                player1Wins = 1;
                break;
            }

            roundCount++;
            if (roundCount == 9) break;
            displayBoard(board);

            cout << "Player 2, enter your move (O): ";
            cin >> playerMove;

            while (!isValidMove(playerMove, board)) {
                cout << "Invalid move. Try again, Player 2: ";
                cin >> playerMove;
            }

            makeMove(playerMove, "O", board);

            if (checkWinner("O", board) == "O") {
                player2Wins = 1;
                break;
            }

            roundCount++;
            displayBoard(board);
        }

        displayBoard(board);
        if (player1Wins) {
            cout << "Congratulations! Player 1 wins!" << endl;
        } else if (player2Wins) {
            cout << "Congratulations! Player 2 wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }

        for (int i = 1; i < 10; ++i) {
            board[i] = to_string(i); // Reset the board
        }
        
        cout << "Press any key to play again or 'q' to quit: ";
        cin >> play;
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}
