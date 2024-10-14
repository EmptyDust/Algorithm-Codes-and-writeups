#include <bits/stdc++.h>

using i64 = long long;

// i64 comb[30][30];
// const int N = 30;

// void _init() {
//     for (int i = 0;i < N;++i) {
//         comb[i][0] = 1;
//         for (int j = 1;j < N;++j) {
//             comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
//         }
//     }
// }

const int MAXN = 30;
const i64 inf = 1e18;

int n;
i64 dp[1ll << 22];
i64 a[MAXN];
i64 b[MAXN][MAXN];

i64 check(int x, int y, int z) {
    i64 res = std::max({ a[x],a[y],a[z],b[x][y],b[x][z],b[y][z] });
    res = std::max(res, b[x][y] * b[x][z] * b[y][z]);
    return res;
}

i64 dfs(int mask) {
    if (mask == 0)return 0;
    // std::cout << dp[mask] << ' ';
    if (dp[mask] != -inf)return dp[mask];
    int cho1;
    for (int i = 0;i < n;++i) {
        if (mask >> i & 1) {
            cho1 = i;
            break;
        }
    }
    i64& res = dp[mask];
    for (int i = cho1 + 1;i < n;++i) {
        if (mask >> i & 1)
            for (int j = i + 1;j < n;++j) {
                if (mask >> j & 1) {
                    mask ^= (1ll << i) + (1ll << j) + (1ll << cho1);
                    res = std::max(res, check(i, j, cho1) + dfs(mask));
                    mask ^= (1ll << i) + (1ll << j) + (1ll << cho1);
                }
            }
    }
    return res;
}

void solve() {
    std::cin >> n;
    for (int i = 0;i < (1 << n);++i)dp[i] = -inf;
    for (int i = 0;i < n;++i)std::cin >> a[i];
    for (int i = 0;i < n;++i)for (int j = 0;j < n;++j)
        std::cin >> b[i][j];
    std::cout << dfs((1ll << n) - 1);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    // _init();
    // i64 res = 1;
    // for (int i = 21;i >= 3;i -= 3) {
    //     res *= comb[i][3];
    // }
    // std::cout << res << '\n';
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}