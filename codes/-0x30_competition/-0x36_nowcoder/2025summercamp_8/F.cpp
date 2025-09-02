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

std::vector<int> g(1024, inf);

int L[10][7] = {
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};

int vaild[6] = { 0,1,2,3,4,6 };

void solve() {

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    // std::cout << (1 << 15) * 100 * 100;
    std::vector<int> vis(1 << 7);
    for (int i = 0;i < 1024;++i) {
        for (int j = 0;j < (1 << 7);++j) {
            bool f = 1;
            for (int x = 0;x < 10;++x) if (i >> x & 1) {
                int p = 0;
                for (int y = 0;y < 7;++y)if (j >> y & 1) {
                    p += L[x][y] << y;
                }
                if (vis[p]) f = 0;
                vis[p] = 1;
            }
            if (f) g[i] = std::min(g[i], std::__popcount(j));

            for (int x = 0;x < 10;++x) if (i >> x & 1) {
                int p = 0;
                for (int y = 0;y < 7;++y)if (j >> y & 1) {
                    p += L[x][y] << y;
                }
                vis[p] = 0;
            }
        }
        // std::cout << i << ' ' << g[i] << '\n';
    }

    for (int i = 0;i < 1024;++i) {
        int res = inf;
        for (int j = 0;j < (1 << 7);++j) {
            bool f = 1;
            for (int x = 0;x < 10;++x) if (i >> x & 1) {
                int p = 0;
                for (auto y : vaild)if (j >> y & 1) {
                    p += L[x][y] << y;
                }
                if (vis[p]) f = 0;
                vis[p] = 1;
            }
            if (f) res = std::min(res, std::__popcount(j));

            for (int x = 0;x < 10;++x) if (i >> x & 1) {
                int p = 0;
                for (auto y : vaild)if (j >> y & 1) {
                    p += L[x][y] << y;
                }
                vis[p] = 0;
            }
        }
        if (res != g[i]) {
            std::cout << i << ' ' << g[i] << ' ' << res << '\n';
        }
    }
    // int t;std::cin >> t;
    // while (t--) {
    //     solve();
    //     std::cout << '\n';
    // }
    return 0;
}