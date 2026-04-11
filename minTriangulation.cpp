#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

// 点的结构体
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// 计算两点之间的距离
double dist(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// 计算三角形v_i v_k v_j的权重（周长）
double weight(Point v[], int i, int k, int j) {
    return dist(v[i], v[k]) + dist(v[k], v[j]) + dist(v[j], v[i]);
}

// 凸多边形最优三角剖分
double minTriangulation(Point v[], int n, vector<vector<int>>& s) {
    vector<vector<double>> dp(n, vector<double>(n, 0));

    // l 是多边形的顶点数，从3到n（至少3个点才能构成三角形）
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            // 枚举分割点k
            for (int k = i + 1; k < j; k++) {
                double cost = dp[i][k] + dp[k][j] + weight(v, i, k, j);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    s[i][j] = k; // 记录最优分割点
                }
            }
        }
    }
    return dp[0][n-1];
}

// 回溯输出三角剖分的三角形
void printTriangulation(vector<vector<int>>& s, int i, int j) {
    if (j - i < 2) return;
    int k = s[i][j];
    cout << "(" << i << "," << k << "," << j << ") ";
    printTriangulation(s, i, k);
    printTriangulation(s, k, j);
}

int main() {
    // 示例：凸6边形的顶点坐标
    Point v[] = {
        Point(0, 0), Point(2, 0), Point(3, 2),
        Point(1, 4), Point(-1, 2), Point(0, 1)
    };
    int n = sizeof(v) / sizeof(v[0]);
    vector<vector<int>> s(n, vector<int>(n, 0));

    double min_weight = minTriangulation(v, n, s);
    cout << "凸多边形最优三角剖分最小权重和：" << min_weight << endl;
    cout << "剖分的三角形（顶点索引）：";
    printTriangulation(s, 0, n-1);
    cout << endl;
    return 0;
}