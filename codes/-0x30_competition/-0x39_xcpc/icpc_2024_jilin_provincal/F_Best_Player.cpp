#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, i64>;
using a4 = std::array<i64, 4>;

void solve() {
    i64 n, m;std::cin >> n >> m;
    std::vector<a4> adj[n + 1];
    std::vector<pii> ps;
    for (i64 i = 0;i < m;++i) {
        i64 a, b, x, y, z;
        std::cin >> a >> b >> x >> y >> z;
        i64 p = (x + y + z) / 2;
        if (p < x) ps.push_back({ x,i });
        else if (p < y) ps.push_back({ y,i });
        else ps.push_back({ p + (x + y + z) % 2,i });
        adj[a].push_back({ x,y,z,i });
        adj[b].push_back({ y,x,z,i });
        // if (a == 2) std::cout << ps.back().first << ' ';
    }
    std::vector<int> zbs(m);
    std::iota(zbs.begin(), zbs.end(), 0);
    std::sort(zbs.begin(), zbs.end(), [&](int a, int b) {return ps[a] > ps[b];});
    std::vector<bool> vis(m);
    std::vector<int> ans;
    for (int i = 1;i <= n;++i) {
        i64 me = -inf, mx = -inf;
        for (auto [x, y, z, p] : adj[i]) {
            me = std::max(me, x + z);
            mx = std::max(y, mx);
            vis[p] = 1;
            // if (i == 1)std::cout << x << ' ' << y << ' ' << z << '\n';
        }
        // if (i == 1) std::cout << mx << ' ' << me << '\n';
        if (mx < me) {
            bool f = true;
            for (int j = 0;j < m;++j) {
                // if (i == 1)std::cout << ps[j].first << ' ';
                if (!vis[zbs[j]]) {
                    if (ps[zbs[j]].first >= me)f = false;
                    break;
                }
            }
            if (f)ans.push_back(i);
        }
        for (auto [x, y, z, p] : adj[i])
            vis[p] = 0;
    }
    std::cout << ans.size() << '\n';
    for (int x : ans)std::cout << x << ' ';
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