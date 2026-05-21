#include <bits/stdc++.h>

#define ranges std::ranges

using i64 = long long;
using a2 = std::array<int, 2>;
const int mod = 998244353;
const int inf = 2e9;

void solve(){
    int n, m; std::cin>>n>>m;
    std::vector adj(n, std::vector<a2>());
    for(int i = 0; i < m; ++i){
        int u, v, p; std::cin>>u>>v>>p;
        u--, v--;
        adj[u].push_back({v, p});
    }
    for(int i = 0; i < n; ++i){
        ranges::sort(adj[u], [&](a2 x, a2 y){
            if(x[1] == y[1]) return x[0] < y[0];
            return x[1] > y[1];
        });
    }
    std::vector<int> vis(n);
    std::string ans;
    auto dfs = [&](auto &&dfs, int u) ->void{
        
    };

    int q; std::cin>>q;
    while(q--){
        int x; std::cin>>x; x--;
        vis.assign(n, 0);
        ans = std::to_string(x + 1);
        dfs(dfs, x);
        std::cout<<ans<<'\n';
    }
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}