#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;
const double eps = 1e-5;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<pii> ps(n);
    for (auto& [x, r] : ps)std::cin >> x;
    for (auto& [x, r] : ps)std::cin >> r;
    std::map<int, i64> mp;
    for (auto [x, r] : ps) {
        for (int i = x - r;i <= x + r;++i) {
            i64 res = r * r - (x - i) * (x - i);
            i64 sq = std::sqrt(res);
            mp[i] = std::max(mp[i], sq);
            // std::cout << i << ' ' << sq << '\n';
        }
    }
    i64 ans = 0;
    for (auto [x, res] : mp) {
        ans += res * 2 + 1;
    }
    std::cout << ans;
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