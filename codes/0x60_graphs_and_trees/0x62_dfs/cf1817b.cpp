#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n, m;
std::vector<int> adj[MAXN];
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n >> m;
    for (int i = 1;i <= n;++i)adj[i].clear();
    int u, v;
    std::vector<int> cnt(n + 1);
    for (int i = 0;i < m;++i) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }
    for (int i = 1;i <= n;++i)if (cnt[i] >= 4) {
        std::vector<bool> vis(n + 1, 0), used(n + 1, 0);
        std::vector<int> path;
        std::function<bool(int, int)> dfs = [&](int x, int p)->bool {
            if (x == i)
                return true;
            vis[x] = 1;
            path.push_back(x);
            for (int nxt : adj[x])if (nxt != p && !vis[nxt]) {
                if (dfs(nxt, x)) {
                    return true;
                }
            }
            path.pop_back();
            return false;
            };
        for (int nxt : adj[i]) {
            if (dfs(nxt, i)) {
                std::cout << "Yes\n";
                std::vector<pt> ans;
                for (int j = 1;j < path.size();++j) {
                    ans.push_back({ path[j - 1],path[j] });
                    used[path[j - 1]] = true;
                    if (std::count(adj[i].begin(), adj[i].end(), path[j])) {
                        ans.push_back({ path[j],i });
                        used[path[j]] = true;
                        break;
                    }
                }
                ans.push_back({ i,nxt });
                used[nxt] = true;
                int cnt = 0;
                for (int nxt_2 : adj[i])if (!used[nxt_2] && cnt < 2) {
                    ans.push_back({ i,nxt_2 });
                    cnt++;
                }
                std::cout << ans.size() << '\n';
                for (auto& [l, r] : ans)std::cout << l << ' ' << r << '\n';
                return;
            }
        }
    }
    std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

