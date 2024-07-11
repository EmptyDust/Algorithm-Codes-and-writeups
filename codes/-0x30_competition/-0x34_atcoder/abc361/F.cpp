#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 n;std::cin >> n;
    i64 x = 1;
    for (;x * x * x <= n;++x);
    i64 sqrt = std::sqrt(n);
    i64 ans = sqrt - x + 1;
    std::vector<bool> t(x);
    i64 c = 0;
    for (i64 i = 1;i < x;++i)if (!t[i]) {
        for (i64 j = i * i;j < n;j *= i) {
            if (j < x)
                t[j] = 1;
            c++;
        }
    }
    std::cout << c;
    return 0;
}