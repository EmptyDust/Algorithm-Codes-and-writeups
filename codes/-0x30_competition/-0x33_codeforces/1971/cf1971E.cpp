#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    // dt / ds * ti
    i64 n, k, m;
    std::cin >> n >> k >> m;
    std::vector<i64> a(k + 1), b(k + 1), q(m), qi(m), ans(m);
    a[0] = b[0] = 0;
    for (int i = 1;i <= k;++i)std::cin >> a[i];
    for (int i = 1;i <= k;++i)std::cin >> b[i];
    for (int i = 0;i < m;++i)std::cin >> q[i];
    std::iota(qi.begin(), qi.end(), 0);
    std::sort(qi.begin(), qi.end(), [&](int x, int y) {return q[x] < q[y];});
    for (int i = 0, j = 0;i < m;++i) {
        while (j < k && q[qi[i]] >= a[j + 1])++j;
        ans[qi[i]] = b[j];
        if (q[qi[i]] == a[j]) continue;
        ans[qi[i]] += (q[qi[i]] - a[j]) * (b[j + 1] - b[j]) / (a[j + 1] - a[j]);
    }
    for (int i = 0;i < m;++i)std::cout << ans[i] << ' ';
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