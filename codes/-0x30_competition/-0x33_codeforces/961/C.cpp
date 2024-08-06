#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n), c(n);
    for (auto& x : a)std::cin >> x;
    for (int i = 1;i < n;++i) {
        if (a[i] == a[i - 1])continue;
        if (a[i] > a[i - 1]) {
            if (a[i - 1] == 1)continue;
            i64 x = a[i], y = a[i - 1];
            while (x >= y) {
                y *= y;
                c[i]++;
            }
            c[i]--;
        }
        else {
            if (a[i] == 1) {
                std::cout << -1;
                return;
            }
            i64 x = a[i - 1], y = a[i];
            while (x > y) {
                y *= y;
                c[i]--;
            }
        }
    }
    i64 cur = 0, ans = 0;
    for (int i = 0;i < n;++i) {
        if (a[i] == 1)continue;
        cur += c[i];
        // std::cout << cur << " ";
        if (cur > 0)cur = 0;
        else if (cur < 0) {
            ans += -cur;
        }
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