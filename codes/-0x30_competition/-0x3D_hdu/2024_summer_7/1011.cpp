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
    i64 x, y;
    std::cin >> x >> y;
    i64 gcd = std::__gcd(x, y);
    // i64 n = y / gcd;
    // y * x / gcd / x
    if (y / gcd % 2 && gcd != y)
        std::cout << y << ' ' << x / gcd * 2;
    else
        std::cout << y << ' ' << x / gcd;
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