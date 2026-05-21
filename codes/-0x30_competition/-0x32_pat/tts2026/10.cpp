#include <bits/stdc++.h>

#define ranges std::ranges

using i64 = long long;
using a2 = std::array<i64, 2>;
const int mod = 998244353;

void solve(){
    int n; std::cin>>n;
    std::vector<a2> a(n);
    for(auto& it:a) std::cin>>it[0];
    for(int i = 0; i < n; ++i) a[i][1] = i + 1;
    ranges::sort(a, [&](a2 x, a2 y){
        if(x[0] == y[0]) return x[1] < y[1];
        return x[0] < y[0];
    });
    for(int i = 0; i < n; ++i) if(a[i][0] == a[n - 1][0]){
        std::cout<<a[i][1]<<" \n"[i == n - 1];
    }
    int q;std::cin>>q;
    while(q--){
         i64 x; std::cin>>x; x++;
         auto it = std::lower_bound(a.begin(), a.end(), a2{x, 0});
         if(it == a.end()) std::cout<<0<<'\n';
         else std::cout<<(*it)[1]<<'\n';
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