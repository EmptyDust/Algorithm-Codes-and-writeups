#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int m, T, P;std::cin >> m >> T >> P;
    std::vector<a3> work(m);
    for (auto& [t, p, id] : work)std::cin >> t >> p >> id;
    std::sort(work.begin(), work.end(), [&](a3 a, a3 b) {
        return a[2] < b[2];
        });
    i64 l = 0, r = 1e9 + 1;
    auto check = [&](auto x)->bool {
        std::vector<i64> dp(T + 1), ndp(T + 1);
        for (int i = 0;i < m;++i) {
            auto [t, p, id] = work[i];
            if (i && id != work[i - 1][2]) dp = ndp;
            if (p > x)continue;
            for (int j = T - t; j >= 0;--j) {
                ndp[j + t] = std::max(ndp[j + t], dp[j] + p);
            }
            // for (auto x : ndp)std::cout << x << " ";std::cout << '\n';
        }
        dp = ndp;
        for (auto x : dp) if (x >= P) return true;
        return false;
        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    if (l == 1e9 + 1)std::cout << -1;
    else std::cout << l;
    // std::cout << check(6) << '\n';
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