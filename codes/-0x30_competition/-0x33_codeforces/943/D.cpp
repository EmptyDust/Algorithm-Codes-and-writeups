#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    i64 n, k, pb, ps;
    std::cin >> n >> k >> pb >> ps;
    std::vector<i64> p(n + 1), a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> p[i];
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    i64 maxb = 0, sum = 0;
    for (int x = pb, i = 0;i < std::min(k, n);x = p[x], ++i) {
        maxb = std::max(maxb, sum + (k - i) * a[x]);
        sum += a[x];
    }
    i64 maxs = 0; sum = 0;
    for (int x = ps, i = 0;i < std::min(k, n);x = p[x], ++i) {
        maxs = std::max(maxs, sum + (k - i) * a[x]);
        sum += a[x];
    }
    //std::cout << maxs << ' ' << maxb << '\n';
    if (maxs == maxb)std::cout << "Draw";
    else std::cout << (maxs > maxb ? "Sasha" : "Bodya");
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