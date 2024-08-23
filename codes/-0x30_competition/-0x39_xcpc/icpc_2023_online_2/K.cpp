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
    i64 a, b, n;
    std::cin >> a >> b >> n;
    i64 x = a % n, y = b % n;
    i64 ans = x * x + y * y;
    while (x || y) {
        if (x <= 142 && y <= 142)
            ans = std::min(ans, x * x + y * y);
        i64 times = std::min((n - x + a - 1) / a, (n - y + b - 1) / b);
        x = (x + times * a) % n;
        y = (y + times * b) % n;
    }
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}