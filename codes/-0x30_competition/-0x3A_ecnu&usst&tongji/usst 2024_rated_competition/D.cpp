#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

#define M1 998244853
#define M2 1000000009
#define N 2000000

i64 qpow(i64 x, i64 p, i64 mod) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

struct hsh {
    i64 w1, w2;
    hsh operator * (const int w) {
        return { w1 * w % M1,w2 * w % M2 };
    }
    hsh operator * (const hsh w) {
        return { w1 * w.w1 % M1,w2 * w.w2 % M2 };
    }
    hsh operator + (const hsh w) {
        return { (w1 + w.w1) % M1,(w2 + w.w2) % M2 };
    }
    hsh operator - (const hsh w) {
        return { (w1 + M1 - w.w1) % M1,(w2 + M2 - w.w2) % M2 };
    }
    bool operator == (const hsh w) {
        return (w1 == w.w1) && (w2 == w.w2);
    }
    i64 wt() {
        return M2 * w1 + w2;
    }
    void show() { std::cout << w1 << ' ' << w2 << '\n'; }
}pw[N + 50], inv[N + 50];

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void init() {
    int b1 = rng() % M1 + 1, b2 = rng() % M2 + 1;
    pw[0] = inv[0] = { 1,1 };
    pw[1] = { b1,b2 };
    inv[1] = { qpow(b1,M1 - 2,M1),qpow(b2,M2 - 2,M2) };
    for (int i = 2;i <= N;i++) {
        pw[i] = pw[i - 1] * pw[1];
        inv[i] = inv[i - 1] * inv[1];
    }
}

hsh pre[MAXN], suf[MAXN];
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    int n;std::cin >> n;
    std::string t;std::cin >> t;
    t = '%' + t;
    for (int i = 1;i <= n;++i) {
        pre[i] = pre[i - 1] + pw[i] * t[i];
    }
    for (int i = 2 * n;i >= n + 1;--i) {
        suf[i] = suf[i + 1] + pw[2 * n + 1 - i] * t[i];
    }
    hsh p = pre[n];
    // p.show();
    for (int i = n;i <= 2 * n - 1;++i) {
        hsh s1 = (suf[n + 1] - suf[i + 1]) * inv[2 * n - i];
        hsh s2 = suf[i + 1] - suf[2 * n + 1];
        hsh s = s1 + s2 * pw[i - n];
        // s.show();
        // s1.show();
        // s2.show();
        // s.show();
        if (s == p) {
            std::string ans = t.substr(i - n + 1, n);
            std::reverse(ans.begin(), ans.end());
            std::cout << ans << '\n';
            std::cout << i - n;
            // std::cout << t.substr(n + 1, i - (n + 1) + 1) << ' ';
            return 0;
        }
    }
    std::cout << -1;
    return 0;
}