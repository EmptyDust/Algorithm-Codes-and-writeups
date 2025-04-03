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
    std::vector<int> rank(n + 1), idx(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> rank[i];
    for (int i = 1;i <= n;++i)idx[rank[i]] = i;
    // for (auto x : idx)std::cout << x << ' ';
    int mcnt = std::__lg(n);
    // std::cout << mcnt << ' ';
    auto find = [&](int u) {
        for (int i = 0;i <= mcnt;++i)if (!(u >> i & 1))return 1 << i;
        return -1;
        };
    i64 ans = 0;
    int cnt = 0;
    std::vector<pii> res;
    auto swap = [&](int u, int v) { //pos
        if (u == v)return;
        std::swap(rank[u], rank[v]);
        std::swap(idx[rank[u]], idx[rank[v]]);
        res.push_back({ u,v });
        cnt++;
        // std::cout << u << ' ' << v << '\n';
        // assert(cnt <= 3 * n);
        };
    if (n == (1ll << mcnt + 1) - 1 && idx[n] != n) {
        auto p = find(idx[n]);
        // std::cout << p << ' ';
        swap(idx[n], p);
        swap(p, 1);
        swap(1, n);
        ans++;
    }
    for (int i = n;i;--i) {
        if (std::__popcount(i) == 1) {
            continue;
        }

        if (rank[i] == i) continue;

        int p = idx[i];
        auto u = find(p);
        auto v = find(i);
        // std::cout << p << ' ' << u << ' ' << v << ' ' << i << '\n';
        swap(p, u);
        swap(u, v);
        swap(v, i);
    }
    for (int i = 1;i <= n;i <<= 1) {
        if (idx[i] != i) {
            swap(idx[i], i);
        }
    }

    for (int i = 1;i <= n;++i) {
        assert(rank[i] == i);
    }

    std::cout << ans << '\n';
    std::cout << res.size() << '\n';
    for (auto [u, v] : res)std::cout << u << ' ' << v << '\n';
    // std::cout << res.size() << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}