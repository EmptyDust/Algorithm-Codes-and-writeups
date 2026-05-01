#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9;
i64 n, m, a, q;
using pt = std::pair<int, int>;

int mod;
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
    std::cin >> n >> m >> a >> mod;
    std::vector<int> ans;
    for (int i = 0;i < m;++i) {
        i64 mul = comb(m + i, i);
        ans.push_back(qpow(a, mul));
    }
    for (int i = 1;i <= n - m;++i) {
        i64 mul = comb(m + i, i) + (1 + i) * i / 2 * comb(m + m - 1, m - 1);
    }
    std::reverse(ans.begin(), ans.end());
    for (int& x : ans)std::cout << x << ' ';
    return 0;
}