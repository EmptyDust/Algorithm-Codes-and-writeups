#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e5 + 10;
int nums[MAXN], dp[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    for (int i = 0;i < n;++i)cin >> nums[i];
    for (int i = 1;i < n;++i) {
        int& num = dp[i] = INT_MAX;
        for (int j = 1;j <= k;++j)
            if (i > j - 1)num = min(num, dp[i - j] + abs(nums[i] - nums[i - j]));
    }
    cout << dp[n - 1];
    return 0;
}