#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 30, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
int nums[MAXN], n, k;
using pt = std::pair<int, int>;

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

i64 comb(int x, int k) {
    i64 res = 1;
    for (int i = 1;i <= k;++i)res = res * inv(i) % mod;
    for (int i = x - k + 1;i <= x;++i)res = res * i % mod;
    return res;
}

#define lowbit(x) (x&-x)
void solve() {
    std::cin >> n >> k;
    for (int i = 1;i <= n;++i)
        std::cin >> nums[i];
    for (int i = 1;i <= n;++i) {
        std::cout << nums[i] << ' ';
        for (int x = i + lowbit(i), dis = 1;x <= n;x += lowbit(x), dis++) {
            nums[x] = ((nums[x] - comb(k + dis - 1, dis) * nums[i] % mod) % mod + mod) % mod;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}