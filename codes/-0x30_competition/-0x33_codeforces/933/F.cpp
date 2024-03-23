#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 2e5 + 10;
i64 a[MAXN], d[MAXN], f[MAXN];
using pt = std::pair<int, int>;

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    for (int i = 0;i < n;++i)std::cin >> a[i];
    for (int i = 0;i < m;++i)std::cin >> d[i];
    for (int i = 0;i < k;++i)std::cin >> f[i];
    std::sort(d, d + m);std::reverse(d, d + m);
    std::sort(f, f + k);
    i64 max = 0, low = a[0], high = a[1], nxt = 0;
    for (int i = 0;i < n - 1;++i) {
        if (a[i + 1] - a[i] > max) {
            nxt = max;
            low = a[i];
            high = a[i + 1];
            max = a[i + 1] - a[i];
        }
        else if (a[i + 1] - a[i] > nxt)
            nxt = a[i + 1] - a[i];
    }
    if (nxt == max) {
        std::cout << max;
        return;
    }
    i64 res = max;
    for (int i = 0, j = 0;i < m && j < k;++i) {
        while (j < k && d[i] + f[j] < low + max / 2)++j;
        if (j < k)
            res = std::min(res, std::max(d[i] + f[j] - low, high - d[i] - f[j]));
        if (j > 0)
            res = std::min(res, std::max(d[i] + f[j - 1] - low, high - d[i] - f[j - 1]));
        if (res < nxt) {
            std::cout << nxt;
            return;
        }
    }
    std::cout << std::max(nxt, res);
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