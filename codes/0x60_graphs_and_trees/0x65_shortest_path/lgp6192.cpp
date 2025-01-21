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
    int n, m, k;std::cin >> n >> m >> k;
    std::vector adj(n, std::vector<pii>());
    for (int i = 0;i < m;++i) {
        int u, v, w;std::cin >> u >> v >> w;u--, v--;
        adj[u].push_back(std::make_pair(v, w));
        adj[v].push_back(std::make_pair(u, w));
    }
    std::vector dp(n, std::vector<int>(1 << k, inf));
    std::vector to(n, std::vector<a3>(1 << k));
    for (int i = 0;i < k;++i) {
        int x;std::cin >> x;x--;
        dp[x][1 << i] = 0;
    }
    auto dijkstra = [&](int S) {
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        for (int i = 0;i < n;++i)pq.push(std::make_pair(dp[i][S], i));
        while (pq.size()) {
            auto [dis, u] = pq.top();
            pq.pop();
            if (dp[u][S] < dis)continue;
            for (auto [v, w] : adj[u]) {
                if (dp[v][S] > dp[u][S] + w) {
                    pq.push(std::make_pair(dp[v][S] = dp[u][S] + w, v));
                    to[v][S] = { 1,u,v };
                }
            }
        }
        };
    for (int S = 1;S < 1 << k;++S) {
        for (int A = (S - 1) & S;A;A = (A - 1) & S)
            for (int i = 0;i < n;++i)
                if (dp[i][S] > dp[i][A] + dp[i][S ^ A]) {
                    dp[i][S] = dp[i][A] + dp[i][S ^ A];
                    to[i][S] = { 2, A, S ^ A };
                }
        dijkstra(S);
    }
    int ans = inf, ai = -1;
    for (int i = 0;i < n;++i)if (dp[i].back() < ans) {
        ans = dp[i].back();
        ai = i;
    }
    std::vector<pii> edges;
    auto cal = [&](auto&& self, int u, int A)->void {
        auto [type, a, b] = to[u][A];
        if (type == 1) {
            self(self, a, A);
            edges.push_back({ a + 1,b + 1 });
        }
        if (type == 2) {
            self(self, u, a);
            self(self, u, b);
        }
        };
    std::cout << ans << '\n';
    cal(cal, ai, (1 << k) - 1);
    for (auto [x, y] : edges)std::cout << x << ' ' << y << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}