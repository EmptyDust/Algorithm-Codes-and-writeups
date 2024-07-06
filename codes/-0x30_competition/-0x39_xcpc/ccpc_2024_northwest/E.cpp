#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, k;std::cin >> n >> k;
    std::string A;std::cin >> A;
    int a = std::count(A.begin(), A.end(), '1');
    //cnt + cnt1(B) = B
    int mask = (1 << 20) - 1;
    i64 res = 1e18;
    for (int i = 0;i < k;++i) {
        int d = a + i;d &= mask;
        if (std::__popcount(d) == i) {
            res = std::min(res, (i64)d);
        }
    }
    if (res == 1e18)std::cout << "None";
    else {
        std::string B;
        while (res) {
            if (res & 1)B += '1';
            else B += '0';
            res >>= 1;
        }
        std::reverse(B.begin(), B.end());
        std::cout << B;
    }
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