#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e5 + 10;
int nums[MAXN], dp[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    for (int i = 1;i < n;++i) {
        int& num = dp[i] = INT_MAX;
        if (i > 0)num = min(num, dp[i - 1] + abs(nums[i] - nums[i - 1]));
        if (i > 1)num = min(num, dp[i - 2] + abs(nums[i] - nums[i - 2]));
    }
    cout << dp[n - 1];
    return 0;
}