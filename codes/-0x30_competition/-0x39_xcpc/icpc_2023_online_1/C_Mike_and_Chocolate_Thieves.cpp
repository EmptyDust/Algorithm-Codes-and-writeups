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
    i64 m;std::cin >> m;
    i64 l = 0, r = 1e18;
    auto cal = [&](auto x) {
        i64 res = 0;
        for (i64 i = 2;i <= 1e9;++i) {
            i64 b = i * i * i;
            if (b > x) {
                break;
            }
            res += x / b;
        }
        // std::cout << res << ' ';
        return res;
        };
    auto check = [&](auto x)->bool {
        return cal(x) >= m;
        };
    // check(10);
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    // std::cout << cal(l) << ' ';
    if (cal(l) == m)
        std::cout << l;
    else std::cout << -1;
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