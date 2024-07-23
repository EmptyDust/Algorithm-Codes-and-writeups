#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m;std::cin >> n >> m;
    // std::cout << n << ' ' << m << '\n';
    if (n * m == 1) {
        int x;
        std::cin >> x;
        std::cout << -1 << '\n';
        return;
    }
    if (m == 1) {
        std::vector<int> a(n);
        for (int& x : a)std::cin >> x;
        int tmp = a[0];
        for (int i = 1;i < n;++i) {
            a[i - 1] = a[i];
        }
        a.back() = tmp;
        for (int x : a)std::cout << x << '\n';
        return;
    }
    for (int i = 0;i < n;++i) {
        std::vector<int> a(m);
        for (int& x : a)std::cin >> x;
        int tmp = a[0];
        for (int i = 1;i < m;++i) {
            a[i - 1] = a[i];
        }
        a.back() = tmp;
        for (int x : a)std::cout << x << ' ';
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}