#include<bits/stdc++.h>

#define ranges std::ranges

using pii = std::pair<int, int>;

using i64 = long long;

void solve(){
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<int> use(n), vis(n);
    for (int i = 0;i < k;++i){
        int x;std::cin >> x;x--;
        use[x] = 1;
    }
    std::vector adj(n, std::vector<int>());
    for (int i = 0;i < m;++i){
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<std::vector<int>> ans;
    std::vector<int> ans2;
    ans.reserve(n), ans2.reserve(n);
    auto dfs = [&](auto&& self, int u)->bool{
        if (vis[u])return 0;
        vis[u] = 1;
        if (use[u])return 1;
        int p = ans.size();
        ans.push_back(std::vector<int>());
        ans2.push_back(u);
        for (int v : adj[u]){
            if (self(self, v)){
                ans[p].push_back(v);// std::cout << v << ' ' << u << '\n';
                // std::cout << ans.size() << ' ';
            }
        }
        return 1;
        };
    bool ok = false;
    for (int i = 0;i < n;++i){
        if (!use[i]){
            // std::cout << i << ' ';
            dfs(dfs, i);
            ok = true;
            bool check = true;
            for (int j = 0;j < n;++j){
                if (!vis[j]){
                    check = false;
                    break;
                }
            }
            if (!check) ok = false;
            break;
        }
    }
    if (!ok){
        std::cout << "No";
        return;
    }
    std::cout << "Yes" << '\n';
    int sz = 0;
    for (auto vt : ans)if (vt.size())sz++;
    std::cout << sz << '\n';
    for (int i = 0;i < ans.size();++i){
        if (ans[i].empty())continue;
        std::cout << ans2[i] + 1 << ' ' << ans[i].size() << ' ';
        for (auto x : ans[i])std::cout << x + 1 << " ";
        std::cout << '\n';
    }
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--){
        solve();
    }
    return 0;
}