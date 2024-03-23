#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
std::vector<int> adj[MAXN];
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    int n, m, q, x;
    std::cin >> n >> m >> q >> x;x--;
    int u, v;
    while (m--) {
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::queue<pt> que;
    std::vector<int> dis(std::min(n + 1, 5001), 0);
    std::vector<int> f(n, -1);
    que.push({ x,-1 });
    f[x] = 0;
    while (!que.empty()) {
        pt cur = que.front();
        que.pop();
        for (int nxt : adj[cur.first])if (nxt != cur.second && !~f[nxt]) {
            f[nxt] = f[cur.first] + 1;
            dis[f[nxt]]++;
            que.push({ nxt,cur.first });
        }
    }
    std::vector<i64> dp(dis.size(), 0);
    dp[0] = 1;
    for (int i = 0;i < dis.size();++i) {
        i64 cur = dis[i];
        for (int j = i;j;--j) {
            dp[j] = (dp[j] + dp[j - 1] * dis[i] % mod) % mod;
        }
    }
    int query;
    for (int i = 0;i < q;++i) {
        std::cin >> query;
        std::cout << dp[query] << '\n';
    }
    return 0;
}