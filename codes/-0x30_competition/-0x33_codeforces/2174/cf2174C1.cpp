#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
int mod;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x, mod-2)

void solve() {
    i64 n, m;std::cin >> n >> m >> mod;
    // E[C ^ 2] = E[C] ^ 2 + Var(C) = sum(Var(S_i)) + (sum(E[S_1])) ^ 2
    // = sum(E(S_i ^ 2) - E(S_i) ^ 2) + (sum(E[S_1])) ^ 2
    // min(L, R) 
    std::vector<i64> G(n + 1), H(n + 1);
    i64 ppow = 1, inv_m = inv(m);
    G[0] = 1; H[0] = 0;
    for (int i = 1;i <= n;++i) {
        ppow = ppow * inv_m % mod;
        G[i] = (G[i - 1] + ppow) % mod;
        H[i] = (H[i - 1] + i * ppow % mod) % mod;
    }
    i64 sum_E = 0, sum_Var = 0;
    for (int k = 2;k <= 2 * n;++k) {
        if (k % 2 == 0) {
            int L = k / 2;
            int R = n + 1 - k / 2;
            int lim = std::min(L, R) - 1;
            i64 E = G[lim];
            i64 V = (G[lim] + 2 * H[lim]) % mod;
            sum_E = (sum_E + E) % mod;
            sum_Var = ((sum_Var + V - E * E % mod) % mod + mod) % mod;
        }
        else {
            int L = k / 2;
            int R = n + 1 - (k + 1) / 2;
            int lim = std::min(L, R);
            i64 E = (G[lim] - 1 + mod) % mod;
            i64 V = ((2 * H[lim] - E) % mod + mod) % mod;
            sum_E = (sum_E + E) % mod;
            sum_Var = ((sum_Var + V - E * E % mod) % mod + mod) % mod;
        }
    }
    i64 ans = (sum_E * sum_E % mod + sum_Var) % mod;
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