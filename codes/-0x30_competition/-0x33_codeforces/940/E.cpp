#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int res[MAXN], prime[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    for (int j = 2;j <= 1e6;++j)if (!prime[j]) {
        for (int i = j;i <= 1e6;i += j) {
            i64 add = (j - (i / j) % j) % j;
            res[i] = (res[i] + add) % mod;
            if (i + j <= 1e6)
                res[i + j] = (res[i + j] - add) % mod;
            prime[i] = 1;
        }
    }
    for (int i = 4;i <= 1e6;i += 4) {
        if ((i / 4) % 2 == 1) {
            res[i] += 2;
            res[i + 4] -= 2;
        }
    }
    for (int i = 2;i <= 1e6;++i)
        res[i] = ((res[i] + res[i - 1]) % mod + mod) % mod;
    for (int i = 2;i <= 1e6;++i)
        res[i] = (res[i] + res[i - 1]) % mod;
    int t;std::cin >> t;
    while (t--) {
        std::cin >> n;
        std::cout << res[n] << '\n';
    }
    return 0;
}