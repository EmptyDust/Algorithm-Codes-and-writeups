#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
std::vector<int> adj[MAXN];

void solve() {
    int n, m;std::cin >> n >> m;
    for (int i = 1;i <= n;++i)adj[i].clear();
    while (m--) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<i64> id(n + 1), low(n + 1, n + 1), cnt(n + 1), F(n + 1);
    int idx;
    std::function<int(int, int)> dfs1 = [&](int x, int p)->int {
        low[x] = id[x] = idx++;
        F[x] = p;
        int ret = 1;
        for (int nxt : adj[x])if (!id[nxt]) {
            ret += dfs1(nxt, x);
        }
        cnt[x] = ret;
        return ret;
        };
    i64 res, sum;
    std::function<void(int, int)> dfs2 = [&](int x, int p) {
        for (int nxt : adj[x])if (nxt != p) {
            if (F[nxt] == x) {
                dfs2(nxt, x);
                low[x] = std::min(low[x], low[nxt]);
                if (low[nxt] > id[x]) {
                    res = std::max(res, std::min(cnt[nxt], sum - cnt[nxt]));
                }
            }
            else low[x] = std::min(low[x], id[nxt]);
        }
        };
    i64 ans = 0, ans1 = 0;
    for (int i = 1;i <= n;++i)if (id[i] == 0) {
        idx = 1, res = 0;
        sum = dfs1(i, 0);
        dfs2(i, 0);
        ans = std::max(ans, res * (sum - res));
        ans1 += sum * (sum - 1) / 2;
    }
    std::cout << ans1 - ans;
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