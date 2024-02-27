#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e3 + 10, mod = 1e9 + 7;
int nums[MAXN];
int dp[MAXN][MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 1;i <= n;++i)cin >> nums[i];
    for (int i = 1;i <= n;++i)for (int j = 1;j <= n;++j)if (i + j <= n) {
        if ((i + j) & 1)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + nums[i];
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + nums[i];
    }

    return 0;
}