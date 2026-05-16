#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (auto &x : a)
        std::cin >> x;
    i64 ped = a[0], cur = 0, ans = 1;
    for (int i = 1; i < n; ++i) {
        i64 dx, dy;
        std::cin >> dx >> dy;
        i64 t = dx + dy;
        cur += t;
        if (ped < cur - a[i]) {
            ans++;
            ped = cur + a[i];
        } else if (cur + a[i] < ped) {
            ped = cur + a[i];
        }
        // std::cout << t << " " << ped << ' ' << ans << '\n';
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}