#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m, q;std::cin >> n >> m >> q;
    std::vector map(m, std::vector<int>(m));
    for (int i = 0;i < m;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < m;++j) {
            map[i][j] = s[j] == '#';
        }
    }
    std::vector ans(n, std::vector<int>(n));
    for (int i = 0;i < q;++i) {
        int opt;std::cin >> opt;
        if (opt == 1) {
            std::vector rotate(m, std::vector<int>(m));
            for (int x = 0;x < m;++x) {
                for (int y = 0;y < m;++y) {
                    int nx = y;
                    int ny = m - 1 - x;
                    rotate[nx][ny] = map[x][y];
                }
            }
            map = rotate;
        }
        else {
            int x, y;std::cin >> x >> y;x--, y--;
            for (int i = x;i < x + m;++i) {
                for (int j = y;j < y + m;++j) {
                    ans[i][j] += map[i - x][j - y];
                }
            }
        }
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}