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
    std::vector<int> p(n), vis(n);
    for (auto& x : p)std::cin >> x, x--;
    int pos = 0;
    std::vector<a2> ans;
    auto dfs = [&](auto&& dfs, int u)->void {
        vis[u] = 1;
        pos++;
        std::set<int> st;
        for (auto v : g[u]) st.insert(v);
        while (st.size()) {
            while (st.size() && vis[*st.begin()])
                st.erase(st.begin());
            if (pos == n || st.empty())break;
            if (st.count(p[pos])) {
                dfs(dfs, p[pos]);
            }
            else {
                ans.push_back({ u, p[pos] });
                dfs(dfs, p[pos]);
            }
        }
        };
    while (pos < n) {
        dfs(dfs, p[pos]);
    }
    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans)std::cout << x + 1 << " " << y + 1 << '\n';
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