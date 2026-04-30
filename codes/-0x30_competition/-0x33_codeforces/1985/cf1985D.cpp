#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m;std::cin >> n >> m;
    pii ans;
    int mx = 0;
    for (int i = 0;i < n;++i) {
        std::string s;
        std::cin >> s;
        int cnt = 0;int p = -1;
        for (int j = 0;j < m;++j) {
            if (s[j] == '#') {
                p = j;
                cnt++;
            }
        }
        if (p != -1 && cnt > mx) {
            ans = { i + 1,p - cnt / 2 + 1 };
            mx = cnt;
        }
    }
    std::cout << ans.first << ' ' << ans.second;
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