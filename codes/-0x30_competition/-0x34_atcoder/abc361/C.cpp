#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    std::sort(a.begin(), a.end());
    int ans = inf;
    for (int i = n - k;i <= n;++i) {
        ans = std::min(ans, a[i] - a[i - (n - k) + 1]);
    }
    std::cout << ans;
    return 0;
}