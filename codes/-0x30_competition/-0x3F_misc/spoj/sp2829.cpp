#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = (1 << 15) - 1, MAXN = 1e6 + 10, inf = 1e9, mod = 1000000000;
using pii = std::pair<int, int>;

i64 Ts[50][N + 1];
void solve() {
    memset(Ts, 0, sizeof Ts);
    int n, m;std::cin >> n >> m;
    std::vector<int> c(n);
    for (int& x : c)std::cin >> x;
    int nN = (1 << m) - 1;
    for (int mask = 0;mask <= nN;++mask)
        if (mask % c[0])
            Ts[0][mask] = 1;

    // for (int mask = 0;mask <= nN;++mask)
    //     std::cout << Ts[0][mask] << " ";

    for (int i = 1;i < n;++i) {
        for (int mask = 0;mask <= nN;++mask)
            Ts[i][nN ^ mask] = Ts[i - 1][mask];

        for (int s = 0;s < m;++s)
            for (int mask = 0;mask <= nN;++mask)
                if (!(mask >> s & 1))
                    Ts[i][mask] = (Ts[i][mask | (1 << s)] + Ts[i][mask]) % mod;

        for (int mask = 0;mask <= nN;++mask)
            if (mask % c[i] == 0)
                Ts[i][mask] = 0;
    }
    i64 ans = 0;
    for (int mask = 0;mask <= nN;++mask) {
        ans = (ans + Ts[n - 1][mask]) % mod;
    }
    std::cout << ans;
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