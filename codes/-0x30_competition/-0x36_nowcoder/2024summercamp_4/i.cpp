#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;



signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    std::vector<i64> a(n + 2);
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        a[u]++;
        a[v]--;
    }
    for (int i = 1;i <= n;++i)
        a[i] += a[i - 1];
    for (int i = 1;i <= n;++i)
        std::cout << a[i] << ' ';
    i64 ans = 0;
    for (int i = 1, j = 0;i < n;++i) {
        while (1ll * (j - i) * (j - i - 1) / 2 != a[i] - a[j]) {
            j++;
        }
        ans += i - j - 1;
    }
    std::cout << ans;
    return 0;
}