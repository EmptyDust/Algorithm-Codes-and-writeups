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
int mod = 998244353;


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

std::vector<int> fact(1, 1);
std::vector<int> inv_fact(1, 1);
i64 comb(int n, int k) {
    if (k<0 || k>n)return 0;
    while ((int)fact.size() < n + 1) {
        fact.push_back(1ll * fact.back() * (int)fact.size() % mod);
        inv_fact.push_back(inv(fact.back()));
    }
    return 1ll * fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}

void solve() {
    i64 n, p;std::cin >> n >> p;
    mod = p;
    std::vector<i64> ans(n + 1);
    ans[0] = qpow(n, n);
    for (int i = 1;i <= n;++i) {
        // ans[i] = i * qpow(n - i + 1, i - 1) % mod;
        ans[i] = ((qpow(n - i + 1, i) - qpow(n - i, i)) % mod + mod) % mod;
        // for (int j = 2;j <= i;++j) {
        //     ans[i] = 2 * ans[i] * (n - j) % mod;
        // }
        i64 C = 0;
        for (int a = 0;a <= n - i;++a) {
            int b = n - i - a;
            C = (C + comb(a, a + b)) % mod;
        }
        ans[i] = ans[i] * C % mod;
        for (int j = i + 1;j <= n;++j) {
            ans[i] = ans[i] * (n - j + 1) % mod;
        }
        ans[0] = ((ans[0] - ans[i]) % mod + mod) % mod;

    }
    for (int i = 0;i <= n;++i)std::cout << ans[i] << ' ';
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