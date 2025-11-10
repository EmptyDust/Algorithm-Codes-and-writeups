#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector g(n, std::vector<int>());
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // up: cost cnt
    // down: cost add
    std::vector dp(n, std::vector<a3>());
    auto dfs = [&](this auto&& dfs, int u, int p) ->void {
        std::vector<a3> info;
        info.push_back({ 0, 0, 0 });
        // info.push_back({ { a[u], 1, 0} }); // up
        // info.push_back({ { a[u], 0, a[u]} }); // down

        for (auto v : g[u]) if (v != p) {
            dfs(v, u);
            std::vector<a3> ninfo;
            for (auto [cost, cnt, add] : info) {
                for (auto [vcost, vc, va] : dp[v]) {
                    ninfo.push_back({ cost + vcost + vc * add + cnt * va, cnt + vc, add + va });
                }
            }
            ranges::sort(ninfo);
            info.clear();
            int cur = inf;
            for (auto x : ninfo) {
                if (x[1] < cur) {
                    info.push_back(x);
                    cur = x[1];
                }
            }
        }

        };
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