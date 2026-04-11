#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 求LCS长度 + 回溯输出LCS序列
void lcsLength(string X, string Y, vector<vector<int>>& dp, vector<vector<int>>& b) {
    int m = X.size();
    int n = Y.size();
    // 初始化边界：空序列LCS长度为0
    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int j = 0; j <= n; j++) dp[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                b[i][j] = 1; // 1：来自左上角（字符相等）
            } else if (dp[i-1][j] >= dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                b[i][j] = 2; // 2：来自上方（X去掉当前字符）
            } else {
                dp[i][j] = dp[i][j-1];
                b[i][j] = 3; // 3：来自左方（Y去掉当前字符）
            }
        }
    }
}

// 回溯输出LCS序列
void printLCS(vector<vector<int>>& b, string X, int i, int j) {
    if (i == 0 || j == 0) return;
    if (b[i][j] == 1) {
        printLCS(b, X, i-1, j-1);
        cout << X[i-1];
    } else if (b[i][j] == 2) {
        printLCS(b, X, i-1, j);
    } else {
        printLCS(b, X, i, j-1);
    }
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCAB";
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    vector<vector<int>> b(m+1, vector<int>(n+1, 0));

    lcsLength(X, Y, dp, b);
    cout << "最长公共子序列长度：" << dp[m][n] << endl;
    cout << "最长公共子序列为：";
    printLCS(b, X, m, n);
    cout << endl;
    return 0;
}