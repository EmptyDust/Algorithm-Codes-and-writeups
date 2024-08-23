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
const i64 inf = 1e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector map(n, std::vector<i64>(n));
    std::vector l(n, 0), h(n, 0);
    i64 ans = 0;
    for (int i = 0;i < n;++i)for (int j = 0;j < n;++j) {
        std::cin >> map[i][j];
        if (map[i][j] < 0) {
            ans += map[i][j];
            l[i] = 1;
            h[j] = 1;
            map[i][j] = inf;
        }
    }
    i64 res = inf;
    {
        i64 res1 = 0;
        for (int i = 0;i < n;++i) if (!l[i]) {
            i64 min = inf;
            for (int j = 0;j < n;++j)
                min = std::min(min, map[i][j]);
            res1 += min;
        }
        res = std::min(res, res1);
    }
    {
        i64 res1 = 0;
        for (int i = 0;i < n;++i) if (!h[i]) {
            i64 min = inf;
            for (int j = 0;j < n;++j)
                min = std::min(min, map[j][i]);
            res1 += min;
        }
        // std::cout << res1 << ' ';
        res = std::min(res, res1);
    }
    ans += res;
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