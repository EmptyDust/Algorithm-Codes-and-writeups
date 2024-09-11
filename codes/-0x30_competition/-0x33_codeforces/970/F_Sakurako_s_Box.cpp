#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;
// const int mod = 998244353;

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

void solve() {
    i64 n;std::cin >> n;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll) % mod;
    i64 s = 0;
    for (int i = 0;i < n;++i) {
        s = (s + a[i] * (sum - a[i]) % mod) % mod;
    }
    s = s * inv(n) % mod * inv(n - 1) % mod;
    std::cout << (s + mod) % mod;
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