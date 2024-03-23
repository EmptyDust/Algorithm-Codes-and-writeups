#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], ans[MAXN], n;
std::vector<int> adj[MAXN], check[MAXN];
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    for (int i = 1;i < n;++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::function<void(int, int)> dfs = [&](int x, int par) {
        if (!check[nums[x]].empty())ans[check[nums[x]].back()]++;
        check[nums[x]].push_back(x);
        for (int nxt : adj[x])if (nxt != par) {
            dfs(nxt, x);
        }
        check[nums[x]].pop_back();
        };
    dfs(0, -1);
    for (int i = 0;i < n;++i)std::cout << ans[i] << " \n"[i == n - 1];
    return 0;
}