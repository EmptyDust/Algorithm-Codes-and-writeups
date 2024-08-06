#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

/*
    已知 x ， 求最小t使得
    t1 = t / 2
    t2 = t - t / 2
    x <= (1 + t) * t / 2 - (1 + t1) * t1 / 2 - (1 + t2) * t2 / 2;
    ans = t + 1
*/

void solve() {
    i64 x;std::cin >> x;
    i64 sq = -1;
    i64 l = 0, r = 1e9;
    while (l <= r) {
        i64 mid = l + r >> 1;
        if (mid * mid <= x)l = mid + 1, sq = mid;
        else r = mid - 1;
    }

    i64 ans = 2 * sq + 1;
    if (sq * sq == x) {

    }
    else if (x <= sq * (sq + 1)) {
        i64 c = x - sq * sq;
        ans++;
        if (sq % 2 != c % 2) {
            ans++;
        }
    }
    else {
        ans += 2;
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
    // std::cout << check(13, 36);
    // std::cout << check(14, 42);
    return 0;
}