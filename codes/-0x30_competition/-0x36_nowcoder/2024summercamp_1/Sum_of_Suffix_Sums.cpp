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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int q;std::cin >> q;
    Mi64 r = 0;
    std::vector<Mi64> arr(q + 1), pre(q + 1);
    i64 sz = 0;
    for (int i = 0;i < q;++i) {
        i64 t, v;std::cin >> t >> v;
        if (t > 0) {
            r = r - (pre[sz] - pre[sz - t]);
            sz = sz - t;
        }
        arr[sz] = v;
        pre[sz + 1] = pre[sz] + v * (sz + 1);
        r = r + v * (sz + 1);
        sz++;
        std::cout << r.value << "\n";
    }
    return 0;
}