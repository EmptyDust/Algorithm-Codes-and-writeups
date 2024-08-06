#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<int> a(n), b(n);
    std::vector<int> qs(q);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    for (int& x : qs)std::cin >> x;
    int f = std::min(2000, q);
    for (int i = 0;i < f;++i) {
        i64 sum = 0;
        for (int j = 0;j < n;++j) {
            a[j] = std::max(a[j], b[(j + qs[i]) % n]);
            sum += a[j];
        }
        std::cout << sum << '\n';
    }
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int x, int y) {return b[x] > b[y];});
    int k = std::min(2000, n);
    for (int i = f;i < q;++i) {
        for (int j = 0;j < k;++j) {
            int ai = (p[j] - qs[i] + n) % n;
            int bn = b[p[j]];
            if (a[ai] < bn) {
                sum += bn - a[ai];
                a[ai] = bn;
            }
        }
        std::cout << sum << '\n';
    }
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