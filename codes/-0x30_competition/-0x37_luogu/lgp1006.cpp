#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 50 + 10;
int nums[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN], m, n;

void d(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2 && x1 + y1 != m + n - 2)return;
    int& num = dp[x1][y1][x2][y2];
    if (x1 && x2)num = max(num, dp[x1 - 1][y1][x2 - 1][y2]);
    if (x1 && y2)num = max(num, dp[x1 - 1][y1][x2][y2 - 1]);
    if (y1 && x2)num = max(num, dp[x1][y1 - 1][x2 - 1][y2]);
    if (y1 && y2)num = max(num, dp[x1][y1 - 1][x2][y2 - 1]);
    num += nums[x1][y1] + nums[x2][y2];
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0;i < m;++i)for (int j = 0;j < n;++j)cin >> nums[i][j];
    for (int x1 = 0;x1 < m;++x1)
        for (int y1 = 0;y1 < n;++y1)
            for (int x2 = 0;x2 < m;++x2)
                for (int y2 = 0;y2 < n;++y2)
                    if (x1 + y1 == x2 + y2)
                        d(x1, y1, x2, y2);
    cout << dp[m - 1][n - 1][m - 1][n - 1];
    return 0;
}