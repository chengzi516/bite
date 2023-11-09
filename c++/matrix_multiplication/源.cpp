#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

using namespace std;

int matrixChainMultiplication(vector<int>& p) {
    int n = p.size() - 1; // 矩阵个数
    vector<vector<int>> m(n, vector<int>(n, 0)); // 存储最小乘法次数

    // 填充m数组
    for (int chainLength = 2; chainLength <= n; chainLength++) {
        for (int i = 0; i < n - chainLength + 1; i++) {
            int j = i + chainLength - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    return m[0][n - 1]; // 返回最小乘法次数
}

int main() {
    vector<int> matrixDimensions = {5,4,3,2};
    int minMultiplications = matrixChainMultiplication(matrixDimensions);
    cout << "最小乘法次数：" << minMultiplications << endl;
    return 0;
}
