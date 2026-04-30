#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9;
using pt = std::pair<i64, i64>;
//x xa
//y ya
/*
x + k * xa = y + k * ya (mod h)
k * (xa - ya) = y - x (mod h)

*/

i64 qpow(i64 x, i64 p, i64 mod) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x,mod) qpow(x,mod-2,mod)

void solve() {
    i64 n, m, h;
    std::cin >> n >> m >> h;
    std::vector<i64> l(n), s(n);
    for (auto& x : l)std::cin >> x;
    for (auto& x : s)std::cin >> x;

    std::vector<int> adj[n];int u, v;
    while (m--) {
        std::cin >> u >> v;u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto cal = [&](i64 x, i64 xa, i64 y, i64 ya) ->i64 {
        auto gcd = std::__gcd(xa - ya, h);
        if ((y - x) % gcd)return -1;
        auto k = inv((xa - ya) % h, h) * (y - x) % h;
        return k;
        };

    std::priority_queue<pt, std::vector<pt>, std::greater<pt>> pq;
    std::vector<i64> vis(n, -1);
    pq.push({ 0,0 });
    while (pq.size()) {
        auto [dis, pos] = pq.top();
        pq.pop();
        if (vis[pos] != -1)continue;
        vis[pos] = dis;
        for (int nxt : adj[pos])if (vis[nxt] == -1) {
            i64 d = cal((l[pos] + dis * s[pos] % h) % h, s[pos], (l[nxt] + dis * s[nxt] % h) % h, s[nxt]);
            if (d <= -1)continue;
            pq.push({ dis + d,nxt });
        }
    }
    std::cout << vis[n - 1];
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