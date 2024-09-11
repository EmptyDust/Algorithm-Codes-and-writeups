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
    int n, k;std::cin >> n >> k;
    i64 L = k, R = n + k - 1;
    auto l = L, r = R + 1;
    auto check = [&](auto x)->bool {
        return (L + x) * (x - L + 1) / 2 >= (x + 1 + R) * (R - x) / 2;
        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    i64 tmp = (L + l) * (l - L + 1) / 2 - (l + 1 + R) * (R - l) / 2;
    i64 tmp2 = tmp - 2 * l;
    std::cout << std::min(std::abs(tmp), std::abs(tmp2));
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