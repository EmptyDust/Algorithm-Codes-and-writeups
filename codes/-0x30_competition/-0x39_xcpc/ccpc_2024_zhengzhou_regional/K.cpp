#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using d64 = long double;
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
    int n;
    d64 k;std::cin >> n >> k;
    d64 p;std::cin >> p;
    p = 1 - p;
    std::vector<d64> f(n), g(n + 1);
    f[0] = 1 / p;
    for (int i = 1;i < n;++i) {
        f[i] = (f[i - 1] + 1) / p;
    }
    d64 ans = f[n - 1];
    g[n] = 1;
    for (int i = n - 1;i >= 1;--i) {
        g[i] = g[i + 1] / p;
        auto x = g[i] - g[i + 1];
        d64 c = std::min(k, x);
        ans -= c * f[i - 1];
        k -= c;
        std::cout << i << ' ' << c << ' ' << c * f[i - 1] << '\n';
    }   
    // f[i] = (f[i - 1] + 1) / p - t * f[i - 1]
    // for (auto x : f)std::cout << x << '\n';
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout << std::fixed << std::setprecision(10);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}