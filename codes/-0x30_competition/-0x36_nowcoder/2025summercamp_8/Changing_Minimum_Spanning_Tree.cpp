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
const int mod = 1e9 + 7;
// const int mod = 998244353;

struct DSU {
    std::vector<int> siz;
    std::vector<int> f;
    std::vector<std::array<int, 2>> his;

    DSU(int n) : siz(n + 1, 1), f(n + 1) {
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        while (f[x] != x) {
            x = f[x];
        }
        return x;
    }

    int lca(int x, int y) {
        if (x == y) {
            return x;
        }
        else if (siz[x] < siz[y]) {
            x = f[x];
        }
        else y = f[y];
        return lca(x, y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] < siz[y]) {
            std::swap(x, y);
        }
        his.push_back({ x, y });
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int time() {
        return his.size();
    }

    void revert(int tm) {
        while (his.size() > tm) {
            auto [x, y] = his.back();
            his.pop_back();
            f[y] = y;
            siz[x] -= siz[y];
        }
    }
};

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<a3> edges(m), tree;
    std::vector<i64> minus(n + 1);
    for (auto& [w, u, v] : edges)std::cin >> u >> v >> w;
    ranges::sort(edges);
    DSU d1(n), d2(n);
    for (auto& [w, u, v] : edges) {
        if (d1.merge(u, v)) tree.push_back({ w,u,v });
        minus[d1.lca(u, v)]++;
    }
    for (auto x : minus)std::cout << x << " ";std::cout << '\n';
    int sz = tree.size();
    // std::cout << sz << ' ';
    for (int i = sz - 1;i >= 0;--i) {
        auto& [w, u, v] = tree[i];
        d2.merge(u, v);
    }
    i64 ans = 0;
    for (int i = 0;i < sz;++i) {
        auto& [w, _, __] = tree[i];
        auto [u, v] = d2.his.back();
        d2.revert(sz - 1 - i);

        std::cout << w << ' ' << u << ' ' << v << ' ' << d2.siz[u] << ' ' << d2.siz[v] << '\n';
        ans = (ans + (1ll * d2.siz[u] * d2.siz[v] - minus[u]) % mod * (w - 1)) % mod;
    }
    std::cout << ans;
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