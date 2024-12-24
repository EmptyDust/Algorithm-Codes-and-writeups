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

void solve() {
    int n;std::cin >> n;
    std::vector<pii> p(n);
    i64 max = -inf;
    i64 sum = 0;
    for (auto& [a, _] : p)std::cin >> a;
    for (auto& [_, b] : p)std::cin >> b;
    for (auto& [a, b] : p) {
        max = std::max(max, std::min(a, b));
        sum += std::max(a, b);
    }
    // i64 m = inf;
    // for (auto& [a, b] : p) {
    //     if (a + b == max) {
    //         m = std::min(m, std::max(a, b));
    //     }
    // }
    // std::cout << sum << ' ' << max << ' ' << m << '\n';
    std::cout << sum + max;
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