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

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    i64 a = 100, b = 100;
    i64 k = 1'000'000'000;
    a -= 2 * k;
    b += 3 * k;
    // a += 4 * k;
    int n;std::cin >> n;
    std::vector<a2> points(n);
    i64 ans = 1e18;
    for (auto& [x, y] : points) {
        std::cin >> x >> y;
        ans = std::min(ans, std::abs(a - x) + std::abs(b - y));
    }

    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}