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

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x;
        p >>= 1;
        x = x * x;
    }
    return ret;
}

i64 ceil_sqrtl(i64 x) {
    i64 l = 0, r = 2e9 + 10;
    while (l < r) {
        auto mid = l + r >> 1;
        if (mid * mid >= x)r = mid;
        else l = mid + 1;
    }
    return l;
}

i64 floor_sqrtl(i64 x) {
    i64 l = 0, r = 2e9 + 10;
    while (l < r) {
        auto mid = l + r >> 1;
        if (mid * mid > x)r = mid;
        else l = mid + 1;
    }
    return l - 1;
}

void solve() {
    int n;std::cin >> n;n /= 2;
    i64 l, r;std::cin >> l >> r;
    i64 ll = l / qpow(10, n), lr = l % qpow(10, n);
    // std::cout << ll << ' ' << lr << '\n';
    i64 rl = r / qpow(10, n), rr = r % qpow(10, n);
    i64 cnt = floor_sqrtl(qpow(10, n) - 1) + 1;
    i64 lmin = ceil_sqrtl(ll), lmax = floor_sqrtl(rl);
    i64 rmin = ceil_sqrtl(lr) + 1, rmax = floor_sqrtl(rr) + 1;
    // std::cout << cnt << '\n';
    // std::cout << lmin << ' ' << lmax << "\n";
    if (lmin > lmax) {
        std::cout << 0;
        return;
    }
    if (lmin == lmax) {
        i64 sq = lmin * lmin;
        if (sq == ll && sq == rl) {
            if (rmin > rmax) {
                std::cout << 0;
            }
            else std::cout << rmax - rmin + 1;
        }
        else if (sq > ll && sq < rl) {
            std::cout << cnt;
        }
        else if (sq > ll) {
            std::cout << rmax;
        }
        else std::cout << cnt - rmin + 1;
        return;
    }
    i64 ans = (lmax - lmin - 1) * cnt;
    if (lmin * lmin > ll)
        ans += cnt;
    else
        ans += cnt - rmin + 1;
    if (lmax * lmax < rl)
        ans += cnt;
    else
        ans += rmax;
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