#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 数组版（直观易理解）
int maxSubArraySum(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 0);
    dp[0] = a[0];
    int max_sum = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(a[i], dp[i-1] + a[i]);
        max_sum = max(max_sum, dp[i]);
    }
    return max_sum;
}

// 空间优化版（O(1)空间）
int maxSubArraySumOpt(vector<int>& a) {
    int current_max = a[0];
    int global_max = a[0];

    for (int i = 1; i < a.size(); i++) {
        current_max = max(a[i], current_max + a[i]);
        global_max = max(global_max, current_max);
    }
    return global_max;
}

int main() {
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "数组版最大子段和：" << maxSubArraySum(a) << endl;
    cout << "空间优化版最大子段和：" << maxSubArraySumOpt(a) << endl;
    return 0;
}