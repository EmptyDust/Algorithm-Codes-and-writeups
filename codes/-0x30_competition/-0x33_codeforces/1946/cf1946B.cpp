#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
int nums[MAXN], n;
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

void solve() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    i64 sum = 0, res = 0;
    for (int i = 0;i < n;++i) {
        sum += nums[i];
        if (sum < 0) sum = 0;
        res = std::max(res, sum);
    }
    sum = 0;
    for (int i = 0;i < n;++i)sum = (sum + nums[i]) % mod;
    res %= mod;
    std::cout << ((res * qpow(2, k) % mod + sum - res) % mod + mod) % mod;
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