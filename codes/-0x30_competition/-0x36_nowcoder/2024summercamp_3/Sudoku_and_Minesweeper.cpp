#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::vector<std::vector<int>> map(10, std::vector<int>(10));
    std::vector<std::vector<char>> ans(10, std::vector<char>(10, '*'));
    for (int i = 1;i <= 9;++i) {
        std::string s;std::cin >> s;
        for (int j = 1;j <= 9;++j) {
            map[i][j] = s[j - 1] - '0';
        }
    }
    bool f = true;
    for (int i = 2;i <= 8 && f;++i)for (int j = 2;j <= 8 && f;++j) {
        if (map[i][j] == 8) {
            ans[i][j] = '8';
            f = false;
        }
    }
    for (int i = 1;i <= 9;++i) {
        for (int j = 1;j <= 9;++j) {
            std::cout << ans[i][j];
        }
        std::cout << '\n';
    }
    return 0;
}