#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    if (n == 1){
        std::cout << a[0];
        return;
    }
    bool fx = false, fy = false;
    for (auto x : a){
        if (x >= 0)fx = true;
        if (x <= 0)fy = true;
    }
    if (fx && fy){
        i64 ans = 0;
        for (auto x : a)ans += std::abs(x);
        std::cout << ans;
    }
    else if (fx){
        i64 ans = std::accumulate(a.begin(), a.end(), 0ll);
        i64 min = *std::min_element(a.begin(), a.end());
        ans -= min * 2;
        std::cout << ans;
    }
    else if (fy){
        i64 ans = -std::accumulate(a.begin(), a.end(), 0ll);
        i64 min = -*std::max_element(a.begin(), a.end());
        ans -= min * 2;
        std::cout << ans;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}