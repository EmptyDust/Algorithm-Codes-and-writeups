#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<i64, i64>;

#define ranges std::ranges

void solve(){
    int n, W, k;std::cin >> n >> W >> k;
    std::vector<pii> info(n);
    for (auto& [w, v] : info)std::cin >> w >> v;
    ranges::sort(info);
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;//find the smallist value
    std::vector<i64> suf(n + 1);
    i64 sum = 0;
    for (int i = n - 1;i >= 0;--i){
        pq.push(info[i].second);
        sum += info[i].second;
        if (pq.size() > k){
            sum -= pq.top();
            pq.pop();
        }
        suf[i] = sum;
    }
    std::vector<i64> dp(W + 1);
    i64 ans = 0;
    for (int i = 0;i < n;++i){
        auto [w, v] = info[i];
        for (int j = W;j >= w;--j){
            dp[j] = std::max(dp[j], dp[j - w] + v);
        }
        // if (i == 1)std::cout << dp[W] << ' ' << suf[i + 1] << '\n';
        ans = std::max(ans, dp[W] + suf[i + 1]);
    }
    std::cout << ans;
    return;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--){
        solve();
        std::cout << '\n';
    }
    return 0;
}