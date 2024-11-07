#include<bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::vector adj(n, std::vector<int>());
    for (int i = 1;i < n;++i){
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 1){
        std::cout << 0;
        return;
    }
    i64 max = 0, maxid = -1;
    auto dfs = [&](auto&& self, int u, int p, i64 dis)->void{
        dis += a[u];
        if (dis > max){
            maxid = u;
            max = dis;
        }
        for (int v : adj[u])if (v != p){
            self(self, v, u, dis);
        }
        };
    dfs(dfs, 0, -1, 0);
    int u = maxid;
    max = 0;
    dfs(dfs, u, -1, 0);
    int v = maxid;
    std::stack<int> st, path;
    auto dfs2 = [&](auto&& self, int u, int p)->void{
        st.push(u);
        if (u == v)path = st;
        for (int v : adj[u])if (v != p){
            self(self, v, u);
        }
        st.pop();
        };
    dfs2(dfs2, u, -1);
    i64 ans = 0;
    while (path.size()){
        ans += a[path.top()];
        a[path.top()] *= -1;
        // std::cout << path.top() + 1 << ' ';
        path.pop();
    }
    max = 0;
    auto dfs3 = [&](auto&& self, int u, int p)->i64{
        std::array<i64, 2> dp = { 0,0 };
        for (int v : adj[u])if (v != p){
            i64 x = self(self, v, u);
            for (int i = 0;i < 2;++i)
                if (dp[i] < x)
                    std::swap(dp[i], x);
        }
        max = std::max(max, dp[0] + a[u] + dp[1]);
        return dp[0] + a[u];
        };
    dfs3(dfs3, 0, -1);
    ans += max;
    std::cout << ans;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--){
        solve();
        std::cout << '\n';
    }
    return 0;
}