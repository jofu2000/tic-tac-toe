#include <stdio.h>

char board[3][3]; // Game board
char currentPlayer = 'X'; // X always starts

// Initialize empty board
void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the board
void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Display board with cell numbers for reference
void displayBoardWithNumbers() {
    printf("\n");
    printf(" 1 | 2 | 3 \n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9 \n");
    printf("\n");
}

// Convert cell number (1-9) to board coordinates
void getCoordinates(int cell, int *row, int *col) {
    cell--; // Convert to 0-8
    *row = cell / 3;
    *col = cell % 3;
}

// Check if move is valid
int isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Check for win
int checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    
    return 0;
}

// Check if board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int gameOver = 0;
    int cell;
    int row, col;
    
    initBoard();
    
    printf("=== TIC-TAC-TOE ===\n");
    printf("Two players on one computer\n");
    printf("X goes first, then O\n");
    printf("Cells are numbered 1-9:\n");
    displayBoardWithNumbers();
    
    while (!gameOver) {
        displayBoard();
        
        printf("Player %c's turn. Enter cell (1-9): ", currentPlayer);
        scanf("%d", &cell);
        
        // Validate input
        if (cell < 1 || cell > 9) {
            printf("Invalid cell! Please enter 1-9.\n");
            continue;
        }
        
        getCoordinates(cell, &row, &col);
        
        if (!isValidMove(row, col)) {
            printf("Cell already taken! Try another.\n");
            continue;
        }
        
        // Make the move
        board[row][col] = currentPlayer;
        
        // Check for win
        if (checkWin(currentPlayer)) {
            displayBoard();
            printf("Player %c wins! Congratulations!\n", currentPlayer);
            gameOver = 1;
        }
        // Check for draw
        else if (isBoardFull()) {
            displayBoard();
            printf("It's a draw! Game over.\n");
            gameOver = 1;
        }
        // Switch player
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
    
    printf("\nThanks for playing!\n");
    return 0;
}