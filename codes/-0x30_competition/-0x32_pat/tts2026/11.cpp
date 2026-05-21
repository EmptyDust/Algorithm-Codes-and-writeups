#include <bits/stdc++.h>

#define ranges std::ranges

using i64 = long long;
using a2 = std::array<int, 2>;
const int mod = 998244353;
const int inf = 2e9;

void solve(){
    int n; std::cin>>n; n--;
    std::vector adj(n + 1, std::vector<a2>());
    for(int i = 1; i <= n; ++i){
        int p, len; std::cin >> p >> len;
        adj[p].push_back({i, len});
    }
    std::vector<int> len(n+1, inf);
    auto dfs = [&](auto &&dfs, int u, int w) -> void{
        len[u] = w;
        for(auto [v, wei]:adj[u]){
            dfs(dfs, v, std::min(wei, w));
        }
    };
    
    dfs(dfs, 0, inf);
    int max = 0;

    for(int i = 0; i <= n; ++i) {
        // std::cout<<i<<' '<<len[i]<<'\n';
        if(adj[i].size() == 0)max = std::max(max, len[i]);
    }
    std::cout<<max<<'\n';
    std::vector<int> res;
    for(int i = 0; i <= n; ++i) if(adj[i].size() == 0){
        if(len[i] == max) res.push_back(i);
    }
    for(int i = 0; i < res.size(); ++i){
        std::cout<<res[i] << " \n"[res.size() - 1 == i];
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