#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<i64, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    i64 n, m, x1;std::cin >> n >> m >> x1;
    std::vector<pii> start[n + 1];
    std::vector<a4> info(m + 1);
    for (int i = 1;i <= m;++i) {
        int u, v, s, t;std::cin >> u >> v >> s >> t;
        start[u].push_back({ s,i });
        info[i] = { u,v,s,t };
    }
    for (int i = 1;i <= n;++i)ranges::sort(start[i]);
    std::vector<i64> ans(m + 1);
    std::priority_queue<pii> que;que.push({ x1,1 });
    while (que.size()) {
        auto [x, p] = que.top();
        que.pop();
        if (ans[p] >= x)continue;
        ans[p] = x;
        auto [u, v, s, t] = info[p];
        auto l = std::lower_bound(start[v].begin(), start[v].end(), std::make_pair(t, 0ll));
        auto r = std::lower_bound(start[v].begin(), start[v].end(), std::make_pair(t + x, 0ll));
        while (l != start[v].end() && l != r) {
            // std::cout << x << ' ';
            auto [qs, q] = *l;
            que.push({ t + x - qs,q });
            l++;
        }
    }
    for (int i = 2;i <= m;++i)std::cout << ans[i] << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}