#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

#define M1 998244853
#define M2 1000000009
#define N 1048576//1048576

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


bool operator<(const hsh a, const hsh b) {
    if (a.w1 == b.w1)return a.w2 < b.w2;
    return a.w1 < b.w1;
}

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

void solve() {
    std::string a, b;std::cin >> a >> b;
    std::set<hsh> st;
    int n = a.length(), m = b.length();
    std::vector<hsh> pre(n + 1), preb(m + 1);
    for (int i = 1;i <= n;++i) {
        pre[i] = pre[i - 1] + pw[i - 1] * a[i - 1];
    }
    for (int i = 1;i <= n;++i) {
        hsh h = (pre[n] - pre[i]) * inv[i] + pre[i] * pw[n - i];
        st.insert(h);
    }
    int cnt = 0;
    for (int i = 1;i <= m;++i) {
        preb[i] = preb[i - 1] + pw[i - 1] * b[i - 1];
        if (i >= n) {
            hsh f = (preb[i] - preb[i - n]) * inv[i - n];
            if (st.count(f)) {
                cnt++;
            }
        }
    }
    std::cout << cnt;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}