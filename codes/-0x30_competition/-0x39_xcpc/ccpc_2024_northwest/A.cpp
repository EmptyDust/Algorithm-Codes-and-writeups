#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 x, k;std::cin >> x >> k;
    if (x == 1) {
        std::cout << 1;
        return 0;
    }
    i64 ans = k + 1;
    while (1) {
        i64 sq = std::sqrt(x);k--;
        if (k < 0)break;
        if (sq == 1) {
            ans++;
            break;
        }
        if (sq * sq == x)ans++;
        else ans += k + 1;
        x = sq;
    }
    //17 * *
    //4 16
    //2 
    std::cout << ans;
    return 0;
}