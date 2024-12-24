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

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<int> Fa(n), dep(n);
    std::vector adj(n, std::vector<int>());
    for (int i = 0;i < n - 1;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&](auto&& self, int u)->void {
        for (int v : adj[u])if (v != Fa[u]) {
            Fa[v] = u;
            dep[v] = dep[u] + 1;
            self(self, v);
        }
        };
    dfs(dfs, 0);
    for (int i = 0;i < q;++i) {
        int v, c;std::cin >> v >> c;
        v--;

        int ans = dep[v];
        std::vector<int> cnt(n);
        for (int x = Fa[v];x > 0;x = Fa[Fa[x]]) {
            int sz = adj[x].size();
            cnt[sz]++;
            ans += 2 * (sz - 1);
        }
        for (int i = n - 1;i > 0;--i) {
            while (cnt[i] && c) {
                c--;
                cnt[i]--;
                ans -= (2 * (i - 1));
            }
        }
        std::cout << ans << "\n";
    }
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