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
    std::vector<i64> f(2 * n);
    i64 base = 0;
    while (q--) {
        int a, b;std::cin >> a >> b;
        i64 t = a / n, s = a % n;
        base += t;
        f[b]++, f[b + s]--;
        // std::cout << b + s << ' ';
    }
    std::vector<i64> ans(n, base);
    for (int i = 0;i < 2 * n;++i) {
        if (i) f[i] += f[i - 1];
        ans[i % n] += f[i];
        // std::cout << f[i] << ' ';
    }
    // std::cout << '\n';
    for (auto x : ans)std::cout << x << ' ';
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