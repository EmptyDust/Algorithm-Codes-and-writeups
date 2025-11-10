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
    std::vector dis(n + 1, std::vector<int>(n + 1));
    for (int i = 1;i <= n;++i) {
        for (int j = i;j <= n;++j) {
            std::cin >> dis[i][j];
            dis[j][i] = dis[i][j];
        }
    }
    std::vector g(n + 1, std::vector<int>());
    for (int u = 1;u <= n;++u) {
        for (int v = 1;v <= n;++v) if (v != u) {
            if ((dis[1][u] ^ dis[u][v] ^ dis[1][v]) == u) {
                g[u].push_back(v);
                // std::cout << u << ' ' << v << "\n";
            }
        }
    }
    std::vector<int> vis(n + 1), fa(n + 1);
    auto tobo = [&](this auto&& tobo, int u) ->void {
        if (vis[u]) return;
        vis[u] = 1;
        for (auto v : g[u]) {
            tobo(v);
        }
        for (auto v : g[u]) {
            if (fa[v] == 0) fa[v] = u;
        }
        };
    tobo(1);
    for (int u = 2;u <= n;++u) {
        std::cout << u << ' ' << fa[u] << '\n';
    }
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