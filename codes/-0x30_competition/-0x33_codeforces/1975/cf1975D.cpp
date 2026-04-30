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
    int a, b;std::cin >> a >> b;a--, b--;
    std::vector<pii> adj[n];
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        adj[u].push_back({ v,1 });
        adj[v].push_back({ u,1 });
    }
    int dis_b;
    std::vector<int> chain;
    std::function<bool(int, int, i64)> dfs = [&](int x, int p, i64 d) {
        chain.push_back(x);
        if (x == b) {
            dis_b = d;
            return true;
        }
        for (auto [nxt, dis] : adj[x])if (nxt != p) {
            if (dfs(nxt, x, d + dis))return true;
        }
        chain.pop_back();
        return false;
        };
    dfs(a, -1, 0);
    i64 cur = 0;
    int pos = 0;
    std::function<void(int, int, i64)> dfs2 = [&](int x, int p, i64 d) {
        if (x == b)dis_b = d;
        if (d > cur) {
            cur = d;
            pos = x;
        }
        for (auto [nxt, dis] : adj[x])if (nxt != p) {
            dfs2(nxt, x, d + dis);
        }
        };
    if (chain.size() % 2) {
        dfs2(chain[chain.size() / 2], -1, 0);
        // std::cout << chain[chain.size() / 2] << ' ';
        int ans = (n - 1) * 2 - cur + chain.size() / 2;
        std::cout << ans;
    }
    else {
        dfs2(chain[chain.size() / 2 - 1], -1, 0);
        int ans = (n - 1) * 2 - cur + chain.size() / 2;
        std::cout << ans;
    }
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