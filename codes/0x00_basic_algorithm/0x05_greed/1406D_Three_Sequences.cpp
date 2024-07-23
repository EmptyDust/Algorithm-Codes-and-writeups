#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

i64 cal(i64 a, i64 u) {
    //x + y = a
    //max(x + u,y)
    //x + u = y
    //2 * y - u = a
    i64 y = (a + u) / 2;
    i64 x = a - y;
    return std::max(x + u, y);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<i64> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    for (int i = 1;i <= n;++i)b[i] = a[i] - a[i - 1];
    i64 u = 0;
    for (int i = 2;i <= n;++i) {
        if (b[i] > 0)u += b[i];
    }
    i64 a1 = a[1];
    // std::cout << u << ' ' << -d << '\n';
    std::cout << cal(a1, u) << '\n';
    int q;std::cin >> q;
    while (q--) {
        int l, r, x;std::cin >> l >> r >> x;
        if (l == 1)a1 += x;
        if (l != 1) {
            if (b[l] > 0)u -= b[l];
            b[l] += x;
            if (b[l] > 0)u += b[l];
        }
        if (r != n) {
            if (b[r + 1] > 0)u -= b[r + 1];
            b[r + 1] -= x;
            if (b[r + 1] > 0)u += b[r + 1];
        }
        // std::cout << a1 << ' ' << u << "\n";
        std::cout << cal(a1, u) << '\n';
    }
    return 0;
}