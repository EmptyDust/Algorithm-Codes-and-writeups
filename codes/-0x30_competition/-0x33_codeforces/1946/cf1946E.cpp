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

#define inv(x) qpow(x,mod-2)

std::vector<int> fact(1, 1);
std::vector<int> inv_fact(1, 1);

auto get_fact(int x, bool inv = 0) {
    while ((int)fact.size() < x + 1) {
        fact.push_back(1ll * fact.back() * fact.size() % mod);
        inv_fact.push_back(inv(fact.back()));
    }
    return (inv ? inv_fact[x] : fact[x]);
}

auto get_inv_fact(int x) { return get_fact(x, 1); }

i64 C(int n, int k) {
    if (k<0 || k>n)return 0;
    return 1ll * get_fact(n) * get_inv_fact(k) % mod * get_inv_fact(n - k) % mod;
}

i64 A(int n, int k) {
    return 1ll * get_fact(n) * get_inv_fact(n - k) % mod;
}

i64 F(int n) { return get_fact(n); }

void solve() {
    int n, m1, m2;std::cin >> n >> m1 >> m2;
    std::vector<int> s(m1), t(m2);
    for (int i = 0;i < m1;++i)std::cin >> s[i];
    for (int i = 0;i < m2;++i)std::cin >> t[i];
    if (s.front() != 1 || s.back() != t.front() || t.back() != n) {
        std::cout << 0;
        return;
    }
    i64 res = C(n - 1, s[m1 - 1] - 1);
    for (int i = m1 - 2;~i;--i) {
        res = res * C(s[i + 1] - 2, s[i + 1] - s[i] - 1) % mod * F(s[i + 1] - s[i] - 1) % mod;
    }
    for (int i = 1;i < m2;++i) {
        res = res * C(n - t[i - 1] - 1, t[i] - t[i - 1] - 1) % mod * F(t[i] - t[i - 1] - 1) % mod;
    }
    std::cout << res;
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