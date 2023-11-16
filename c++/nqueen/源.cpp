#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

using namespace std;

// 检查当前位置是否安全放置皇后
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // 检查同一列上是否已经有皇后
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // 检查左上到右下的对角线是否已经有皇后
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // 检查右上到左下的对角线是否已经有皇后
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// 打印棋盘
void printBoard(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (board[i][j] ? "Q" : ".") << " ";
        }
        cout << endl;
    }
}

// 递归函数来解决N皇后问题
void solveNQueens(vector<vector<int>>& board, int row, int N) {
    // 所有皇后都已经成功放置，打印当前解决方案
    if (row == N) {
        cout << "Solution: " << endl;
        printBoard(board, N);
        cout << "------------------" << endl;
        return;
    }

    for (int col = 0; col < N; ++col) {
        // 检查当前位置是否安全放置皇后
        if (isSafe(board, row, col, N)) {
            // 放置皇后
            board[row][col] = 1;

            // 递归继续放置下一行的皇后
            solveNQueens(board, row + 1, N);

            // 回溯当前行，以便尝试下一个列位置
            board[row][col] = 0;
        }
    }
}



int main() {
    int N;
    cout << "Please input the size: ";
    cin >> N;

    // 创建一个N x N的棋盘并初始化为0
    vector<vector<int>> board(N, vector<int>(N, 0));

    // 解决N皇后问题并列出所有解决方案
    solveNQueens(board, 0, N);

    return 0;
}
