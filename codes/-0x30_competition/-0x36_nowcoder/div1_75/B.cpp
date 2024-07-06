#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    std::vector<i64> a(n), b(m), c(n), d(m);
    for (int i = 0;i < n;++i) {
        int x, y;std::cin >> x >> y;
        a[i] = x + y;
        c[i] = x - y;
    }
    for (int i = 0;i < m;++i) {
        int x, y;std::cin >> x >> y;
        b[i] = x + y;
        d[i] = x - y;
    }
    i64 ans = 0;
    ans = std::max(ans, *std::max_element(a.begin(), a.end()) - *std::min_element(b.begin(), b.end()));
    ans = std::max(ans, *std::max_element(b.begin(), b.end()) - *std::min_element(a.begin(), a.end()));
    ans = std::max(ans, *std::max_element(c.begin(), c.end()) - *std::min_element(d.begin(), d.end()));
    ans = std::max(ans, *std::max_element(d.begin(), d.end()) - *std::min_element(c.begin(), c.end()));
    std::cout << ans;
    return 0;
}