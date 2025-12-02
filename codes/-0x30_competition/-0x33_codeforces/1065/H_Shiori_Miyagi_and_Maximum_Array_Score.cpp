#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 2e5;
const int MAXN = 2e5 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    i64 n, m;std::cin >> n >> m;
    std::vector<a2> dp;
    dp.push_back({ 0, 1 });
    for (int i = 2;i <= n;++i) {
        std::vector<i64> base(1, 1);
        while (base.back() * i <= m) base.push_back(base.back() * i);
        std::vector<a2> ndp;
        for (auto& [x, p] : dp) {
            for (int k = 0;k < base.size();++k) {
                i64 np = (p / base[k] + 1) * base[k];
                if (np > m) break;
                ndp.push_back(a2{ x + k, np });
            }
        }
        ranges::sort(ndp);
        std::vector<a2> tmp;
        for (int j = 0;j < ndp.size();++j) {
            if (tmp.size() && tmp.back()[0] < ndp[j][0] && tmp.back()[1] == ndp[j][1]) {
                tmp.back()[0] = ndp[j][0];
            }
            else if (tmp.empty() || tmp.back()[0] < ndp[j][0]) {
                tmp.push_back(ndp[j]);
            }
        }
        dp = tmp;
        // for (auto [a, b] : dp)std::cout << a << ' ' << b << '\n';std::cout << '\n';
    }
    std::cout << dp.back()[0];
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



