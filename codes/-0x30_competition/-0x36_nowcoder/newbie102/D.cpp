#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a2 = std::array<i64, 2>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::vector adj(n, std::vector<int>());
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector dp(k + 1, std::vector<i64>(n, -1));
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq;
    pq.push({ 1,1,0 });
    pq.push({ a[0],0,0 });
    while (pq.size()) {
        auto [dis, cnt, u] = pq.top();
        pq.pop();
        if (cnt > k || ~dp[cnt][u])continue;
        if (u == n - 1) {
            std::cout << dis;
            return;
        }
        dp[cnt][u] = dis;
        for (auto& v : adj[u]) {
            pq.push({ dis + 1, cnt + 1,v });
            pq.push({ dis + a[v], 0,v });
        }
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