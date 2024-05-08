#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::string a, b;std::cin >> a >> b;
    for (int i = 0;i < n;++i)if (a[i] < b[i])std::swap(a[i], b[i]);
    i64 ax = 0, bx = 0;
    for (int i = 0;i < n;++i)
        ax = (ax * 10 + a[i] - '0') % mod;
    for (int i = 0;i < n;++i)
        bx = (bx * 10 + b[i] - '0') % mod;
    std::cout << ax * bx % mod;
    return 0;
}