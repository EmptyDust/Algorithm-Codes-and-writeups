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
    int n, m;std::cin >> n >> m;
    std::vector g(n, std::vector<int>());
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<int> p(n), dfn(n, -1), low(n, -1), col(n, -1), stk;
    for (auto& x : p)std::cin >> x, x--;
    int now = 0, cnt = 0;
    auto tarjen = [&](auto&& tarjen, int u)->void {
        dfn[u] = low[u] = now++;
        stk.push_back(u);
        for (auto v : g[u]) {
            if (dfn[v] == -1) {
                tarjen(tarjen, u);
                low[u] = std::min(low[u], low[v]);
            }
            else if (col[v] == -1) {//fan zu
                low[u] = std::min(low[u], low[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int pre;
            cnt++;
            do {
                pre = stk.back();
                col[pre] = cnt;
                stk.pop_back();
            } while (pre != u);
        }
        };
    for (int i = 0;i < n;++i)
        if (dfn[i] == -1)
            tarjen(tarjen, i);
    auto dfs = [&](auto&& dfs, int u, int l, int r) {

        };
    dfs(dfs, 0, 0, n - 1);
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