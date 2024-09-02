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
const int mod = 1e9 + 7;
// const int mod = 998244353;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n), b(n), w(n);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x, x--;
    for (int& x : w)std::cin >> x;
    std::vector<int> g[n];
    std::vector<i64> p(n), T(n + 1);
    for (i64 i = 1, now = 1;i <= n;++i) {
        now = now * i % mod;
        T[i] = inv(now);
    }
    for (int i = 0;i < n;++i) {
        if (a[i] < a[b[i]]) {
            p[i] = 1;
        }
        else if (a[i] < a[b[i]] + w[b[i]]) {
            g[b[i]].push_back(i);
        }
        else {
            p[i] = 0;
        }
    }
    std::vector<int> depth(n);
    std::function<void(int, int)> dfs = [&](int d, int u) {
        depth[u] = d;
        for (int v : g[u]) {
            dfs(d + 1, v);
        }
        };
    for (int i = 0;i < n;++i)if (p[i] == 1) {
        dfs(1, i);
    }
    for (int i = 0;i < n;++i)if (depth[i]) {
        p[i] = T[depth[i]];
    }
    for (int i = 0;i < n;++i) {
        std::cout << ((a[i] * (1 - p[i]) % mod + (a[i] + w[i]) * p[i] % mod) % mod + mod) % mod << ' ';
    }
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