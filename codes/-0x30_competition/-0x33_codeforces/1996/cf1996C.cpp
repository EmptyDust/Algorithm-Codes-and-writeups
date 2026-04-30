#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, q;std::cin >> n >> q;
    std::string a, b;std::cin >> a >> b;
    std::vector cnt(n + 1, std::vector<int>(26));
    for (int i = 1;i <= n;++i) {
        for (int j = 0;j < 26;++j) {
            cnt[i][j] = cnt[i - 1][j];
        }
        cnt[i][a[i - 1] - 'a']++;
        cnt[i][b[i - 1] - 'a']--;
    }
    while (q--) {
        int l, r;std::cin >> l >> r;
        std::vector<int> c(26);
        int res = 0;
        for (int j = 0;j < 26;++j) {
            c[j] += cnt[r][j];
            c[j] -= cnt[l - 1][j];
            res += std::abs(c[j]);
        }
        std::cout << res / 2 << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}