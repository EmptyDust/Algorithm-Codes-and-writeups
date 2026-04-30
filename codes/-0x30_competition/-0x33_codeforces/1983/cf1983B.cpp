#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<std::vector<int>> map1(n, std::vector<int>(m));
    std::vector<std::vector<int>> map2(n, std::vector<int>(m));
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < m;++j) {
            map1[i][j] = s[j] - '0';
        }
    }
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < m;++j) {
            map2[i][j] = s[j] - '0';
        }
    }
    for (int i = 0;i < n - 1;++i) {
        for (int j = 0;j < m - 1;++j) {
            int c = (map2[i][j] - map1[i][j] + 3) % 3;
            if (c == 0)continue;
            if (c == 1) {
                map1[i + 1][j] = (map1[i + 1][j] + 2) % 3;
                map1[i][j + 1] = (map1[i][j + 1] + 2) % 3;
                map1[i][j] = (map1[i][j] + 1) % 3;
                map1[i + 1][j + 1] = (map1[i + 1][j + 1] + 1) % 3;
            }
            else {
                map1[i + 1][j] = (map1[i + 1][j] + 1) % 3;
                map1[i][j + 1] = (map1[i][j + 1] + 1) % 3;
                map1[i][j] = (map1[i][j] + 2) % 3;
                map1[i + 1][j + 1] = (map1[i + 1][j + 1] + 2) % 3;
            }
        }
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            if (map1[i][j] != map2[i][j]) {
                std::cout << "NO";
                return;
            }
            // std::cout << map2[i][j] << ' ';
        }
        // std::cout << '\n';
    }
    std::cout << "YES";
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