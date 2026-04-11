#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 二维数组版本（直观易理解）
int knapsack2D(vector<int>& w, vector<int>& v, int W) {
    int n = w.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j >= w[i-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i-1]] + v[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

// 一维数组优化版（空间复杂度更低）
int knapsack1D(vector<int>& w, vector<int>& v, int W) {
    int n = w.size();
    vector<int> dp(W+1, 0);

    for (int i = 0; i < n; i++) {
        // 倒序遍历容量，避免重复使用同一物品
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return dp[W];
}

int main() {
    vector<int> w = {2, 3, 4, 5};  // 物品重量
    vector<int> v = {3, 4, 5, 6};  // 物品价值
    int W = 8;                     // 背包容量

    cout << "二维数组版最大价值：" << knapsack2D(w, v, W) << endl;
    cout << "一维优化版最大价值：" << knapsack1D(w, v, W) << endl;
    return 0;
}