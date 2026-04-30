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
    int n;std::cin >> n;
    std::vector adj(n, std::vector<int>());
    for (int i = 0;i < n - 1;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> ans(n + 1);
    std::function<int(int, int, int)> dfs1 = [&](int u, int p, int depth) {
        int ret = depth;
        for (auto v : adj[u])if (v != p) {
            ret = std::max(ret, dfs1(v, u, depth + 1));
        }
        ans[0]++;
        ans[depth]--;
        ans[ret + 1]++;
        // std::cout << u << ' ' << depth << ' ' << ret << '\n';
        return ret;
        };
    dfs1(0, -1, 0);
    for (int i = 1;i <= n;++i) {
        ans[i] += ans[i - 1];
        // std::cout << ans[i] << ' ';
    }
    std::cout << *std::min_element(ans.begin(), ans.end());
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