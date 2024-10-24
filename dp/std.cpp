#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<i64, i64>;

#define ranges std::ranges

void solve(){
    i64 P, m;std::cin >> P >> m;
    int ans = 0;
    for (int x = 0;x < (1 << 20);++x){
        if (((x * P + 1) ^ (P - 1)) <= m)ans++;
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