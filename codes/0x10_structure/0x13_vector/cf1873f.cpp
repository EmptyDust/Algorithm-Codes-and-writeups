#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), h(n);
    for (int& x : a)std::cin >> x;
    for (int& x : h)std::cin >> x;
    int ans = 0;
    int sum = 0;
    for (int i = 0, j = 0;j < n;++j) {
        if (j && h[j - 1] % h[j]) {
            i = j;
            sum = 0;
        }
        sum += a[j];
        while (sum > k)sum -= a[i], ++i;
        ans = std::max(ans, j - i + 1);
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