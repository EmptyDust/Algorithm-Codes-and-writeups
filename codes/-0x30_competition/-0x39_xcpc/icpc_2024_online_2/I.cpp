#include<bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;

void solve() {
    i64 n;std::cin >> n;
    if (n % 4 == 0) {
        std::cout << "NO\n";
        return;
    }
    std::vector<int> ans(32);
    ans[31] = 1;
    i64 cur = 1ll << 31;
    for (i64 i = 30;i >= 0;--i) {
        if (n == cur)ans[i] = 0;
        else if (n > cur)ans[i] = 1;
        else ans[i] = -1;
        cur += (1ll << i) * ans[i];
    }
    std::cout << "YES\n";
    for (int i = 0;i < 32;++i) {
        if (i && i % 8 == 0)std::cout << '\n';
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
    // i64 res = 0;
    // for (int i = 0;i < 32;++i) {
    //     res += (1ll << i) * ans[i];
    // }
    // if (res == n)std::cout << "AC\n";
    // else std::cout << "WA\n";
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