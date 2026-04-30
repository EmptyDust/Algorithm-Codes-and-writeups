#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
using pt = pair<int, int>;

void solve() {
    int n, x, y, s;
    cin >> n >> x >> y >> s;
    int b = x % y;
    s -= n * b;
    if (s < 0 || s % y) {
        cout << "NO";
        return;
    }
    s /= y, x /= y;
    vector<int> dp(s + 1, INT_MAX);
    vector<int> par(s + 1, -1);
    dp[0] = 0, par[0] = 0;
    for (int i = 0;i <= s;++i) {
        for (int j = 1;i + j * (j - 1) / 2 <= s;++j) {
            int k = i + j * (j - 1) / 2;
            if (dp[k] > dp[i] + j) {
                dp[k] = dp[i] + j;
                par[k] = j;
            }
        }
    }
    bool f = false;
    for (int i = 1;(2 * x + i - 1) * i / 2 <= s;++i) {
        if (i + dp[s - (2 * x + i - 1) * i / 2] <= n) {
            cout << "Yes" << '\n';
            vector<int> ans(n, 0);
            int ani = 0;
            for (;ani < i;++ani)ans[ani] = x + ani;
            int u = s - (2 * x + i - 1) * i / 2;
            while (u) {
                int k = par[u];
                u -= (k - 1) * k / 2;
                for (int j = 0;j < k;++j, ++ani)ans[ani] = j;
            }
            for (int j = 0;j < n;++j)cout << ans[j] * y + b << ' ';
            f = true;
            break;
        }
    }
    if (!f)cout << "NO";
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}