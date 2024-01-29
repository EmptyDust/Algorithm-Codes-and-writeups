#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 80 + 10;
int dp[MAXN][MAXN], n, m, mp[MAXN][MAXN];

int solve(int nums[]) {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 0;
    for (int i = 0;i <= m;++i)for (int j = 0;j <= m;++j) {
        if (!i && !j)continue;
        if (i + j > m)continue;
        int tmp = 1LL << (i + j);
        dp[i][j] = max(i == 0 ? 0 : dp[i - 1][j] + tmp * nums[i], j == 0 ? 0 : dp[i][j - 1] + tmp * nums[m - j + 1]);
    }
    int res = 0;
    for (int i = 0;i <= m;++i)res = max(res, dp[i][m - i]);
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;++i)for (int j = 1;j <= m;++j)cin >> mp[i][j];
    int ans = 0;
    for (int i = 0;i < n;++i)ans += solve(mp[i]);
    cout << ans;
    return 0;
}