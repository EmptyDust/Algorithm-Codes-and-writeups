#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<i64, i64>;

#define ranges std::ranges

void solve(){
    i64 P, m;std::cin >> P >> m;
    int pcnt = std::__lg(P) + 2;
    i64 mL = std::max(0ll, m - (1ll << pcnt));
    i64 ans = (mL - 1) / P;
    if ((1 ^ (P - 1)) <= m)ans++;

    for (mL = (mL - 1) / P * P + P + 1;mL <= m + (1ll << pcnt);mL += P){
        if ((mL ^ (P - 1)) <= m){
            ans++;
        }
    }
    std::cout << ans;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--){
        solve();
        std::cout << '\n';
    }
    return 0;
}