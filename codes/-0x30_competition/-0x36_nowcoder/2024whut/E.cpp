#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int a, b, c, k;std::cin >> a >> b >> c;
    int ans = a / 3 + b / 3 + c / 3 + std::min({ a % 3, b % 3, c % 3 });
    ans = std::max(ans, (k = std::min({ a,b,c })) + (a - k) / 3 + (b - k) / 3 + (c - k) / 3);
    std::cout << ans;
    return 0;
}