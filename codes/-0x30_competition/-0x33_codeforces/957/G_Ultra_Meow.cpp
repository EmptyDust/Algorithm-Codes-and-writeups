#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct Mi64 {
    i64 value;
    Mi64() {}
    Mi64(i64 value) { this->value = value; }
    Mi64 operator * (const i64 w) {
        return value * w % mod;
    }
    Mi64 operator * (const Mi64 w) {
        return value * w.value % mod;
    }
    Mi64 operator + (const Mi64 w) {
        return (value + w.value) % mod;
    }
    Mi64 operator - (const Mi64 w) {
        return((value - w.value) % mod + mod) % mod;
    }
    bool operator == (const Mi64 w) {
        return value == w.value;
    }
};

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
Mi64 comb(int n, int k) {
    if (k == 0)return 1;
    if (k<0 || k>n)return 0;
    while ((int)fact.size() < n + 1) {
        fact.push_back(1ll * fact.back() * (int)fact.size() % mod);
        inv_fact.push_back(inv(fact.back()));
    }
    return 1ll * fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}
//5 6
//1 3    2 5 7
void solve() {
    i64 n;std::cin >> n;
    Mi64 ans = 0;
    for (int len = 0;len <= n;++len) {
        for (i64 x = len + 1;x <= len + len + 1;++x) {
            //C(x-1,x-len-1)*C(n-x,2*len-x+1)*x
            ans = ans + comb(std::min(x - 1, n), x - len - 1) * comb(n - x, 2 * len - x + 1) * x;
            // std::cout << len << ' ' << x << ' ' << n - x << " " << 2 * len - x + 1 << " " << ans.value << '\n';
        }
        // for (int cnt = 0;cnt <= len;++cnt) {
        //     int lim = len + 1 + cnt;
        //     ans = ans + comb(lim, cnt) * comb(n - lim, len - cnt) * lim;
        //     std::cout << len << ' ' << cnt << ' ' << n - lim << " " << len - cnt << " " << ans.value << '\n';
        // }
    }
    std::cout << ans.value;
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