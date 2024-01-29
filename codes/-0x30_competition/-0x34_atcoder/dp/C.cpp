#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e5 + 10;
int nums[MAXN][3], dp[MAXN][3];

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 1;i <= n;++i)for (int j = 0;j < 3;++j)
        cin >> nums[i][j];
    for (int i = 1;i <= n;++i)
        for (int m = 0;m < 3;++m)
            for (int n = 0;n < 3;++n)if (m != n)
                dp[i][m] = max(dp[i][m], dp[i - 1][n] + nums[i][m]);
    cout << max({ dp[n][0],dp[n][1],dp[n][2] });
    return 0;
}