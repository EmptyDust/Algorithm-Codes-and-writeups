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
    if (m <= n) {
        std::cout << "YES\n";
        for (int i = 0;i < 2 * n;++i) {
            for (int j = 1;j <= m;++j)
                std::cout << j << ' ';
            std::cout << '\n';
        }
        return;
    }
    if (m == n + 1) {
        std::cout << "YES\n";
        // std::vector ans(2 * n, std::vector<int>(m));
        // std::vector<int> curl(2 * n);
        // std::vector<int> curr(m);
        // std::vector<int> visl(m);
        // std::vector<int> visr(m);
        // int id = 1;
        // auto dfs = [&](auto&& self, int u, bool left)->void {
        //     if (left) {
        //         while (ans[u][curl[u]])curl[u]++;
        //         ans[u][curl[u]] = id;
        //         self(self, curl[u], 0);
        //     }
        //     else {
        //         while (ans[curr[u]][u])curr[u]++;
        //         ans[curr[u]][u] = id;
        //         self(self, curr[u], 1);
        //     }
        //     };
        // for (int i = 0;i < n;++i) {
        //     dfs(dfs, i, 1);
        // }
        for (int i = 0;i < 2 * n;++i) {
            for (int j = 0;j < m;++j) {
                
            }
            // std::cout << ans[i][j] << ' ';
            std::cout << '\n';
        }
        return;
    }
    std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}