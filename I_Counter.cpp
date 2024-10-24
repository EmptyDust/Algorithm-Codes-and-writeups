#include <bits/stdc++.h>

using pii = std::pair<int, int>;

#define ranges std::ranges

void solve(){
    int n, m;std::cin >> n >> m;
    std::vector<pii> info(m);
    for (auto& [x, y] : info)std::cin >> x >> y;
    ranges::sort(info);
    for (int i = 0, cur = 0, pre = 0;i < m;++i){
        auto [a, b] = info[i];
        if (a - pre == b - cur || a - pre > b){
            pre = a;
            cur = b;
        }
        else{
            std::cout << "No";
            return;
        }
    }
    std::cout << "Yes";
    return;
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