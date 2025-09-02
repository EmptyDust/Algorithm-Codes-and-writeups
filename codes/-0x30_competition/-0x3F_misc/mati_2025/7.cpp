#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

// 1 1 2 3 5 8 13 21 33

void solve() {
    int n;std::cin >> n;
    std::vector<i64> fib(n + 1), cnt(n + 1), g(n + 1);
    fib[1] = fib[2] = 1;
    for (int i = 3;i <= n;++i) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    for (int i = 1;i <= n;++i) {
        for (int j = i;j <= n;j += i) {
            g[j]++;
        }
    }
    i64 ans = 0;
    for (int i = n;i >= 1;--i) {
        i64 x = n / i;
        cnt[i] = 1ll * x * x % mod * x % mod;
        for (int j = i + i;j <= n;j += i) cnt[i] = ((cnt[i] - cnt[j]) % mod + mod) % mod;
        ans = (ans + cnt[i] * g[i] % mod * fib[i] % mod) % mod;
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