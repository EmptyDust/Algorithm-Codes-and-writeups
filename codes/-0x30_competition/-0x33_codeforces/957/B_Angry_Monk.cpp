#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(k);
    for (int& x : a)std::cin >> x;
    std::ranges::sort(a);
    i64 ans = 0;
    for (int i = 0;i < k - 1;++i) {
        ans += a[i] - 1;
        ans += a[i];
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