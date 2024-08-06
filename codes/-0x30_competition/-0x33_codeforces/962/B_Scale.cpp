#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, k;std::cin >> n >> k;
    int m = n / k;
    std::vector<std::vector<int>> mp(n / k, std::vector<int>(n / k));
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < n;++j) {
            int t = s[j] - '0';
            if (i % k == 0 && j % k == 0) {
                mp[i / k][j / k] = t;
            }
        }
    }
    for (int i = 0;i < m;++i) {
        for (int j = 0;j < m;++j) {
            std::cout << mp[i][j];
        }
        std::cout << '\n';
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