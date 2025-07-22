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
    int n, m;std::cin >> n >> m;
    std::vector g(n, std::vector<int>());
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> distence(n, inf), ans2(n, inf), last(n);
    std::vector fa(n, std::vector<int>());
    std::priority_queue<a2, std::vector<a2>, std::greater<a2>> pq;
    pq.push({ 0, 0 });
    distence[0] = 0;
    ans2[0] = 0;
    std::deque<a3> dq;
    while (pq.size()) {
        auto [dis, u] = pq.top();
        pq.pop();
        if (dis != distence[u]) continue;
        int sz = g[u].size();
        last[u] = dis;
        while (dq.size() && dq.front()[0])
            for (int f : fa[u]) {
                ans2[u] = std::min(ans2[u], dis - 1 - last[f] + ans2[f]);
            }
        // std::cout << u << ' ' << dis << ' ' << ans2[u] << '\n';
        for (int i = dis;i < dis + sz;i++) {
            int v = g[u][i % sz];
            if (distence[v] > i + 1) {
                distence[v] = i + 1;
                pq.push({ i + 1, v });
                fa[v].assign(1, u);
            }
            else if (distence[v] == i + 1) {
                fa[v].push_back(u);
            }
            else dq.push_back({ i + 1, v, i + 1 - (ans2[u] - ans2[v]) });
        }
    }
    std::cout << distence[n - 1] << ' ' << ans2[n - 1];
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