#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

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
    int x, y;std::cin >> x >> y;
    std::vector<int> f(2, 1);
    while (f.back() <= 1e9) {
        f.push_back(f.back() * 2 + 1);
    }
    int gcd = std::__gcd(x, y);
    x /= gcd, y /= gcd;
    if (x > y)std::swap(x, y);
    if (std::__popcount(x + y) != 1) {
        std::cout << -1;
        return;
    }
    int ans = 0;
    while (x) {
        y -= x;
        x *= 2;
        if (x > y)std::swap(x, y);
        ans++;
        assert(ans <= 100);
    }
    std::cout << ans << ' ';
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