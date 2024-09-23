#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector a(m, std::vector<int>(n));
    for (int i = 0;i < m;++i)for (int j = 0;j < n;++j)std::cin >> a[i][j];
    int ans = inf;
    std::vector<int> as;
    for (int i = 0;i < n - 1;++i) {
        std::vector<int> c(m), z(m);
        std::iota(z.begin(), z.end(), 0);
        for (int j = 0;j < m;++j) {
            c[j] = a[j][n - 1] - a[j][i];
        }
        int cz = std::accumulate(c.begin(), c.end(), 0);
        ranges::sort(z, [&](int x, int y) {return c[x] > c[y];});
        std::vector<int> res;
        for (auto x : z) {
            if (cz <= 0)break;
            cz -= c[x];
            res.push_back(x + 1);
        }
        // std::cout << cz << ' ';
        if (ans > res.size()) {
            ans = res.size();
            as = res;
        }
    }
    std::cout << ans << '\n';
    for (int x : as)std::cout << x << " ";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}