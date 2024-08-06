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
    i64 m, k, h;std::cin >> m >> k >> h;
    if (m == k) {
        std::cout << 1;
        return;
    }
    i64 l = 0, r = 1e9, ans = 0;
    auto check = [&](auto x)->bool {
        if (x >= m) {
            i64 cnt = (x - m) / (m - k) + 1;
            x += cnt * k;
        }
        return x >= h;
        };
    while (l <= r) {
        auto mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
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