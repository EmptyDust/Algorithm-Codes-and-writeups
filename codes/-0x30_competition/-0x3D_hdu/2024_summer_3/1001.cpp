#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pii = std::pair<int, int>;

std::vector<int> y[MAXN];
void init() {
    // for (int i = 2;i <= N;++i)if (!p[i]) {
    //     primes.push_back(i);
    //     p[i] = i;
    //     for (i64 j = 1ll * i * i;j <= N;j += i) {
    //         p[j] = i;
    //     }
    // }
    for (int i = 1;i <= N;++i) {
        for (int j = i;j <= N;j += i) {
            y[j].push_back(i);
        }
    }
}

i64 res[MAXN];
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    int n;std::cin >> n;
    res[1] = res[0] = 1;
    for (int i = 2;i <= n;++i) {
        // for (int j = 1;j <= std::sqrt(i);++j)if (i % j == 0) {
        //     int x1 = j;
        //     res[i] = (res[i] + res[(i - x1) / x1]) % mod;
        //     int x2 = i / j;
        //     if (x1 != x2)
        //         res[i] = (res[i] + res[(i - x2) / x2]) % mod;
        // }
        for (auto x : y[i]) {
            res[i] = (res[i] + res[(i - x) / x]) % mod;
        }
    }
    for (int i = 1;i <= n;++i) {
        std::cout << res[i] << ' ';
    }
    return 0;
}