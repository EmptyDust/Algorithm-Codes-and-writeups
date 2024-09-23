#include<bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

i64 check(i64 T, i64 y) {
    i64 hi = y * y - y + 2 * T;
    i64 lo = 2 * y;
    return y > hi / lo + 1;
}

void cal(i64 T, i64 y) {
    i64 hi = y * y - y + 2 * T;
    i64 lo = 2 * y;
    i64 gcd = std::__gcd(hi, lo);
    hi /= gcd, lo /= gcd;
    std::cout << hi << ' ' << lo << '\n';
}

void solve() {
    i64 T;std::cin >> T;
    i64 l = 1, r = T + 1;
    while (l < r) {
        i64 mid = l + r >> 1;
        if (check(T, mid)) {
            r = mid;
        }
        else l = mid + 1;
    }
    cal(T, l - 1);
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