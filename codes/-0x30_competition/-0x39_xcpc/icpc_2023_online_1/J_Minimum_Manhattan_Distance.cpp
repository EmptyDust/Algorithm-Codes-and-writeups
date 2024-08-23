#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<long double, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

a3 input() {
    i64 a, b, c, d;
    std::cin >> a >> b >> c >> d;
    long double x = (a + c) / 2.0;
    long double y = (b + d) / 2.0;
    return { x,y,std::sqrt((a - c) * (a - c) + (b - d) * (b - d)) / 2.0 };
}

void solve() {
    auto a = input();
    auto b = input();
    a3 c = { b[0] - a[0],b[1] - a[1],b[2] };
    double ans = std::abs(c[0]) + std::abs(c[1]) - 2 * c[2] / std::sqrt(2);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.precision(14);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}