#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int k, n, x;std::cin >> n >> k >> x;
    std::vector<int> a(n);
    for (int i = 0;i < n;++i)std::cin >> a[i];
    for (int i = 0;i < n;++i) {
        std::cout << a[i] << ' ';
        if (i == k - 1)std::cout << x << ' ';
    }
    return 0;
}