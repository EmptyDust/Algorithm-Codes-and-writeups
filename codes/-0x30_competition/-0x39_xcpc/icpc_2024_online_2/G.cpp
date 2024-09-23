#include<bits/stdc++.h>

using i64 = long long;
using pii = std::pair<i64, i64>;
const int inf = 1e9;
const int mod = 998244353;

struct Mi64 {
    i64 value;
    Mi64() {}
    Mi64(i64 value) { this->value = value; }
    Mi64 operator*(const i64 w) {
        return value * w % mod;
    }
    Mi64 operator*(const Mi64 w) {
        return value * w.value % mod;
    }
    Mi64 operator+(const Mi64 w) {
        return (value + w.value) % mod;
    }
    Mi64 operator-(const Mi64 w) {
        return ((value - w.value) % mod + mod) % mod;
    }
    bool operator==(const Mi64 w) {
        return value == w.value;
    }
};

using a5 = std::array<Mi64, 5>;

Mi64 qpow(Mi64 x, i64 p) {
    Mi64 res = 1;
    while (p) {
        if (p & 1)res = res * x;
        x = x * x;
        p >>= 1;
    }
    return res;
}

#define inv(x) qpow(x,mod-2)

a5 cal(i64 x, i64 y, Mi64 p0, Mi64 p1) {//x < y
    if (y % x == 0) {
        i64 k = y / x - 1;
        Mi64 pt = qpow(p0 * inv(p0 + p1), k);
        Mi64 p1w = Mi64(1) - pt;
        return { x,x,0,p1w,pt };
    }
    i64 k = y / x;
    Mi64 pt = qpow(p0 * inv(p0 + p1), k);
    Mi64 p1w = Mi64(1) - pt;
    return { x,y % x,0,p1w,pt };
}

void solve() {
    i64 x, y;std::cin >> x >> y;
    Mi64 a0, a1, b;std::cin >> a0.value >> a1.value >> b.value;
    Mi64 p0 = a0 * inv(b), p1 = a1 * inv(b);
    // std::cout << 9 * inv(25) % mod;
    Mi64 ans0 = 0, ans1 = 0, cur = 1;
    while (x != y) {
        // std::cout << x << " " << y << '\n';
        if (x > y) {
            auto [ny, nx, p1w, p0w, pt] = cal(y, x, p1, p0);
            // std::cout << p0w.value << '\n';
            ans0 = ans0 + cur * p0w;
            ans1 = ans1 + cur * p1w;
            cur = cur * pt;
            x = nx.value;
            y = ny.value;
        }
        else {
            auto [nx, ny, p0w, p1w, pt] = cal(x, y, p0, p1);
            // std::cout << p1w.value << '\n';
            ans0 = ans0 + cur * p0w;
            ans1 = ans1 + cur * p1w;
            cur = cur * pt;
            x = nx.value;
            y = ny.value;
        }
        // std::cout << ans1.value << ' ' << (inv(10) * 3).value << '\n';
    }
    // std::cout << cur.value << ' ' << (inv(25) * 4).value << '\n';
    ans0 = ans0 + cur * p0 * inv(p0 + p1);
    ans1 = ans1 + cur * p1 * inv(p0 + p1);
    std::cout << ans0.value << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}