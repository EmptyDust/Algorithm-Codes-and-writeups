#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 3e3 + 10, mod = 1e9 + 7;
double nums[MAXN], dp[MAXN][MAXN];
vector<int> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    int n;cin >> n;
    dp[0][0] = 1;
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
        for (int j = 0;j <= i;++j) {
            dp[i + 1][j + 1] += dp[i][j] * nums[i];
            dp[i + 1][j] += dp[i][j] * (1 - nums[i]);
        }
    }
    double ans = 0;
    for (int j = (n + 1) / 2;j <= n;++j)
        ans += dp[n][j];
    cout << ans;
    return 0;
}