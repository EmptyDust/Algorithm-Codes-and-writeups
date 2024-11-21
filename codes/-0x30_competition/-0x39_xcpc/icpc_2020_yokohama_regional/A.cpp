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
    int n;std::cin >> n;
    std::vector
        yz(n, std::vector<int>(n)),
        zx(n, std::vector<int>(n)),
        xy(n, std::vector<int>(n));
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < n;++j) {
            yz[n - 1 - i][j] = s[j] == '1';
        }
    }
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < n;++j) {
            zx[n - 1 - i][j] = s[j] == '1';
        }
    }
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < n;++j) {
            xy[n - 1 - i][j] = s[j] == '1';
        }
    }
    std::vector info(n, std::vector<std::vector<int>>(n, std::vector<int>(n, 1)));
    for (int x = 0;x < n;++x) {
        for (int y = 0;y < n;++y) {
            for (int z = 0;z < n;++z) {
                if (!xy[y][x] || !yz[z][y] || !zx[x][z]) {
                    info[x][y][z] = 0;
                    // std::cout << x << ' ' << y << ' ' << z << '\n';
                }
            }
        }
    }
    for (int y = 0;y < n;++y) {
        for (int z = 0;z < n;++z) {
            bool f = 0;
            for (int x = 0; x < n;++x)
                if (info[x][y][z])
                    f = 1;
            if (f != yz[z][y]) {
                std::cout << "No";
                return;
            }
        }
    }
    for (int z = 0;z < n;++z) {
        for (int x = 0;x < n;++x) {
            bool f = 0;
            for (int y = 0; y < n;++y)
                if (info[x][y][z])
                    f = 1;
            if (f != zx[x][z]) {
                std::cout << "No";
                return;
            }
        }
    }
    for (int x = 0;x < n;++x) {
        for (int y = 0; y < n;++y) {
            bool f = 0;
            for (int z = 0;z < n;++z)
                if (info[x][y][z])
                    f = 1;
            if (f != xy[y][x]) {
                std::cout << "No";
                return;
            }
        }
    }
    std::cout << "Yes";
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