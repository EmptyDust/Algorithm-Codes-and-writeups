#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
i64 nums[MAXN], n;
using pt = std::pair<i64, i64>;
std::vector<pt> adj[MAXN];
#define yl first
#define t second

pt dfs(int x, int p) {//time yingli
    std::vector<pt> times, a, b, v0;
    for (auto& [nxt, w] : adj[x])if (nxt != p) {
        auto [t, yl] = dfs(nxt, x);
        t += 2 * w;
        if (yl >= w)t -= w, yl -= w;
        else t -= yl, yl = 0;
        if (yl == 0)v0.push_back({ yl,t });
        else if (yl > t)a.push_back({ yl,t });
        else b.push_back({ yl,t });
    }
    std::sort(a.begin(), a.end(), [&](pt a, pt b) {return a.t < b.t;});
    std::sort(b.begin(), b.end(), [&](pt a, pt b) {return a.yl > b.yl;});
    for (pt& x : a)times.push_back(x);
    for (pt& x : b)times.push_back(x);
    for (pt& x : v0)times.push_back(x);
    i64 must = 0, have = nums[x];
    for (auto [yl, t] : times) {
        t -= have;
        if (t < 0)
            have = -t;
        else {
            must += t;
            have = 0;
        }
        have += yl;
    }
    return { must,have };
}

void solve() {
    int n;std::cin >> n;
    for (int i = 1;i <= n;++i)std::cin >> nums[i], adj[i].clear();
    i64 u, v, w;
    for (int i = 1;i < n;++i) {
        std::cin >> u >> v >> w;
        adj[v].push_back({ u, w });
        adj[u].push_back({ v, w });
    }
    std::cout << dfs(1, 0).first;
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