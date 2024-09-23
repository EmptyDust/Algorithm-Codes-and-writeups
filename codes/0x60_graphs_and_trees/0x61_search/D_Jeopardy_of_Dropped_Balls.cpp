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
    int n, m, k;std::cin >> n >> m >> k;
    std::vector a(n, std::vector<int>(m, 0));
    std::vector v(n, std::vector<bool>(m, 0));
    for (int i = 0;i < n;++i)
        for (int j = 0;j < m;++j)
            std::cin >> a[i][j];
    std::vector<int> p(k);
    for (int& x : p)std::cin >> x, x--;
    auto update = [&](int x, int y) {
        if (v[x][y])return;
        if (x == n - 1) {
            if (a[x][y] == 2)
                v[x][y] = 1;
            x--;
        }
        for (int i = x;i >= 0;--i) {
            if (v[i + 1][y] && a[i][y] == 2)
                v[i][y] = 1;
            else break;
        }
        };
    for (int i = 0;i < m;++i)
        update(n - 1, i);

    int nx[4] = { 0, 0,1,0 };
    int ny[4] = { 0,1,0,-1 };
    for (auto x : p) {
        pii cur = { 0,x };
        while (1) {
            auto& [x, y] = cur;
            auto [px, py] = cur;
            if (v[x][y]) {
                std::cout << y + 1 << ' ';
                break;
            }
            x += nx[a[px][py]];
            y += ny[a[px][py]];
            a[px][py] = 2;
            update(px, py);
            if (x == n) {
                std::cout << y + 1 << ' ';
                break;
            }
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}