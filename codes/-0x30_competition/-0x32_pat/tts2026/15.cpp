#include <bits/stdc++.h>

#define ranges std::ranges

using i64 = long long;
using a2 = std::array<int, 2>;
const int mod = 998244353;
const int inf = 2e9;

void solve(){
    int n;std::cin>>n;
    std::vector<int> a(n);
    for(auto &x:a)std::cin>>x;
    std::vector<int> b(n);
    int cnt = 0;
    auto dfs = [&](auto &&dfs, int i)->void{
        if(i == n){
            std::vector<int> c1(n), c2(n);
            for(int i = 0; i < n;++i){
                c1[i] = a[b[i]];
                c2[i] = b[a[i]];
            }
            if(c1 == c2) cnt++;
            return;
        }
        for(int x = 1; x<=n;++x){
            b[i] = x;
            dfs(dfs,i +1);
        }   
    };
    dfs(dfs, 0);
    std::cout<<cnt<<'\n';
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1; std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
1 2
1 1

1 1
1 1
*/