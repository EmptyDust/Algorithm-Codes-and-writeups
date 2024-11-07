#include<bits/stdc++.h>

#define ranges std::ranges

using i64 = long long;
using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;


void solve(){
    i64 n, m;std::cin >> n >> m;
    std::vector<a3> info(n);
    for (auto& [w, l, r] : info)std::cin >> w >> l >> r;
    ranges::sort(info);
    i64 lsum = 0, lbd = 0;
    for (auto [w, l, r] : info)lsum += l, lbd += w * l;
    i64 sy = m - lsum;
    i64 ans = lbd;
    for (int i = n - 1, j = n - 1;i >= 0;--i){
        auto [w, l, r] = info[i];
        sy += l;
        lbd -= l * w;
        while (j > i && sy >= info[j][2] - info[j][1]){
            lbd += (info[j][2] - info[j][1]) * info[j][0];
            sy -= info[j][2] - info[j][1];
            j--;
        }
        if (sy >= 0)
            ans = std::max(ans, lbd + sy * info[j][0]);
        sy -= l;
        lbd += l * w;
    }

    lsum = 0, lbd = 0;
    for (auto [w, l, r] : info)lsum += l, lbd += w * l;
    sy = m - lsum;
    for (int i = 0, j = n - 1;i < n && i <= j;++i){
        auto [w, l, r] = info[i];
        sy += l;
        lbd -= l * w;
        while (i < j && sy >= info[j][2] - info[j][1]){
            lbd += (info[j][2] - info[j][1]) * info[j][0];
            sy -= info[j][2] - info[j][1];
            j--;
        }
        if (sy >= 0)
            ans = std::max(ans, lbd + sy * info[j][0]);
        sy -= l;
        lbd += l * w;
    }
    std::cout << ans;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--){
        solve();
    }
    return 0;
}