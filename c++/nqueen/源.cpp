#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

using namespace std;

// ��鵱ǰλ���Ƿ�ȫ���ûʺ�
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // ���ͬһ�����Ƿ��Ѿ��лʺ�
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // ������ϵ����µĶԽ����Ƿ��Ѿ��лʺ�
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // ������ϵ����µĶԽ����Ƿ��Ѿ��лʺ�
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// ��ӡ����
void printBoard(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (board[i][j] ? "Q" : ".") << " ";
        }
        cout << endl;
    }
}

// �ݹ麯�������N�ʺ�����
void solveNQueens(vector<vector<int>>& board, int row, int N) {
    // ���лʺ��Ѿ��ɹ����ã���ӡ��ǰ�������
    if (row == N) {
        cout << "Solution: " << endl;
        printBoard(board, N);
        cout << "------------------" << endl;
        return;
    }

    for (int col = 0; col < N; ++col) {
        // ��鵱ǰλ���Ƿ�ȫ���ûʺ�
        if (isSafe(board, row, col, N)) {
            // ���ûʺ�
            board[row][col] = 1;

            // �ݹ����������һ�еĻʺ�
            solveNQueens(board, row + 1, N);

            // ���ݵ�ǰ�У��Ա㳢����һ����λ��
            board[row][col] = 0;
        }
    }
}



int main() {
    int N;
    cout << "Please input the size: ";
    cin >> N;

    // ����һ��N x N�����̲���ʼ��Ϊ0
    vector<vector<int>> board(N, vector<int>(N, 0));

    // ���N�ʺ����Ⲣ�г����н������
    solveNQueens(board, 0, N);

    return 0;
}
