#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int x, y;std::cin >> x >> y;
    i64 ans = 1;
    for (int s = 0;s < 30;++s) {
        int a = x >> s & 1;
        int b = y >> s & 1;
        if (a == b) {
            ans *= 2;
        }
        else break;
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