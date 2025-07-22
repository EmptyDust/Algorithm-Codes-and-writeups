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
    int n, k;std::cin >> n >> k;
    std::vector<int> tag(n), depth(n);
    std::vector fa(n, std::vector<int>(32, -1)), g(n, std::vector<int>());
    for (int i = 1;i < n;++i) {
        std::cin >> fa[i][0];
        fa[i][0]--;
        // std::cout<<fa[i][0]
        g[fa[i][0]].push_back(i);
    }
    auto work = [&](auto&& dfs, int u, int dep)->void {
        depth[u] = dep;
        for (int i = 1;i < 32;++i) {
            if (fa[u][i - 1] != -1) {
                fa[u][i] = fa[fa[u][i - 1]][i - 1];
            }
        }
        for (auto v : g[u])
            dfs(dfs, v, dep + 1);
        };
    work(work, 0, 1);
    std::vector<a3> pos(k);
    for (auto& [u, l, r] : pos)std::cin >> u >> l >> r, u--;
    tag[0] = 1;
    for (auto& [u, l, r] : pos) {
        int x = u;
        for (int i = 31;i >= 0;--i) {
            if (fa[x][i] != -1 && !tag[fa[x][i]]) {
                x = fa[x][i];
            }
        }
        x = fa[x][0];
        int dep = depth[u] - depth[x];
        // std::cout << dep << ' ';
        if (dep <= r - l + 1) {
            std::cout << l + dep - 1;
            return;
        }
        int len = dep - (r - l + 1);
        x = u;
        for (int i = 31;i >= 0;--i)if (len >> i & 1) {
            x = fa[x][i];
        }
        while (!tag[x]) {
            tag[x] = 1;
            x = fa[x][0];
        }
    }
    std::cout << -1;
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