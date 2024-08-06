#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector map(2, std::vector<int>(n));
    for (int i = 0;i < 2;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < n;++j) {
            map[i][j] = s[j] == '.';
        }
    }
    int cnt = 0;
    for (int s = 0;s < 2;++s)
        for (int i = 1;i < n - 1;++i) {
            if (map[s][i] && map[s][i + 1] && map[s][i - 1] && map[!s][i] && !map[!s][i + 1] && !map[!s][i - 1]) {
                cnt++;
            }
        }
    std::cout << cnt;
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