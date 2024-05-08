#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    std::string s;std::cin >> s;
    int n = s.length();
    for (int i = 0;i < n - 1;++i) {
        if (s[i] != s[i + 1]) {
            std::cout << n + n - (i + 1);
            return;
        }
    }
    std::cout << n - 1;
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