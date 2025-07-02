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
    int n, q;std::cin >> n >> q;
    std::vector<int> b(n);
    for (auto& x : b)std::cin >> x;
    std::vector<a3> ops(q);
    for (auto& [x, y, z] : ops)std::cin >> x >> y >> z, x--, y--, z--;
    ranges::reverse(ops);
    std::vector<a2> range(n);
    for (int i = 0;i < n;++i)range[i] = { b[i],b[i] };
    for (auto [x, y, z] : ops) {
        // std::cout << x << ' ' << y << ' ' << z << '\n';
        // for (int i = 0;i < n;++i)std::cout << range[i][0] << ' ';std::cout << '\n';
        // for (int i = 0;i < n;++i)std::cout << range[i][1] << ' ';std::cout << '\n';
        auto& [l, r] = range[z];
        auto& [xl, xr] = range[x];
        auto& [yl, yr] = range[y];
        if (r < std::min(xl, yl) || std::min(xr, yr) < l) {
            std::cout << -1;
            return;
        }
        if (y == z) {
            if (r < xl) continue;
            yl = xl = std::max(xl, yl), yr = inf;
            continue;
        }
        if (x == z) {
            if (r < yl) continue;
            xl = yl = std::max(xl, yl), xr = inf;
            continue;
        }
        if (r < xl) {
            yl = yr = std::max(yl, l);
        }
        else if (r < yl) {
            xl = xr = std::max(xl, l);
        }
        else {
            xl = std::max(xl, l);
            yl = std::max(yl, l);
        }
        l = 0, r = inf;
    }
    std::vector<int> a(n);
    for (int i = 0;i < n;++i) {
        a[i] = range[i][0];
        // if (range[i][0] == 0)a[i] = inf;
        // std::cout << a[i] << ' ';
    }
    ranges::reverse(ops);
    for (auto [x, y, z] : ops) {
        a[z] = std::min(a[x], a[y]);
    }
    if (a != b) {
        std::cout << -1;
    }
    else for (int i = 0;i < n;++i) {
        a[i] = range[i][0];
        // if (range[i][0] == 0)a[i] = inf;
        std::cout << a[i] << ' ';
    }
    // std::cout << (a == b ? "YES" : "NO");
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