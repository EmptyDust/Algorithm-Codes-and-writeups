#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, a, k;std::cin >> n >> a >> k;
    for (int i = 0, x = a + 1;i < k;++i, x += n) {
        int y = x;
        bool f = false;
        while (y) {
            if (y % 10 == 7)f = true;
            y /= 10;
        }
        if (x % 7 == 0)f = true;
        if (f)std::cout << 'p';
        else std::cout << x;
        std::cout << ' ';
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