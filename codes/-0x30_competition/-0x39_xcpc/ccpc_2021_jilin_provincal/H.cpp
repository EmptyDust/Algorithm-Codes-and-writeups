#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 998244853;
i64 nums[MAXN], n, m, k, u, v, w;
using pt = std::pair<i64, i64>;
std::map<int, i64> sums[MAXN];
std::map<int, i64> cnts[MAXN];

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> k;
    for (int i = 0;i < m;++i) {
        std::cin >> u >> v >> w;
        sums[u][v] = (sums[u][v] + w) % mod;
        cnts[u][v]++;
        sums[v][u] = (sums[v][u] + w) % mod;
        cnts[v][u]++;
    }
    for (int i = 0;i < k;++i)std::cin >> nums[i];
    i64 ans = 0;
    for (int i = 0;i < k - 1;++i) {
        i64 sum = sums[nums[i]][nums[i + 1]], cnt = cnts[nums[i]][nums[i + 1]];
        if (cnt == 0) {
            std::cout << "Stupid Msacywy!";
            return 0;
        }
        ans = (ans * 10 % mod + sum * inv(cnt) % mod) % mod;
    }
    std::cout << ans;
    return 0;
}