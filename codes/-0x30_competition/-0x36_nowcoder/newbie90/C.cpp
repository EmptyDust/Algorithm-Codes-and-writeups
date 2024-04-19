#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
i64 nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int _n;
    std::cin >> _n;
    n = _n;
    i64 res = 0, t = 1;
    while (n) {
        if (n % 10 == 0)res += t;
        t *= 10;
        n /= 10;
    }
    if (!res) {
        if (_n % 10 == 1)res = 2;
        else res = 1;
    }
    std::cout << res;
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