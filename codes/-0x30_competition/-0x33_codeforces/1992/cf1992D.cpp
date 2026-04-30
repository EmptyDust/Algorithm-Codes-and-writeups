#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    std::string s;std::cin >> s;
    s = 'L' + s + 'L';
    std::vector<int> dp(n + 2, inf);dp[0] = 0;
    std::vector<int> nxt(n + 2, -1);
    int cur;
    for (int i = n + 1;i >= 1;--i) {
        if (s[i] == 'L')cur = i;
        if (s[i] == 'C')cur = -1;
        if (s[i] == 'W')nxt[i] = cur;
    }
    for (int i = 0;i <= n;++i) {
        switch (s[i])
        {
        case 'L': {
            for (int j = i + 1;j <= std::min(i + m, n + 1);++j) {
                dp[j] = std::min(dp[j], dp[i]);
            }
            break;
        }
        case 'W': {
            if (nxt[i] == -1)break;
            dp[nxt[i]] = std::min(dp[nxt[i]], dp[i] + nxt[i] - i);
            break;
        }
        default:
            break;
        }
    }
    std::cout << (dp[n + 1] <= k ? "YES" : "NO");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}