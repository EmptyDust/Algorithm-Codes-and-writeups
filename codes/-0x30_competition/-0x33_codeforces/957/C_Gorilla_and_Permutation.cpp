#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    int mx = std::max(m + 1, k), mn = std::min(m, k - 1);
    std::vector<int> ans(n);
    for (int i = 0, j = n;j >= mx;++i, --j) {
        ans[i] = j;
    }
    for (int i = n - mn, j = 1;j <= mn;++i, ++j) {
        ans[i] = j;
    }
    int cur = mn + 1;
    for (int i = 0;i < n;++i) {
        if (!ans[i]) {
            ans[i] = cur++;
        }
    }
    for (int& x : ans)std::cout << x << ' ';
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