#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, mod = 998244353;
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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    for (int i = 1;i <= n;++i)a[i] += a[i - 1];
    for (int i = 1;i <= n;++i)std::cin >> b[i];
    for (int i = 1;i <= n;++i)b[i] += b[i - 1];
    std::vector<i64> mul(b[n] + 1);mul[0] = 1;
    for (int i = b[n] - 1;i >= 0;--i)
        mul[i] = (mul[i + 1] + comb(b[n], i + 1)) % mod;
    i64 inv_sum = inv(qpow(2, b[n]));
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        i64 in_a = a[r] - a[l - 1];
        i64 in_b = b[r] - b[l - 1];
        i64 out_a = a[n] - in_a;
        i64 out_b = b[n] - in_b;
        i64 bound = out_a + out_b - in_a;
        i64 res = (bound >= b[n] ? 0 : (bound < 0 ? 1 : mul[bound] * inv_sum % mod));
        std::cout << res << ' ';
    }
    return 0;
}