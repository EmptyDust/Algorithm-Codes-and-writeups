#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector map(n, std::vector<int>(m));
    bool ok = true;
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < m;++j) {
            map[i][j] = s[j] == '1';
            if (!map[i][j])ok = false;
        }
    }
    if (ok) {
        std::cout << 0;
        return;
    }
    if (map[0][0] && map[n - 1][m - 1] || map[0][m - 1] && map[n - 1][0]) {
        std::cout << 1;
        return;
    }
    bool a, b, c, d;a = b = c = d = false;
    for (int j = 0;j < m;++j) {
        if (map[0][j])a = true;
    }
    for (int i = 0;i < n;++i) {
        if (map[i][m - 1])b = true;
    }
    for (int j = 0;j < m;++j) {
        if (map[n - 1][j])c = true;
    }
    for (int i = 0;i < n;++i) {
        if (map[i][0])d = true;
    }
    if (map[0][0] && b && c || map[0][m - 1] && c && d || map[n - 1][m - 1] && a && d || map[n - 1][0] && a && b) {
        std::cout << 2;
        return;
    }
    if (a && b && c && d) {
        std::cout << 3;
        return;
    }
    std::cout << -1;
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