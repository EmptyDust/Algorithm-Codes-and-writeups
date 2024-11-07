#include<bits/stdc++.h>

#define ranges std::ranges

using i64 = long long;

void solve(){
    i64 n;std::cin >> n;
    std::vector<int> y;
    for (int i = 1;i <= std::sqrt(n);++i)if (n % i == 0){
        y.push_back(i);
        if (i != n / i)y.push_back(n / i);
    }
    ranges::sort(y);
    i64 ans = 1;
    for (int i = 0;i < y.size() - 1;++i){
        ans += (0ll + y[i + 1] - y[i]) * (n / y[i]);
    }
    std::cout << ans;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--){
        solve();
        std::cout << '\n';
    }
    return 0;
}