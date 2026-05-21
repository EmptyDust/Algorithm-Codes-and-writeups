#include <bits/stdc++.h>

using i64 = long long;
using a2 = std::array<int, 2>;
const int mod = 998244353;

void solve(){
    int n, T; std::cin>>n>>T;
    std::vector<a2> a(n);
    for(auto &x:a) std::cin>>x[0];
    for(int i = 0; i < n; ++i) a[i][1] = i + 1;
    std::vector<a2> na;
    std::vector<int> ans;
    while(a.size()){
    // for(int i = 0; i < 100; ++i){
        // std::cout<<T<<" ";
        // for(auto x:a) std::cout<<x[1]<<' '; std::cout<<'\n';
        for(auto it:a){
            auto [c, id] = it;
            if(c <= T) ans.push_back(id);
            else na.push_back(it);
        }
        a = na;
        std::reverse(a.begin(), a.end());
        na.clear();

        i64 sum = 0;
        for(auto [c, _]: a) sum += c;
        if(a.size()) T = sum / a.size();
    }
    for(int i = 0; i < n; ++i){
        std::cout<<ans[i]<<" \n"[i == n - 1];
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