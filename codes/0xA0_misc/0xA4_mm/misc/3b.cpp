#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10, mod = 998244353;
using i64 = long long;

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
    i64 x1, y1, x2, y2, n, p, q;
    cin >> x1 >> y1 >> x2 >> y2 >> n >> p >> q;
    auto cx = x2 - x1, cy = y2 - y1;
    if (cx + cy != n || cx < 0 || cy < 0) {
        cout << 0;
        return;
    }
    p *= inv(100);p %= mod;
    q *= inv(100);q %= mod;
    //C(cx)(n)*p^(cx)*q(cy)
    cout << comb(n, cx) * qpow(p, cx) % mod * qpow(q, cy) % mod;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}