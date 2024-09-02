#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    i64 n, w;std::cin >> n >> w;
    std::vector<int> g[n], p[n], fa(n), cnt(n);
    std::vector<i64> wei(n);
    for (int i = 1;i < n;++i) {
        std::cin >> fa[i];fa[i]--;
        g[fa[i]].push_back(i);
    }
    std::vector<int> edges;
    std::function<void(int)> dfs = [&](int u) {
        if (u)edges.push_back(u);
        cnt[u] = edges.size();
        for (int e : edges)p[e].push_back(u);
        edges.clear();
        for (auto v : g[u]) {
            dfs(v);
        }
        if (u)edges.push_back(u);
        };
    dfs(0);
    cnt[0] = edges.size();
    for (int e : edges)p[e].push_back(0);
    edges.clear();
    i64 rest = w, ans = 0, c = n;
    for (int i = 1;i < n;++i) {
        i64 x, y;std::cin >> x >> y;x--;
        rest -= y;
        for (int e : p[x]) {
            // std::cout << e << ' ';
            ans += y;
            cnt[e]--;
            if (!cnt[e]) {
                c--;
            }
        }
        // std::cout << ans << ' ';
        std::cout << ans + rest * c << " ";
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