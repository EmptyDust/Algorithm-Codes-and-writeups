#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e4;
int t[MAXN], v[MAXN], dp[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0;i < n;++i) {
        cin >> t[i] >> v[i];
        sum += v[i];
    }
    vector<int> dp(2 * n + 1, -1), tmp(dp);
    dp[n] = 0;
    int ans = 0;
    for (int i = 0;i < n;++i) {
        for (int j = 2 * n;j >= 0;--j) {
            tmp[j] = -1;
            if (j - t[i] >= 0 && dp[j - t[i]] != -1)
                tmp[j] = max(dp[j - t[i]], tmp[j]);
            if (j + 1 <= 2 * n && dp[j + 1] != -1)
                tmp[j] = max(tmp[j], dp[j + 1] + v[i]);
            if (j >= n) {
                ans = max(ans, tmp[j]);
            }
        }
        dp = tmp;
    }
    cout << sum - ans;
    return 0;
}