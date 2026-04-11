#include <iostream>
#include <vector>// 包含vector容器 ，用于存储矩阵维度数组
#include <climits>// 包含climits头文件，用于定义INT_MAX常量，表示整数的最大值
using namespace std;

// 矩阵连乘：求最小乘法次数 + 输出最优加括号顺序
void matrixChainOrder(vector<int>& p, vector<vector<int>>& dp, vector<vector<int>>& s) {
    int n = p.size() - 1; // 矩阵个数
    // 初始化：单个矩阵乘法次数为0
    for (int i = 1; i <= n; i++) dp[i][i] = 0;

    // l 是矩阵链的长度，从2到n
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            // 枚举分割点k
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    s[i][j] = k; // 记录最优分割点
                }
            }
        }
    }
}

// 回溯输出最优加括号顺序
void printOptimalParens(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j]+1, j);
        cout << ")";
    }
}

int main() {
    // 示例：矩阵维度数组 p = [30,35,15,5,10,20,25]
    // 对应矩阵：A1(30×35), A2(35×15), A3(15×5), A4(5×10), A5(10×20), A6(20×25)
    vector<int> p = {30, 35, 15, 5, 10, 20, 25};
    int n = p.size() - 1;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    vector<vector<int>> s(n+1, vector<int>(n+1, 0));

    matrixChainOrder(p, dp, s);
    cout << "矩阵连乘最小乘法次数：" << dp[1][n] << endl;
    cout << "最优加括号顺序：";
    printOptimalParens(s, 1, n);
    cout << endl;
    return 0;
}