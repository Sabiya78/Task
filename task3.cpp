#include <iostream>
#include <vector>

// Function prototypes
void displayBoard(const std::vector<std::vector<char>>& board);
bool makeMove(std::vector<std::vector<char>>& board, char currentPlayer, int row, int col);
bool checkWin(const std::vector<std::vector<char>>& board, char currentPlayer);
bool checkDraw(const std::vector<std::vector<char>>& board);
void switchPlayer(char& currentPlayer);
bool playAgain();

int main() {
    // Game variables
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    // Main game loop
    do {
        displayBoard(board);

        // Player input loop
        int row, col;
        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;
        } while (!makeMove(board, currentPlayer, row, col));

        // Check for win or draw
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
        } else if (checkDraw(board)) {
            displayBoard(board);
            std::cout << "It's a draw!\n";
        } else {
            // Switch to the other player for the next turn
            switchPlayer(currentPlayer);
        }

    } while (playAgain());

    return 0;
}

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool makeMove(std::vector<std::vector<char>>& board, char currentPlayer, int row, int col) {
    // Check if the chosen cell is empty
    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        std::cout << "Invalid move. The selected cell is already occupied. Try again.\n";
        return false;
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char currentPlayer) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true; // Check row
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true; // Check column
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true; // Check diagonal (top-left to bottom-right)
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true; // Check diagonal (top-right to bottom-left)
    }

    return false;
}

bool checkDraw(const std::vector<std::vector<char>>& board) {
    // Check if the board is full (no empty cells)
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // There is an empty cell
            }
        }
    }
    return true; // The board is full
}

void switchPlayer(char& currentPlayer) {
    // Switch between 'X' and 'O'
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
