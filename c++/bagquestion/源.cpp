#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (weights[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 10;
    vector<int> weights = { 2, 3, 4, 5 };
    vector<int> values = { 3, 4, 5, 6 };

    int result = knapsack(W, weights, values);
    cout << "Maximum value: " << result << endl;

    return 0;
}
