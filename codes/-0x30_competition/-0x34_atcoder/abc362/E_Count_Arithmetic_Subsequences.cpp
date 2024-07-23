#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pii = std::pair<int, int>;


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
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::map<int, int> mp;
    for (int x : a)mp[x]++;
    std::vector<i64> ans(n + 1);
    for (auto [x, cnt] : mp) {
        for (int i = 1;i <= cnt;++i) {
            ans[i] += comb(cnt, i);
        }
    }
    for (int i = 0;i < n;++i)for (int j = i + 1;j < n;++j) {
        int x = a[i];
        int d = a[j] - a[i];
        if (d == 0)continue;
        i64 cur = 1;
        std::vector<i64> dp(n + 2);dp[2] = 1;
        for (int k = j + 1;k < n;++k) {
            if ((a[k] - x) % d)continue;
            int t = (a[k] - a[i]) / d + 1;
            // if (t == 3)std::cout << i << " " << j << " " << k << "\n";
            if (t > n || t <= 2)continue;
            dp[t] += dp[t - 1];
        }
        for (int s = 2;s <= n;++s) {
            ans[s] += dp[s];
        }
    }
    for (int i = 1;i <= n;++i)std::cout << ans[i] << ' ';
    return 0;
}