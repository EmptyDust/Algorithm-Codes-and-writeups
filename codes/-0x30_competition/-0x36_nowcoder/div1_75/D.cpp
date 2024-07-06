#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 5e3 + 10, inf = 1e9;
i64 C[MAXN][MAXN], F[MAXN][MAXN], n, mod, Fsum[MAXN];
using pii = std::pair<int, int>;

void init() {
    F[0][0] = 1;
    Fsum[0] = 1;
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j <= i;++j) {
            F[i][j] = (F[i - 1][j - 1] + j * F[i - 1][j] % mod) % mod;
            Fsum[i] = (Fsum[i] + F[i][j]) % mod;
        }
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++)
            if (!j) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
}

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> mod;
    init();
    i64 ans = 1;
    for (int x = 0;x < n;++x) {
        std::cout << qpow(2, 1ll * x * (x - 1)) << ' ';
        std::cout << C[n - 1][x] * qpow(2, 1ll * x * (x - 1)) % mod * Fsum[n - 1 - x] % mod << '\n';
        ans = (ans + C[n - 1][x] * qpow(2, 1ll * x * (x - 1)) % mod * Fsum[n - 1 - x] % mod - 1);
    }
    std::cout << ans;
    return 0;
}