#include <bits/stdc++.h>

using i64 = long long;

const int MAXN = 30;
const i64 inf = 1e18;

int n;
i64 a[MAXN];
i64 b[MAXN][MAXN];

i64 check(int x, int y, int z) {
    i64 res = std::max({ a[x],a[y],a[z],b[x][y],b[x][z],b[y][z] });
    res = std::max(res, b[x][y] * b[x][z] * b[y][z]);
    return res;
}

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> a[i];
    for (int i = 0;i < n;++i)for (int j = 0;j < n;++j)
        std::cin >> b[i][j];
    std::vector<int> zb(n);
    std::iota(zb.begin(), zb.end(), 0);
    i64 ans = 0;
    do
    {
        i64 res = 0;
        for (int i = 0;i < n;i += 3) {
            res += check(zb[i], zb[i + 1], zb[i + 2]);
        }
        ans = std::max(ans, res);
    } while (std::next_permutation(zb.begin(), zb.end()));
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}