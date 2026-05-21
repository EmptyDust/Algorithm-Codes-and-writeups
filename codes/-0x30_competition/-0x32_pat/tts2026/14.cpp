#include <bits/stdc++.h>

#define ranges std::ranges

using i64 = long long;
using a2 = std::array<int, 2>;
const int mod = 998244353;
const int inf = 2e9;

void solve(){
    int n;std::cin>>n;
    std::vector<a2> info(n);
    std::map<int, int> cnt, tmp;
    for(auto &[r, b]:info) {
        std::cin>>r>>b;
        cnt[b]++;
        tmp[r]++;
    }
    ranges::sort(info, [&](a2 x, a2 y){
        if(tmp[x[0]] == tmp[y[0]]) return x[0] < y[0];
        return tmp[x[0]] > tmp[y[0]];
    });
    int ans = cnt.size() + n;
    int add = 0;
    for(int i = 0; i < n; ++i){
        int x = i;
        add++;
        while(i < n && info[i][0] == info[x][0]){
            auto [r, b] = info[i];
            cnt[b]--;
            if(cnt[b] == 0) cnt.erase(r);
            i++;
        }
        ans = std::min(ans, add + (int)cnt.size() + n);
    }
    std::cout<<ans<<'\n';
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
