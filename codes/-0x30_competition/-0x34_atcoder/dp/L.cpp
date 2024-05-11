#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e3 + 10, mod = 1e9 + 7;
#define int long long 
int nums[MAXN];
int dp[MAXN][MAXN];

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin >> n;
    for (int i = 1;i <= n;++i)cin >> nums[i];
    for (int len = 1;len <= n;++len)for (int i = 1;i + len - 1 <= n;++i) {
        int j = i + len - 1;
        if ((n - len) & 1)
            dp[i][j] = min(dp[i + 1][j] - nums[i], dp[i][j - 1] - nums[j]);
        else
            dp[i][j] = max(dp[i + 1][j] + nums[i], dp[i][j - 1] + nums[j]);
    }
    std::cout << dp[1][n];
    return 0;
}