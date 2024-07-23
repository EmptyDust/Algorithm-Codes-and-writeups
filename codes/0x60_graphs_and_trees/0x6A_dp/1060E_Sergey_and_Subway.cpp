#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, int>;
std::vector<int> adj[MAXN];

int cnt1 = 0, cnt0 = 0;
i64 sum = 0;
pii dfs(int x, int p, bool f) {
    if (f)cnt1++;
    else cnt0++;
    i64 dis = 0;
    int cnt = 1;
    for (int nxt : adj[x])if (nxt != p) {
        auto [d, c] = dfs(nxt, x, !f);
        d += c;
        sum += dis * c + cnt * d;

        cnt += c;
        dis += d;
    }
    return { dis,cnt };
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 1);
    i64 odd = 1ll * cnt1 * cnt0;
    i64 ans = (sum - odd) / 2 + odd;
    std::cout << ans;
    return 0;
}