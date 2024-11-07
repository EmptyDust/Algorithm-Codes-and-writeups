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
// const int mod = 1e9 + 7;
const int mod = 998244353;

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
    i64 n, m;std::cin >> n >> m;
    std::vector<i64> fib(31), pre(31);
    fib[1] = fib[2] = 1;
    for (int i = 3;i <= 30;++i)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    for (int i = 1;i <= 30;++i)
        pre[i] = (pre[i - 1] + fib[i]) % mod;
    std::vector<i64> f(n + 1);f[0] = 1;
    for (int i = 1;i <= 30;++i)
        for (i64 j = fib[i], pw = qpow(m, pre[i]);j <= n;++j){
            f[j] = (f[j] + pw * f[j - fib[i]] % mod) % mod;
        }
    i64 ans = 0;
    for (int j = 1;j <= n;++j){
        ans = (ans + f[j]) % mod;
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}