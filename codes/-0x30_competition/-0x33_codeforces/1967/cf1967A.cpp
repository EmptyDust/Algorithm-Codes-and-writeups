#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int a[MAXN], b[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> a[i];
    for (int i = 0;i < n;++i)std::cin >> b[i];
    for (int ans = 0;ans < n;++ans) {
        bool f = true;
        for (int i = ans;i < n;++i) {
            if (b[i] < a[i - ans]) {
                f = false;
                break;
            }
        }
        if (f) {
            std::cout << ans;
            return;
        }
    }
    std::cout << n;
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