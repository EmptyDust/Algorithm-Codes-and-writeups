#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 5e3, MAXN = 5e3 + 10, inf = 1e9;
i64 mod;
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

Mi64 comb[MAXN][MAXN];
void init() {
    for (int i = 0;i <= N;++i) {
        comb[i][0] = 1;
        for (int j = 1;j <= i;++j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

i64 pow2[MAXN];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m >> mod;
    init();
    pow2[0] = 1;
    for (int i = 1;i <= m;++i)pow2[i] = pow2[i - 1] * 2 % mod;

    Mi64 ans = 0;
    for (int j = 1;j <= n;++j) {//奇数数量
        Mi64 res = qpow(pow2[m - 1], n - j);
        Mi64 res1 = 0;
        for (int i = 0;i <= j;++i) {
            if (i % 2)
                res1 = res1 - comb[m - 1][i] * qpow(pow2[m - 1 - i], j);
            else
                res1 = res1 + comb[m - 1][i] * qpow(pow2[m - 1 - i], j);
        }
        ans = ans + res * res1;
    }
    std::cout << ans.value;
    return 0;
}