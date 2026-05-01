#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e5;
int t[MAXN], v[MAXN], dp[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0;i < n;++i) {
        cin >> t[i] >> v[i];
        sum += t[i];
    }
    vector<int> dp(4 * n + 1, INT_MAX), tmp(dp);
    dp[2 * n] = 0;
    for (int i = 0;i < n;++i) {
        for (int j = 4 * n;j >= 0;--j) {
            tmp[j] = INT_MAX;
            if (j - t[i] >= 0 && dp[j - t[i]] != INT_MAX)
                tmp[j] = min(tmp[j], dp[j - t[i]] + t[i]);
            if (j + v[i] <= 4 * n && dp[j + v[i]] != INT_MAX)
                tmp[j] = min(tmp[j], dp[j + v[i]]);
        }
        dp = tmp;
    }
    int ans;
    for (int i = 2 * n;i < 4 * n + 1;++i)
        if (tmp[i] != INT_MAX)
            ans = min(dp[i], ans);
    cout << ans;
    return 0;
}