#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int boardSize = 8;

// Function to print the board
void printBoard(int board[boardSize][boardSize]) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

// Recursive function to perform chessboard covering
void chessboard(int tr, int tc, int dr, int dc, int size, int board[boardSize][boardSize]) {
    if (size == 1)
        return;

    int t = 0;
    int s = size / 2;

    // L-shaped tile in the top-left quadrant
    if (dr < tr + s && dc < tc + s) {
        t++;
        chessboard(tr, tc, dr, dc, s, board);
    }
    else {
        board[tr + s - 1][tc + s - 1] = t;
        chessboard(tr, tc, tr + s - 1, tc + s - 1, s, board);
    }

    // L-shaped tile in the top-right quadrant
    if (dr < tr + s && dc >= tc + s) {
        t++;
        chessboard(tr, tc + s, dr, dc, s, board);
    }
    else {
        board[tr + s - 1][tc + s] = t;
        chessboard(tr, tc + s, tr + s - 1, tc + s, s, board);
    }

    // L-shaped tile in the bottom-left quadrant
    if (dr >= tr + s && dc < tc + s) {
        t++;
        chessboard(tr + s, tc, dr, dc, s, board);
    }
    else {
        board[tr + s][tc + s - 1] = t;
        chessboard(tr + s, tc, tr + s, tc + s - 1, s, board);
    }

    // L-shaped tile in the bottom-right quadrant
    if (dr >= tr + s && dc >= tc + s) {
        t++;
        chessboard(tr + s, tc + s, dr, dc, s, board);
    }
    else {
        board[tr + s][tc + s] = t;
        chessboard(tr + s, tc + s, tr + s, tc + s, s, board);
    }
}

int main() {
    int board[boardSize][boardSize];

    // Initialize the board
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = -1;
        }
    }

    // Set a special square as the starting point
    int startRow = 3;
    int startCol = 4;
    board[startRow][startCol] = 0;

    // Call the chessboard covering algorithm
    chessboard(0, 0, 3, 3, boardSize, board);

    // Print the board
    printBoard(board);

    return 0;
}
