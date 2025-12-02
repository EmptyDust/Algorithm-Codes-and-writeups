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
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<int> res(2 * n + 1, inf), premin(n + 1, inf), premax(n + 1), sufmin(n + 2, inf), sufmax(n + 2);
    std::vector map(2, std::vector<int>(n + 1));
    for (int i = 1;i <= n;++i) std::cin >> map[0][i];
    for (int i = 1;i <= n;++i) std::cin >> map[1][i];
    for (int i = 1;i <= n;++i) {
        premin[i] = std::min(premin[i - 1], map[0][i]);
        premax[i] = std::max(premax[i - 1], map[0][i]);
    }
    for (int i = n;i >= 1;--i) {
        sufmin[i] = std::min(sufmin[i + 1], map[1][i]);
        sufmax[i] = std::max(sufmax[i + 1], map[1][i]);
    }
    for (int i = 1;i <= n;++i) {
        int max = std::max({ map[0][i], map[1][i], sufmax[i + 1], premax[i - 1] });
        int min = std::min({ map[0][i], map[1][i], sufmin[i + 1], premin[i - 1] });
        res[min] = std::min(res[min], max);
    }
    i64 ans = 0;
    for (int i = 2 * n, minmax = inf;i >= 1;--i) if ((minmax = std::min(minmax, res[i])) != inf) {
        ans += 2 * n - minmax + 1;
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