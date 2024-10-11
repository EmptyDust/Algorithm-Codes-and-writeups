#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m, h;std::cin >> n >> m >> h;
    std::vector adj(n + 1, std::vector<pii>());
    std::vector<int> horse(n + 1);
    for (int i = 0;i < h;++i) {
        int x;std::cin >> x;
        horse[x] = 1;
    }
    for (int i = 0;i < m;++i) {
        int u, v, w;std::cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    std::vector dp1(n + 1, std::array<i64, 2>{-1, -1});
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq1;//time pos 
    pq1.push({ 0,1,0 });
    while (pq1.size()) {
        auto [time, p, h] = pq1.top();
        pq1.pop();
        if (~dp1[p][h])continue;
        dp1[p][h] = time;
        if (!h && horse[p])pq1.push({ time,p,1 });
        for (auto [v, w] : adj[p]) {
            pq1.push({ time + w / (h + 1),v,h });
        }
    }
    if (dp1[n][0] == -1 && dp1[n][1] == -1) {
        std::cout << -1;
        return;
    }
    std::vector dp2(n + 1, std::array<i64, 2>{-1, -1});
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq2;//time pos 
    pq2.push({ 0,n,0 });
    while (pq2.size()) {
        auto [time, p, h] = pq2.top();
        pq2.pop();
        if (~dp2[p][h])continue;
        dp2[p][h] = time;
        if (!h && horse[p])pq2.push({ time,p,1 });
        for (auto [v, w] : adj[p]) {
            pq2.push({ time + w / (h + 1),v,h });
        }
    }
    auto get = [&](std::array<i64, 2> a) {
        if (a[0] == -1)return a[1];
        if (a[1] == -1)return a[0];
        return std::min(a[0], a[1]);
        };
    i64 ans = 2e18;
    for (int i = 1;i <= n;++i) {
        if (get(dp1[i]) != -1 && get(dp2[i]) != -1)
            ans = std::min(ans, std::max(get(dp1[i]), get(dp2[i])));
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