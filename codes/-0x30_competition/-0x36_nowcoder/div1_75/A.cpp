#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    i64 ans = (1ll + (n + 1) / 2) * ((n + 1) / 2) / 2 + n / 2;
    std::cout << ans;
    return 0;
}